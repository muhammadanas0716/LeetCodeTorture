/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
Return an array of coordinates representing the positions of the grid in the order you visited them.


Example 1:

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols
*/

class Solution {
public:
    bool valid_to_push(int i, int j, int rows, int cols){
        if(i>=0 && i<rows && j>=0 && j<cols)
            return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int counter, direction, checker;
        ans.push_back({rStart, cStart});
        counter = 1;
        direction = 0;
        checker = 1;
        
        int i = rStart, j = cStart;
        while(counter != rows * cols){
            if(direction == 0){
                for(int k = 1; k<= checker; k++){
                    j++;
                    if(valid_to_push(i,j,rows,cols)){
                        ans.push_back({i, j});
                        counter++;
                    }
                }
                direction = 1;
            }
            if(direction == 1){
                for(int k = 1; k<= checker; k++){
                    i++;
                    if(valid_to_push(i,j,rows,cols)){
                        ans.push_back({i, j});
                        counter++;
                    }
                }
                direction = 2;
            }
            checker++;
            if(direction == 2){
                for(int k = 1; k<= checker; k++){
                    j--;
                    if(valid_to_push(i,j,rows,cols)){
                        ans.push_back({i, j});
                        counter++;
                    }
                }
                direction = 3;
            }
            if(direction == 3){
                for(int k = 1; k<= checker; k++){
                    i--;
                    if(valid_to_push(i,j,rows,cols)){
                        ans.push_back({i, j});
                        counter++;
                    }
                }
                direction = 0;
            }
            checker++;
        }
        
        return ans;
    }
};
