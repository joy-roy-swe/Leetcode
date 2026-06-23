class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        # Maps char in s -> char in t
        map_s_t = {}
        # Maps char in t -> char in s
        map_t_s = {}
        
        for c1, c2 in zip(s, t):
            # Check if mapping exists
            if c1 in map_s_t and map_s_t[c1] != c2:
                return False
            if c2 in map_t_s and map_t_s[c2] != c1:
                return False
            
            # Create new mapping
            map_s_t[c1] = c2
            map_t_s[c2] = c1
            
        return True