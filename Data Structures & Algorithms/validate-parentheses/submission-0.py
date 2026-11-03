class Solution:
    def isValid(self, s: str) -> bool:
        hashMap = {')' : '(', '}': '{', ']':'['}
        stk = []
        for i in s:
            if i not in hashMap:
                stk.append(i)
            else:
                if not stk:
                    return False
                else:
                    val = stk.pop()
                    if val != hashMap[i]:
                        return False
        return not stk