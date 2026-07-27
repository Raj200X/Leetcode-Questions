class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> st;
        for (auto num : nums1) {
            st.insert(num);
        }
        unordered_set<int> s2;
        for (auto num : nums2) {
            s2.insert(num);
        }
        for (auto it = st.begin(); it != st.end(); ++it) {
            if (!s2.count(*it)){
                ans[0].push_back(*it);
            }
        }
        for (auto it = s2.begin(); it != s2.end(); ++it) {
            if (!st.count(*it)){
                ans[1].push_back(*it);
            }
        }
        return ans;
    }
};