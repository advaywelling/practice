class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size());
        std::vector<int> postfix(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix[i] = 1;
            } else {
                prefix[i] = prefix[i - 1] * nums[i - 1];
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i == nums.size() - 1) {
                postfix[i] = 1;
            } else {
                postfix[i] = postfix[i + 1] * nums[i + 1];
            }
        }
        for(int i = 0; i < prefix.size(); i++) {
            prefix[i] *= postfix[i];
        }
        return prefix;
    }
};
