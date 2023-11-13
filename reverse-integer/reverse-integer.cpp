class Solution {
public:
    int reverse(int x) {
        //take a loop, which iterate each digit of given integer
        long reverse_integer=0, reminder;
        while(x!=0){
            reminder = x%10;
            reverse_integer = (reverse_integer*10)+reminder;
            x = x/10;
        }
        if(reverse_integer>INT_MAX || reverse_integer<INT_MIN)
            return 0;
        return reverse_integer;
    }
};