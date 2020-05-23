//练习 15.21：从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组成一个继承体系：
// (a) 图形文件格式（如 gif、tiff、jpeg、bmp）
// (b) 图形基元（如方格、球、圆锥）
// (c) C++ 语言中的类型（如类、函数、成员函数）

/*
* 图形类
*/

#include <iostream>
#include <string>

class Shape {
};

class Circle : public Shape {
};
