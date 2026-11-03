class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        count = Counter(nums)
        frequency = [0] * (n + 1)
        for num, freq in count.items():
            if frequency[freq] == 0:
                frequency[freq] = [num]
            else:
                frequency[freq].append(num)
        result = []
        for i in range(n, 0, -1):
            if frequency[i] != 0:
                result.extend(frequency[i])
            if len(result) == k:
                return result
