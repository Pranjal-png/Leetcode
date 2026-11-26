class Solution {
public:

    bool checkdiff(string a , string b){
        int diff =0;
        for(int i=0 ; i<a.size() ; i++){
            if(a[i]!=b[i]){
                diff++;
            }
        }
        if(diff==1){
            return true;
        }
        else{
            return false;
        }
        
    }

    int bfs( string start , string endWord , unordered_set<string>&vis , vector<string>&wordList){
        int ans =1;
        queue<string>que;
        que.push(start);
        vis.insert(start);
        while(!que.empty()){
            int size = que.size();
            
            for(int i=0 ; i<size ;i++){
                string node = que.front();
                que.pop();
                for(auto neighbour: wordList){
                if(checkdiff(neighbour,node)){
                    if(vis.find(neighbour)==vis.end()){
                        if(neighbour == endWord){
                        return ans+=1;
                    }
                        que.push(neighbour);
                        vis.insert(neighbour);
   
                    }
                    
                }
            }
       

            }
                 ans+=1;
            
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(find(wordList.begin() , wordList.end() , endWord)==wordList.end()){
            return 0;
        }
        
        unordered_set<string>vis;
        return bfs(beginWord , endWord , vis , wordList);
    }
};