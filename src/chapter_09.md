# 分配对象：字符串字面量

[@Bili: BV1eJePejErv](https://www.bilibili.com/video/BV1eJePejErv)


## 什么是 String Literal？

**String Literal** 由**编码前缀**和**双引号引导的字符序列**构成：

*encoding-prefix* **"** *s-char-sequence* **"**

### 字符序列中的字符

1. 可以包含所有源字符集中的字符，除了 **`"`**，**`\`** 与**实际的回车**。
2. 可以包含由 `\` 引导的转义字符


### 编码前缀

一共有 5 种：无编码、`u8`、`u`、`U` 与 `L`。


#### "Hello" 分配对象

**匿名对象**，分别用 `'H', 'e', 'l', 'l', 'o', '\0'` 初始化 `char` 数组中的每个元素。

> **对象存储周期（Storage Duration）**，C 语言一共定义了 4 种，决定对象的有效期：
> 
> - **`static`**：有效期覆盖整个程序运行期间，程序运行前会被初始化（如果未显式初始化的话）。
> - **`automatic`**
> - **`allocated`**
> - **`thread`**
>
> ```c
> int a;  // duration: static，被初始化为缺省的 0
> int main(int argc, char* argv[]) {
>     int b;  // storage duration: automatic，没有显式初始化
>     return 0;
> }
> ```
> > **C 语言没有全局、局部变量的概念**。

> **所有 String Literal 都具有静态存储周期**。

#### 另外四种编码前缀

构成字符数组的元素对象类型：

| 编码前缀 | 元素字符对象类型 |
| :---: | :---: |
| `u8` | `char8_t` |
| `u` | `char16_t` |
| `U` | `char32_t` |
| `L` | `wchar_t` |


## 多个对象表示一样的 String Literal 分配对象

```c
int main(int argc, char* argv[]) {
    "hello";
    "hello";
    return 0;
}
```

第二个 `"hello"` 是否分配另一个对象值一样的字符数组**取决于编译器的实现**。

```c
int main(int argc, char* argv[]) {
    "hello";
    L"hello";
    return 0;
}
```

上述两个，**对象表示不一样**，因此会分配两个对象。


## String 与 String Literal

若双引号中不**显式**包含 `\0` 字符，则这样的 String Literal 被称为 **String**.


## 多个相邻 String Literal 合并在一起

`"A" " " "B"` 会被合并为 `"A B"`，要求各个 String Literal 的编码前缀一致。
