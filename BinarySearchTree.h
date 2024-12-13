#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

    //exercise 1

//insert function
void insert(int value) {
    root = insertRec(root, value);
}

Node* insertRec(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value); 
    }
    if (value < node->data) {
        node->left = insertRec(node->left, value); 
    } else if (value > node->data) {
        node->right = insertRec(node->right, value); 
    }
    return node; 
}

//binary tree inorder

void inOrder() {
    inOrderRec(root);
    std::cout << std::endl;
}
void inOrderRec(Node* node) {
    if (node == nullptr) return;

    inOrderRec(node->left);
    std::cout << node->data << " ";
    inOrderRec(node->right);
}
//search value function

bool search(int key) {
    return searchRec(root, key);
}

bool searchRec(Node* node, int key) {
    if (node == nullptr) return false; 
    if (node->data == key) return true; 

    if (key < node->data) {
        return searchRec(node->left, key); 
    } else {
        return searchRec(node->right, key); 
    }
}

//deleteNode function
void deleteNode(int value) {
    root = deleteRec(root, value);
}

Node* deleteRec(Node* node, int value) {
    if (node == nullptr) return node; 

    if (value < node->data) {
        node->left = deleteRec(node->left, value); 
    } else if (value > node->data) {
        node->right = deleteRec(node->right, value); 
    } else {
        // Node with one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right); 
        node->data = temp->data;
        node->right = deleteRec(node->right, temp->data);
    }
    return node;
}

Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


   // exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        //Important note: you are allowed to use the std::queue class to implement this function
        std::queue<Node*> Q;
        Q.push(root);

        while (!Q.empty ()){
            Node* current = Q.front();
            result +=std::to_string(current->data ) + " ";
            if (current->left != NULL) Q.push(current->left);
            if (current->right !=NULL) Q.push(current->right);
            Q.pop();
        }
        return result;
    }
    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

};

#endif // BINARYTREE_H


