//练习 5.7：改正下列代码中的错误。
// (a) if (ival1 != ival2)
//          ival1 = ival2
//     else ival1 = ival2 = 0;
// (b) if (ival < minval)
//          minval = ival;
//          occurs = 1;
// (c) if (int ival = get_value())
//          cout << "ival = " << ival << endl;
//     if (!ival)
//          cout << "ival = 0\n";
// (d) if (ival = 0)
//          ival = get_value();

// 改正之后：
// (a) if (ival1 != ival2)
//          ival1 = ival2;  //缺少分号表示一个语句。
//     else ival1 = ival2 = 0;

// (b) if (ival < minval) {
//          minval = ival;
//          occurs = 1;
//     }

// (c) if (int ival = get_value()) {
//          cout << "ival = " << ival << endl;
//     if (!ival)
//          cout << "ival = 0\n";
//     }

// (d) if (ival == 0)
//          ival = get_value();
