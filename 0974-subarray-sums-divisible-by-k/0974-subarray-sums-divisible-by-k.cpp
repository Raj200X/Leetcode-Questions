class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        seen[0]=1;
        int count=0,prefix=0;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i];
            int rem = prefix%k;
            if(rem<0){
                rem+=k;
            }
            if(seen.find(rem) != seen.end()){
                count += seen[rem];
            }
            if(seen.find(rem) != seen.end()){
                seen[rem]+=1;
            }else{
                seen[rem]=1;
            }
        }
        return count;
    }
};