class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);
        while (left<=right){
            long long sum = 1LL * left * left + right*right;
            if (sum==c){
                return true;
            }
            else if (sum>c){
                right--;
            }
            else{
                left++;
            }
        }
        return false;
    }
};