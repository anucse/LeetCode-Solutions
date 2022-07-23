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
    vector<int>v;
    void inorder(TreeNode *root) //storing value by inorder traversal
    {
        if(root!=NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)return false; //in case root is null we can't find two values
        inorder(root);
        int i=0,j=v.size()-1;
        while(i<j) //using two pointers approach
        {
            if(v[i]+v[j]<k) i++;  //in case our sum if <k move right to get larger value
            else if(v[i]+v[j]>k) j--;  //vice versa
            else return true; //we got the pair
        }
        return false; //in case we can't find the valid pairs
    }
};