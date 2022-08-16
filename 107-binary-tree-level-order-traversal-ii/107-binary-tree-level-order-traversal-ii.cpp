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
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root)
            return {};
        
        int h=height(root);
        
        vector<vector<int>> ans(h);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            h--;
            vector<int> temp;
            while(s--){
                
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            ans[h]=temp;
        }
        
        return ans;
    }
};