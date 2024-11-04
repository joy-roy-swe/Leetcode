class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Sort the points based on X-coordinates
        sort(points.begin(), points.end());

        // Iterate through the sorted points and calculate vertical distance
        int max_width = 0;
        for(int i=1; i<points.size(); ++i){
            int width = points[i][0] - points[i-1][0];

            // Keep track of the maximum width
            max_width = max(max_width, width);
        }
        return max_width;
    }
};