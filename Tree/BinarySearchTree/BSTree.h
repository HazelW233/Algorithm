/*
此文件定义了二叉查找树节点BSTNode，
二叉查找树BSTree类。
BSTree类中有public方法如下：
~BSTree();
void makeEmpty();
BSTNode* find(ElementType e);
BSTNode* findMin();
BSTNode* findMax();
void insert(ElementType e);
void remove(ElementType e);
void travel();

ElementType 暂定为int类型
 */

#ifndef BINARY_SEARCH_TREE

#define BINARY_SEARCH_TREE

#include<iostream>
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
    //在树T中查找元素为e对节点
    BSTNode* find(ElementType e);
    //找到树中元素最大的节点
    BSTNode* findMin();
    //找到树中元素最小的节点
    BSTNode* findMax();
    //将元素为e节点插入到树T
    void insert(ElementType e);
    //将元素为e对节点从树T中删除
    void remove(ElementType e);
    //中序遍历树，按element由小到大输出
    void travel();
private:
    BSTNode* root;
    void travel(BSTNode* T);
    void makeEmpty(BSTNode* T);
    BSTNode* findMin(BSTNode* T);
};

#endif
