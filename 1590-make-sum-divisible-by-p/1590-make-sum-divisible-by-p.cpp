class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums)
            total += x;

        int need = total % p;
        if (need == 0)
            return 0;

        unordered_map<int, int> seen;
        seen[0] = -1;

        long long pref = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            pref = (pref + nums[i]) % p;

            int wanted = (pref - need + p) % p;

            if (seen.count(wanted))
                ans = min(ans, i - seen[wanted]);

            seen[pref] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
