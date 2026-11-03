class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        longest = 0
        for i in s:
            if i - 1 not in s:
                next = i
                seq = 1
                while next + 1 in s:
                    next += 1
                    seq += 1
                longest = max(seq, longest)
        return longest