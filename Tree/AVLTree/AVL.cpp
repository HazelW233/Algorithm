/*
 此文件定义了AVLTree对实现
 */

#include"AVL.h"

AVLTree::AVLTree(){
    root = NULL;
}

//递归删除树中所有节点
void AVLTree::makeEmpty(AVLNode* T){
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

AVLTree::~AVLTree(){
    makeEmpty(root);
}

void AVLTree::travel(AVLNode* T){
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
void AVLTree::travel(){
    AVLNode* node = root;
    travel(node);
    std::cout<<std::endl;
}

AVLNode* AVLTree::singleRotateLeft(AVLNode* T){
    AVLNode* k2 = T;
    AVLNode* k1 = T->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;
    k2->height = AVLHeight(k2->lchild) > AVLHeight(k2->rchild) ? (AVLHeight(k2->lchild)+1) : (AVLHeight(k2->rchild)+1);
    k1->height = AVLHeight(k1->lchild) > AVLHeight(k1->rchild) ? (AVLHeight(k1->lchild)+1) : (AVLHeight(k1->rchild)+1);
    return k1;
}

AVLNode* AVLTree::singleRotateRight(AVLNode* T){
    AVLNode* k2 = T;
    AVLNode* k1 = T->rchild;
    k2->rchild = k1->lchild;
    k1->lchild = k2;
    k2->height = AVLHeight(k2->lchild) > AVLHeight(k2->rchild) ? (AVLHeight(k2->lchild)+1) : (AVLHeight(k2->rchild)+1);
    k1->height = AVLHeight(k1->lchild) > AVLHeight(k1->rchild) ? (AVLHeight(k1->lchild)+1) : (AVLHeight(k1->rchild)+1);
    return k1;
}

AVLNode* AVLTree::doubleRotateLeft(AVLNode* T){
    T->lchild = singleRotateRight(T->lchild);
    return singleRotateLeft(T);
}

AVLNode* AVLTree::doubleRotateRight(AVLNode* T){
    T->rchild = singleRotateLeft(T->rchild);
    return singleRotateRight(T);
}

AVLNode* AVLTree::setHeight(AVLNode* T){
    if(T==NULL){
        return NULL;
    }

    T->lchild = setHeight(T->lchild);
    T->rchild = setHeight(T->rchild);
    int lHeight = AVLHeight(T->lchild);
    int rHeight = AVLHeight(T->rchild);
    if(lHeight-rHeight==2){
        if(AVLHeight(T->lchild->lchild)>AVLHeight(T->lchild->rchild)){
            T = singleRotateLeft(T);
        }else{
            T = doubleRotateLeft(T);
        }
    }else if(rHeight-lHeight==2){
        if(AVLHeight(T->rchild->lchild)<AVLHeight(T->rchild->rchild)){
            T = singleRotateRight(T);
        }else{
            T = doubleRotateRight(T);
        }
    }
    T->height = AVLHeight(T->lchild) > AVLHeight(T->rchild) ? (AVLHeight(T->lchild)+1) : (AVLHeight(T->rchild)+1);
    
    return T;
}

//更新树中所有节点对高度
void AVLTree::setHeight(){
    AVLNode* node = root;
    root = setHeight(node);
}

/*
 将element为e对节点插入到树中
 */
void AVLTree::insert(ElementType e){
    //树为空
    if(root==NULL){
        root=new AVLNode;
        root->element=e;
        root->lchild=root->rchild=0;
        setHeight();
        return;
    }
    //树不为空
    AVLNode* node = root;
    while(true){
        if(e<node->element){
            if(node->lchild!=NULL){
                node=node->lchild;
            }else{
                //插入节点
                AVLNode* new_node = new AVLNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild=NULL;
                node->lchild = new_node;
                setHeight();
                return;
            }
        }else if(e>node->element){
            if(node->rchild!=NULL){
                node=node->rchild;
            }else{
                //插入节点
                AVLNode* new_node = new AVLNode;
                new_node->element = e;
                new_node->lchild = new_node->rchild = NULL;
                node->rchild = new_node;
                setHeight();
                return;
            }
        }else{
            //树中已存在element为e的节点，直接返回
            return;
        }
    }
}

AVLNode* AVLTree::findMin(AVLNode* T){
    if(T==NULL){
        return T;
    }
    while(T->lchild!=NULL){
        T=T->lchild;
    }
    return T;
}

//将element为e的节点从树中删除
void AVLTree::remove(ElementType e){
    if(root->element==e){
        if(root->lchild==NULL || root->rchild==NULL){
            AVLNode* temp_node = root;
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
    AVLNode* node = root;
    AVLNode* parent = NULL;
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
        AVLNode* temp_node = findMin(node->rchild);
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

    setHeight();
}
