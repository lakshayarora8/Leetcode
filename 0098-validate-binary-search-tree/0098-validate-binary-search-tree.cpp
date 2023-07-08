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
    bool ans=true;
public:
    void helper(TreeNode * root,long &temp)
    {
        if(root == NULL) 
            return;
        
        helper(root->left,temp);
         if(temp >= root->val)
                {
                    ans=false;
                    return;
                }
        else
            temp=root->val;
        helper(root->right,temp);
        
        
    }
    bool isValidBST(TreeNode* root) {
        
        long temp=LONG_MIN;
        helper(root,temp);
        return ans;
    }
};