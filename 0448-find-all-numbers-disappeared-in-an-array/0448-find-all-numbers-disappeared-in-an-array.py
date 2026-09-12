class Solution(object):
    def findDisappearedNumbers(self, nums):
        nums.sort()
        ans = []
        count = 1

        for i in nums:
            if i == count:
                count += 1

            elif i > count:
                while count < i:
                    ans.append(count)
                    count += 1

                count = i + 1

        while count <= len(nums):
            ans.append(count)
            count += 1

        return ans