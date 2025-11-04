class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            priority_queue<pair<int, int>> pq;
            for (auto &p : freq) {
                pq.push({p.second, p.first});
            }
            int sum = 0;
            int count = 0;
            while (!pq.empty() && count < x) {
                auto top = pq.top(); pq.pop();
                sum += top.first * top.second;
                count++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
