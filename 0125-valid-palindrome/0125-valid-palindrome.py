class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        left=0
        right=len(s)-1

        while left<right:
            if s[left].lower()!=s[right].lower():
                return False
            left+=1
            right-=1
        
        return True