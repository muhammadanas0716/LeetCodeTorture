//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
//
//
//Example 1:
//
//Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
//  
//Example 2:
//
//Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
//Output: false
//Explanation: It is impossible to make mat equal to target by rotating mat.
//  
//Example 3:
//
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
// 
//
//Constraints:
//
//n == mat.length == target.length
//n == mat[i].length == target[i].length
//1 <= n <= 10
//mat[i][j] and target[i][j] are either 0 or 1.

class Solution {
public:
    //rotate 90 degree
    void rotate(vector<vector<int>>& mat)
    { 
        int N = mat.size();
        // REVERSE every row
        for (int i = 0; i < N; i++)
            reverse(mat[i].begin(), mat[i].end());
 
        // Performing Transpose
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //check and rotate the matrix
        for(int i = 0; i <= 3; i++){
            if(mat == target){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};
