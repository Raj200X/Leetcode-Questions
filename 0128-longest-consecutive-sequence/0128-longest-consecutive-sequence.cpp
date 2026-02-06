class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_set<int> st;
        for (auto x : nums) {
            st.insert(x);
        }
            int ans = 0;
        for (auto x : st) {


        if (!st.count(x - 1)) {

            int curr = x;
            int count = 1;

            while (st.count(curr + 1)) {
                curr++;
                count++;
            }

            ans = max(ans, count);
        }
    }
        
        return ans;
    }
    
};