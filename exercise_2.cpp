#include <iostream>
#include"BinarySearchTree.h"
#include "Node.h"
#include<queue>

int main() {
    BinarySearchTree bst(7); 
//traversal bst 

    Node* root = bst.getroot();
    root->left = new Node (5);
    root->right = new Node(9);
    root->left->left = new Node(1);
    root->left->right = new Node (6);
    root->right->left = new Node (8);
    root->right->right = new Node(11);

    std::cout <<"Level Order Traversal : " <<bst.levelOrderTraverse()<<std::endl;

    return 0;
}