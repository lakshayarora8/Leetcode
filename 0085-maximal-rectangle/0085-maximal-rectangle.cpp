class Solution {

     vector<int> nextSmaller(vector<int>& arr, int n) {
        vector<int> ans(n, n);  // Initialize with n, because next of last element is considered as n (out of bounds)
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (!stk.empty() && arr[stk.top()] >= curr) stk.pop();
            if (!stk.empty()) ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr, int n) {
        vector<int> ans(n, -1);  // Initialize with -1, because there is no smaller element to the left of the first element
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (!stk.empty() && arr[stk.top()] >= curr) stk.pop();
            if (!stk.empty()) ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            int newArea = height * width;
            area = max(area, newArea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int>histogram(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            // To create histogram array
            for(int j=0;j<histogram.size();j++){
                if(matrix[i][j]=='1')histogram[j]++;
                else{
                    histogram[j]=0;
                }
            }
            maxi = max(maxi,largestRectangleArea(histogram));
        }
        return maxi;
    }
};