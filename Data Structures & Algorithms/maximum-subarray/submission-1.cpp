class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int curr_sum = nums[0];
        int global_sum = nums[0];
        for(size_t i = 1; i < nums.size(); i++) {
            curr_sum = nums[i] > curr_sum + nums[i] ? nums[i] : curr_sum + nums[i];
            global_sum = curr_sum > global_sum ? curr_sum : global_sum;
        }
        return global_sum;
    }
};
