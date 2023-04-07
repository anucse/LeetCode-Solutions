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
    bool sameTree(TreeNode* p, TreeNode* q) {
        
        if(!p && !q)
            return true;
        if(!p || !q )
            return false;
        
        return (p->val == q->val ) && sameTree(p->left,q->left) && sameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(sameTree(root,subRoot))
            return true;
        bool l=false,r=false;
        if(root->left)
            l = isSubtree(root->left,subRoot);
        if(root->right)
            r = isSubtree(root->right,subRoot);
        
        return l||r;
    }
};