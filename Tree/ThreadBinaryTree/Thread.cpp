#include"Thread.h"
/*
 此文件定义了BSTree的实现
 */

BSTree::BSTree(){
    root = NULL;
}

//递归删除树中所有节点
void BSTree::makeEmpty(ThreadNode* T){
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
ThreadNode* BSTree::find(ElementType e){
    ThreadNode* node = root;
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
ThreadNode* BSTree::findMin(ThreadNode* T){
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
ThreadNode* BSTree::findMin(){
    ThreadNode* node = root;
    return findMin(node);
}

/*
 找到树中最大对节点，
 树为空返回NULL
 */
ThreadNode* BSTree::findMax(){
    ThreadNode* node = root;
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
        root=new ThreadNode;
        root->element=e;
        root->lchild=root->rchild=0;
        root->ltag = 0;
        root->rtag = 1;
        return;
    }
    //树不为空
    ThreadNode* node = root;
    while(true){
        if(e<node->element){
            if(node->lchild!=NULL){
                node=node->lchild;
            }else{
                //插入节点
                ThreadNode* new_node = new ThreadNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild=NULL;
                new_node->ltag = new_node->rtag = 0;
                node->lchild = new_node;
                return;
            }
        }else if(e>node->element){
            if(node->rchild!=NULL){
                node=node->rchild;
            }else{
                //插入节点
                ThreadNode* new_node = new ThreadNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild = NULL;
                new_node->ltag = new_node->rtag = 0;
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
    if(root->element==e){
        //如果要删除的节点为根节点，且根节点child个数小于等于1
        if(root->lchild==NULL || root->rchild==NULL){
            ThreadNode* temp_node = root;
            if(root->lchild==NULL && root->rchild==NULL){
                root = NULL;
            }else if(root->lchild==NULL){
                root = root->rchild;
            }else{
                root = root->lchild;
            }
            delete temp_node;
            return;
        }
    }
    ThreadNode* node = root;
    ThreadNode* parent = NULL;
    //找到该节点
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
        //如果该节点有lchild和rchild，使该节点的element等于该节点rchild的最小节点的element，然后删除那个最小节点
        ThreadNode* temp_node = findMin(node->rchild);
        ElementType temp = temp_node->element;
        node->element = temp;
        parent = node;
        node = node->rchild;
        while(node->element!=temp){
            parent = node;
            node = node->lchild;
        }
    }
    
    //删除节点node
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

void BSTree::travel(ThreadNode* T){
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
    ThreadNode* node = root;
    travel(node);
    std::cout<<std::endl;
}

