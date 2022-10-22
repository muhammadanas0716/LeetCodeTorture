//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//
//Example 1:
//
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//
//Example 2:
//
//Input: n = 1
//Output: [[1]] 
//
//Constraints:
//
//1 <= n <= 20

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int direction = 1;
        int num = 1;
        while(left <= right && top <= bottom)
        {
            if(direction == 1)
            {
                for(int i = left; i <= right; i++){
                    matrix[top][i] = num;
                    num++;
                }
                direction = 2;
                top++;
            }
            
            else if(direction == 2)
            {
                for(int i = top; i <= bottom; i++){
                    matrix[i][right] = num;
                    num++;
                }
                direction = 3;
                right--;
            }
            
            else if(direction == 3)
            {
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = num;
                    num++;
                }
                direction = 4;
                bottom--;
            }
            
            else if(direction == 4)
            {
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = num;
                    num++;
                }
                direction = 1;
                left++;
            }
        }
        return matrix;
    }
};
