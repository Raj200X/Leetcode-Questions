class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        int h = k - 1;
        int max_sum = INT_MIN;
        vector<int> prefix_sum(nums.size(), 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        while (h < nums.size()) {
            if (l>0) {
                int sum = prefix_sum[h] - prefix_sum[l - 1];
                max_sum = max(max_sum, sum);
                l++;
                h++;
            }
            else{
                int sum = prefix_sum[h];

            max_sum = max(max_sum, sum);
            l++;
            h++;
            }
            
        }
        double ans = (double)max_sum / k;
        return ans;
    }
};