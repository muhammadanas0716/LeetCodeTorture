/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 2^31 - 1
*/

class Solution {
public:
    int arrangeCoins(int n) {
        long int l = 0, h = n;
        while(l <= h){
            long int mid = l + (h-l)/2;
            long long int curr = mid*(mid+1)/2;
            if(curr == n)
                return mid;
            else if(curr > n)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return h;
    }
};
