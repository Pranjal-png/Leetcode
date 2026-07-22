class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        long long smax=0;
        long long smin=0;
        vector<int>prev(n);
        vector<int>next(n);
        vector<int>mnext(n);
        vector<int>mprev(n);
        stack<int>st;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
        st.pop();}
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        for(int i=0 ; i<n ; i++){
            int left = i - prev[i];
            int right = next[i] - i;
            long long c = 1LL*nums[i]*left*right;
            smin = smin + c;
        }

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                mprev[i]=-1;
            }
            else{
                mprev[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
        st.pop();}
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                mnext[i]=n;
            }
            else{
                mnext[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0 ; i<n ; i++){
            int left = i - mprev[i];
            int right = mnext[i] - i;
            long long c = 1LL*nums[i]*left*right;
            smax = smax + c;
        }

        ans = ans + smax - smin;
        return ans;
    
    }
};