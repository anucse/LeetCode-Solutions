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
    int preindex=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int instart,int inend){
        if(instart>inend)
            return NULL;
        TreeNode* node=new TreeNode(preorder[preindex++]);
        int index;
        for(int i=instart;i<=inend;i++){
            if(inorder[i]==node->val){
                index=i;
                break;
            }
        }
        
        node->left=solve(preorder,inorder,instart,index-1);
        node->right=solve(preorder,inorder,index+1,inend);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};