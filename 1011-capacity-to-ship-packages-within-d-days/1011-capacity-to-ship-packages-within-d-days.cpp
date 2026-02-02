class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int cap) {
        int curr = 0;
        int d = 1;

        for (int w : weights) {
            if (curr + w > cap) {
                d++;
                curr = 0;
            }
            curr += w;
        }
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 0;

        for (int w : weights) {
            l = max(l, w);
            h += w;
        }

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isPossible(weights, days, mid)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
