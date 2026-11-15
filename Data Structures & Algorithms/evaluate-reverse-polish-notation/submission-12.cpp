class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> vals;
        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int rhs = vals.top();
                vals.pop();
                int lhs = vals.top();
                vals.pop();
                switch (token[0]) {
                    case '+': 
                        vals.push(lhs + rhs); 
                        break;
                    case '-': 
                        vals.push(lhs - rhs); 
                        break;
                    case '*': 
                        vals.push(lhs * rhs); 
                        break;
                    case '/': 
                        vals.push(lhs / rhs); 
                        break;
                }
            } else {
                vals.push(std::stoi(token));
            }
        }
        return vals.top();
    }
};
