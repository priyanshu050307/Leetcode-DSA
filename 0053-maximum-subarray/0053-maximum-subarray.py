class Solution(object):
    def maxSubArray(self, nums):
        currSum = 0
        maxSum = float('-inf')
        for val in nums:
            currSum += val
            maxSum = max(currSum, maxSum)
            if currSum < 0:
                currSum = 0
        return maxSum