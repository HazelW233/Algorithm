/*
 此文件定义了AVL结点
 AVL树高度获得函数 int AVLHeight(AVLNode* T);
 AVLTree类中包含
 */

#ifndef AVL_TREE

#define AVL_TREE

#include<iostream>

#define ElementType int

struct AVLNode{
    ElementType element;
    AVLNode* lchild;
    AVLNode* rchild;
    int height;
};

//返回一个AVL树对高度，空树高度为0
int AVLHeight(AVLNode* T){
    if(T==NULL){
        return 0;
    }else{
        return T->height;
    }
}

class AVLTree{
public:
    AVLTree();
    ~AVLTree();
    void travel();
    void insert(ElementType e);
    void remove(ElementType e);

    AVLNode* root;
private:
    void makeEmpty(AVLNode* T);
    void setHeight();
    AVLNode* setHeight(AVLNode* T);
    void travel(AVLNode* T);
    AVLNode* findMin(AVLNode* T);
    AVLNode* singleRotateLeft(AVLNode* T);
    AVLNode* singleRotateRight(AVLNode* T);
    AVLNode* doubleRotateLeft(AVLNode* T);
    AVLNode* doubleRotateRight(AVLNode* T);
};

#endif

