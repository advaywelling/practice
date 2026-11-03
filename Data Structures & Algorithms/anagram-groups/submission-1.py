from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = defaultdict(list)
        res = []
        for i in strs:
            sorted_str = tuple(sorted(i))
            anagram[sorted_str].append(i)
        for i in anagram.values():
            res.append(i)
        return res

        
        
        
        

