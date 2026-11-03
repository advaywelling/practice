class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 1;
        int max_count = 1;
        int count = 1;
        std::unordered_set<char> chars;
        if (s.size() == 1) {
        }
        else if (s.size() == 0) {
            return 0;
        }
        else {
            chars.insert(s[r]);
            while (l < s.size()) {
                if (chars.contains(s[l])) {
                    max_count = count > max_count ? count : max_count;
                    chars.erase(s[r]);
                    r += 1;
                    count -= 1;
                } else {
                    chars.insert(s[l]);
                    count += 1;
                    l += 1;
                }
            }
        }
        return count > max_count ? count : max_count;
    }
};
