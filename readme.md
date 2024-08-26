# 《C 语言标准中的概念体系》学习笔记

授课教师：[荣文戈老师](https://space.bilibili.com/1601374953)（@BUAA）

说是笔记，可能**更像摘抄**，添加了一些可直接运行的代码，位于 `code/` 目录下

在线阅读：[GitHub Pages](https://swkfk.github.io/Notes-CLanguageConceptualSystem)


## 使用 mdBook 进行预览与构建

1. 安装 mdBook 本体（使用 `cargo` 呗）：

```sh
cargo install mdbook
```

2. 安装 graphviz 依赖（用于渲染 dot 图）：

```sh
sudo apt update && sudo apt install -y graphviz
cargo install mdbook-graphviz
```

3. 本地预览

```sh
mdbook serve
```

4. 本地构建

```sh
mdbook build
```
