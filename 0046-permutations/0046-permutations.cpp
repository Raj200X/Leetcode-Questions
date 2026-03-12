class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<vector<int>>& ans,vector<int>res){
        int n = nums.size();
        if (idx>=n){
            ans.push_back(res);
            return;
        }
        for (int j = idx;j<n;j++){
            swap(nums[idx],nums[j]);
            res.push_back(nums[idx]);
            solve(nums,idx+1,ans,res);
            res.pop_back();
            swap(nums[idx],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int idx = 0;
        solve(nums,idx,ans,res);
        return ans;
    }
};