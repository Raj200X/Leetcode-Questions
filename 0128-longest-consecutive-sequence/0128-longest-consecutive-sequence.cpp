class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return 0;
        }
        set<int> st;
        for (auto x : nums) {
            st.insert(x);
        }
        int count = 1;
        nums.clear();
        for (auto& x : st) {
            nums.push_back(x);
        }
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i - 1]) > 1) {
                count = 1;
            } else {
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};