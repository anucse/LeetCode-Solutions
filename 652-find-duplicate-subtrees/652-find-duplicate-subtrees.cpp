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
    
    unordered_map<string,pair<TreeNode*,int>> m;
    
    string solve(TreeNode* root){
        
        if(!root)
            return "";
        string left=solve(root->left);
        string right=solve(root->right);
        string subtree=to_string(root->val)+" "+left+" "+right;
        
        if(m.count(subtree)>0){
            m[subtree].second++;
        }
        else{
            m[subtree]={root,1};
        }
        
        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        solve(root);
        vector<TreeNode*> ans;
        for(auto x:m){
            if (x.second.second>1){
                ans.push_back(x.second.first);
            }
        }
        
        return ans;
    }
};










