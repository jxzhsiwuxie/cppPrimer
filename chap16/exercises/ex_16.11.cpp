//练习 16.11：下面 List 的定义是错误的，应该如何修正它？
// template <typename elemType> class ListItem;

// template <typename elemType> class List {
//    public:
//     List<elemType>();
//     List<elemType>(const List<elemType> &);
//     List<elemType> &operator=(const List<elemType> &);
//     ~List();
//     void insert(ListItem *ptr, elemType value);

//    private:
//     ListItem *front, *end;
// };

/*
* 在类外部使用类模板时需要加上模板参数，insert 函数的参数、front 和 end 的定义都是不正确的，应改为：
* void insert(ListItem<elemType> *ptr, elemType value);
* ListItem<elemType> *front, *end;
*/
