class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> anagrams;
        std::vector<std::vector<string>> result;
        for(string i : strs) {
            std::string curr_str = i;
            std::sort(curr_str.begin(), curr_str.end());
            anagrams[curr_str].push_back(i);
        }
        for(auto& [i,j] : anagrams) {
            result.push_back(j);
        }
        return result;
    }
};
