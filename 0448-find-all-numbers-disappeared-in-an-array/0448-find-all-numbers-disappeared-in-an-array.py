class Solution(object):
    def findDisappearedNumbers(self, nums):
        for x in nums:
            index = abs(x) - 1
            nums[index] = -abs(nums[index])
        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                ans.append(i + 1)
        return ans