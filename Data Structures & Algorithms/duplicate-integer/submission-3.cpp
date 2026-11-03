class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        for(int i : nums) {
            if (nums_set.contains(i)) {
                return true;
            } else {
                nums_set.insert(i);
            }
        }
        return false;
    }
};