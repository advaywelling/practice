class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        std::unordered_set<int> vals;
        for(int& i : nums) {
            vals.insert(i);
        }
        int curr_seq = 1;
        int max_seq = 1;
        for(const int& i : vals) {
            int temp = i + 1;
            if (vals.contains(i - 1)) {
                continue;
            } else {
                while(vals.contains(temp)) {
                    curr_seq++;
                    temp++;
                }
            }
            max_seq = curr_seq > max_seq ? curr_seq : max_seq;
            curr_seq = 1;
        }
        return max_seq;
    }
};
