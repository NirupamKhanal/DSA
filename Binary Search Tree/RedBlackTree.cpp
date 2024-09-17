#include <iostream>

using namespace std;

const int COUNT = 10;

// Enumeration for Red or Black
enum Color {RED, BLACK};

class TreeNode {
public:
    int value;
    Color color;
    TreeNode * left, * right, * parent;

    TreeNode() {
        value = 0;
        color = RED;
        left = right = parent = NULL;
    }

    TreeNode(int v) {
        value = v;
        color = RED;
        left = right = parent = NULL;
    }
};

class RBTree {
public:
    TreeNode *root;

    RBTree() {
        root = NULL;
    }

    bool isTreeEmpty() {
        return root == NULL;
    }

    void leftRotate(TreeNode *&root, TreeNode *&x) {
        TreeNode * y = x -> right;
        x -> right = y -> left;
        if (y -> left != NULL) {
            y -> left -> parent = x;
            y -> parent = x -> parent;
        }
        if (x -> parent == NULL) {
            root = y;
        }
        else if (x == x -> parent -> left) {
            x -> parent -> left = y;
        }
        else {
            x -> parent -> right = y;
            y -> left = x;
            x -> parent = y;}
    }

    void rightRotate(TreeNode *&root, TreeNode *&y) {
        TreeNode * x = y -> left;
        y -> left = x -> right;
        if (x -> right != NULL) {
            x -> right -> parent = y;
            x -> parent = y -> parent;
        }
        if (y->parent == NULL) {
            root = x;
        }
        else if (y == y->parent->left) {
            y -> parent -> left = x;
        }
        else {
            y -> parent -> right = x;
            x -> right = y;
            y -> parent = x;
        }
    }

    void fixViolation(TreeNode *&root, TreeNode *&pt) {
        TreeNode *parent_pt = NULL;
        TreeNode *grand_parent_pt = NULL;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            // Case A: Parent is left child of grandparent
            if (parent_pt == grand_parent_pt -> left) {
                TreeNode *uncle_pt = grand_parent_pt -> right;

                if (uncle_pt != NULL && uncle_pt -> color == RED) {
                    grand_parent_pt -> color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    if (pt == parent_pt -> right) {
                        leftRotate(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    rightRotate(root, grand_parent_pt);
                    swap(parent_pt -> color, grand_parent_pt -> color);
                    pt = parent_pt;
                }
            }

            // Case B: Parent is right child of grandparent
            else {
                TreeNode *uncle_pt = grand_parent_pt -> left;

                if (uncle_pt != NULL && uncle_pt -> color == RED) {
                    grand_parent_pt -> color = RED;
                    parent_pt -> color = BLACK;
                    uncle_pt -> color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    if (pt == parent_pt -> left) {
                        rightRotate(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt -> parent;
                    }
                    leftRotate(root, grand_parent_pt);
                    swap(parent_pt -> color, grand_parent_pt -> color);
                    pt = parent_pt;
                }
            }
        }
        root -> color = BLACK;
    }

    TreeNode *insert(TreeNode *r, TreeNode *new_node) {
        if (r == NULL) {
            return new_node;
        }

        if (new_node -> value < r -> value) {
            r -> left = insert(r -> left, new_node);
            r -> left -> parent = r;
        } else if (new_node -> value > r -> value) {
            r -> right = insert(r -> right, new_node);
            r -> right -> parent = r;
        } else {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        return r;
    }

    void insertValue(int val) {
        TreeNode *new_node = new TreeNode(val);
        root = insert(root, new_node);
        fixViolation(root, new_node);
    }

    // Print tree (2D Representation)
    void print2D(TreeNode *r, int space) {
        if (r == NULL) return;
        space += COUNT;
        print2D(r -> right, space);
        cout << endl;
        for (int i = COUNT; i < space; i++) {
            cout << " ";
        }
        cout << r -> value << (r -> color == RED ? "R" : "B") << "\n";  // Show color R or B
        print2D(r -> left, space);
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        // Traverse down to the leftmost node
        while (current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    TreeNode *deleteBST(TreeNode *root, int data) {
        if (root == NULL)
            return root;

        if (data < root -> value)
            return deleteBST(root -> left, data);

        if (data > root -> value)
            return deleteBST(root -> right, data);

        if (root -> left == NULL || root -> right == NULL)
            return root;

        TreeNode *temp = minValueNode(root -> right);
        root -> value = temp->value;
        return deleteBST(root->right, temp -> value);
    }

    void deleteNode(TreeNode *&root, int data) {
        TreeNode *v = deleteBST(root, data);

        if (v == NULL)
            return;

        fixDelete(root, v);
    }

    void fixDelete(TreeNode *&root, TreeNode *&x) {
        if (x == NULL)
            return;

        if (x == root) {
            root = NULL;
            return;
        }

        if (x -> color == RED || (x -> left != NULL && x -> left -> color == RED) || (x -> right != NULL && x -> right -> color == RED)) {
            TreeNode *child = (x -> left != NULL) ? x -> left : x -> right;

            if (x == x -> parent -> left) {
                x -> parent -> left = child;
                if (child != NULL)
                    child -> parent = x -> parent;
                child -> color = BLACK;
                delete (x);
            } else {
                x -> parent -> right = child;
                if (child != NULL)
                    child -> parent = x -> parent;
                child -> color = BLACK;
                delete (x);
            }
        } else {
            TreeNode *sibling = NULL;
            TreeNode *parent = NULL;
            TreeNode *ptr = x;
            ptr -> color = BLACK;

            while (ptr != root && ptr -> color == BLACK) {
                parent = ptr -> parent;
                if (ptr == parent -> left) {
                    sibling = parent -> right;
                    if (sibling -> color == RED) {
                        sibling -> color = BLACK;
                        parent -> color = RED;
                        leftRotate(root, parent);
                        sibling = parent -> right;
                    }

                    if ((sibling -> left == NULL || sibling -> left->color == BLACK) && (sibling -> right == NULL || sibling -> right->color == BLACK)) {
                        sibling -> color = RED;
                        ptr = parent;
                    } else {
                        if (sibling->right == NULL || sibling->right->color == BLACK) {
                            sibling -> left -> color = BLACK;
                            sibling -> color = RED;
                            rightRotate(root, sibling);
                            sibling = parent -> right;
                        }

                        sibling -> color = parent -> color;
                        parent -> color = BLACK;
                        sibling -> right -> color = BLACK;
                        leftRotate(root, parent);
                        break;
                    }
                } else {
                    sibling = parent -> left;
                    if (sibling -> color == RED) {
                        sibling -> color = BLACK;
                        parent -> color = RED;
                        rightRotate(root, parent);
                        sibling = parent -> left;
                    }

                    if ((sibling -> left == NULL || sibling -> left -> color == BLACK) && (sibling -> right == NULL || sibling -> right -> color == BLACK)) {
                        sibling -> color = RED;
                        ptr = parent;
                    } else {
                        if (sibling -> left == NULL || sibling -> left -> color == BLACK) {
                            sibling -> right -> color = BLACK;
                            sibling -> color = RED;
                            leftRotate(root, sibling);
                            sibling = parent -> left;
                        }

                        sibling -> color = parent -> color;
                        parent -> color = BLACK;
                        sibling -> left -> color = BLACK;
                        rightRotate(root, parent);
                        break;
                    }
                }
            }
            if (x == x->parent->left)
                x -> parent -> left = NULL;
            else
                x -> parent -> right = NULL;
            delete (x);
            root->color = BLACK;
        }
    }

    TreeNode *iterativeSearch(int value) {
        if (root == NULL) return NULL;
        
        TreeNode *temp = root;
        while (temp != NULL) {
            if (value == temp -> value)
                return temp;
            else if (value < temp -> value)
                temp = temp -> left;
            else
                temp = temp -> right;
        }
        return NULL;
    }

    TreeNode *recursiveSearch(TreeNode *r, int value) {
        if (r == NULL || r -> value == value) {
            return r;
        }
        else if (value < r -> value) {
            return recursiveSearch(r -> left, value);
        }
        else {
            return recursiveSearch(r -> right, value);
        }
    }

    void printPreOrder(TreeNode *r) {
        if (r == NULL) return;
        cout << r -> value << (r -> color == RED ? "R " : "B ");
        printPreOrder(r -> left);
        printPreOrder(r -> right);
    }

    void printInOrder(TreeNode *r) {
        if (r == NULL) return;
        printInOrder(r -> left);
        cout << r -> value << (r -> color == RED ? "R " : "B ");
        printInOrder(r -> right);
    }

    void printPostOrder(TreeNode *r) {
        if (r == NULL) return;
        printPostOrder(r -> left);
        printPostOrder(r -> right);
        cout << r -> value << (r -> color == RED ? "R " : "B ");
    }

    void printGivenLevel(TreeNode *r, int level) {
        if (r == NULL) return;
        if (level == 0) {
            cout << r -> value << (r -> color == RED ? "R " : "B ");
        } else {
            printGivenLevel(r -> left, level - 1);
            printGivenLevel(r -> right, level - 1);
        }
    }

    int height(TreeNode *r) {
        if (r == NULL) return -1;
        int left_height = height(r -> left);
        int right_height = height(r -> right);
        return max(left_height, right_height) + 1;
    }

    void printLevelOrderBFS(TreeNode *r) {
        int h = height(r);
        for (int i = 0; i <= h; i++) {
            printGivenLevel(r, i);
            cout << endl;
        }
    }

};

int main() {
    RBTree rb;
    int option, value;

    do {
        cout << "\n\n--- Red-Black Tree Operations ---" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Search a node (Iterative)" << endl;
        cout << "4. Search a node (Recursive)" << endl;
        cout << "5. Print tree (Preorder)" << endl;
        cout << "6. Print tree (Inorder)" << endl;
        cout << "7. Print tree (Postorder)" << endl;
        cout << "8. Print tree (Level Order/BFS)" << endl;
        cout << "9. Print tree (2D)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                rb.insertValue(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                rb.deleteNode(rb.root, value);
                break;

            case 3:
                cout << "Enter value to search (Iterative): ";
                cin >> value;
                if (rb.iterativeSearch(value) != NULL)
                    cout << "Value found in the tree!" << endl;
                else
                    cout << "Value not found." << endl;
                break;

            case 4:
                cout << "Enter value to search (Recursive): ";
                cin >> value;
                if (rb.recursiveSearch(rb.root, value) != NULL)
                    cout << "Value found in the tree!" << endl;
                else
                    cout << "Value not found." << endl;
                break;

            case 5:
                cout << "Preorder Traversal of the Red-Black Tree:" << endl;
                rb.printPreOrder(rb.root);
                cout << endl;
                break;

            case 6:
                cout << "Inorder Traversal of the Red-Black Tree:" << endl;
                rb.printInOrder(rb.root);
                cout << endl;
                break;

            case 7:
                cout << "Postorder Traversal of the Red-Black Tree:" << endl;
                rb.printPostOrder(rb.root);
                cout << endl;
                break;

            case 8:
                cout << "Level Order Traversal (BFS) of the Red-Black Tree:" << endl;
                rb.printLevelOrderBFS(rb.root);
                cout << endl;
                break;

            case 9: // Print tree (2D)
                cout << "2D Representation of the Red-Black Tree:" << endl;
                rb.print2D(rb.root, 0);
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 0);

    return 0;
}