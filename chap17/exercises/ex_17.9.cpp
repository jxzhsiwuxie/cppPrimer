//练习 17.9：解释下面每个 bitset 对象所包含的位模式。
// (a) bitset<64> bitvec(32);   //100000
// (b) bitset<32> bv(1010101);
// (c) string bstr; cin >> bstr; bitset<8>bv (bstr);

/*
* (a) 64 位，第 5 位为 1，其它位为 0
* (b) 43 位，第 0、2、4、6 位为 1，其它位为 0
* (c) 8 位，根据 bstr 的不同有不同的模式。
*/
