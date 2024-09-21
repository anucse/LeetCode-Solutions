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
    int dfs(TreeNode* root, int target, long long sum,unordered_map<long long,int>& mp){
        if(!root)
            return 0;
        
        sum+=root->val;
        int count =mp[sum-target];
        mp[sum]++;
        count+=dfs(root->left,target,sum,mp);
        count+=dfs(root->right,target,sum,mp);
        mp[sum]--;
        return count;
         
    }
    int pathSum(TreeNode* root, int target) {
        unordered_map<long long, int> mp;
        mp[0]=1;
        return dfs(root,target,0,mp);
    }
};