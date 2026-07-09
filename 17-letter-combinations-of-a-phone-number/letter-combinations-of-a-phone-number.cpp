class Solution {
public:

    void solve(vector<string>&preans , vector<string> &ans , string pans, int i){
    
        if(i==preans.size()){
             ans.push_back(pans);
             return;
            }
        
        

        for(int j=0; j<preans[i].size() ; j++){
            pans.push_back(preans[i][j]);
            solve(preans,ans,pans,i+1);
            pans.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string>keypad = {
            "",//0
            "",//1
            "abc",//2
            "def",//3
            "ghi",//4
            "jkl",//5
            "mno",//6
            "pqrs",//7
            "tuv",//8
            "wxyz",//9
        };
        vector<string>ans;
        vector<string>preans;
        string pans;
        for(int i=0;i<digits.size();i++){
            preans.push_back(keypad[digits[i]-'0']);
        }
    
        solve(preans,ans,pans,0);
        return ans;

    }
};