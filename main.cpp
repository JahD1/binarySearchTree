//
//  main.cpp
//  BST
//
//  Created by Nadjah Duke on 9/5/26.
//

#include <iostream>
#include "bst.h"

int main(int argc, const char * argv[]) {

    bst bst1;
    
    bst1.insert(30);
    bst1.insert(10);
    bst1.insert(40);
    bst1.insert(22);
    
    bst1.postOrderTraversal();
    
   // bool found = bst1.search(20);
    
    //std::cout << found << "\n";
    
    //bool removed = bst1.remove(22);
    
    //std::cout << removed << "\n";
    
    //bst1.print();
    
    int minVal = bst1.findMin();
    
    std::cout<< "the min value: " << minVal << "\n";
    
    int maxVal = bst1.findMax();
    
    std::cout<< "the maxvalue: " << maxVal << "\n";
    
    return 0;
}
