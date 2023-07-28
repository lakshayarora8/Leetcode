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
    
    private: 
        
    int depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=depth(root->left);
        int right= depth(root->right);
        
        return 1+ max(left,right); 
    }
    int sumfinder(TreeNode *root,int gehrayi,int depth)
    {
        if(root == NULL)
            return 0;
        if(depth == gehrayi) return root->val;
        
        return sumfinder(root->left,gehrayi,depth+1) +sumfinder(root->right,gehrayi,depth+1);
        
        
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        
       int gehrayi = depth(root);
        int sum=0;
        int ans= sumfinder(root,gehrayi,1);
        
        return ans;
    }
};