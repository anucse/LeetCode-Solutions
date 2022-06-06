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
    int diameter=0;
    
    int height(TreeNode* root){
        
        if(!root)
            return 0;
        
        int left_h=height(root->left);
        int right_h=height(root->right);
        
        diameter=max(diameter,(left_h+right_h));
        
        return max(left_h,right_h)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
        
    }
};