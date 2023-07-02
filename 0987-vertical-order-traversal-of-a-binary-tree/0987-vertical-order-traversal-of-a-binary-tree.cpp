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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> node;
        vector<vector<int>> ans;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int x=p.second.first,y=p.second.second;
            node[x][y].insert(temp->val);
            
            if(temp->left)
                q.push({temp->left,{x-1,y+1}});
            if(temp->right)
                q.push({temp->right,{x+1,y+1}});
            
        }
        for(auto it:node)
        {
            vector<int> col;
            for(auto x: it.second)
            {
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(col);
            
        }
        
        return ans;
        
        
    }
};