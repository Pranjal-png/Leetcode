class Solution {
public:

    bool Ispalindrome(string sub){
        string m = sub;
        reverse(sub.begin(),sub.end());
        if(m==sub){
            return true;
        }
        return false;
    }

    void solve(vector<vector<string>>&ans,vector<string>&current, string& s, int start ){
        if(start == s.size()){
            ans.push_back(current);
            return;
        }
        for(int i=start ; i<s.size();i++){
            string part=(s.substr(start,i-start+1));
            if (Ispalindrome(part)){
                    current.push_back(part);
                    solve(ans, current,s,i+1);
                    current.pop_back();
                }
                

            }
        }

    

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>current;
        solve(ans , current,s ,0);
        return ans;
        
    }
};