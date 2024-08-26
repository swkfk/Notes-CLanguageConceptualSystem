# 分配对象：对象声明

[@Bili: BV1UKiLezEKJ](https://www.bilibili.com/video/BV1UKiLezEKJ)


## 分配一个对象的方法

- 对象声明
- String Literal（字符串字面量）
- Compound Literal（复合字面量）
- 内存管理函数


## 对象声明的基本语法形式

```c
T O = initializer;
```

上述语句进行了三件事：

1. 分配了一个 `T` 类型的对象；
2. 对象的名字叫做 `O`；
3. 用 `initializer` 初始化这个对象的对象表示（也可以没有 `initializer`）。

这里的 `T` 需要**作为整体对待**，否则在使用 `T`，`T[N]` 与 `T*` 时，`O` 的位置会有所区别，不再赘述。


### 一次声明多个对象

基本形式为：

```c
T O1 = initializer1, O2 = initializer2, ..., On = initializern;
```

对于数组类型 `T[N]`，有下面两种写法：

```c
T O1[N] = initializer1, O2[N] = initializer2, ..., On[N] = initializern;
typeof(T[N]) O1 = initializer1, O2 = initializer2, ..., On = initializern;
```

对于指针类型 `T*`，有下面两种写法：

```c
T *O1 = initializer1, *O2 = initializer2, ..., *On = initializern;
typeof(T*) O1 = initializer1, O2 = initializer2, ..., On = initializern;
```


## 标量类型与非标量类型

算数类型与指针类型（以及 `nullptr_t` 类型）统称为**标量类型（Scalar Type）**。


### 标量类型对象的 initializer

对于标量类型 `T`，以及与之关联的限定类型 `Q T`，initializer 有下列两种形式：

- `{}`，空初始化列表（从 C23 开始）
- **除逗号表达式外**的任意表达式 `exp` 或 `{exp}`

```c
// chapter_07/scalar_init.c:main
{{#include ../code/chapter_07/scalar_init.c:main}}
```

`{}` 意味着将该对象的值设置为该类型的**缺省值**。

- 整数对象的缺省值为 `+0` 或者无符号的 `0`；
- 十进制浮点数对象的缺省值为 `+0`，其他浮点数的缺省值为 `+0`，或者无符号的 `0`；
- 指针类型的缺省值为空指针。

表达式意味着使用该**表达式求值后的右值**来初始化对象表示。


### 数组类型 `T[N]` 对象的 initializer

同样有两种形式：

- `{}`，空初始化列表
- `{sub-initializer_1, sub-initializer_2, ..., sub-initializer_n}`

每一个 `sub-initializer_i` 用来初始化数组中的一个**元素对象**，如果元素对象依然是一个数组对象，则 `sub-initializer_i` 则再使用数组对象初始化的形式。

> 若 `N` 不存在时，不可以使用空初始化列表，**子初始化列表的个数**就是数组的元素个数。
>
> 若数组是**变长数组**时，只能用 `{}` 进行初始化。

对于普通数组，使用 `{}` 初始化，元素对象会被**递归地**设置成缺省值。若 \\(n < N\\)，则剩下的对象被设置成缺省值。

```c
// chapter_07/array_init.c
{{#include ../code/chapter_07/array_init.c:main}}
```

## 不确定的对象表示

当没有 `initializer` 时，对象其实也有确定的对象值，但并不是程序员设定的，因此此时的对象表示被称为 "**indeterminate representation**"。
