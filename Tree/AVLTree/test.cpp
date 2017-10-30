#include<iostream>
#include"AVL.h"
#include"AVL.cpp"

int main(){
    AVLTree a;
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(16);
    a.insert(15);
    a.insert(14);
    a.insert(13);
    a.insert(12);
    a.insert(11);
    a.insert(10);
    a.insert(8);
    a.insert(9);
    a.travel();

    return 0;
}
