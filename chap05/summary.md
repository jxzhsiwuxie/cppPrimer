## 小节

&emsp; &emsp; C++ 语言仅提供了有限的语句类型，它们中的大多数会影响程序的控制流程：  
 * while、for 和 do while 语句，执行迭代操作。

 * if 和 switch 语句提供条件分支结构。

 * continue 语句，终止循环的当前一次迭代。

 * break 语句， 退出循环或者 switch 语句。

 * goto 语句，将控制权转移到一条带标签的语句。

 * try 和 catch，将一段可能抛出异常的语句序列括在花括号里构成 try 语句块。catch 子句负责处理代码抛出的异常。

 * throw 表达式语句，存在于代码块中，将控制权转移到相关的 catch 子句。

 * return 语句，终止函数的执行。我们将在第 6 章介绍 return 语句。

 &emsp; &emsp; 除此之外还有表达式语句和声明语句。表达式语句用于求解表达式，关于变量的定义和声明在第 2 章已经介绍过了。

 ## 术语表

 **块（block）** 包围在花括号内的由 0 条或多条语句组成的序列。块也是一条语句，所以只要能使用语句的地方，就可以使用块。

 **break 语句（break statement）** 终止离它最近的循环或 switch 语句。控制权转移到循环或 switch 语句之后的第一条语句。

 **case 标签（case label）** 在 switch 语句中紧跟在 case 关键字之后的常量表达式（参见 2.4.4 节）。在同一个 switch 语句中任意两个 case 标签的值不能相同。

 **cartch 子句（catch clause）** 由三部分组成：catch 关键字、括号里的异常声明以及一个语句块。catch 子句负责处理在异常声明中定义的异常。

 **符合语句（compound statement）** 和块是同义词。

 **continue 语句（continue statement）** 终止离它最近的循环的当前迭代。控制权转移到 while 或 do while 的条件部分、或者范围 for 循环的下一次迭代、或者传统 for 循环的头部表达式。

 **悬垂 else（dangling else）** 是一个俗语，指的是如何处理嵌套 if 语句中 if 语句多于 else 语句的情况。C++ 语言规定，else 应该与前一个未匹配的 if 匹配在一起。使用花括号可以把位于内层的 if 语句隐藏起来，这样程序员就能更好地控制 else 该与哪个 if 匹配。

 **default 标签（default label）** 是一种特殊的 case 标签，当 switch 表达式的值与所有 case 标签都无法匹配的时候，程序执行 default 标签下的内容。

 **do while 语句（do while statement）** 与 while 语句类似，区别是 do while 语句限制性循环体，再判断条件。循环体代码至少会执行一次。

 **异常类（exception class）** 是标准库定义的一组类，用于表示程序发生的错误。表 5.1 列出了不同用途的异常类。

 **异常声明（excetion declaration）** 位于 catch 子句中的声明，指定了该 catch 子句能处理的异常类型。

 **异常处理代码（exception handler）** 程序某处引发异常后，用于处理该异常的另一处代码。和 catch 子句是同义词。

 **异常安全（exception safe）** 是一个述语，表示的含义是当抛出异常后，程序能执行正确的行为。

 **表达式语句（exception statement）** 即一条表达式后面跟上一个分号，令表达式执行求值过程。

 **控制流（flow of control）** 程序执行的路径。

 **for 语句（for statement）** 提供迭代执行的迭代语句。常常用于遍历一个容器或者重复计算若干次。

 **got 语句（goto statement）** 令控制权无条件转移到同一函数中一个指定的带标签语句。goto 语句容易造成程序的控制流混乱，应禁止使用。

 **if else 语句（if else statement）** 判断条件，根据结果分别执行 if 分支或 else 分支的语句。

 **if 语句（if statement）** 判断条件，根据其结果有选择的执行语句。如果条件为真，执行 if 分支的代码；如果条件为假，控制权转到 if 结构之后的第一条语句。

 **带标签语句（labeled statement）** 前面带有标签的语句。所谓标签是指一个标识符以及紧跟着的一个冒号。对于同一个标识符来说，用作标签的同时还能用于其它目的，互不干扰。

 **空语句（null statement）** 只含有一个分号的语句。

 **引发（raise）** 含义类似于 throw。在 C++ 语言中既可以说抛出异常，也可以说引发异常。

 **范围 for 循环（range for statement）** 在一个序列中进行迭代的语句。

 **switch 语句（switch statement）** 一种条件语句，首先求 switch 关键字后面表达式的值，如果某个 case 标签的值与表达式的值相等，程序直接跨过之前的代码从这个 case 标签开始执行。当所有的 case 标签都无法匹配时，如果有 default 标签，从 default 标签继续执行；如果没有，结束 switch 语句。

 **terminate** 是一个标准库函数，当异常没有被捕捉到时调用。terminate 终止当前程序的执行。

 **try 语句块（try block）** 跟在 try 关键字后面的块，以及一个或多个 catch 子句。如果 try 语句块中的代码引发异常并且其中一个 catch 子句匹配该异常类型，则异常被该 catch 子句处理。否则，异常将由外围 try 语句块处理，或者程序终止。

 **while 语句（while statement）** 只要指定的条件为真，就一直迭代执行目标语句。随着条件真值的不同，循环可能执行多次，也可能一次也不执行。

