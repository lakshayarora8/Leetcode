class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n=words.size();
        unordered_map<char,int> mp[n];
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                mp[i][words[i][j]]++;
            }
        }
        for(auto it: mp[0])
        {   
        int mini= it.second;
            for(int i=1;i<n;i++)
            {
                mini=min(mini , mp[i][it.first]);
            }
            
            while(mini>0)
            {
                ans.push_back(string(1,it.first));
                mini--;
            }
            
        }
        return ans;
        
        
    }
};