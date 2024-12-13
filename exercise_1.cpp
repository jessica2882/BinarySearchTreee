#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"
int main() {
    BinarySearchTree bst(7);
    
    bst.insert(7);
    bst.insert(5);
    bst.insert(9);
    bst.insert(1);
    bst.insert(6);
    bst.insert(8);
    bst.insert(11);
  //INSERT VALUE INORDER TRAVERSAL
    std::cout << "Insert value: ";
    bst.inOrder(); 

    // Search for a value
    std::cout << "Search 6: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;

    // Delete a node and verify the structure
    bst.deleteNode(9);
    std::cout << "Inorder Traversal after deleting : ";
    bst.inOrder(); 

    return 0;
}

