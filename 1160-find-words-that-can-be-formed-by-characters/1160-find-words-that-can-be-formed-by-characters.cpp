class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<int,int> mp,temp;
        int sum=0;
        for(auto it: chars)
        {
            mp[it]++;
        }
        
        for(int i=0;i<words.size();i++)
        {
            temp=mp;
            int n=words[i].size();
            for(int j=0;j<n;j++)
            {
                if(temp[words[i][j]] == 0)
                    break;
                else
                temp[words[i][j]]--;
                if( j== n-1)
                    sum+=n;
            }
        }
        
        return sum;
        
    }
};