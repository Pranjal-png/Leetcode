class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        int freq1[26] = {0};
        int n = s.size();
        for(int i=0 ; i<n ; i++){
            freq[s[i]-'a']++;
        }
        for(int j=0 ; j<t.size();j++){
            freq1[t[j]-'a']++;
        }
        bool ans = true;
        for(int i=0 ; i<26 ; i++){
            if(freq[i]!=freq1[i]){
                ans = false;
            }
        
        }

        return ans;
    }
};