class Solution(object):
    def majorityElement(self, nums):
        freq = {}
        for i in nums:
            freq[i] = freq.get(i,0)+1
        for i in freq:
            if freq[i] > len(nums) // 2:
                return i

        