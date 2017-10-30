#include"BSTree.h"
#include"BSTree.cpp"
#include<iostream>

int main(){
    BSTree tree;
    tree.insert(1);
    tree.travel();
    tree.insert(2);
    tree.travel();
    tree.remove(1);
    tree.travel();

    return 0;
}
