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
    vector<vector<int>> ans;
    
    
    void dfs(TreeNode* root, int target,vector<int>& temp, int sum){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(sum==target){
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            
        }
        
        if(root->left){
            temp.push_back(root->left->val);
            dfs(root->left,target,temp,sum+root->left->val);
        }
        if(root->right){
            temp.push_back(root->right->val);
            dfs(root->right,target,temp,sum+root->right->val);
        }
        
        temp.pop_back();
            
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        vector<int> temp;
        temp.push_back(root->val);
        dfs(root,targetSum,temp,root->val);
        return ans;
    }
};