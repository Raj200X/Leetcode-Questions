class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int, int > mp;
        vector <int> ans;
        for (auto &p : nums){
            if (mp.count(p)){
                ans.push_back(p);
            }
            mp[p]++;
        }
        
        return ans;
    }
};