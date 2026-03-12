class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<vector<int>>& ans){
        int n = nums.size();
        if (idx>=n){
            ans.push_back(nums);
            return;
        }
        for (int j = idx;j<n;j++){
            swap(nums[idx],nums[j]);
            solve(nums,idx+1,ans);
            swap(nums[idx],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx = 0;
        solve(nums,idx,ans);
        return ans;
    }
};