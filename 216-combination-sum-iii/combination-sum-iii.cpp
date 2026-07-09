class Solution {
public:

    void solve(int start,vector<vector<int>>& ans , vector<int>preans,int total , int k , int n){
        
        if(preans.size()==k){
            if(total == n){
                ans.push_back(preans);
            }
            return;
        }
        if (preans.size() > k)
            return;

        if (total > n)
            return;
       
        for(int j=start;j<=9;j++){
            preans.push_back(j);
            solve(j+1,ans,preans,total+j,k,n);
            preans.pop_back();
            }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>preans;
        solve(1,ans,preans,0,k,n);
        return ans;
        
    }
};