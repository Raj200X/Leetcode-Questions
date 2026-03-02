class Solution {
public:
    int solve(int n){
        int sum = 0;
        if (n<10){
            return n;
        }
        while (n>0){
            int digit = n%10;
            sum+=digit;
            n = n/10;
        }
        return solve(sum);
    }
    int addDigits(int num) {
        return solve(num);
    }
};