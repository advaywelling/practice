class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        for i in tokens:
            if i in '+-*/':
                x = stk.pop()
                y = stk.pop()
                if i == '+':
                    stk.append(y + x)
                elif i == '-':
                    stk.append(y - x)
                elif i == '*':
                    stk.append(y * x)
                else:
                    num = y / x
                    if num < 0:
                        num = abs(num) // 1
                        stk.append(int(-num))
                    else:
                        stk.append(int(num // 1))
            else:
                stk.append(int(i))
        return stk[0]
