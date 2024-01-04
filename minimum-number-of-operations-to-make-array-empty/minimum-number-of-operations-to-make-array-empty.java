class Solution {
    public int minOperations(int[] nums) {
        // Create a HashMap to store the frequency of each element in 'nums'
        Map<Integer, Integer> map = new HashMap<>();
        
        // Count the frequency of each element in 'nums'
        for(int num: nums){
            // Put the element in the map and increment its count by 1
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        // Initialize a variable to count the minimum operations needed
        int count = 0;

        // Iterate through the entries in the HashMap
        for(Map.Entry<Integer, Integer> entry: map.entrySet()){
            // Get the frequency count of the current element
            int current = entry.getValue();
            // If there is only one occurrence of any element, it's not possible to make it divisible by 3
            if(current == 1) return -1;

            // Calculate the number of operations needed to make the frequency divisible by 3
            // Count the complete sets of 3 elements
            count += current/3;
            // If there are remaining elements, increment the count
            if(current % 3 != 0)
                count++;
        }
        // Return the total count of operations needed
        return count;
    }
}