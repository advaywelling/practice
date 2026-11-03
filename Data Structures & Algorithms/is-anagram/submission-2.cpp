class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> str_map;
        if (s.size() != t.size()) return false;
        for(char i : s) {
            str_map[i]++;
        }
        for(char i : t) {
            str_map[i]--;
            if (str_map[i] < 0) {
                return false;
            }
        }
        return true;
    }
};
