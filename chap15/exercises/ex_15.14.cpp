//练习 15.14：给定上一题中的类以及下面的这些对象，说明在运行时调用哪个函数：
// base bobj;       base *bp1 = &bobj;      base &br1 = bobj;
// derived dobj;    base *bp2 = &dobj;      base &br2 = dobj;
//(a) bobj.print();     (b) dobj.print();       (c) bp1->name();
//(d) bp2->name();      (e) br1.print();        (f) br2.print();

/*
* (a) 调用 base 的 print，(b) 调用 derived 的 print，(c) 调用 base 的 name，
* (d) 调用 base 的 name，(e) 调用 base 的 print，(f) 调用 derived 的 print。
*/
