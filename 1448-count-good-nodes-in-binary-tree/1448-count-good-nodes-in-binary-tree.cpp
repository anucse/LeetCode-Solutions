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
    int count=0;
    void solve(TreeNode* root,int maximum){
        if(!root)
            return ;
        if(root->val>=maximum){
            maximum=root->val;
            count++;
        }
        
        solve(root->left,maximum);
        solve(root->right,maximum);
    }
    int goodNodes(TreeNode* root) {
        int maximum=root->val;
        
        solve(root,maximum);
        return count;
    }
};