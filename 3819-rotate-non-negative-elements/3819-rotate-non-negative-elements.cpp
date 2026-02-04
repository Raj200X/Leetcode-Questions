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
        unordered_set <int> indices;
        vector <int> elements;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]>=0){
                indices.insert(i);
                elements.push_back(nums[i]);
            }
        }

        rotate(elements,k);
        int j = 0;
        for (int i = 0;i<nums.size();i++){
            if (indices.count(i)){
                nums[i] = elements[j++];
            }
        }
        return nums;
        
    }
};