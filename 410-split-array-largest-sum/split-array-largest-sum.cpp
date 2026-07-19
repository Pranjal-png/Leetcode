class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right =0;
        if(k>n){
            return -1;
        }
        int ans =-1;
        for(int i=0;i<n;i++){
            if(nums[i]>left){
                left = nums[i];
                }
                right +=nums[i];
            }
            
        while(left<=right){
           
            int mid = left + (right-left)/2;
            int subarray =1;
            int count =0;
            for(int i=0;i<n;i++){
                if(count + nums[i]<=mid){
                    count+=nums[i];
                }
                else{
                    subarray ++;
                    count = nums[i];
                }
            }
            if(subarray<=k){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
        
    }
};