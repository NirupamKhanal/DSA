class BST {

private:
    struct node {
        int key; 
        node* left; 
        node* right;
    };

    node* root; 

    void AddLeafPrivate(int key, node* Ptr);
    void PrintInOrderPrivate(node* Ptr); 
    node* ReturnNodePrivate(int key, node* Ptr);
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* Parent); 
    void RemoveRootMatch();
    void RemoveMatch(node* Parent, node* match, bool left);
    void RemoveSubTree(node* Ptr);

public: 

    BST(); 
    ~BST();
    node* CreateLeaf(int key);
    node* ReturnNode(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key); 
};