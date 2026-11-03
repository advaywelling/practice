class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        for(int i{}; i < nums.size(); i++) {
            if (nums_set.contains(nums[i])) {
                return true;
            }
            nums_set.insert(nums[i]); 
        }
        return false;
    }
};