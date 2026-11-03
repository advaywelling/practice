class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l = 0
        r = n - 1
        while l < r:
            m = (r + l) // 2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        if r == 0:
            left = 0
            right = n - 1
        elif nums[0] <= target and nums[r - 1] >= target:
            right = r - 1
            left = 0
        else:
            left = r
            right = n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1