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
int ans=0;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max (depth(root->left),depth(root->right))+1;
    }

    void solve(TreeNode* root){
        if(!root)
            return;
        solve(root->left);
        solve(root->right);
        int l_depth=depth(root->left);
        int r_depth=depth(root->right);
        ans=max(ans,l_depth+r_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        solve(root);
        return ans;
    }
};