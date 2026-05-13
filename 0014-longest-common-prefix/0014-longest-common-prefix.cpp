class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int cnt = ans.size();
        for (int i =1;i<strs.size();i++){
            int temp = 0;
            for (int j =0;j<min(ans.size(), strs[i].size());j++){
                if (ans[j]==strs[i][j]){
                    temp++;
                }
                else{
                    break;
                }
            }
            cnt = min(temp,cnt);
        }
        return ans.substr(0,cnt);
    }
};