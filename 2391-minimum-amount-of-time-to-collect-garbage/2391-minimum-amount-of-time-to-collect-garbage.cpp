class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int glass=0,metal=0,paper=0;
        int g=0,m=0,p=0;
        int n=garbage.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<garbage[i].size();j++)
            {
                if(garbage[i][j] == 'G')
                {
                    glass++;
                    g=max(g,i);
                }
                 if(garbage[i][j] == 'P')
                 {
                    p=max(p,i);
                    paper++;
                 }
                 if(garbage[i][j] == 'M')
                 {
                    metal++;
                    m=max(m,i);
                 }
            
            }
        }
        int sum=0;
        for(int i=0;i<g;i++)
        {
            sum+=travel[i];
        }
         for(int i=0;i<p;i++)
        {
            sum+=travel[i];
        }
         for(int i=0;i<m;i++)
        {
            sum+=travel[i];
        }
        sum+=glass+paper+metal;
        
        return sum;
        
    }
};