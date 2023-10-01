class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=0, n=s.length(); 
        while(j < n){
            if(s[j+1]==' ' || j==n-1){ 
                int k = j;
                while(k>=i)
                    swap(s[k--], s[i++]); 
                j++;
                i = j+1; 
            }
            j++;
        }
        return s;
    }
};