/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    int returnIndex(vector<int>& nums, int target, bool findStartIndex){
        int l = 0, h = nums.size() -1;
        int res = -1;
        
        
        while(l <= h){
            int m = l + (h-l)/2; //middle element
            if(nums[m] == target){
                //check for first occurance
                if(findStartIndex == true){
                    h = m-1;
                    res = m;
                }
                //check for last occurance
                else{
                    l = m +1;
                    res = m;
                }
            }
            else if(nums[m] < target)
                l = m+1;
            else
                h = m-1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        //find first occurance
        ans[0] = returnIndex(nums, target, true);
        //find last occurance
        ans[1] = returnIndex(nums, target, false);
        return ans;
    }
};
