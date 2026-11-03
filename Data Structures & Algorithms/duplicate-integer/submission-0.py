class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numbers = {}
        n = len(nums)

        for i in range(n):
            numbers[nums[i]] = i
        
        for i in range(n):
            if nums[i] in numbers and numbers[nums[i]] != i:
                return True
        
        return False
         