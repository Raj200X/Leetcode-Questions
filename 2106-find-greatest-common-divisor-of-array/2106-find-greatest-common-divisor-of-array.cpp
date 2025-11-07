class Solution {
public:
    int gcd(int n ,int m){
        if (m==0){
            return n;
        }
        return gcd(m,n%m);
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int small = nums[0];
        int large = nums[nums.size()-1];
        return gcd(small,large);
    }
};