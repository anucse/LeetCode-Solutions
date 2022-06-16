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
    int preIndex=0;
    TreeNode* newTree(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd){
        if(inStart>inEnd)
            return NULL;
        TreeNode* node=new TreeNode(preorder[preIndex++]);
        int index;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==node->val){
                index=i;
                break;
            }
        }
        node->left=newTree(preorder,inorder,inStart,index-1);
        node->right=newTree(preorder,inorder,index+1,inEnd);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return newTree(preorder,inorder,0,inorder.size()-1);
    }
};