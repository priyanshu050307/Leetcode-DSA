class Solution:
    def maxVowels(self, s, k):
        vowelCount = 0

        for i in range(k):
            if s[i] in "aeiou":
                vowelCount += 1

        maxVowelCount = vowelCount

        for i in range(1, len(s) - k + 1):
            if s[i - 1] in "aeiou":
                vowelCount -= 1

            if s[i + k - 1] in "aeiou":
                vowelCount += 1

            maxVowelCount = max(maxVowelCount, vowelCount)

        return maxVowelCount