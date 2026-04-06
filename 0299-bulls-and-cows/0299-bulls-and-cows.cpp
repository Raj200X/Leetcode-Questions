class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        unordered_map<int,int>sset;
        for (auto &p:guess){
            sset[p]++;
        }
        for (int i = 0;i<n;i++){
            if (secret[i]==guess[i]){
                bulls++;
                sset[secret[i]]--;
            } 
            if (sset[secret[i]]==0){
                sset.erase(secret[i]);
            }
        }
        for (int i = 0; i < n; i++){
            if (secret[i] != guess[i]){   // only non-bulls
                if (sset.count(secret[i]) && sset[secret[i]] > 0){
                    cows++;
                    sset[secret[i]]--;
                }
            }
        }
        
        string b = to_string(bulls);
        string c = to_string(cows);
        ans = b+"A"+c+"B";
        return ans;

    
    }
};