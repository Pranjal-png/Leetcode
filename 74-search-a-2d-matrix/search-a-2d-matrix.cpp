class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = matrix[0].size() -1;
        int high = 0;
        while(low>=0 && high<=matrix.size() -1){
            if(matrix[high][low]==target){
                return true;
            }
            else if(matrix[high][low]>target){
                low--;
            }
            else{
                high++;
            }
        }
        return false;
        
    }
};