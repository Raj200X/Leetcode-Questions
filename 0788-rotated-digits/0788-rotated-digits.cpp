class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int temp = i;
            bool valid = true;
            bool changed = false;

            while (temp > 0) {
                int d = temp % 10;

                if (d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }

                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    changed = true;
                }

                temp /= 10;
            }

            if (valid && changed) ans++;
        }

        return ans;
    }
};