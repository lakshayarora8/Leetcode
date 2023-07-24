class Solution {
public:
    int nthUglyNumber(int n) {
        
        int index1=0,index2=0,index3=0;
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            int nthugly= min({ ans[index1] *2 , ans[index2] *3 , ans[index3]*5});
            ans[i]=nthugly;
            
            if( ans[index1] *2 == nthugly) index1++;
            if( ans[index2] *3 == nthugly) index2++;
            if( ans[index3] *5 == nthugly) index3++;
        }
        
        return ans[n-1];
        
    }
};