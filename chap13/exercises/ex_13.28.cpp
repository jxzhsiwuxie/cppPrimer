//练习 13.28：给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。
// (a) class TreeNode {                                 (b) class BinStrTree {
//     private:                                             private:
//         std::string value;                                   TreeNode *root;
//         int         count;                               };
//         TreeNode    *left;
//         TreeNode    *right;
//     };

#include <string>

class TreeNode {
   private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

   public:
    //默认构造函数
    TreeNode() : value(std::string()), count(0), left(nullptr), right(nullptr) {}
    ~TreeNode() = default;
};

class BinStrTree {
   private:
    TreeNode *root;

   public:
    //默认你构造函数
    BinStrTree() : root(nullptr) {}
    ~BinStrTree() = default;
};
