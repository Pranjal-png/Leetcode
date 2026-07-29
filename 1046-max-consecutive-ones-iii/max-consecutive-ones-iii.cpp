class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans =0;
        int m=k;
        int n = nums.size();
        
        while(i<=j && j<n){
           
            if(nums[j]==0 ){
                m--;
            }
            while (m < 0) {
                if (nums[i] == 0)
                m++;
                i++;
} 
            ans = max(ans,j-i+1);
            j++;
                     
        }
        return ans;
    }
};