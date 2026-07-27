class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for (auto it = st.begin(); it != st.end(); ++it) {
            if (!s2.count(*it)) {
                ans[0].push_back(*it);
            }
        }
        for (auto it = s2.begin(); it != s2.end(); ++it) {
            if (!st.count(*it)) {
                ans[1].push_back(*it);
            }
        }
        return ans;
    }
};