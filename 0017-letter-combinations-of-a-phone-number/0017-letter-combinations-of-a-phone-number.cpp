class Solution {
public:

    void solve(int ind, vector<string>&ans, string&ds, string digits, string mapping[]){
        if(ind>=digits.size()){
            ans.push_back(ds);
            return;
        }
        else{
            int num = digits[ind]-'0';
            string hold = mapping[num];
            for(int i=0; i<hold.size(); i++){
                ds.push_back(hold[i]);
                solve(ind+1, ans, ds, digits, mapping);
                ds.pop_back();
            }
            return;
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string ds="";
        int index=0;
        string mapping[10]={"", "", "abc", "def","ghi","jkl", "mno","pqrs","tuv", "wxyz"};
        solve(index, ans, ds, digits, mapping);
        return ans;
    }
};