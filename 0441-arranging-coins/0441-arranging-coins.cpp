class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0;
        long h = n;
        while (l<=h){
            long mid = (l+h)/2;
            long ans = mid*(mid+1)/2;
            if (ans==n){
                return (int)mid;
            }
            else if (ans>n){
                h = mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return (int)l-1;
    }
};