class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            nums[i]= nums[i]%2;
        }
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int prefixsum = 0;
        int need = 0;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            prefixsum+=nums[i];
            need = prefixsum - k;
            if(mpp.find(need)!=mpp.end()){
                ans+=mpp[need];
            }
            mpp[prefixsum]++;
        }
        return ans;
    }
};