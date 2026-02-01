class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];
       int sec = INT_MAX;
       int third = INT_MAX;
       for (int i = 1;i<nums.size();i++){
            if (nums[i]<sec){
                third = sec;
                sec = nums[i];
            }
            else if (nums[i]<third){
                third = nums[i];
            }
       }
       cost = cost+ sec + third;
        return cost;
    }
};