class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& m) {
        int val = 0;
        vector<bool> res(m.size(), false);
        for (int i = 0; i < m.size(); i++) {
            val = (2 * val + m[i]) % 5;
            if (val == 0)
                res[i] = true;
        }
        return res;
    }
};