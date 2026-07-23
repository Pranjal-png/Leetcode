class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans =0;
        vector<int>prev(n);
        vector<int>next(n);
        stack<int>st;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
            st.pop();
        }

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i] = st.top();
            }
            st.push(i);
        }
        for(int i=0 ; i<n ; i++){
            int width = next[i]-prev[i]-1;
            int height = heights[i];
            int preans = width*height;
            ans = max(ans,preans);
        }
        return ans;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int>heights(matrix[0].size(),0);
        int marea =0 ;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j] =0;
                }
            }
            int carea = largestRectangleArea(heights);
            marea = max(carea,marea);
        }
        return marea;
        
    }
};