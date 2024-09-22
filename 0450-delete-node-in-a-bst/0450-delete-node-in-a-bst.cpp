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
    TreeNode* replace(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(key>root->val)
            deleteNode(root->right,key);
        else if(key<root->val){
            deleteNode(root->left,key);
        }
        else{
            if(!root->left){
                return root->right;
            }
            if(!root->right)
                return root->left;
            TreeNode* replaceNode=replace(root->right);
            root->val=replaceNode->val;
            root->right=deleteNode(root->right,replaceNode->val);
        }

        return root;
    }
};