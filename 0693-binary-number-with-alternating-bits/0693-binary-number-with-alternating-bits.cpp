class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bin;

        while (n != 0) {
            bin.push_back(n % 2 + '0');
            n = n / 2;
        }

        reverse(bin.begin(), bin.end());

        for (int i = 1; i < bin.size(); i++) {
            if (bin[i] == bin[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
