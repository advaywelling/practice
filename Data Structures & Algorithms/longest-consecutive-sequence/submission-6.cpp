class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        std::set<int> vals;
        for (int& i : nums) {
            vals.insert(i);
        }
        int curr_seq = 1, max_seq = 1;
        for(const int& i : vals) {
            if (vals.contains(i + 1)) {
                curr_seq ++;
                max_seq = curr_seq > max_seq ? curr_seq : max_seq;
            } else {
                curr_seq = 1;
            }
        }
        return max_seq;
    }
};
