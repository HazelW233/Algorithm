#define ElementType int

struct BSTNode{
    ElementType element;
    BSTNode* lchild;
    BSTNode* rchild;
};

class BSTree{
public:
    BSTree();
    ~BSTree();
    //将树清空，变为一颗空树
    void makeEmpty(BSTree T);
    //在树T中查找元素为e对节点
    BSTNode find(ElementType e, BSTree T);
    //找到树中元素最大的节点
    BSTNode findMin(BSTree T);
    //找到树中元素最小的节点
    BSTNode finMax(BSTree T);
    //将元素为e节点插入到树T
    void insert(elementType e, BSTree T);
    //将元素为e对节点从树T中删除
    void remove(elementType e, BSTree T);
private:
    BSTNode* root;
};
