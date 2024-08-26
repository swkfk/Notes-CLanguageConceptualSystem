# 对象类型：限定类型

[@Bili: BV1hS411w76B](https://www.bilibili.com/video/BV1hS411w76B)

C 语言中有四种**限定符（Qualifier）**。

## 原子限定类型 `_Atomic(T)`

给定一个类型 `T`，其原子限定类型为 `_Atomic(T)`，是一个合法的新类型，其对象的大小与缺省对齐要求为 `sizeof(_Atomic(T))` 与 `alignof(_Atomic(T))`。

`_Atomic(T)` 与 `T` 是两种不同的类型，大小、对齐要求以及相同对象值对应的对象表示不一定相同。

> 原子类型也是一种**派生类型**，编译器可以选择不支持原子类型。


## 另外三种限定类型

剩下三个限定符：`const`，`volatile` 与 `restrict`。

给定类型 `T` 和上述三个之一的限定符 `Q`，则 `T` 的限定类型为 `T Q` 或 `Q T`，它们和 `T` 是**不同的类型**，但是**大小、表示值与对齐方式一致**。

> `restrict` 只能限定**对象指针类型**，或者对象指针类型**构成的多维数组类型**。


## `typedef` 提供的类型整体视角

- 非数组非指针类型 `T`：`typedef T Alias;`
- 数组类型 `T[N]`：`typedef T Alias[N];`
- 指针类型 `T*`：`typedef T* Alias;`

> 复杂示例：
> - `int*[10]`：`typedef int* Alias[10];`
> - `int(*)[10]`：`typedef int(* Alias)[10];`

在这种情况下，`Q Alias` 与 `Alias Q` 等价（视作整体）。

## 非整体视角下，限定符在左右的区别

1. 非数组非指针类型 `T`：`Q T === T Q`
2. 数组类型 `T[N]`
   - `Q T[N]`：数组类型，元素类型为 `Q T`，元素个数为 `N`
   - `T[N] Q`：不合法
3. 指针类型 `T*`：
   - `Q T*`：指针类型，Reference Type 是 `Q T`
   - `T* Q`：`Q` 限定了 `T*` 类型

```c
// chapter_06/const_qualifier.c
{{#include ../code/chapter_06/const_qualifier.c:main}}
```

> `Q typeof(T[N])` 等价于 `Q typeof(T)[N]`，**与 `Q T[N]` 有区别！**
>
> `const typeof(int*[10])` 等价于 `const typeof(int*)[10]`，而 `const typeof(int*)` 等价于 `int *const`，因此原类型等价于 `int* const[10]`，而非 `const int*[10]`。


## 多个限定符的语义

`const volatile int` 与 `volatile const int` 等价。

C23 提供新关键词 `typeof_unqual(T)` 获取 `T` 类型的非限定类型，`typeof_unqual(const volatile int)` 等价于 `int`。
