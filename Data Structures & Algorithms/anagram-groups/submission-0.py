from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = defaultdict(list)
        result = []
    
        for i in strs:
            sortedStrs = tuple(sorted(i))
            anagram[sortedStrs].append(i)
        
        for i in anagram.values():
            result.append(i)

        return result

        
        
        
        

