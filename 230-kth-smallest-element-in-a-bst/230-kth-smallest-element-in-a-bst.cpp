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
    int ans;
    int n;
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        n--;
        if(n==0)
            ans=root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        inorder(root);
        return ans;
    }
};