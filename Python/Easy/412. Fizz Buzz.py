# Given an integer n, return a string array answer (1-indexed) where:

# answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
# answer[i] == "Fizz" if i is divisible by 3.
# answer[i] == "Buzz" if i is divisible by 5.
# answer[i] == i (as a string) if none of the above conditions are true.
 

# Example 1:

# Input: n = 3
# Output: ["1","2","Fizz"]
# Example 2:

# Input: n = 5
# Output: ["1","2","Fizz","4","Buzz"]
# Example 3:

# Input: n = 15
# Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

# Question Link: https://leetcode.com/problems/fizz-buzz/

class Solution:
    def fizzBuzz(self, n: int):
        output = []
        for i in range(1, n+1):
            if (i % 5 == 0) and (i % 3 == 0):
                output.append("FizzBuzz")
            elif (i % 3 == 0):
                output.append("Fizz")
            elif (i % 5 == 0):
                output.append("Buzz")
            else:
                output.append(str(i))

        return output

Sol = Solution()
print(Sol.fizzBuzz(15))