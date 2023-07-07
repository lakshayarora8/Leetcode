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
     int left_height(TreeNode* node)
    {
        int ht=0;
        while(node)
        {
            node=node->left;
            ht++;
        }
        return ht;
    }
    int right_height(TreeNode* node)
    {
        int ht=0;
        while(node)
        {
            node=node->right;
            ht++;
        }
        return ht;
    }
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int lh=left_height(root);
        int rh=right_height(root);
        
        if(lh == rh)
            return {(1<<lh)-1};
        else
        return 1+ countNodes(root->left) + countNodes(root->right);
        
    }
    
   
};