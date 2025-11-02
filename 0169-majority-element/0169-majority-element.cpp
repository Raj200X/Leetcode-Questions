class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto &p:nums){
            mp[p]++;
        }
        int n = nums.size()/2;
        for (auto &k:mp){
            if (k.second>n){
                return k.first;
            }
        }
        return -1;
    }
};