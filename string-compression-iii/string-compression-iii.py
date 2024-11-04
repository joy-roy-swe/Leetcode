class Solution:
    def compressedString(self, word: str) -> str:
        if not word:
            return ""
        
        comp = ""
        n = len(word)
        window_start = 0

        while window_start < n:
            current_char = word[window_start]
            count = 0

            # Count consecutive occurrences of current_char up to a maximum of 9
            while window_start + count < n and word[window_start + count] == current_char and count < 9:
                count += 1

            # Append the count and character to the compressed result
            comp += str(count) + current_char

            # Move window_start forward by the count we just processed
            window_start += count

        return comp
