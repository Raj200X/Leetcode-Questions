class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long product = 0;
        vector<int> arr(2, 0); 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        int cnt = 0;
        arr[0] = nums[nums.size()-1];
        arr[1] = nums[nums.size()-2];
        product = 1LL * arr[0] * arr[1] * 100000;
        return product; 
    }
};