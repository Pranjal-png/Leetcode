class Solution {
public:

    void solve(vector<int>&candidates , int target , int i , int total , vector<vector<int>>& ans , vector<int> &preans){

        if(total >target){
            return;
        }
        if(i == candidates.size()){
            return;
        }
        if(total == target){
                ans.push_back(preans);
                return ;
            }
        total += candidates[i];
        preans.push_back(candidates[i]);
        solve(candidates,target,i,total,ans,preans);
        preans.pop_back();
        total -= candidates[i];
        solve(candidates,target,i+1,total,ans,preans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int i=0;
        vector<int>preans;
        
        solve(candidates , target , 0 , 0 , ans , preans);
        return ans;
        
    }
};