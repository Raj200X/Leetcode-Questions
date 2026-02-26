class Solution {
public:
    void generate(int index,vector<int> &curr,vector<int> &nums,vector<vector<int>> &res,int &k){
        if (curr.size()==k){
            res.push_back(curr);
            return;
        }
         if (index >= nums.size()) {
            return;
        }
        generate(index+1,curr,nums,res,k);
        curr.push_back(nums[index]);
        generate(index+1,curr,nums,res,k);
        curr.pop_back();
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> nums;
        for (int i = 1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> curr;
        generate(0,curr,nums,res,k);
        return res;
    }
};