class Solution {
public:

    void count(int n , string & temp , vector<string>&ans , int right , int left){
        if(temp.length()==2*n){
            ans.push_back(temp);
            return;
        
        }
        if(right<n){
            temp.push_back('(');
            right++;
            count(n,temp,ans,right,left);
            temp.pop_back();
            right--;
        }
        
        if(right>left){
            temp.push_back(')');
            left++;
            count(n,temp,ans,right,left);
            temp.pop_back();
            left--;
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        int left =0;
        int right =0;
        count(n,temp,ans,right,left);
        return ans;
        
    }
};