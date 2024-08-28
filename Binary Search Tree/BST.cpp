#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;     
    
BST::BST() {
    root = NULL; 
}

BST::node* BST::CreateLeaf(int key) {
    node* n = new node; 
    n -> key = key; 
    n -> left = NULL; 
    n -> right = NULL; 

    return n;
}

void BST::AddLeaf(int key) {
    AddLeafPrivate(key, root); 
}

void BST::AddLeafPrivate(int key, node* Ptr) {
    if(root == NULL) {
        root = CreateLeaf(key);
    }
    else if(key < Ptr -> key) {
        if(Ptr -> left != NULL) {
            AddLeafPrivate(key, Ptr -> left); 
        }
        else {
            Ptr -> left = CreateLeaf(key); 
    }
    }
    else if(key > Ptr -> key) {
        if(Ptr -> right != NULL) {
            AddLeafPrivate(key, Ptr -> right); 
        }
        else {
            Ptr -> right = CreateLeaf(key); 
        }
    }
    else {
        cout << "The key " << key << "has already been added to the tree.\n";
    }
}

void BST::PrintInOrder() {
    PrintInOrderPrivate(root); 
}

void BST::PrintInOrderPrivate(node* Ptr) {
    if(root != NULL) {
        if(Ptr -> left != NULL) {
            PrintInOrderPrivate(Ptr -> left); 
        }
        cout << Ptr -> key << " "; 
        if(Ptr -> right != NULL) {
            PrintInOrderPrivate(Ptr -> right); 
        }
    }
    else {
        cout << "The tree is empty.\n"; 
    }
}

BST::node* BST::ReturnNode(int key) {
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
    if(Ptr != NULL) {
        if(Ptr -> key == key) {
            return Ptr;
        }
        else {
            if(key < Ptr -> key) {
                return ReturnNodePrivate(key, Ptr -> left);
            }
            else {
                return ReturnNodePrivate(key, Ptr -> right); 
            }
        }
    }
    else {
        return NULL;
    }
}

int BST::ReturnRootKey() {
    if(root != NULL) {
        return root -> key; 
    }
    else {
        return -1000;
    }
}

void BST::PrintChildren(int key) {
    node* Ptr = ReturnNode(key); 

    if(Ptr != NULL) {
        cout << "Parent node = " << Ptr -> key << endl; 

        Ptr -> left == NULL ? 
        cout << "Left child = NULL\n": 
        cout << "Left child = " << Ptr -> left -> key << endl; 

        Ptr -> right == NULL ? 
        cout << "Right child = NULL\n": 
        cout << "Right child = " << Ptr -> right -> key << endl; 

    }
    else {
        cout << "Key " << key << "is not in the tree.\n"; 
    }
}

int BST::FindSmallest() {
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr) {
    if(root == NULL) {
        cout << "The tree is empty.\n"; 
        return -1000; 
    }
    else {
        if(Ptr -> left != NULL) {
            return FindSmallestPrivate(Ptr -> left); 
        }
        else {
            return Ptr -> key; 
        }
    }
}

void BST::RemoveNode(int key) {
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* Parent) {
    if(root != NULL) {
        if(root -> key == key) {
            RemoveRootMatch();
        }
        else {
            if(key < Parent -> key && Parent -> left != NULL) {
                Parent -> left -> key == key ? 
                RemoveMatch(Parent, Parent -> left, true):
                RemoveNodePrivate(key, Parent -> left);
            }
            else if(key > Parent -> key && Parent -> right != NULL) {
                Parent -> right -> key == key ? 
                RemoveMatch(Parent, Parent -> right, false):
                RemoveNodePrivate(key, Parent -> right);
            }
            else {
                cout << "The key " << key << "was not found in the tree.\n"; 
            }
        }
    }
    else {
        cout << "The tree is empty.\n";
    }
}

void BST::RemoveRootMatch() {
    if(root != NULL) {
        node* delPtr = root; 
        int rootKey = root -> key; 
        int smallestInRightSubTree; 

        if(root -> left == NULL && root -> right == NULL) {
            root = NULL; 
            delete delPtr; 
        }
        else if(root -> left == NULL && root -> right != NULL) {
            root = root -> right; 
            delPtr -> right = NULL; 
            delete delPtr; 
            cout << "The root node with the key " << rootKey << "was deleted." <<
                    "The new root contains the key " << root -> key << endl; 
        }
        else if(root -> right == NULL && root -> left != NULL) {
            root = root -> left; 
            delPtr -> left = NULL; 
            delete delPtr; 
            cout << "The root node with the key " << rootKey << "was deleted." <<
                    "The new root contains the key " << root -> key << endl; 
        }
        else {
            smallestInRightSubTree = FindSmallestPrivate(root -> right); 
            RemoveNodePrivate(smallestInRightSubTree, root);
            root -> key = smallestInRightSubTree; 
            cout << "The root key containing key " << rootKey << 
                    "was overwritten with key " << root -> key << endl; 
        }
    }
    else {
        cout << "The tree is empty.\n"; 
    }
}

void BST::RemoveMatch(node* Parent, node* match, bool left) {
    if(root != NULL) {
        node* delPtr; 
        int matchKey = match -> key; 
        int smallestInRightSubTree; 

        if(match -> left == NULL && match -> right == NULL) {
            delPtr = match; 
            left == true ? Parent -> left = NULL : Parent -> right = NULL; 
            delete delPtr; 
            cout << "The node containing key " << matchKey << "was removed.\n"; 
        }
        else if(match -> left == NULL && match -> right != NULL) {
            left == true ? Parent -> left = match -> right : Parent -> right = match -> right; 
            match -> right = NULL;
            delPtr = match; 
            delete delPtr; 
            cout << "The node containing key " << matchKey << "was removed.\n";
        }
        else if(match -> left != NULL && match -> right == NULL) {
            left == true ? Parent -> left = match -> left : Parent -> right = match -> left; 
            match -> left = NULL;
            delPtr = match; 
            delete delPtr; 
            cout << "The node containing key " << matchKey << "was removed.\n";
        }
        else {
            smallestInRightSubTree = FindSmallestPrivate(match -> right); 
            RemoveNodePrivate(smallestInRightSubTree, match);
            match -> key = smallestInRightSubTree;
        }
    }
    else {
        cout << "The tree is empty.\n";
    }
}

BST::~BST() {
    RemoveSubTree(root); 
}

void BST::RemoveSubTree(node* Ptr) {
    if(Ptr != NULL) {
        if(Ptr -> left != NULL) {
            RemoveSubTree(Ptr -> left); 
        }
        if(Ptr -> right != NULL) {
            RemoveSubTree(Ptr -> right);
        }
        cout << "Deleting the node containing the key " << Ptr -> key << endl;
        delete Ptr; 
    }
}