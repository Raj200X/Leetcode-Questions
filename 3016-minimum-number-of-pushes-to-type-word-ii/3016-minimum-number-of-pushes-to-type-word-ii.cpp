class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); i++) {
            freq[word[i] - 'a']++;
        }
        int cnt = 0;
        for (auto p : freq) {
            if (p != 0) {
                cnt++;
            }
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }
        int pop = 0;
        int ans = 0;
        while (!pq.empty()) {
            if (pop < 8) {
                ans = ans + (1 * pq.top());
            } else if (pop >= 8 && pop < 16) {
                ans = ans + (2 * pq.top());
            } else if (pop < 24) {
                ans = ans + (3 * pq.top());
            } else {
                ans = ans + (4 * pq.top());
            }
            pq.pop();
            pop++;
        }
        return ans;
    }
};