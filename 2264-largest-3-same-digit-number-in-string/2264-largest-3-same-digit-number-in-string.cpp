class Solution {
public:
    string largestGoodInteger(string num) {
        
        string ans="";
        int max=INT_MIN;
        int n=num.size();
        for(int i=0;i<n-2;i++)
        {
            int temp=int(num[i]);
            if( num[i] == num[i+1] && num[i]== num[i+2] && temp>max)
            {
                max=temp;
                ans="";
                ans += num[i];
                ans += num[i];
                ans += num[i];         
            }  
        }    
        return ans;
        
    }
};