class Solution {
public:
    int maxScore(string s) {
        int zerosLeft = 0;
        int onesRight = count(s.begin(), s.end(), '1');

        int maxScore = 0;

        // Iterate through the string, excluding the last character
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                zerosLeft++;
            } else {
                onesRight--;
            }

            maxScore = max(maxScore, (zerosLeft + onesRight));
        }

        return maxScore;
    }
};