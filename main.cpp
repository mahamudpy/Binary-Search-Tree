//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Mahmudul Islam on 12/5/19.
//  Copyright © 2019 Mahmudul Islam. All rights reserved.
//

/*
 Md Mahamudul Islam
 
 U 29218485
 
 FINAL PROJECT
 
 */

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main (){
    
    //calling all the insert function in the main
    
    BST <double> tree1;
    tree1.insert(31.5);
    tree1.insert(19.5);
    tree1.insert(7.5);
    tree1.insert(59.5);
    tree1.insert(43.5);
    tree1.insert(23.5);
    tree1.insert(22.5);
    tree1.insert(24.5);
    tree1.inorder();
    tree1.preorder();
    tree1.postorder();
    tree1.getSuccessor(19.5);
    cout << endl;
    tree1.getPre(19.5);
    cout << endl;
    BST <double> tree2(tree1);
    tree2.inorder();
    
}//end main
