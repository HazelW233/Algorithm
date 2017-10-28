#include"BSTree.h"
#include"BSTree.cpp"
#include<iostream>

int main(){
    BSTree tree;
    tree.insert(33);
    tree.travel();
    tree.insert(983);
    tree.insert(-82);
    tree.insert(43);
    tree.insert(4);
    tree.insert(1);
    tree.insert(53);
    tree.insert(42);
    tree.insert(-9);
    tree.travel();
    tree.remove(-82);
    tree.travel();
    tree.remove(983);
    tree.remove(1);
    tree.travel();

    return 0;
}
