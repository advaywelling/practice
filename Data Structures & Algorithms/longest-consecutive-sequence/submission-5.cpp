class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        if (!nums.size()) {
            return 0;
        }
        std::set<int> nums_set;
        int max_seq = 1;
        int curr_seq = 1;
        for (auto i : nums) {
            nums_set.insert(i);
        }
        for (auto i = nums_set.begin(); i != std::prev(nums_set.end()); i++) {
            auto next_i = std::next(i);
            if (*next_i - *i != 1) {
                curr_seq = 1;
            } else {
                curr_seq++;
                max_seq = curr_seq > max_seq ? curr_seq : max_seq;
            }
        }
        return max_seq;
    }
};
