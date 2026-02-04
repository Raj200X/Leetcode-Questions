class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         if (n == 0) return;
        k %= n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector <int> indices;
        vector <int> elements;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]>=0){
                indices.push_back(i);
                elements.push_back(nums[i]);
            }
        }

        rotate(elements,k);
        for (int i = 0;i<indices.size();i++){
                nums[indices[i]] = elements[i];
        }
        return nums;
        
    }
};