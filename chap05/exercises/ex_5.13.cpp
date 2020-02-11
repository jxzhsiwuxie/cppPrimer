//练习 5.13：下面每一个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。

// (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
//     char ch = next_text();
//     switch(ch) {
//         case 'a': aCnt++;
//         case 'e': eCnt++;
//         default: iouCnt++;
//     }

// (b) unsigned index = some_value();
//     switch (index) {
//         case 1:
//             int ix = get_value();
//             ivec[ix] = index;
//             break;
//         default:
//             ix = ivec.size() - 1;
//             ivec[ix] = index;
//     }

// (c) unsigned evenCnt = 0, oddCnt = 0;
//     int digit = get_num() % 10;
//     switch (digit) {
//         case 1, 3, 5, 7, 9:
//             oddCnt++;
//             break;
//         case 2, 4, 6, 8, 10:
//             evenCnt++;
//             break;
//     }

// (d) unsigned ival = 512, jval = 1024, kval = 4096;
//     unsigned bufsize;
//     unsigned swt = get_bufCnt();
//     switch (swt) {
//         case ival:
//             bufsize = ival * sizeof(int);
//             break;
//         case jval:
//             bufsize = jval * sizeof(int);
//             break;
//         case kval:
//             bufsize = kval * sizeof(int);
//             break;
//     }


/*
* (a) 没有正确的使用 break 标签，应修改为：
*/
// (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
//     char ch = next_text();
//     switch(ch) {
//         case 'a': aCnt++;
//             break;
//         case 'e': eCnt++;
//             break;
//         default: iouCnt++;
//             break;
//     }

/*
* (b) 变量作用域错误，应修改为：
*/
// (b) unsigned index = some_value();
//     int ix;
//     switch (index) {
//         case 1:
//             ix = get_value();
//             ivec[ix] = index;
//             break;
//         default:
//             ix = ivec.size() - 1;
//             ivec[ix] = index;
//     }

/*
* (c) case 后面不是一个表达式，应修改为：
*/
// (c) unsigned evenCnt = 0, oddCnt = 0;
//     int digit = get_num() % 10;
//     switch (digit) {
//         case 19:
//         case 3:
//         case 5:
//         case 7:
//         case 9:
//             oddCnt++;
//             break;
//         case 2:
//         case 4:
//         case 6:
//         case 8:
//         case 10:
//             evenCnt++;
//             break;
//     }

/*
* (d) case 后面表达式不是常量表达式，应修改为：
*/
// (d) const unsigned ival = 512, jval = 1024, kval = 4096;
//     unsigned bufsize;
//     unsigned swt = get_bufCnt();
//     switch (swt) {
//         case ival:
//             bufsize = ival * sizeof(int);
//             break;
//         case jval:
//             bufsize = jval * sizeof(int);
//             break;
//         case kval:
//             bufsize = kval * sizeof(int);
//             break;
//     }
