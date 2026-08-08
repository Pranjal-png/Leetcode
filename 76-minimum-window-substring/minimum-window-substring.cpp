class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())
            return "";
        unordered_map<char,int>need;
        for(int k=0 ; k<t.size(); k++){
            need[t[k]]++;
        }
        
        unordered_map<char,int>window;
        int i=0;
        int j=0;
        int start =0;
        int minlen = INT_MAX;
        int required= t.size();
        int formed = 0;
        while(j<s.size()){
            window[s[j]]++;
            if(need.count(s[j]) && window[s[j]]<=need[s[j]]){
                formed++;
            }
            j++;

            while(formed == required){
                if(j-i<minlen){
                    start = i;
                    minlen = j-i;}
                if(need.count(s[i]) && window[s[i]]<=need[s[i]]){
                    formed--;
                }
                window[s[i]]--;
                
                i++;
            }
        }
        if(minlen == INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
        
    }
};