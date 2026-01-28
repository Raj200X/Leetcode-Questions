class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int l = 0;
      int h = nums.size()-1;
      int maxsum = INT_MIN;
      while(l<h){
        int sum = nums[l]+nums[h];
            maxsum = max(sum,maxsum);
        l++;
        h--;
      }
      return maxsum;
    }
};