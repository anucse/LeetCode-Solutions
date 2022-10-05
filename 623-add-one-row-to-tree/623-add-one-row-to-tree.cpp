
class Solution {
public:
    void solve(TreeNode* root,int val,int depth,int curr){
        if(!root)
            return ;
        if(curr+1==depth){
            
            TreeNode* tempLeft=new TreeNode(val);
            TreeNode* tempRight=new TreeNode(val);
            
            tempLeft->left=root->left;
            tempRight->right=root->right;
            
            root->left=tempLeft;
            root->right=tempRight;
            
        }
        
        else{
            solve(root->left,val,depth,curr+1);
            solve(root->right,val,depth,curr+1);
        }
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        int curr=1;
        
        if(curr==depth){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        
        solve(root,val,depth,curr);
        return root;
    }
};

























