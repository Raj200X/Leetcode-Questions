class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int q = nums.size()-1;
        int n = nums.size();
        for (int i = 0,j = n-1;i<j;){
            if (nums[i]<nums[i+1]){
                p++;
                i++;
            }
            else if (nums[j]>nums[j-1]){
                q--;
                j--;
            }
            else{
                break;
            }

        }
        
        if (p==0 || q==nums.size()-1){
            return false;
        }
        for (int i = p;i<q;i++){
            if (nums[i+1]>=nums[i]){
                return false;
            }
        }
        return true;

    }
};