class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for (int i =0;i<strs.size();i++){
            string st = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(st);
        }
        vector<vector<string>>ans;
        for (auto &p:mp){
            vector<string>temp;
            for (int i =0;i<p.second.size();i++){
                temp.push_back(p.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
