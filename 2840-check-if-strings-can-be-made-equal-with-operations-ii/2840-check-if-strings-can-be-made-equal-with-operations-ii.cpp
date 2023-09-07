class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        map<char,int> mp1,mp2,mp3,mp4;
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                mp2[s1[i]]++;
                mp4[s2[i]]++;
            }
            else
            {
                mp1[s1[i]]++;
                mp3[s2[i]]++;
            }  
        }
        
        for( auto it:mp1)
        {
            if( mp3[it.first] != it.second)
                return false;
        }
        
        for( auto it:mp2)
        {
            if( mp4[it.first] != it.second)
                return false;
        }
        
     
        
        return true;
        
        
        
    }
};