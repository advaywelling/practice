class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> results(temperatures.size());
        std::stack<int> idx_stack;
        for(size_t i{}; i < temperatures.size(); i++) {
            if (idx_stack.empty()) {
                idx_stack.push(i);
                continue;
            }
            while (!idx_stack.empty() && (temperatures[i] > temperatures[idx_stack.top()])) {
                int tmp = idx_stack.top();
                results[tmp] = i - tmp;
                idx_stack.pop();
            }
            idx_stack.push(i);
        }
        return results;
    }
};
