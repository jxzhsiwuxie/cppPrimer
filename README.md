# cppPrimer

C++Primer5 练习题

## 该仓库主要包含三部分

1. 书中的示例程序，对应的源文件放在每一章节文件夹下的 `examples` 子文件夹中
2. 书中的练习题，对应的源文件放在每一章节文件夹下的 `exercises` 子文件夹中

## 编译器信息

```txt
x86_64-w64-mingw32
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
```

### 关于打印中文乱码问题

如果使用的是 windows 中文系统并且源文件编码格式是 utf-8，则程序在控制台打印中文的时候可能会乱码。这里有两种方法：

* 将源文件编码改为和系统一样的 gbk 编码。
* 在使用 g++ 编译的时候添加一个编译参数 `-fexec-charset` 来指定代码中字符串的编码，例如

```cmd
    g++ -fexec-charset=gbk -o main .\main.cpp
```

如果不指定这个参数并且源文件是 utf-8 编码的话，由于控制台使用的是 gbk 编码，所以就导致打印的中文字符乱码。

---

## 第 1 章

## 开始

### 1.1 编写一个简单的 c++ 程序

* 1.1.1 编写、运行程序

### 1.2 初识输入输出

### 1.3 注释简介

### 1.4 控制流

* 1.4.1 while 语句
* 1.4.2 for 语句
* 1.4.3 读取数量不定的输入数据
* 1.4.4 if 语句

### 1.5 类简介

* 1.5.1 Sales_item 类
* 1.5.2 初识成员函数

### 1.6 书店程序

### 小节

### 术语表

---

## 第 2 章

## 变量和基本类型

### 2.1 基本内置类型

* 2.1.1 算数类型
* 2.1.2 类型转换
* 2.1.3 字面值常量

### 2.2 变量

* 2.2.1 变量定义
* 2.2.2 变量声明和定义的关系
* 2.2.3 标识符
* 2.2.4 名字的作用域

### 2.3 复合类型

* 2.3.1 引用
* 2.3.2 指针
* 2.2.3 理解复合类型的声明

### 2.4 const 限定符

* 2.4.1 const 的引用
* 2.4.2 指针和 const
* 2.4.3 顶层 const
* 2.4.4 constexpr 和常量表达式

### 2.5 处理类型

* 2.5.1 类型别名
* 2.5.2 auto 类型说明符
* 2.5.3 decltype 类型指示符

### 2.6 自定义数据结构

* 2.6.1 定义 Sales_data 类型
* 2.6.2 使用 Sales_data 类
* 2.6.3 编写自己的头文件

### 小节

### 术语表
---

## 第 3 章

## 字符串、向量和数组

### 3.1 命名空间的 using 声明

### 3.2 标准库类型 string

* 3.2.1 定义和初始化 string
* 3.2.2 string 对象上的操作
* 3.2.3 处理 string 对象中的字符

### 3.3 标准库类型 vector

* 3.3.1 定义和初始化 vector 对象
* 3.3.2 向 vector 对象中添加元素
* 3.3.3 其它 vector 操作

### 3.4 迭代器介绍

* 3.4.1 使用迭代器
* 3.4.2 迭代器运算

### 3.5 数组

* 3.5.1 定义和初始化内置数组
* 3.5.2 访问数组元素
* 3.5.3 指针和数组
* 3.5.4 C 风格 字符串
* 3.5.5 与旧代码的接口

### 3.6 多维数组

### 小节

### 术语表

---

## 第 4 章

## 表达式

### 4.1 基础

* 4.1.1 基本概念
* 4.1.2 优先级与结合律
* 4.1.3 求值顺序

### 4.2 算数运算符

### 4.3 逻辑和关系运算符

### 4.4 赋值运算符

### 4.5 递增和递减运算符

### 4.6 成员访问运算符

### 4.7 条件运算符

### 4.8 位运算符

### 4.9 sizeof 运算符

### 4.10 都好运算符

### 4.11 类型转换

* 4.11.1 算数转换

* 4.11.2 其它隐式类型转换

* 4.11.3 显式转换

### 4.12 运算符优先级表

### 小节

### 术语表

---

## 第 5 章

## 语句

### 5.1 简单语句

### 5.2 语句作用域

### 5.3 条件语句

* 5.3.1 if 语句

* 5.3.2 switch 语句

### 5.4 迭代语句

* 5.4.1 while 语句

* 5.4.2 传统的 for 语句

* 5.4.3 范围 for 语句

* 5.4.4 do while 语句

### 5.5 跳转语句

* 5.5.1 break 语句

* 5.5.2 continue 语句

* 5.5.3 goto 语句

### 5.6 try 语句块和异常处理

* 5.6.1 throw 表达式

* 5.6.2 try 语句块

* 5.6.3 标准异常

### 小节

### 术语表

---

## 第 6 章

## 函数

### 6.1 函数基础

* 6.1.1 局部对象

* 6.1.2 函数声明

* 6.1.3 分离式编译

### 6.2 参数传递

* 6.2.1 传值参数

* 6.2.2 传引用参数

* 6.2.3 const 形参和实参

* 6.2.4 数组形参

* 6.2.5 main 处理命令行选项

* 6.2.6 含有可变形参的函数

### 6.3 返回类型和 return 语句

* 6.3.1 无返回值的函数

* 6.3.2 有返回值的函数

### 6.4 函数重载

* 6.4.1 重载与作用域

### 6.5 特殊用途语言特性

* 6.5.1 默认实参

* 6.5.2 内联函数和 constexpr 函数

* 6.5.3 调试帮助

### 6.6 函数匹配

* 6.6.1 实参类型转换

### 小节

### 术语表

---

## 第 7 章

## 类

### 7.1 定义抽象数据类型

* 7.1.1 设计 Sales_data 类

* 7.1.2 定义改进的 Sales_data 类

* 7.1.3 定义类相关的非成员函数

* 7.1.4 构造函数

* 7.1.5 拷贝、赋值和析构

### 7.2 访问控制与封装

* 7.2.1 友元

### 7.3 类的其它特性

* 7.3.1 类成员再探

* 7.3.2 返回 *this 的成员函数

* 7.3.3 类类型

* 7.3.4 友元再探

### 7.4 类的作用域

* 7.4.1 名字查找与类的作用域

### 7.5 构造函数再探

* 7.5.1 构造函数的初始值列表

* 7.5.2 委托构造函数

* 7.5.3 默认构造函数的作用

* 7.5.4 隐式的类类型转换

* 7.5.5 聚合类

* 7.5.6 字面值常量类

### 7.6 类的静态成员

### 小节

### 术语表

---

## 第 8 章

## IO 库

### 8.1 IO 类

* 8.1.1 IO 对象无拷贝或赋值

* 8.1.2 条件状态

* 8.1.3 管理输出缓冲

### 8.2 文件输入输出

* 8.2.1 使用文件流对象

* 8.2.2 文件模式

### 8.3 string 流

* 8.3.1 使用 istringstream

* 8.3.2 使用 ostringsstream

### 小节

### 术语表

---

## 第 9 章

## 顺序容器

### 9.1 顺序容器概述

### 9.2 容器库概览

* 9.2.1 迭代器

* 9.2.2 容器类型成员

* 9.2.3 begin 和 end 成员

* 9.2.4 容器定义和初始化

* 9.2.5 赋值和 swap

* 9.2.6 容器大小操作

* 9.2.7 关系运算符

### 9.3 顺序容器操作

* 9.3.1 向顺序容器添加元素

* 9.3.2 访问元素

* 9.3.3 删除元素

* 9.3.4 特殊的 forward_list 操作

* 9.3.5 改变容器大小

* 9.3.6 容器操作可能使迭代器失效

### 9.4 vector 对象是如何增长的

### 9.5 额外的 string 操作

* 9.5.1 构造 stirng 的其它方法

* 9.5.2 改变 stirng 的其它方法

* 9.5.3 string 搜索操作

* 9.5.4 compare 函数

* 9.5.5 数值转换

### 9.6 容器适配器

### 小节

### 术语表

---

## 第 10 章

## 泛型算法

### 10.1 概述

### 10.2 初始泛型算法

* 10.2.1 只读算法

* 10.2.2 写容器元素的算法

* 10.2.3 重排容器元素的算法

### 10.3 定制操作

* 10.3.1 向算法传递函数

* 10.3.2 lambda 表达式

* 10.3.3 lambda 捕获和返回

* 10.3.4 参数绑定

### 10.4 再探迭代器

* 10.4.1 插入迭代器

* 10.4.2 iostream 迭代器

### 10.5 泛型算法结构

* 10.5.1 5 类迭代器

* 10.5.2 算法形参模式

* 10.5.3 算法命名规范

### 10.6 特定容器算法

### 小节

### 术语表

---

## 第 11 章

## 关联容器

### 11.1 使用关联容器

### 11.2 关联容器概述

* 11.2.1 定义关联容器

* 11.2.2 关键字类型的要求

* 11.2.3 pair 类型

### 11.3 关联容器操作

* 11.3.1 关联容器迭代器

* 11.3.2 添加元素

* 11.3.3 删除元素

* 11.3.4 map 的下标操作

* 11.3.5 访问元素

* 11.3.6 一个单词转换的 map

### 11.4 无序容器

---

## 第 12 章

## 动态内存

### 12.1 动态内存与智能指针

* 12.1.1 shared_ptr 类

* 12.1.2 直接管理内存

* 12.1.3 shared_ptr 和 new 结合使用

* 12.1.4 智能指针和异常

* 12.1.4 智能指针和异常

* 12.1.5 unique_ptr

* 12.1.6 weak_ptr

### 12.2 动态数组

* 12.2.1 new 和数组

* 12.2.2 allocator 类

### 12.3 使用标准库：文本查询程序

* 12.3.1 文本查询程序设计

* 12.3.2 文本查询程序类的定义

### 小节

### 术语表

---

## 第 13 章

## 拷贝控制

### 13.1 拷贝、赋值与销毁

* 13.1.1 拷贝构造函数

* 13.1.2 拷贝赋值运算符

* 13.1.3 析构函数

* 13.1.4 三/五法则

* 13.1.5 使用 =default

* 13.1.6 阻止拷贝

### 13.2 拷贝控制和资源管理

* 13.2.1 行为像值的类

* 13.2.2 定义行为像指针的类

### 13.3 交换操作

### 13.4 拷贝控制示例

### 13.5 动态内存管理类

### 13.6 对象移动

* 13.6.1 右值引用

* 13.6.2 移动构造函数和移动赋值运算符

* 13.6.3 右值引用和成员函数

### 小节

### 术语表

---

## 第 14 章

## 重载运算与类型转换

### 14.1 基本概念

### 14.2 输入和输出运算符

* 14.2.1 重载输出运算符 <<

* 14.2.2 重载输入运算符 >>

### 14.3 算数和关系运算符

* 14.3.1 相等运算符

* 14.3.2 关系运算符

### 14.4 赋值运算符

### 14.5 下标运算符

### 14.6 递增和递减运算符

### 14.7 成员访问运算符

### 14.8 函数调用运算符

### 14.8.1 lambda 是函数对象

### 14.8.2 标准库定义的函数对象

### 14.8.3 可调用对象与 function

## 14.9 重载、类型转换与运算符

### 14.9.1 类型转换运算符

### 14.9.2 避免有二义性的类型转换

### 小节

### 术语表

---

## 第 15 章

## 面向对象程序设计

### 15.1 OOP：概述

### 15.2 定义基类和派生类

* 15.2.1 定义基类

* 15.2.2 定义派生类

* 15.2.3 类型转换与继承

### 15.3 虚函数

### 15.4 抽象基类

### 15.5 访问控制与继承

### 15.6 继承中的类作用域

### 15.7 构造函数与拷贝控制

* 15.7.1 虚析构函数

* 15.7.2 合成拷贝控制与继承

* 15.7.3 派生类的拷贝控制成员

* 15.7.4 继承的构造函数

### 15.8 容器与继承

* 15.8.1 编写 Basket 类

### 15.9 文本查询程序再探

* 15.9.1 面向对象的解决方案

* 15.9.2 Query_base 类和 Query 类

* 15.9.3 派生类

* 15.9.4 eval 函数

### 小节

### 术语表

---

## 第 16 章

## 模板与泛型编程

### 16.1 定义模板

* 16.1.1 函数模板

* 16.1.2 类模板

* 16.1.3 模板参数

* 16.1.4 成员模板

* 16.1.5 控制实例化

* 16.1.6 效率与灵活性

### 16.2 模板实参推断

* 16.2.1 类型转换与模板类型参数

* 16.2.2 函数模板显式实参

* 16.2.3 尾置返回类型与类型转换

* 16.2.4 函数指针和实参推断

* 16.2.5 模板实参推断和引用

* 16.2.6 理解 std::move

* 16.2.7 转发

### 16.3 重载与模板

### 16.4 可变参数模板

* 16.4.1 编写可变参数函数模板

* 16.4.2 包扩展

* 16.4.3 转发参数包

### 16.5 模板特例化

### 小节

### 术语表

---

## 第 17 章

## 标准库特殊设施

### 17.1 tuple 类型

* 17.1.1 定义和初始化 tuple

* 17.1.2 使用 tuple 返回多个值

### 17.2 bitset 类型

* 17.2.1 定义和初始化 bitset

* 17.2.2 bitset 操作

### 17.3 正则表达式

* 17.3.1 使用正则表达式

* 17.3.2 匹配与 Regexp 迭代器类型

* 17.3.3 使用子表达式

* 17.3.4 使用 regex_replace

### 17.4 随机数

* 17.4.1 随机数引擎和分布

* 17.4.2 其它随机数分布

### 17.5 IO 库再探

* 17.5.1 格式化输入与输出

* 17.5.2 未格式化的输入输出操作

* 17.5.3 流随机访问

### 小节

### 术语表

---

## 第 18 章

## 用于大型程序的工具

### 18.1 异常处理

* 18.1.1 抛出异常

* 18.1.2 捕获异常

* 18.1.3 函数 try 语句块与构造函数

* 18.1.4 noexpect 异常说明

* 18.1.5 异常类层次

### 18.2 命名空间

* 18.2.1 命名空间定义

* 18.2.2 使用命名空间成员

* 18.2.3 类、命名空间与作用域

* 18.2.4 重载与命名空间

### 18.3 多重继承与虚继承

* 18.3.1 多重继承

* 18.3.2 类型转换与多个基类

* 18.3.3 多重继承下的类作用域

* 18.3.4 虚继承

* 18.3.5 构造函数与虚函数

### 小节

### 术语表

---

## 第 19 章

## 特殊工具与技术

### 19.1 控制内存分配

* 19.1.1 重载 new 和 delete

* 19.1.2 定位 new 表达式

### 19.2 运行时类型识别

* 19.2.1 dynamic_cast 运算符

* 19.2.2 typeid 运算符

* 19.2.3 使用 RTTI

* 19.2.4 type_info 类

### 19.3 枚举类型

### 19.4 类成员指针

* 19.4.1 数据成员指针

* 19.4.2 成员函数指针

* 19.4.3 将成员函数用作可调用对象

### 19.5 嵌套类

### 19.6 union：一种节省空间的类

### 19.7 局部类

### 19.8 固有的不可移植的特性

* 19.8.1 位域

* 19.8.2 volatile 限定符

* 19.8.3 链接指示：extern "C"

### 小节

### 术语表
