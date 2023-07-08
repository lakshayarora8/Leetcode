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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root ==NULL) 
            return new TreeNode(val);
        TreeNode* node=new TreeNode(val);
        TreeNode *temp=root,*temp2;
        while(root!=NULL)
        {
            temp2=root;
            root= root->val > val? root->left:root->right;
        }
        if(temp2->val > val)
            temp2->left=node;
        else
            temp2->right=node;
        return temp;
        
    }
};