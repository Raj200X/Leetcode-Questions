class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        nums.push_back(-1);
        int j=0;
        while(j<nums.size()){
            if(nums[j]==j) j++;
            else if(nums[j]==-1){
                ans = j;
                j++;
            }
            else swap(nums[j],nums[nums[j]]);
        }
        return ans;
    }
};