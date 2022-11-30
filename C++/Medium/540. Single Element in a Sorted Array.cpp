/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() -1;
        int mid;
        while(h > l){
            mid = l + (h-l)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];
            else if(mid%2 == 0){
                if(nums[mid] != nums[mid+1])
                    h = mid - 2;
                else
                    l = mid + 2;
            }
            else{
                if(nums[mid] != nums[mid+1])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return nums[l];
    }
};
