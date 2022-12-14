/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_product (n, 1);
        vector<int> right_product (n, 1);
        
        // left product
        for(int i = 1; i<n; i++){
            left_product[i] = nums[i-1]*left_product[i-1];
        }
        
        // right product
        for(int i = n-2; i>=0; i--){
            right_product[i] = nums[i+1]*right_product[i+1];
        }
        
        // product left product with right one
        for(int i = 0; i<n; i++){
            left_product[i] *= right_product[i];
        }
        
        return left_product;
    }
};
