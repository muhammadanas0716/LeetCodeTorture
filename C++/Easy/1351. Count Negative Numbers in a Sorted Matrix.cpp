/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size()-1;
        int count = 0;
        cout<<m<<" "<<n<<endl;
        
        for(int i = 0; i<n; i++){
            // no negative in col
            if(grid[i][m] >=0){
                continue;
            }
            //whole col is negative
            if(grid[i][0] < 0){
                count += m+1;
                continue;
            }
            
            //some part is negative
            int l = 0, h = m;
            while(l <= h){
                int mid = (h+l)/2;
                if(grid[i][mid] >= 0){
                    l = mid + 1;
                }
                else{
                    h = mid-1;
                }
            }
            count += m - h;
            cout << grid[i][h]<<" ";
        }
        return count;
    }
};
