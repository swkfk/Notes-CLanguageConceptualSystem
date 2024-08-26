# 派生类型：数组类型

[@Bili: BV1pM4m117vb](https://www.bilibili.com/video/BV1pM4m117vb)

> 派生类型：由程序员构造出来的新类型。C 语言标准规定的派生类型有：**数组类型**、**指针类型**、**结构体类型**、**联合体类型**、**原子类型**以及**函数类型**。前五种是**对象类型**。

## 数组类型的定义

假设一个**完全对象类型** `T`，以及元素的个数 `N`，数组类型可形式化定义为：**`T[N]`**，在标准中被称为 **"Array of T"**。

`N` 是一个**表达式**，有下面三种情况“

- 如若没有 `N`，则 `T[]` 也是一个数组类型，但是**不完全对象类型**。
- `N` 是一个**整数常量**或者**整数常量表达式**，则 `T[N]` 是普通数组类型。
- 否则，`T[N]` 是一个**变长数组（VLA）类型**。

`sizeof(T[N]) == N * sizeof(T)`，`alignof(T[N]) == alignof(T)`。不完全对象类型 `T[]` 没有 size 或 alignment.

```c
// chapter_04/array_type.c

{{#include ../code/chapter_04/array_type.c:main}}
```

## 数组类型形式化表示

```c
typedef int AINT[5];
```

通过 `typedef` 为 `int[5]` 提供一个别名 `AINT`，后者是一个整体的 `T`.

> `typedef int[5] AINT;` 是编译错误的，这是语法要求。可以使用 C23 关键词 `typeof` 进行（注：GNU 拓展也有这个关键词）：
> ```c
> typedef typeof(int[5]) AINT;
> ```
> `typeof(int[5])` 与 `int[5]` 只是语法上的差异，在概念含义上没有区别。

将 `int[5]` 视作 `T`，取 `N = 10`，则派生出来的类型为：`int[10][5]`。

于是 `int[10][5]` 就等价于 `AINT[10]`（Array of `AINT`），C 语言所有的数组都是“一维”的。

> 为什么不是 `int[5][10]`？因为 `T[N]` 会从左至右把第一个中括号删掉，剩下的是元素类型。

```c
// chapter_04/array_type.c
{{#include ../code/chapter_04/array_type.c:int_t_t}}
```

注意，**不完全类型不可以派生**，`int[10][]` 是不合法的。同样，`void` 由于也是一个不完全类型，`void[10]` 也是不合法的。
