class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map<int, pair<int,int >> mp;
        unordered_map<int,int> row,col;
        int rows= mat.size();
        int cols =mat[0].size();
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                mp[ mat[i][j] ]= {i,j};
            }
        }
        
        for( int i=0;i< arr.size(); i++)
        {
            int value= arr[i];
            int r= mp[ value ].first;
            int c= mp[ value ].second;
            
            row[r]++;
            col[c]++;
            
            if(row[r]==cols || col[c]== rows)
                return i;
        }
        
        return -1;
        
    }
};