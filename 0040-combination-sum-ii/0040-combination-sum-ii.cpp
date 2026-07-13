class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int i, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        if (i >= candidates.size()) {
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, temp);
        temp.pop_back();
        int next = i + 1;
        while (next < candidates.size() && candidates[next] == candidates[i])
            next++;
        solve(candidates, target, next, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return ans;
    }
};