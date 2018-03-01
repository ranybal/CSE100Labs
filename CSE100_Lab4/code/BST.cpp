#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
    root = NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
void deltree(Node * x) {
    if (x != NULL) {
        deltree(x->left);
        deltree(x->right);
        delete x;
    }
}

BST::~BST() {
}



void BST::Insert(int toInsert) {
    
    Node * x;
    Node * y = NULL;
    Node * z = new Node();
    x = root;
    
   
    while (x != NULL) {
        y = x;
        if (toInsert < x->val)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    
    z-> left = NULL;
    z-> right = NULL;
    z->val = toInsert;
    z->parent = y;
    
    
    if (y == NULL) {
        root = z;
    }
    else if (z->val < y->val)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    
}

void BST::Delete(int toDelete) { //TAKEN FROM PSEUDOCODE
    Node * z = new Node();
    z = BST::Search(toDelete);
    if (z == NULL)
        return;
    else if(z != NULL){
        if (z->left == NULL)
            Transplant(z, z->right);
        else if (z->right == NULL)
            Transplant(z, z->left);
        else {
            Node * y = new Node();
            y = Minimum(z->right);
            if (y->parent != z) {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    
    }
    
}

void BST::Transplant(Node *u, Node *v) {
    if (u->parent == NULL) {
        root = v;
    }
    else if (u == u->parent->left){
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}


Node *BST::Successor(Node *x) {
    if (x->right != NULL)
    {
        return Minimum(x->right);
    }
    
    Node * y = y = x -> parent;
    
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y -> parent;
    }
}

Node *BST::Minimum(Node *x) {
    while (x->left != NULL)
    {
        x = x->left;
    }
    
    return x;
}

Node *BST::Maximum(Node *x) {
    while (x->right != NULL)
    {
        x = x->right;
    }
    
    return x;
}

Node *BST::Search(int toFind) {
    Node *x = root;
    
    while (x != NULL && toFind != x -> val)
    {

    if(toFind < x->val)
        x = x -> left;
    else
        x = x -> right;
        //return NULL;
    }
   
    if(x == NULL || toFind != x->val)
    {
        return x;
    }
    return x;
}

void BST::Print(TraversalOrder Order) {
    if(Order==InOrderTrav)
        InOrder(root);
    else if(Order==PreOrderTrav)
        PreOrder(root);
    else if(Order==PostOrderTrav)
        PostOrder(root);
}

void BST::PreOrder(Node *x) {
    if (x != NULL)
    {
        cout << x->val << endl;
        PreOrder(x->left);
        PreOrder(x->right);
    }
    
}

void BST::InOrder(Node *x) { //TAKEN FROM PSEUDOCODE
    if (x != NULL) {
        InOrder(x->left);
        cout << x->val <<  endl;
        InOrder(x->right);
    }
    
}

void BST::PostOrder(Node *x) {
    if (x != NULL) {
        PostOrder(x->left);
        PostOrder(x->right);
        cout << x->val << endl;
    }
    
}
