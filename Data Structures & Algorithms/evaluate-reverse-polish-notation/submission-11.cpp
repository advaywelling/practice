class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> vals;
        int temp1{};
        int temp2{};
        char i{};
        for(string& str : tokens) {
            if (str == "*" || str == "-" || str == "+" || str == "/") {
                i = str[0];
                switch (i) {
                    case '/':
                        temp1 = vals.top();
                        vals.pop();
                        temp2 = vals.top();
                        vals.pop();
                        temp1 = temp2 / temp1;
                        vals.push(temp1);
                        break;
                    case '*':
                        temp1 = vals.top();
                        vals.pop();
                        temp2 = vals.top();
                        vals.pop();
                        temp1 = temp1 * temp2;
                        vals.push(temp1);
                        break;
                    case '+':
                        temp1 = vals.top();
                        vals.pop();
                        temp2 = vals.top();
                        vals.pop();
                        temp1 = temp1 + temp2;
                        vals.push(temp1);
                        break;
                    case '-':
                        temp1 = vals.top();
                        vals.pop();
                        temp2 = vals.top();
                        vals.pop();
                        temp1 = temp2 - temp1;
                        vals.push(temp1);
                        break;
                }
            } else {
                vals.push(std::stoi(str));
            }
        }
        return vals.top();
    }
};
