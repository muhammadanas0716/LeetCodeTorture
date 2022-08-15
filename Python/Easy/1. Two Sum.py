# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

 
# Example:

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Question Link: https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums, target):
		
        result_list = []
		#Two for loops for selecting two numbers and check sum equal to target or not
        for i in range(len(nums)-1):
            for j in range(i, len(nums)):
			#  j from i + 1; no need to check back elements it covers in i
			# Check sum == target or not
                if nums[i] + nums[j] == target:
                    result_list.append(i)
                    result_list.append(j)

        return result_list[:2]

sol = Solution()
print(sol.twoSum([2,7,11,15], 11))
