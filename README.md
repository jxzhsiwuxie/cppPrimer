# cppPrimer
C++Primer5 练习题

## 该仓库主要包含三部分
1. 书中的示例程序，对应的源文件放在每一章节文件夹下的 `examples` 子文件夹中
2. 书中的练习题，对应的源文件放在每一章节文件夹下的 `exercises` 子文件夹中
3. 收集的一些好玩的 c++ 程序，对应的源文件放在 `interesting_cpps` 文件夹中

## 编译器信息
```
x86_64-w64-mingw32
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
```

### 关于打印中文乱码问题
如果使用的是 windows 中文系统并且源文件编码格式是 utf-8，则程序在控制台打印中文的时候可能会乱码。这里有两种方法：
- 1. 将源文件编码改为和系统一样的 gbk 编码。
- 2. 在使用 g++ 编译的时候添加一个编译参数 `-fexec-charset` 来指定代码中字符串的编码，例如
```
    g++ -fexec-charset=gbk -o main .\main.cpp
```
如果不指定这个参数并且源文件是 utf-8 编码的话，由于控制台使用的是 gbk 编码，所以就导致打印的中文字符乱码。

---

## 第 1 章
## 开始

### 1.1 编写一个简单的 c++ 程序
- 1.1.1 编写、运行程序

### 1.2 初识输入输出

### 1.3 注释简介

### 1.4 控制流
- 1.4.1 while 语句
- 1.4.2 for 语句
- 1.4.3 读取数量不定的输入数据
- 1.4.4 if 语句

### 1.5 类简介
- 1.5.1 Sales_item 类
- 1.5.2 初识成员函数

### 1.6 书店程序

---

## 第 2 章
## 变量和基本类型

### 2.1 基本内置类型
- 2.1.1 算数类型
- 2.1.2 类型转换
- 2.1.3 字面值常量

### 2.2 变量
- 2.2.1 变量定义
- 2.2.2 变量声明和定义的关系
- 2.2.3 标识符
- 2.2.4 名字的作用域

### 2.3 复合类型
- 2.3.1 引用
- 2.3.2 指针
- 2.2.3 理解复合类型的声明

### 2.4 const 限定符
- 2.4.1 const 的引用
- 2.4.2 指针和 const
- 2.4.3 顶层 const
- 2.4.4 constexpr 和常量表达式

### 2.5 处理类型
- 2.5.1 类型别名
- 2.5.2 auto 类型说明符
- 2.5.3 decltype 类型指示符

### 2.6 自定义数据结构
- 2.6.1 定义 Sales_data 类型
- 2.6.2 使用 Sales_data 类
- 2.6.3 编写自己的头文件