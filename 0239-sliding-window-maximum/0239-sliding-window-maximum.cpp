class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        deque<int> l;   //list<int> l;
        vector<int> ans;
        while(j<nums.size()){
            while(!l.empty() && l.back()<nums[j]){
                    l.pop_back();
                }
            l.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(l.front());
                if(!l.empty() && l.front()==nums[i]){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};