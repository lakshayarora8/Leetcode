//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> start,end;
        
        vector<int>  prefix(n,0);
        prefix[0]=A[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+A[i];
        }
        for(int i=0;i<n;i++)
        {
            if(!start[prefix[i]])
            start[prefix[i]]=i+1;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(!end[prefix[i]])
            end[prefix[i]]=i+1;
        }
        
        int ans=0;
        
        for(auto it:prefix)
        {
            if( start[it] && end[it])
            ans= max(ans, end[it]-start[it]);
        }
        ans=max(ans,end[0]);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends