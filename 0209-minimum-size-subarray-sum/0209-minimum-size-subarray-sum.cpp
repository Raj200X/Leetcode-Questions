class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int l = 0;
        int h = 0;
        int sum = 0;
        while(h<nums.size()){
            sum = sum + nums[h];
            while (sum >= target) {
                min_len = min(min_len, h - l + 1);
                sum -= nums[l];
                l++;
            }
            h++;
        }
       return  min_len==INT_MAX ? 0 : min_len;
    }
};