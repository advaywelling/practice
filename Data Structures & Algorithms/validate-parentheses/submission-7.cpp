class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parans;
        for(char& i : s) {
            if (i == '{' || i == '[' || i == '(') {
                parans.push(i);
            }
            else if (i == '}' || i == ']' || i == ')') {
                if (parans.empty()) {
                    return false;
                }
                else if (parans.top() != i - 1 && parans.top() != i - 2) {
                    return false;
                }
                else {
                    parans.pop();
                }
            }
        }
        if (!parans.empty()) {
            return false;
        }
        return true;
    }
};
