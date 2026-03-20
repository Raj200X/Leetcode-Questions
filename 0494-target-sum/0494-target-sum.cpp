class Solution {
public:
    // vector<vector<int>> dp;
    int solve(vector<int>& nums, int target,int i){
        if (i>=nums.size() && target!=0){
            return 0;
        }
        if (i>=nums.size() && target == 0){
            return 1;
        }
        // if (dp[i][target]!=-1){
        //     return dp[i][target];
        // }

        //+ symbol
        int pl = solve(nums,target-nums[i],i+1);

        // -symbol
        int ng = solve(nums,target+nums[i],i+1);

        return pl+ng;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // dp.resize(n,vector<int>(target+1,-1));
        return solve(nums,target,0);
    }
};