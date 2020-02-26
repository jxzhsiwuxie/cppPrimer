//练习 6.43：你会把下面的哪个声明放在头文件中？哪个放在源文件中？为什么？
// (a) inline bool eq(const BigInt&, const BigInt&){...}
// (b) void putValues(int *arr, int size);

/*
* 把 (a) 放在头文件中，从函数名以及 inline 的声明来看，这应该是一个很简短的内联函数，所以将其放在头文件中是合适的。
* 把 (b) 放在源文件中，因为它只是一个普通的函数。
*/
