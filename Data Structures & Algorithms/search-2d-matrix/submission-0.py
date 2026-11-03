class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        count = rows * cols
        l = 0
        r = count - 1
        while l <= r:
            m = l + ((r - l) // 2)
            i = m // cols
            j = m % cols
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                r = m - 1
            else:
                l = m + 1
        return False