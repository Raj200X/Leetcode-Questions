class Solution {
public:
    int mySqrt(int x) {
        vector <int> arr;
        for (int i = 0;i<=46340;i++){
            arr.push_back(i*i);
        }
        int l = 0;
        int h = arr.size()-1;
        while (l<=h){
            int mid = l + (h-l)/2;
            if (arr[mid]>x){
                h = mid-1;
            }
            else if (arr[mid]<x){
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        return h;
    }
};