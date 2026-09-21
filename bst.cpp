//
//  bst.cpp
//  BST
//
//  Created by Nadjah Duke on 9/6/26.
//

#include <iostream>
#include "bst.h"

bool bst::isEmpty()
{
    return (root == nullptr);
}

Node* bst:: rInsert(Node *theNode, int data)

{
    if(theNode == nullptr)
    {
        theNode = new Node(data);
        return theNode;
        
    }
    if(data < theNode->iData)
    {
    
        theNode->leftChild = rInsert(theNode->leftChild, data);
    }
    else if(data > theNode->iData)
    {
        theNode->rightChild = rInsert(theNode->rightChild,data);
    }
    
    return theNode;
}
void bst:: insert(int data)
{
    root = rInsert(root, data);
}

Node* bst:: rInOrderTraversal(Node* theNode)
{
    if(theNode == nullptr)
    {
        return theNode;
    }
    
    theNode-> leftChild = rInOrderTraversal(theNode->leftChild);
    std::cout<< theNode->iData << "\n";
    theNode -> rightChild = rInOrderTraversal(theNode->rightChild);
    
    return theNode;
}
void bst:: inOrderTraversal()
{
    if(isEmpty())
    {
        throw std:: runtime_error("the tree is empty \n");
    }
    rInOrderTraversal(root);
}

void bst::preOrderTraversal()
{
    if(isEmpty())
    {
        throw std::runtime_error("the tree is empty \n");
    }
    rPreOrderTraversal(root);
}
Node* bst::rPreOrderTraversal(Node* theNode)
{
    if(theNode == nullptr)
    {
        return theNode;
    }
    
    std::cout << theNode->iData << "\n";
    rPreOrderTraversal(theNode->leftChild);
    rPreOrderTraversal(theNode->rightChild);
    
    return theNode;
}

void bst::postOrderTraversal()
{
    if(isEmpty())
    {
        throw std::runtime_error("the tree is empty \n");
    }
    rPostOrderTraversal(root);
}
Node* bst::rPostOrderTraversal(Node* theNode)
{
    if(theNode == nullptr)
    {
        return theNode;
    }
    
    rPostOrderTraversal(theNode->leftChild);
    rPostOrderTraversal(theNode->rightChild);
    std::cout<< theNode->iData << "\n";
    
    return theNode;
}

bool bst::search(int data)
{
    if(isEmpty())
    {
        throw std::runtime_error("The tree is empty \n");
    }
    return rSearch(root, data);
}

Node* bst:: rSearch(Node* theNode, int data)
{
    if(theNode== nullptr)
    {
        return theNode;
    }
    
    if(data == theNode->iData)
    {
        return theNode;
    }
    else if(data < theNode->iData)
    {
        return rSearch(theNode->leftChild, data);
    }
    else
    {
        return rSearch(theNode->rightChild, data);
    }
    
    return theNode;
}
Node* bst:: inOrderSuccessor(Node *theNode)
{
    if(theNode->leftChild == nullptr)
    {
        return theNode;
    }
    
    return inOrderSuccessor(theNode->leftChild);
}
Node* bst:: rRemove(Node* theNode, int data, bool& isDeleted)
{
    if(theNode == nullptr)
    {
        return theNode;
    }
    
    if(data == theNode->iData)
    {
        isDeleted = true;
        
        if(theNode->leftChild == nullptr && theNode->rightChild == nullptr)
        {
            delete theNode;
            return nullptr;
        }
        if(theNode->leftChild != nullptr && theNode->rightChild == nullptr)
        {
            Node* temp = theNode->leftChild;
            delete theNode;
            return temp;
        }
        if(theNode->rightChild != nullptr && theNode->leftChild == nullptr)
        {
            Node* temp = theNode->rightChild;
            delete theNode;
            return temp;
        }
        if(theNode->leftChild != nullptr && theNode->rightChild != nullptr)
        {
            Node* successor = inOrderSuccessor(theNode->rightChild);
            
            theNode->iData = successor->iData;
            
            theNode->rightChild = rRemove(theNode->rightChild, successor->iData, isDeleted);
            
        }
    }
    else if(data < theNode->iData)
    {
        theNode->leftChild = rRemove(theNode->leftChild, data, isDeleted);
    }
    else
    {
        theNode->rightChild = rRemove(theNode->rightChild, data, isDeleted);
    }
   
    return theNode;
}
bool bst::remove(int data)
{
    if(isEmpty())
    {
        throw std::runtime_error("The tree is empty \n");
    }
    bool isDeleted = false;
    root = rRemove(root, data, isDeleted);
    
    return isDeleted;
}

Node* bst::rFindMin(Node* theNode)
{
    if(theNode->leftChild == nullptr)
    {
        return theNode;
    }
    
    return rFindMin(theNode->leftChild);
}
int bst::findMin()
{
    if(isEmpty())
    {
        throw std:: runtime_error("The tree is empty \n");
    }
    
    Node * minNode = rFindMin(root);
    
    return minNode->iData;
}

Node* bst::rFindMax(Node* theNode)
{
   if(theNode->rightChild == nullptr)
   {
       return theNode;
   }
    
    return rFindMax(theNode->rightChild);
}

int bst:: findMax()
{
    if(isEmpty())
    {
        throw std:: runtime_error("The tree is empty \n");
    }
    
    Node* maxNode = rFindMax(root);
    
    return maxNode->iData;
}
