#include <iostream>

#define AVL
using namespace std; 

const int COUNT = 10;

class TreeNode {
    public: 
        int value; 
        TreeNode * left; 
        TreeNode * right; 

        TreeNode() {
            value = 0;
            left = NULL; 
            right = NULL; 
        }

        TreeNode(int v) {
            value = v; 
            left = NULL; 
            right = NULL; 
        }
}; 

class AVLTree {
    public: 
        TreeNode * root; 
        AVLTree() {
            root = NULL; 
        }
        bool isTreeEmpty() {
            if (root == NULL) {
                return true; 
            }
            else {
                return false; 
            }
        }

        int height(TreeNode * r) {
            if (r == NULL) {
                return -1; 
            }
            else {
                int l_height = height(r -> left);
                int r_height = height(r -> right); 
            
            if (l_height > r_height) {
                return (l_height++);
            }
            else {
                return(r_height++);
            }
            }
        }

        int getBalanceFactor(TreeNode * n) {
            if (n == NULL) return -1; 
            return height(n -> left) - height(n -> right);
        }

        TreeNode * rightRotate(TreeNode * y) {
            TreeNode * x = y -> left; 
            TreeNode * T2 = x -> right; 

            x -> right = y; 
            y -> left = T2;

            return x;  
        }

        TreeNode * leftRotate(TreeNode * x) {
            TreeNode * y = x -> right; 
            TreeNode * T2 = y -> left; 

            y -> left = x; 
            x -> right = T2;

            return y;  
        }

        TreeNode * insert(TreeNode * r, TreeNode * new_node) {
            if (r == NULL) {
                r = new_node;
                cout << "Value inserted successfully." << endl; 
                return r; 
            }

            if (new_node -> value < r -> value) {
                r -> left = insert(r -> left, new_node); 
            } 
            else if (new_node -> value > r -> value) {
                r -> right = insert(r -> right, new_node); 
            }
            else {
                cout << "No duplicate values allowed!" << endl; 
                return r;
            }

            int bf = getBalanceFactor(r); 
            if (bf > 1 && new_node -> value < r -> left -> value) {
                return rightRotate(r); 
            }

            if (bf < -1 && new_node -> value > r -> right -> value) {
                return leftRotate(r); 
            }

            if (bf > 1 && new_node -> value > r -> left -> value) {
                r -> left = leftRotate(r -> left); 
                return rightRotate(r);
            }

            if (bf < -1 && new_node -> value < r -> right -> value) {
                r -> right = rightRotate(r -> right); 
                return leftRotate(r); 
            }

            return r; 
        }

        TreeNode * minValueNode(TreeNode * node) {
            TreeNode * curr = node; 
            while (curr -> left != NULL) {
                curr = curr -> left;
            }
            return curr; 
        }

        TreeNode * deleteNode(TreeNode * r, int v) {
            if (r == NULL) {
                return NULL;
            }
            else if (v < r -> value) {
                r -> left = deleteNode(r -> left, v);
            }
            else if (v > r -> value) {
                r -> right = deleteNode(r -> right, v);
            }
            else {
                if (r -> left == NULL) {
                    TreeNode * temp = r -> right; 
                    delete r; 
                    return temp; 
                }
                else if (r -> right == NULL) {
                    TreeNode * temp = r -> left; 
                    delete r; 
                    return temp; 
                }
                else {
                    TreeNode * temp = minValueNode(r -> right); 
                    r -> value = temp -> value; 
                    r -> right = deleteNode(r -> right, temp -> value); 
                }
            }

            int bf = getBalanceFactor(r); 
            if (bf == 2 && getBalanceFactor(r -> left) >= 0) {
                return rightRotate(r); 
            }
            else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
                r -> left = leftRotate(r -> left); 
                return rightRotate(r);
            }
            else if (bf == -2 && getBalanceFactor(r -> right) <= -0) {
                return leftRotate(r); 
            }
            else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
                r -> right = rightRotate(r -> right); 
                return leftRotate(r);
            }
            
            return r; 
        }

        void print2D(TreeNode * r, int space) {
            if (r == NULL) return; 
            
            space += COUNT;
            print2D(r -> right, space); 
            cout << endl;
            for (int i = COUNT; i < space; i++) {
                cout << " "; 
                }
            cout << r -> value << "\n"; 
            print2D(r -> left, space); 
        }

        void printPreOrder(TreeNode * r) {
            if (r == NULL) return; 
            cout << r -> value << " "; 
            printPreOrder(r -> left); 
            printPreOrder(r -> right);
        }

        void printInOrder(TreeNode * r) {
            if (r == NULL) return; 
            printInOrder(r -> left); 
            cout << r -> value << " "; 
            printInOrder(r -> right); 
        }

        void printPostOrder(TreeNode * r) {
            if (r == NULL) return;  
            printPostOrder(r -> left); 
            printPostOrder(r -> right);
            cout << r -> value << " ";
        }

        void printGivenLevel(TreeNode * r, int level) {
            if (r == NULL) return; 
            else if (level == 0) {
                cout << r -> value << " "; 
            }
            else {
                printGivenLevel(r -> left, level - 1); 
                printGivenLevel(r -> right, level - 1); 
            }
        }

        void printLevelOrderBFS(TreeNode * r) {
            int h = height(r); 
            for (int i = 0; i <= h; i ++) {
                printGivenLevel(r, i);
                cout << endl;
            }
        }

        TreeNode * iterativeSearch(int v) {
            if (root == NULL) return root; 
            else {
                TreeNode * temp = root; 
                while (temp != NULL) {
                    if (v == temp -> value) {
                        return temp; 
                    }
                    else if (v < temp -> value) {
                        temp = temp -> left; 
                    }
                    else {
                        temp = temp -> right; 
                    }
                }
            }
            return NULL;
        }

        TreeNode * recursiveSearch(TreeNode * r, int val) {
            if (r == NULL || r -> value == val) {
                return r; 
            }
            else if (val < r -> value) {
                return recursiveSearch(r -> left, val); 
            }
            else {
                return recursiveSearch(r -> right, val); 
            }
        }
};

int main() {
    AVLTree avl; 
    int option, value; 

    do {
        cout << "\n\n--- AVL Tree Operations ---" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Search a node (Iterative)" << endl;
        cout << "4. Search a node (Recursive)" << endl;
        cout << "5. Print tree (2D)" << endl;
        cout << "6. Print tree (Preorder)" << endl;
        cout << "7. Print tree (In order)" << endl;
        cout << "8. Print tree (Postorder)" << endl;
        cout << "9. Print tree (Level Order/BFS)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        TreeNode * new_node = NULL;
        switch(option) {
            case 1: // Insert a node
                cout << "Enter value to insert: ";
                cin >> value;
                new_node = new TreeNode(value);
                avl.root = avl.insert(avl.root, new_node);
                break;

            case 2: // Delete a node
                cout << "Enter value to delete: ";
                cin >> value;
                avl.root = avl.deleteNode(avl.root, value);
                break;

            case 3: // Search a node (Iterative)
                cout << "Enter value to search (Iterative): ";
                cin >> value;
                new_node = avl.iterativeSearch(value);
                if (new_node != NULL) {
                    cout << "Value found in the tree!" << endl;
                } else {
                    cout << "Value not found." << endl;
                }
                break;

            case 4: // Search a node (Recursive)
                cout << "Enter value to search (Recursive): ";
                cin >> value;
                new_node = avl.recursiveSearch(avl.root, value);
                if (new_node != NULL) {
                    cout << "Value found in the tree!" << endl;
                } else {
                    cout << "Value not found." << endl;
                }
                break;

            case 5: // Print tree (2D)
                cout << "2D Representation of the AVL Tree:" << endl;
                avl.print2D(avl.root, 0);
                break;

            case 6: // Print tree (Preorder)
                cout << "Preorder Traversal of the AVL Tree:" << endl;
                avl.printPreOrder(avl.root);
                cout << endl;
                break;

            case 7: // Print tree (In order)
                cout << "In order Traversal of the AVL Tree:" << endl;
                avl.printInOrder(avl.root);
                cout << endl;
                break;

            case 8: // Print tree (Postorder)
                cout << "Postorder Traversal of the AVL Tree:" << endl;
                avl.printPostOrder(avl.root);
                cout << endl;
                break;

            case 9: // Print tree (Level Order/BFS)
                cout << "Level Order/BFS Traversal of the AVL Tree:" << endl;
                avl.printLevelOrderBFS(avl.root);
                cout << endl;
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while(option != 0);

    return 0; 
}