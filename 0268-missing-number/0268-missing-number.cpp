class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correct = nums[i];
            if (nums[i] < nums.size() && nums[correct] != nums[i]) {
                swap(nums[correct], nums[i]);
            } else {
                i++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};