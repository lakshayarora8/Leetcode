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
    private:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> parent;
        markparents(root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target]=true;
        
        int distance=0;
        while(!q.empty())
        {
            if(distance == k) break;

            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node]  && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            distance++;
            
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        
    }
};