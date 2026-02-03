class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size()-1;
        while (l<=h){
            int mid = (l+h)/2;
            if (arr[mid]==target){
                return mid;
            }
            
            else if (arr[l]<=arr[mid]){
                if (target<arr[mid] && target>=arr[l]){
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else if (arr[l]>arr[mid]){
                if (target>arr[mid] && target<=arr[h] ){
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};