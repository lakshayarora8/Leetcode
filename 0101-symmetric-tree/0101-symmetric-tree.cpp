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
    bool isSymmetric(TreeNode* root) {
        
        if(root ==NULL) return true; 
        vector<int> a;
        vector<int> b;
        
        preorder1(root,a);
        preorder2(root,b);
        
        return (a==b);
    }
    
    void preorder1(TreeNode* root,vector<int> &a)
    {
        if(root == NULL)
        {
            a.push_back(INT_MIN);
            return;
        }
        a.push_back(root->val);
        preorder1(root->left,a);
        preorder1(root->right,a);      
    }
     void preorder2(TreeNode* root,vector<int> &b)
    {
        if(root == NULL)
        {
            b.push_back(INT_MIN);
            return;
        }
        b.push_back(root->val);
        preorder2(root->right,b);      
        preorder2(root->left,b);
 
    }
    
};