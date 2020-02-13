//练习 5.18：说明下列循环的含义并改正其中的错误。
// (a) do
//         int v1, v2;
//         cout << "Please enter two numbers to sum: ";
//         if(cin >> v1 >> v2)
//             cout << "Sum is: " << v1 + v2 << endl;
//     while (cin);
// (b) do {
//         //...
//     } while (int ival = get_response());
// (c) do {
//         int ival = get_response();
//     } while (ival);

/*
* (a) 连续读取两个整数并计算其和。do 部分有多条语句，应该放在一个语句块中
*/
// do {
//     int v1, v2;
//     cout << "Please enter two numbers to sum: ";
//     if(cin >> v1 >> v2)
//         cout << "Sum is: " << v1 + v2 << endl;
// } while (cin);

/*
* (b) 连续读取 get_response 函数的值，直到值为 0 为止。 不允许在 do while 语句的 while 部分定义变量。
*/
// int ival = 0;
// do {
//     //...
// } while (ival = get_response());

/*
* (c) 连续读取 get_response 函数的值，直到值为 0 为止。do while 循环的条件判断部分用到的变量必须定义在循环体之外。
*/
// int ival = 0;
// (c) do {
//         ival = get_response();
//     } while (ival);
