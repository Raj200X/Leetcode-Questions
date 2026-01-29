class Solution {
public:
    bool isPal(string &s, int l, int h) {
        while (l < h) {
            if (s[l] != s[h]) return false;
            l++; h--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, h = s.size() - 1;

        while (l < h) {
            if (s[l] != s[h]) {
                return isPal(s, l + 1, h) || isPal(s, l, h - 1);
            }
            l++; h--;
        }
        return true;
    }
};
