//Given a square matrix mat, return the sum of the matrix diagonals.
//Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
//
//Example 1:
//
//Input: mat = [[1,2,3],
//              [4,5,6],
//              [7,8,9]]
//Output: 25
//Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
//Notice that element mat[1][1] = 5 is counted only once.
//Example 2:
//
//Input: mat = [[1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1]]
//Output: 8
//Example 3:
//
//Input: mat = [[5]]
//Output: 5
// 
//Constraints:
//
//n == mat.length == mat[i].length
//1 <= n <= 100
//1 <= mat[i][j] <= 100

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i = 0;
        int j = mat[0].size();
        
        for(i = 0; i<mat[0].size(); i++){
            sum += mat[i][i]; //primary diagonal
            sum += mat[i][j-1]; //secondary diagonal
            j--;
        }
        // if matrix has odd no of column
        if(mat.size()%2 != 0){
            //middle number repeated twice
            sum -= mat[i/2][i/2];
        }
        return sum;
    }
};
