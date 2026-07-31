class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int prefixsum=0;
        int need=0;
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            prefixsum+=nums[i];
            need = prefixsum - goal;
            if(mpp.find(need)!=mpp.end()){
                ans+=mpp[need];
                
            }
            mpp[prefixsum]++;
        }
        return ans;
        
    }
};