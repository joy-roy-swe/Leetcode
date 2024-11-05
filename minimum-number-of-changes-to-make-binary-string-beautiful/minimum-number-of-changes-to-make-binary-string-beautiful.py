# /**
#  * @file minimum-number-of-changes-to-make-binary-string-beautiful.py
#  * @author joy.roy
#  * @brief 
#  * @version 0.1
#  * @date 2024-11-05
#  * 
#  * @copyright Copyright (c) 2024
#  * 
#  * leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful
#  */

class Solution:
    def minChanges(self, s: str) -> int:
        minimum_change = 0
        for i in range(0, len(s), 2):
            if s[i] != s[i+1]:
                minimum_change+=1
        return minimum_change
        
def main():
    solution = Solution()
    s = "010101"  # Example input
    result = solution.minChanges(s)
    print(f"Minimum changes to make the string beautiful: {result}")

if __name__ == "__main__":
    main()