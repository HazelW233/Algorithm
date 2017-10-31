
#define ElementType int

/*
 树的parent存储表示
 以一组连续空间存储树的节点，同时在每一个节点中设置一个指示其parent在链表中位置对元素
 */
#define MAX_TREE_SIZE 100
struct PTNode{
    ElementType data;
    int parent;  //parent在链表中的位置
};
struct PTree{
    PTNode nodes[MAX_TREE_SIZE];
    int root;  //根的位置
    int num;  //节点数
};


/*
 child表示法
 把每个节点对孩子排列起来，看成是一个线性表，并以单链表作为存储结构，则n节点有n个孩子链表
 （叶子节点孩子链表为空表），n个头指针又组成一个线性表
 */
struct CTNode{
    int child;
    CTNode* next;
};
struct CTBox{
    ElementType data;
    CTNode* firstChild;  //孩子链表头指针
};
sturct CTree{
    CTBox nodes[MAX_TREE_NODE];
    int root;
    int num;
};


/*
 树的孩子兄弟表示法
 又称二叉树表示法，或二叉链表表示法。即以二叉链表作为树对存储结构。
 链表中节点对两个链域分别指向该节点对第一个孩子节点和下一个兄弟节点。
 */
struct CSNode{
    ElementType data;
    CSNode* firstChild;  //第一个孩子节点
    CSNode* nextsibling;  //下一个兄弟节点
};

