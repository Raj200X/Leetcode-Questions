class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> idx;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (!idx.empty()) {
                    if (i - idx.back() - 1 < k)
                        return false;
                }
                idx.push_back(i);
            }
        }
        return true;
    }
};
