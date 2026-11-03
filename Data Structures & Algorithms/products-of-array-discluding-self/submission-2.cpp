class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int flag {};
        for (int i : nums) {
            if (i != 0) {
                prod *= i;
            }
            else {
                flag++;
            }
        }
        for (int& i : nums) {
            if (!flag) {
                i = prod / i;
            } else {
                i = (i == 0) ?  (flag == 1 ? prod : 0) : 0;
            }
        }
        return nums;
    }
};
