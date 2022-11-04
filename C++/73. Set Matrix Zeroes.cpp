/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.


Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
{
        int row = matrix.size();
        int col = matrix[0].size();
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        
		// For checking if first row contains zero
        for(int i = 0; i < row; i++)
        {
            if(matrix[i][0] == 0)
            {
                isFirstColZero = true;
                break;
            }
        }
        
		// For checking if first column contains zero
        for(int i = 0; i < col; i++)
        {
            if(matrix[0][i] == 0)
            {
                isFirstRowZero = true;
                break;
            }
        }
        
		// check for 0's except first row and column
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    // mark that row and column in first row and column
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
		// for setting values 
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                // if first row and col contains 0 for that index
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
		// for first column
        if(isFirstColZero == true)
        {
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
        
		// for first row
        if(isFirstRowZero == true)
        {
            for(int i = 0; i < col; i++)
                matrix[0][i] = 0;
        }
    }
};
