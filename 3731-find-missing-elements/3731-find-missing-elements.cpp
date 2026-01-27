class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>mp;
        vector<int>ans;
        for (auto &p:nums){
            mp.insert(p);
        }
        int small = INT_MAX;
        int big = INT_MIN;
        for (int i = 0;i<nums.size();i++){
            small = min(small,nums[i]);
            big = max(big,nums[i]);
        }
        for (int i = small+1;i<big;i++){
            if (!mp.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
        

    }
};