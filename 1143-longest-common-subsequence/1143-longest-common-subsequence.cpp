class Solution {
public:
    // vector <vector <int>> dp;
    // int solve(string &str1,string &str2,int i1,int i2){
    //     //base case
    //     if (i1<0|| i2<0){
    //         return 0;
    //     }
    //     if (dp[i1][i2]!=-1){
    //         return dp[i1][i2];
    //     }
    //     int ans = 0;
    //     if (str1[i1]==str2[i2]){
    //        ans = 1 +  solve(str1,str2,i1-1,i2-1);
    //     }
    //     else if (str1[i1]!=str2[i2]){
    //         ans = max(solve(str1,str2,i1-1,i2),solve(str1,str2,i1,i2-1));
    //     }

    //     return dp[i1][i2] = ans;
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // dp.resize(n1,vector<int>(n2,-1));
        // return solve(text1,text2,n1-1,n2-1);
        int ans = 0;
        vector <vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for (int i = 1;i<=n1;i++){
            for (int j = 1;j<=n2;j++){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];

    }
};