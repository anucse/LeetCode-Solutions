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
        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h=height(root);
        if(h==0)
            return {};
        vector<vector<int>> ans(h);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            h--;
            vector<int> temp;
            while(n--){
                TreeNode* top=q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            ans[h]=temp;
        }
        return ans;
    }
};