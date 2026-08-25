class Solution {
public:

    void dfs(int Node , vector<vector<int>>&adj , vector<int>&vis){
        
        vis[Node] = 1;
       
        for(int Neighbour : adj[Node]){
            if(!vis[Neighbour]){
                
                dfs(Neighbour , adj , vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected[0].size());
        for(int i=0 ; i<isConnected.size(); i++){
            for(int j=0 ; j<isConnected.size(); j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    }
                }
            }
            int ans = 0;
            vector<int>vis(isConnected[0].size(),0);
            for(int i=0 ; i<isConnected[0].size() ; i++){
                if(!vis[i]){
                    ans++;
                    dfs(i , adj , vis);
                }
            }
            return ans;
        
    }
};