## 小节 

&emsp; &emsp; C++ 使用标准库类来处理面向流的输入和输出：  

* iostream 处理控制台 IO
* fstream 处理命名文件 IO
* stringstream 完成内存 string 的 IO

&emsp; &emsp; 类 fstream 和 stringstream 都是继承自类 iostream 的。输入类都继承自 istream，输出类都继承自 ostream。因此，可以在 istream 对象上执行的操作，也可以在 ifstream 和 istringstream 对象上执行。继承自 ostream 的输出类也有类似的情况。  

&emsp; &emsp; 每个 IO 对象都维护者一组条件状态，用来指示此对象上是否可以进行 IO 操作。如果遇到了错误——例如在输入流上遇到了文件末尾，则对象的状态变为失效，所有后续输入操作都不能执行，直至错误被纠正。标准库提供了一组函数，用来设置和检测这些状态。  

## 术语表

**条件状态（condition state）** 可以被任何流类使用的一组标志和函数，用来指出给定流是否可用。  

**文件模式（file mode）** 类 fstream 定义的一组标志，在打开文件时指定，用来控制文件如何被使用。  

**文件流（file stream）** 用来读写命名文件的流对象。除了普通的 iostream 操作，文件流还定义了 open 和 close 成员。成员函数 open 接受一个 string 或者 C 风格字符串参数，指定要打开的文件名，它还可以接受一个可选参数，指明文件打开模式。成员函数 close 关闭流所关联的文件，调用 close 后才可以调用 open 打开另一个文件。  

**fstream** 用于同时读写一个相同文件的文件流。默认情况下，fstream 以 in 和 out 模式打开文件。   

**ifstream** 用于从输入文件读取数据的文件流。默认情况下，ifstream 以 in 模式打开文件。   

**继承（inheritance）** 程序设计功能，令一个类型可以从另一个类型继承接口。类 ifstream 和 istringstream 继承自 istream，ofstream 和 ostringstream 继承自 ostream。第 15 章将介绍继承。   

**istringstream** 用来从给定 string 读取数据的字符串流。  

**ofstream** 用来向输入文件写入数据的文件流。默认情况下，ofstream 以 out 模式打开文件。   

**字符串流（string stream）** 用于读写 string 的流对象。除了普通的 iostream 操作之外，字符串流还定义了一个名为 str 的重载成员。调用 str 的无参版本会返回字符串流关联的 string。调用时传递给它一个 string 参数，则会将字符串流与该 string 的一个拷贝相关联。   

**stringstream** 用于读写给定 string 的字符串流。

