class Solution {
public:

    bool solve(string &s, int start,unordered_set<string>&st,vector<int>&dp ){
        if(start == s.size()){;
            return true;
        }
        if (dp[start] != -1)
            return dp[start];
        string current ="";
        for(int i=start ; i<s.size(); i++){
            current.push_back(s[i]);
            if (st.count(current)){
                if (solve(s,i+1,st,dp)){
                    dp[start]=1;
                    return true;
                }
            }
            
        }
        dp[start]=0;
        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int>dp (s.size(),-1);
        
        return solve(s,0,st,dp);
        
    }
};