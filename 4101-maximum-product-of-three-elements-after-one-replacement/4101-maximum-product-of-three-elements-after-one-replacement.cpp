class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1 = 0, max2 = 0;
        for (int n : nums) {
            n = abs(n);
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }
        }
        return 1LL * max1 * max2 * 100000;
    }
};
