class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int num = 0;
            int x = i;

            while (x) {
                if (x & 1) num++;
                x = x >> 1;
            }

            ans[i] = num;
        }
        return ans;
    }
};
