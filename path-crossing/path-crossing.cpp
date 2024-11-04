class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0; int y=0;
        unordered_set<string> visited;
        visited.insert("0,0");
        for(char direction : path){
            switch (direction){
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }
            string currentPosition = to_string(x) + "," + to_string(y);
            if(visited.count(currentPosition) > 0){
                return true;
            }
            
            visited.insert(currentPosition);
        }
        return false;
    }
};