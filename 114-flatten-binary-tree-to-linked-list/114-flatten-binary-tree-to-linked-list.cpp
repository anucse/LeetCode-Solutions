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
    TreeNode* solve(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode* temp=solve(root->right);
        root->right=solve(root->left);
        root->left=NULL;
        TreeNode* node=root;
        while(node->right){
            node=node->right;
        }
        node->right=temp;
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};