class Solution {
public:
    int totalMoney(int n) {
        
        int counter=1,sum=0,count;
        for(int i=1;i<=n;i++)
        {
            if( i%7 == 1)
            count=counter++;
            sum+=count;
            count++;
        }
        
        return sum;
        
    }
};