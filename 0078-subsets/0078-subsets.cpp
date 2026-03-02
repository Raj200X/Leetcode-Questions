class Solution {
public:
    void solve(vector<int>&nums,vector<int> ans,int idx,vector<vector <int>>&op){
    if (idx==nums.size()){
            op.push_back(ans);
        // cout << ans << " ";
        return;
    }
    int val = nums[idx];
    // include
    ans.push_back(val);
    solve(nums,ans,idx+1,op);
    //exclude
    ans.pop_back();
    solve(nums,ans,idx+1,op);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        vector<vector <int >> op;
        solve(nums,ans,i,op);
        return op;
    }
};