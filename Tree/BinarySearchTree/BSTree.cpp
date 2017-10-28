#include"BSTree.h"
/*
 此文件定义了BSTree的实现
 */

BSTree::BSTree(){
    root = NULL;
}

//递归删除树中所有节点
void BSTree::makeEmpty(BSTNode* T){
    if(T!=NULL){
        if(T->lchild!=NULL){
            makeEmpty(T->lchild);
        }
        if(T->rchild!=NULL){
            makeEmpty(T->rchild);
        }
        delete T;
    }
}

BSTree::~BSTree(){
    makeEmpty(root);
}

/*
 寻找element为e的节点，找到返回该节点，
 没找到返回NULL
 */
BSTNode* BSTree::find(ElementType e){
    BSTNode* node = root;
    while(node!=NULL){
        if(e<node->element){
            node=node->lchild;
        }else if(e>node->element){
            node=node->rchild;
        }else{
            //e==node->element, 找到该节点
            break;
        }
    }
    return node;
}

/*
 找到树中element最小对节点
 树为空返回NULL
 */
BSTNode* BSTree::findMin(BSTNode* T){
    if(T==NULL){
        return T;
    }
    while(T->lchild!=NULL){
        T = T->lchild;
    }
    return T;
}

/*
 找到树中element最小对节点，
 树为空返回NULL
 */
BSTNode* BSTree::findMin(){
    BSTNode* node = root;
    return findMin(node);
}

/*
 找到树中最大对节点，
 树为空返回NULL
 */
BSTNode* BSTree::findMax(){
    BSTNode* node = root;
    if(node==NULL){
        return node;
    }
    while(node->rchild!=NULL){
        node = node->rchild;
    }
    return node;
}

/*
 将element为e对节点插入到树中
 */
void BSTree::insert(ElementType e){
    //树为空
    if(root==NULL){
        root=new BSTNode;
        root->element=e;
        root->lchild=root->rchild=0;
        return;
    }
    //树不为空
    BSTNode* node = root;
    while(true){
        if(e<node->element){
            if(node->lchild!=NULL){
                node=node->lchild;
            }else{
                //插入节点
                BSTNode* new_node = new BSTNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild=NULL;
                node->lchild = new_node;
                return;
            }
        }else if(e>node->element){
            if(node->rchild!=NULL){
                node=node->rchild;
            }else{
                //插入节点
                BSTNode* new_node = new BSTNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild = NULL;
                node->rchild = new_node;
                return;
            }
        }else{
            //树中已存在element为e的节点，直接返回
            return;
        }
    }
}

//将element为e的节点从树中删除
void BSTree::remove(ElementType e){
    BSTNode* node = root;
    BSTNode* parent = NULL;
    while(true){
        if(e<node->element){
            if(node->lchild!=NULL){
                parent = node;
                node = node->lchild;
            }else{
                return;
            }
        }else if(e>node->element){
            if(node->rchild!=NULL){
                parent = node;
                node = node->rchild;
            }else{
                return;
            }
        }else{
            //node->element == e
            break;
        }
    }

    //经过此过程后，node最多有一个子孩子
    if(node->lchild!=NULL && node->rchild!=NULL){
        BSTNode* temp_node = findMin(node->rchild);
        ElementType temp = temp_node->element;
        node->element = temp;
        parent = node;
        node = node->rchild;
        while(node->element!=temp){
            parent = node;
            node = node->lchild;
        }
    }

    if(node->lchild!=NULL){
        if(parent->lchild==node){
            parent->lchild = node->lchild;
        }else{
            parent->rchild = node->lchild;
        }
    }else if(node->rchild!=NULL){
        if(parent->lchild==node){
            parent->lchild = node->rchild;
        }else{
            parent->rchild = node->rchild;
        }
    }else{
        if(parent->lchild==node){
            parent->lchild=NULL;
        }else{
            parent->rchild=NULL;
        }
    }
    delete node;
}

void BSTree::travel(BSTNode* T){
    if(T!=NULL){
        if(T->lchild!=NULL){
            travel(T->lchild);
        }
        std::cout<<T->element<<" ";
        if(T->rchild!=NULL){
            travel(T->rchild);
        }
    }
}

//中序遍历树
void BSTree::travel(){
    BSTNode* node = root;
    travel(node);
    std::cout<<std::endl;
}

