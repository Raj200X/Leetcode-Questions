class Solution {
public:
    vector <int> dp;
    int solve(vector<int>& nums,int i){
        if (i>=nums.size()){
            return 0;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        // rob
        int rob = nums[i]+ solve(nums,i+2);
        // not rob
        int notRob = solve(nums,i+1);

        return dp[i] = max(rob,notRob);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        return solve(nums,0);
    }
};
