class Solution {
public:
    void cleanRoom(Robot& robot) {
        // {-1, 0} -> go up
        // {0, 1} -> go right
        // {1, 0} -> go down
        // {0, -1} -> go left
        // face direction: 0(up) 1(right) 2(down) 3(left)
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        unordered_set<string> visited;
        cleanRoomRecursive(robot, visited, directions, 0, 0, 0);
    }
private:
    void cleanRoomRecursive(Robot &robot, unordered_set<string> &visited, const vector<vector<int>> &directions, int i, int j, int faceDirection) {
        // mark the current cell as visited(make sure that each time you call this function, the cell has not been visited yet)
        visited.insert(to_string(i) + "," + to_string(j));
        // clean the current cell
        robot.clean();
        
        // try out 4 differnt directions
        // k = 0: keep moving towards the current direction that we're facing
        // k = 1: make 1 right turn already, and try that new direction
        // k = 2: make 2 right turns already, and try that new direction
        // k = 3: make 3 right turns already, and try that new direction
        for (int k = 0; k < 4; ++k) {
            int nextFaceDirection = (faceDirection + k) % 4;
            int iNext = i + directions[nextFaceDirection][0];
            int jNext = j + directions[nextFaceDirection][1];
            // next cell has not been visited and is accessible
            if (!visited.count(to_string(iNext) + "," + to_string(jNext)) && robot.move()) {
                cleanRoomRecursive(robot, visited, directions, iNext, jNext, nextFaceDirection);
                // come back from the above recursive call, and the robot is currently at (iNext, jNext)
                // we should do a backtracking here to ask the robot to return back to (i, j)
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            // the current direction has been explored
            // we should make a right turn, and try to explore another direction
            robot.turnRight();
        }
    }
    
};