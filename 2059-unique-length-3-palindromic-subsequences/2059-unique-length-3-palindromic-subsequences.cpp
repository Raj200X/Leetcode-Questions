class Solution {
public:
    int countPalindromicSubsequence(string s) {
       vector<vector<int>> count(26,vector<int>(26,0));
       vector<pair<int,int>> index(26,{INT_MAX,INT_MIN});
       for(int i=0;i<s.length();i++){
        int ind = s[i]-'a';
        auto &p = index[ind];
        p.first = min(p.first,i);
        p.second = max(p.second,i);
       }

       for(int i=0;i<s.length();i++){
        int ind = s[i]-'a';
        for(int j=0;j<26;j++){
            auto &[first,second] = index[j];
            if(i>=first && i<=second){
                count[j][ind]++;
            }
        }
       }
       int res = 0;
       for(int i=0;i<26;i++){
        int count_unique=0;
        for(int j=0;j<26;j++){
            if(count[i][j]!=0) count_unique++;
        }
        if(count_unique>0 && count[i][i]<=2) count_unique--;
        res+=count_unique;
       }
       return res;
    }
};