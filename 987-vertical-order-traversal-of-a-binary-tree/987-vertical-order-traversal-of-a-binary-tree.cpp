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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            int n=q.size();
            multiset<pair<int,int>> temp;
            for(int i=0;i<n;i++){
                auto top=q.front(); q.pop();
                temp.insert({top.second->val,top.first});
                if(top.second->left)
                    q.push({top.first-1,top.second->left});
                if(top.second->right)
                    q.push({top.first+1,top.second->right});
            }
            for(auto x:temp)
                m[x.second].push_back(x.first);
        }
        vector<vector<int>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};