class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int row=-1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]<=target)
                row=i;
        }
        if(row==-1)
            return false;
        
        for(int j=0;j<n;j++)
        {
            if(matrix[row][j]==target)
                return true;
        }
        
        return false;
    }
};