
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";

        helper(root,ans,s);
        return ans;

    }

    void helper(TreeNode *root, vector<string> &ans,string s)
    {
        if(root == NULL)
        return ;
        s+=to_string(root->val);

        if(!root->left && !root->right)
        {
            ans.push_back(s);
        }

        helper(root->left, ans,s+ "->");
        helper(root->right, ans,s+ "->");

        
        
    }
};