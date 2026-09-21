//
//  bst.h
//  BST
//
//  Created by Nadjah Duke on 9/6/26.
//

#ifndef BST_H
#define BST_H
#include "Node.h"

class bst
{
    
private:
    Node* root;
    
public:
    bst()
    {
        root = nullptr;
    }
    
    bool isEmpty();
    
    void insert(int data);
    static Node* rInsert(Node* theNode, int iData);
    
    void inOrderTraversal();
    static Node* rInOrderTraversal(Node* theNode);
    
    void preOrderTraversal();
    static Node* rPreOrderTraversal(Node* theNode);
    
    void postOrderTraversal();
    static Node* rPostOrderTraversal(Node* theNode);
    
    
    bool search(int data);
    static Node* rSearch(Node* theNode, int data);
    
    bool remove(int data);
    static Node* inOrderSuccessor(Node* theNode);
    static Node* rRemove(Node* theNode, int data, bool& isDeleted);
    
    int findMin();
    Node* rFindMin(Node*);
    
    int findMax();
    Node* rFindMax(Node* theNode);
};
#endif // !BST_H
