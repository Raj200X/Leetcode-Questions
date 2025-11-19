class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        set<int> s;
        for (int x : nums) {
            s.insert(x);
        }
        while (s.count(org)) {
            org = 2 * org;
        }
        return org;
    }
};