class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int low=0,mid;
        int high=arr.size()-1;
        
        while( low <= high)
        {
             mid= (high-low)/2 + low;
            
            if( arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                break;
            else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])
                high=mid-1;
            else
                low=mid+1;
        }
        
        return mid;
        
    }
};