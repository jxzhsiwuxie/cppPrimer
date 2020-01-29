//练习 2.12：指出下面的名字中哪些是非法的？
/*
* (a) int double = 3.14;        (b) int _;
* (c) int catch-22;             (d) int 1_or_2 = 1;
* (e) double Double = 3.14;
*/

/*
* (a) 变量名 double 是 c++ 关键字，用来作为变量名是非法的。
* (c) 变量名只能包含字母数字下划线，catch-22 作为变量名是非法的。
* (d) 变量名只能以字母和下划线开头，1_or_2 以数字开头，是非法的。
* 
*/

int main()
{
    // int double = 3.14;
    // int _;
    // int catch-22;
    // int 1_or_2 = 1;
    // double Double = 3.14;

    return 0;
}