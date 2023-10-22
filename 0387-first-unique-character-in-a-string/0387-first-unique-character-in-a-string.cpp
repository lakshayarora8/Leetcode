class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> mp;
        
        int index=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            
            if( mp[s[index]] >1)
            {
                index++;
                while( index< n && mp[s[index]] >1)
                    index++;
            }
            
            if( index == n) return -1;
        }
        
        return index;
    }
};