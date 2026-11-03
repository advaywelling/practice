class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numbers = {}
        n = len(nums)

        for i in range(n):
            numbers[nums[i]] = i
        
        for i in range(n):
            result = target - nums[i]
            if result in numbers and numbers[result] != i:
                return (i, numbers[result])
                