class Solution {
public:
    vector<int>vis;
    vector<int>pathvis;
    bool dfs(vector<vector<int>>&adj , int start){
        vis[start]=1;
        pathvis[start]=1;
        for(auto neighbour: adj[start]){
            if(!vis[neighbour]){
                if(dfs(adj,neighbour)){
                    return true;
                }
            }
            else if(pathvis[neighbour]==1){
                return true;
            }

        }
        pathvis[start]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vis.assign(numCourses,0);
        pathvis.assign(numCourses,0);

        for(auto prereq :prerequisites){
            adj[prereq[1]].push_back(prereq[0]);
        }

        for(int i=0 ; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(adj,i)){
                    return false;
                }
            }
        }
        return true;
        
    }
};