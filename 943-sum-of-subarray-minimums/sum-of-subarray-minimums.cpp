class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        const int mod = 1000000007;
        vector<int>prev(arr.size());
        vector<int>next(arr.size());
        long long ans = 0;
        for(int i=0 ; i<arr.size() ; i++){
            while(! st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else {
                prev[i] = st.top();
            }
            st.push(i);   
        }
        while(!st.empty()){
            st.pop();
        }
        for(int j=arr.size()-1; j>=0 ; j--){
            while(!st.empty() && arr[st.top()]>arr[j]){
                st.pop();
            }
            if(st.empty()){
                next[j]=arr.size();
            }
            else{
                next[j] = st.top();
            }
            st.push(j);
        }
        for(int i=0 ; i<arr.size() ; i++){
            int left = i - prev[i];
            int right = next[i] - i;
            long long c = (1LL*arr[i]*left*right)%mod;
            ans = (ans + c)%mod;
        }
        return ans;
    }
};