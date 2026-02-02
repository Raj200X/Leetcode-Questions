class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
         int low = 0;
        int high = arr.size()-1;
        int mid = low + (high - low) / 2;
        while(low<=high){
            mid = low + (high - low) / 2;
            if (target>arr[mid]){
                low = mid+1;
            }
            else if (target<arr[mid]){
                high = mid-1;
            }
            else{
                return mid;
            }
            
            
        }
        return low;
    }
};