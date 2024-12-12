#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            sort(gifts.rbegin(), gifts.rend());
            int pile = gifts[0];
            gifts.erase(gifts.begin());
            gifts.push_back(sqrt(pile));
        }
        long long answer = 0;
        for (auto gift : gifts) {
            answer += gift;
        }
        return answer;
    }
};