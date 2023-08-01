class Solution {
public:
    
    vector< vector<int>> ans;

    void helper(int i,int n,int k,int counter,vector<int> &combo)
    {
        
        if(counter == k)
        {
            ans.push_back(combo);
            counter=0;
            return;
        }
        if(i == n+1) return ;
        
        combo.push_back(i);
        helper(i+1,n,k,counter+1,combo);
        combo.pop_back();
        helper(i+1,n,k,counter,combo);
    
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> combo;
        int counter=0;
        helper(1,n,k,counter,combo);
        
        return ans;
        
        
    }
};