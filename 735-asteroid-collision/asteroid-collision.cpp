class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int> ans;
        for(int i=0 ; i<asteroids.size() ; i++){
            bool alive = true;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(st.top()>(-asteroids[i])){
                    alive = false;
                    break;}
                else if(st.top()<(-asteroids[i])){
                    st.pop();
                }
                else{
                    st.pop();
                    alive = false;
                    break;
                }
            }
            if(alive){
                st.push(asteroids[i]);
            }}
        while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};