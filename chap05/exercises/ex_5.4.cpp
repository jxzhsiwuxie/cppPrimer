//练习 5.4：说明下列例子的含义，如果存在问题，试着修改它。
// (a) while (string::iterator iter != s.end()) {/*...*/}
// (b) while (bool status = find(word)) {/*...*/}
//          if (!status) {/*...*/}

/*
* (a) 遍历字符串 s 直到结尾。
* (b) 程序有问题，if 语句中无法访问 while 语句中定义的变量 status，应修改为：
*/
// (b) while (bool status = find(word)) {
//         /*...*/
//         if (!status) {/*...*/}
//     }
