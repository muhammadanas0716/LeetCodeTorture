//Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
//A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
//
//
//Example 1:
//
//Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
//Output: [15]
//Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 2:
//
//Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
//Output: [12]
//Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 3:
//
//Input: matrix = [[7,8],[1,2]]
//Output: [7]
//Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
// 
//
//Constraints:
//
//m == mat.length
//n == mat[i].length
//1 <= n, m <= 50
//1 <= matrix[i][j] <= 105.
//All elements in the matrix are distinct.

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // only one number in matrix can be lucky number that will be maximum among all minimum row numbers && minimum among all maximum col numbers
      
        //maximum number among all minimum row numbers
        int maxMin = INT_MIN;
        for (int i = 0; i < m; i++) {
            int min = INT_MAX;
            for (int j = 0; j < n; j++){
                min = std::min(min, matrix[i][j]);
            }
            maxMin = std::max(maxMin, min);
        }

        //minimum number among all maximum col numbers
        int minMax = INT_MAX;
        for (int j = 0; j < n; j++) {
            int max = INT_MIN;
            for (int i = 0; i < m; i++){
                max = std::max(max, matrix[i][j]);
            }
            minMax = std::min(minMax, max);
        }
        
        //if not equal
        if (maxMin != minMax) 
        {
            return vector<int> { };
        }
      //else
        return vector<int> { maxMin };
    }
};
