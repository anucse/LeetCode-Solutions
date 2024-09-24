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
    void dfs(TreeNode* root, int prev_dir, int count){
        
        if(!root)
            return;
        ans=max(ans,count);
        //0->left , 1->right
        if(prev_dir==0){
            dfs(root->left,0,1);
            dfs(root->right,1,count+1);
        }
        else if(prev_dir==1){
            dfs(root->right,1,1);
            dfs(root->left,0,count+1);
        }
        else{
            dfs(root->left,0,count+1);
            dfs(root->right,1,count+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,-1,0);
        return ans;
    }
};