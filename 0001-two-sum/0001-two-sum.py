class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        a = len(nums)
        for i in range(a):
            for j in range(i+1,a):
                if (nums[i]+nums[j]==target):
                    return [i,j]
        return [-1,-1]