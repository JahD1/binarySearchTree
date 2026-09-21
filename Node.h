//
//  Node.h
//  BST
//
//  Created by Nadjah Duke on 9/5/26.
//

#ifndef NODE_H
#define NODE_H


class Node
{

public:
    int iData;
    Node* leftChild;
    Node* rightChild;

public:
    Node(int data)
    {
        iData = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};
#endif // !NODE_H
