class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char,int> chars;
        for (char i : s) {
            chars[i]++;
        }
        for (char i : t) {
            chars[i]--;
            if (chars[i] < 0) return false;
        }
        return true;
    }
};
