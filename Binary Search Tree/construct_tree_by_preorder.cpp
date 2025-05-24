/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* insert(TreeNode*curr,int temp){
    if(curr==NULL){
      return new TreeNode(temp);
    }
    if(temp < curr->val){
        curr->left=insert(curr->left,temp);
    }
    else{
     curr->right=insert(curr->right,temp);
    }
    return curr;
}
   
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         TreeNode*root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
             int temp=preorder[i];
             insert(root,temp);
        }
        
        return root;
    }
};