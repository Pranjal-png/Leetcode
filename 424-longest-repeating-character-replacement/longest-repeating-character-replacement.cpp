class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans =0;
        unordered_map<char,int>mpp;
        while(i<=j &&j<n){
            mpp[s[j]]++;
            int maxi=0;
            for(auto it:mpp){
                maxi = max(maxi,it.second);
                
            }
           
            int wl = j-i+1;
        
            
                while(wl-maxi>k){
                    mpp[s[i]]--;
                    i++;
                    maxi = 0;
                    for (auto it : mpp) {
                    maxi = max(maxi, it.second);
                    
                } 
                wl = j-i+1;
            }
            ans = max(ans,j-i+1);
            j++;
            
        
        
        }
        return ans;
    }
};