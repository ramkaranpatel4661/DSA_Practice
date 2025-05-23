#include<iostream>
#include<vector>
using namespace std;

class bst {
public:
    int val;
    bst* left;
    bst* right;
    bst(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bst* insert(bst* root, int val) {
    if (root == NULL) {
        return new bst(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(bst* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

bst* buildbst(vector<int>& arr) {
    bst* root = NULL;
    for (auto i : arr) {
        root = insert(root, i);
    }
    return root;
}

bool search(bst* root, int key) {
    if (root == NULL) return false;
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

bst* deleteNode(bst* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->right == NULL) {
            bst* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == NULL) {
            bst* temp = root->right;
            delete root;
            return temp;
        } else {
            // both children exist
            bst* pred = root->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
        }
    }
    return root;
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    bst* root = buildbst(arr);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    if (search(root, 8)) {
        cout << "Key is present" << endl;
    } else {
        cout << "Key is not present" << endl;
    }

    root = deleteNode(root, 5); // Example deletion
    cout << "Inorder after deleting 5: ";
    inorder(root);
    cout << endl;

    return 0;
}
