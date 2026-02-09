class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0;i<matrix.size();i++){
            int j = matrix[i].size()-1;
            if (target<=matrix[i][j] && matrix[i][0]<=target){
                int low = 0;
                int high = matrix[i].size()-1;;
                while (low<=high){
                    int mid = low + (high-low)/2;
                    if (matrix[i][mid]==target){
                        return true;
                    }
                    else if (matrix[i][mid]>target){
                        high = mid-1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
