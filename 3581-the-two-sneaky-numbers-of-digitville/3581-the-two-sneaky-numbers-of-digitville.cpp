class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int, int > mp;
        vector <int> ans;
        for (auto &p : nums){
            mp[p]++;
        }
        for (auto &c : mp){
            if (c.second==2){
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};