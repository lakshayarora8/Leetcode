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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right)
            return 0;
        int sum=0;
      helper(root,sum,1);
        return sum;
    }
    
    void helper(TreeNode*root, int &sum,int flag)
    {
          if(root == NULL) 
            return ;
        if(!root->left && !root->right && flag==1)
            sum+=root->val;
        helper(root->left,sum,1);
        helper(root->right,sum,0);
    }
};