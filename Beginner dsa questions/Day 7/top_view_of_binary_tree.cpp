#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Define the TreeNode structure
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from a vector input
TreeNode<int>* buildTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return nullptr;
    }
    TreeNode<int>* root = new TreeNode<int>(nodes[index]);
    index++;
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

// Function to get the top view of a binary tree
vector<int> getTopView(TreeNode<int>* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    map<int, int> m; // Map to store the first node at each horizontal distance
    queue<pair<TreeNode<int>*, int>> q; // Queue to store nodes with their horizontal distance

    q.push({root, 0}); // Start with the root node at horizontal distance 0

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode<int>* node = it.first;
        int line = it.second;

        // If this is the first node at this horizontal distance, insert it in the map
        if (m.find(line) == m.end()) {
            m[line] = node->data;
        }

        // Add the left and right children to the queue with updated horizontal distance
        if (node->left != nullptr) {
            q.push({node->left, line - 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, line + 1});
        }
    }

    // Collect the top view from the map in order of horizontal distances
    for (auto it : m) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    cout << "Enter the elements of the tree (-1 for null nodes, level-order): ";
    vector<int> nodes;
    int val;
    while (cin >> val) {
        nodes.push_back(val);
        if (cin.peek() == '\n') break;
    }

    int index = 0;
    TreeNode<int>* root = buildTree(nodes, index);

    vector<int> topView = getTopView(root);
    cout << "Top View of the Binary Tree: ";
    for (int val : topView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
