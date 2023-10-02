class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int alice=0,bob=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++)
        {
            if(colors[i] == 'A' && colors[i-1]== 'A' && colors[i+1]== 'A')
                alice++;
            else if (colors[i] == 'B' && colors[i-1]== 'B' && colors[i+1]== 'B')
                bob++;
        }
        if( alice == 0) return false;
        while(alice!=0 && bob!=0)
        {
            alice--;
            bob--;
            if(alice <= 0 ) return false;
        }
        
        return true;
        
    }
};