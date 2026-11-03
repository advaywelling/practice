class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        for(size_t i{}; i < nums.size(); i++) {
            int req_val = target - nums[i];
            if (nums_map.contains(req_val)) {
                return {nums_map[req_val], (int)i};
            }
            nums_map[nums[i]] = i;
        }
    }
};
