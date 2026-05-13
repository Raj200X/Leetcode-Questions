class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (int i = 1;i<INT_MAX;i++){
            if (!mp.count(i)){
                return i;
            }
        }
        return -1;
    }
};