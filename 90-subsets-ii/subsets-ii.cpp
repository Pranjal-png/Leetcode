class Solution {
public:

    void solve(vector<int>&nums ,int i , vector<vector<int>>&ans,vector<int>preans){
        if(i==nums.size()){
            ans.push_back(preans);
            return;
        }
        preans.push_back(nums[i]);
        solve(nums,i+1,ans,preans);
        preans.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
            
        solve(nums,i+1,ans,preans);

        }
        
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>preans;
        solve(nums,0,ans,preans);
        return ans;
        
    }
};