class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ans = false;
        int n = bits.size();

        for (int i = 0; i < n;) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                if (i == n - 1)
                    ans = true;
                i++;
            }
        }
        return ans;
    }
};
