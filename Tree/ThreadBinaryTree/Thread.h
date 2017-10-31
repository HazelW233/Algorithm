/*
 此文件定义了如何线索化二叉树
 */

#include<iostream>
#define ElementType int

struct ThreadNode{
    ElementType element;
    ThreadNode* lchild;
    bool ltag;
    ThreadNode* rchild;
    bool rtag;
};

class BSTree{
public:
    BSTree();
    ~BSTree();
    //在树T中查找元素为e对节点
    ThreadNode* find(ElementType e);
    //找到树中元素最大的节点
    ThreadNode* findMin();
    //找到树中元素最小的节点
    ThreadNode* findMax();
    //将元素为e节点插入到树T
    void insert(ElementType e);
    //将元素为e对节点从树T中删除
    void remove(ElementType e);
    //中序遍历树，按element由小到大输出
    void travel();
    void inOrderThreading();
private:
    ThreadNode* thread;
    ThreadNode* thread;
    void travel(ThreadNode* T);
    void makeEmpty(ThreadNode* T);
    ThreadNode* findMin(ThreadNode* T);
    void inOrderThreding(ThreadNode* pre, ThreadNode* node);
};

void BSTNode::inOrderThreading(ThreadNode* pre, ThreadNode* node){
    if(node!=NULL){
        if(node->lchild!=NULL){
            inOrderThreading(pre, node->lchild);
        }
        if(pre->rchild==NULL){
            pre->rchil = node;
            pre->rtag = 1;
        }
        if(node->lchild==NULL){
            node->lchild = pre;
            pre->ltag = 1;
        }
        pre = node;
        if(node->lchild!=NULL){
            inOrderThreading(pre, node->rchild);
        }
    }
}

void BSTNode::inOrderThreading(){
    thread = new ThreadNode;
    thread->ltag = thread->rtag = 1;
    thread->lchild = thread->rchild = NULL;
    ThreadNode* pre = thread
    ThreadNode* node = root;
    inOrderThreading(pre, node);
}

