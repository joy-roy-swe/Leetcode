class Solution {
public:
    int totalMoney(int n) {
        // Calculate the number of complete weeks and the remaining days
        int week_count = n / 7;
        int remaining_days = n % 7;

        // Contribution from complete weeks
        int total = ((week_count * (week_count - 1)) / 2) * 7;

        // Contribution from complete weeks (additional on Mondays)
        total += week_count * 28;

        // Contribution from remaining days
        total += ((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days);

        // Return the total amount of money accumulated
        return total;
    }
};