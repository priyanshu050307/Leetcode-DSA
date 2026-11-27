class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = float('-inf')
        currSum = 0
        for val in nums:
            currSum = currSum + val
            maxSum = max(currSum, maxSum)
            if currSum<0:
                currSum = 0
        return maxSum

        