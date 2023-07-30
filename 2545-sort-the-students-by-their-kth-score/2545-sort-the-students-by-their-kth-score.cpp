class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        int m=score.size();
        
        int max_index;
        
        for(int i=0; i<m-1; i++)
        {
            max_index=i;
            for(int j=i+1; j<m; j++)
            {
                if( score[j][k] > score[max_index][k])
                {
                    max_index=j;
                }
            }
            if( max_index!=i)
            score[i].swap(score[max_index]);
        }
        
        return score;
    }
};