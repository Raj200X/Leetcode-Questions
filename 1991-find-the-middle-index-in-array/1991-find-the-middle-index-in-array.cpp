class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
       int n = nums.size();
        vector<int> ps(n);

        ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        int total = ps[n - 1];

        for (int i = 0; i < n; i++) {
            int leftSum = (i == 0) ? 0 : ps[i - 1];
            int rightSum = total - ps[i];

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
    
};