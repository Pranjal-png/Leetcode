class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n;
       
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxRow = 0;
            for(int i =0; i <m ; i++){
                if (mat[i][mid]>mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int leftval = (mid-1 >= 0)? mat[maxRow][mid-1] : -1;
            int rightval = (mid+1 < n)? mat[maxRow][mid+1] : -1;

            if(mat[maxRow][mid]>leftval && mat[maxRow][mid]>rightval){
                return {maxRow,mid};
            }
            else if(mat[maxRow][mid]<leftval){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return {-1,-1};
    }
};