class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0;
        int j =0;
        int n = s.size();
        unordered_map<char,int>mpp;
        int ans =0 ;
        while(i<=j && j<n){
            mpp[s[j]]++;
            while(mpp.size()==3){
                ans+= n-j;
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};