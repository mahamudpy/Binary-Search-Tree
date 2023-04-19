//
//  Header.h
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

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>

using namespace std;

template <class T> //Template created

class BST{

    //making a class named BST
    
    struct node {
    //created the struct and initialized the variable
        T data;
        node* right;
        node* left;
    
    }; //end struct
    
    node* root;
    
    node* insertHelper(T i, node* t){
        
        if (t == nullptr){
            
            t = new node;
            t->data = i;
            t->right = NULL;
            t->left  = NULL;
        }//end if
       
        else if (i < t->data)
            t->left = insertHelper(i, t->left);
        else if (i > t->data)
            t->right = insertHelper(i, t->right);
        return t;
        
    } //end node
    
    void inorderHelper(node* t){
    // void inorder const using a helper function
        if (t == NULL)
            return;
        inorderHelper(t->left);
        cout << t->data << " ";
        inorderHelper(t->right);
    
    } //end inorder
    
    void preorderHelper(node* t){
    
    // void preorder const using a helper function
        if (t == NULL)
            return;
       
        cout << t->data << " ";
        preorderHelper(t->left);
        preorderHelper(t->right);
   
    }//end preorder
    
    void postorderHelper(node* t){
    // void postorder const using a helper function
           if (t == NULL)
               return;
          
           postorderHelper(t->left);
           postorderHelper(t->right);
           cout << t->data << " ";
   
    } //end postorder
   
    node* searchHelper(T x, node* t)const{
    // created the bool search healper function
        
        if (t == NULL)
            return NULL;
        else if (x < t ->data)
            return searchHelper(x, t-> left);
        else if (x > t ->data)
            return searchHelper(x, t-> right);
        else
            return t;
   
    } //end searchHelper
    
    node* removeHelper(T x, node* t){
    // created the bool remove healper function
        node* temp;
    
    if (t == NULL)
        return NULL;
    else if (x < t ->data)
        t->left =  removeHelper(x, t-> left);
    else if (x > t ->data)
        t->right = searchHelper(x, t-> right);
    else if (t->left && t-> right){
        
        temp    = getMinimumHelper(t->right);
        t->data = temp->data;
        t->data = removeHelper(t->data, t->right);
    }//end removeHelper
    else {
        
        temp = t;
        if (t->left == NULL)
            t = t-> right;
        else if (t->right == NULL)
            t = t-> left;
        delete temp;
        
     }//end else
        
        return t;
    
  }//end node
    
    node* getMinimumHelper(node* t){
    // creating T getMinimum() const using a helper function
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return getMinimumHelper(t->left);
    }//end node
    
    node* getMaximumHelper(node* t){
    // creating T getMaximum() const using a helper function

           if (t == NULL)
               return NULL;
           else if (t->right == NULL)
               return t;
           else
               return getMaximumHelper(t->right);
       }//end node
    
    node* deleteBinarySearchTree(node*& subtreeRoot){
   //void deleteBinarySearchTree(Node * &subtreeRoot); which is used by the destructor function.
        
        if (subtreeRoot == NULL)
            return NULL;
        {
            deleteBinarySearchTree(subtreeRoot -> left);
            deleteBinarySearchTree(subtreeRoot -> right);
            delete subtreeRoot;
            
        }//end if
        
        return NULL;
    }//end node
    
    node* getSuccessorHelper(node* root, T data){
    // T getSuccessor is created
        node* current = searchHelper(data, root);
        if (current == NULL)return NULL;
        if (current -> right != NULL)
            return getMinimumHelper(current -> right);
        else {
            node* Successor = NULL;
            node* Ancestor = root;
            while (Ancestor != current){
                if (current -> data < Ancestor -> data){
                    
                    Successor = Ancestor;
                    Ancestor  = Ancestor->left;
                    
                }//end if
                
                else
                    Ancestor = Ancestor -> right;
                
            }//end while
            
            return Successor;
            
        }//end else
   
    }//end node
    
    node* getPreHelper(node* root, T data){
    //T getPreHelper isn created 
           node* current = searchHelper(data, root);
           if (current == NULL) return NULL;
           if (current -> left != NULL)
               return getMaximumHelper(current -> left);
           else {
               node* Pre = NULL;
               node* Ancestor = root;
               while (Ancestor != current){
                   if (current -> data > Ancestor -> data){
                       
                       Pre = Ancestor;
                       Ancestor  = Ancestor->right;
                       
                   }//end if
                   
                   else
                       Ancestor = Ancestor -> left;
                   
               }//end while
               
               return Pre;
               
           }//end else
      
    }//end node
    
public:
    
    BST(){
        
        root = NULL;
    
    }//end BST
    
    ~BST(){
        
        root = deleteBinarySearchTree(root);
    }//end BST
    
    BST (BST& source){
        
        if (source.root == NULL)
            root = NULL;
        else
            copyTree(this->root, source.root);
    }//end BST
    
    void copyTree(node*& thisRoot, node*& sourceRoot){
        
        if (sourceRoot == NULL){
            
            thisRoot = NULL;
            
        }
       
        else{
            thisRoot = new node;
            thisRoot-> data = sourceRoot->data;
            copyTree(thisRoot->left, sourceRoot->left);
            copyTree(thisRoot->right, sourceRoot->right);
            
            
        }
            
    }
    
    bool insert (const T& i){
        
        if (search(i) == false ){
            
            root = insertHelper(i, root);
            return true;
        }
       
        else
            return false;
    }
    
    void inorder (){
        
        inorderHelper(root);
        cout << endl;
    }
    
    void preorder (){
           
           preorderHelper(root);
           cout << endl;
    }
    
    void postorder (){
           
           postorderHelper(root);
           cout << endl;
    }
    
    bool search (const T& x)const {
        
        node* t;
        t = searchHelper(x, root);
           
           if (t == NULL )
               
              return false ;
           
          else
               return true;
    }//end bool
    
    bool remove (const T& x){
     
        root = removeHelper(x, root);
           if (search(x) == true )

               return false ;
           else
               return true;
    }//end bool
    
    T getMaximum(){
        node* t;
        t = getMaximumHelper(root);
        return t->data;
        
    }
    
    T getMinimum(){
           node* t;
           t = getMinimumHelper(root);
           return t->data;
           
    }
    
    void getSuccessor(T data){
        
        node* suc = getSuccessorHelper(root, data);
        cout << suc-> data;
    }
    
    void getPre(T data){
        
        node* pre = getPreHelper(root, data);
        cout << pre-> data;
    }
    
    
    
};


#endif /* Header_h */
