class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& arr,int i,int need){
        if (i==arr.size()){
            return false;
        }
        if (need==0){
            return true;
        }
        if (need<0){
            return false;
        }
        if (dp[i][need]!=-1){
            return dp[i][need];
        }
        // pick
        bool first = solve(arr,i+1,need-arr[i]);
        
        
        //not pick
        bool second = solve(arr,i+1,need);
        
        return dp[i][need] = first||second;
        
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int sum = accumulate(arr.begin(),arr.end(),0);
        int need = sum/2;
        dp.resize(n, vector<int>(need+1, -1));
        if (sum%2!=0){
            return false;
        }
        return solve(arr,i,need);
    }
};