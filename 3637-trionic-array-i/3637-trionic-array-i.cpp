class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int q = nums.size()-1;
        for (int i = 0;i+1<nums.size();i++){
            if (nums[i]<nums[i+1]){
                p++;
            }
            else{
                break;
            }
        }
        for (int i = nums.size()-1;i>p;i--){
            if (nums[i]>nums[i-1]){
                q--;
            }
            else{
                break;
            }
        }
        cout << "p:" << p << "q: " << q << endl;
        
        if (p==0 || q==nums.size()-1){
            return false;
        }
        if (p>q){
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