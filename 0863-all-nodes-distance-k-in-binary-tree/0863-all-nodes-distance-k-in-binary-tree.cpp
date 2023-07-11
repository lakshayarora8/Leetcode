/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node ->left) {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node ->right) {
                parent[node->right]=node;
                q.push(node->right);
            }
            
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        if(root == NULL)
            return ans;
        unordered_map<TreeNode*,TreeNode*> parent; 
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        markparent(root,parent);
        q.push(target);
        visited[target]=true;
        int cnt=0;
        while(!q.empty())
        {
            if(cnt == k)
                break;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }   
            }
                        cnt++;

             
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
        
        
    }
};