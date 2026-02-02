class Solution {
public:
    int firstOcc(vector<int>& a, int x) {
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end() || *it != x) return -1;
    return it - a.begin();
    }
    int lastOcc(vector<int>& a, int x) {
    auto it = upper_bound(a.begin(), a.end(), x);
    if (it == a.begin() || *(it - 1) != x) return -1;
    return (it - a.begin()) - 1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums,target),lastOcc(nums,target)};
    }
};