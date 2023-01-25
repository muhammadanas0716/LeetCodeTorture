/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        int store[256]={0}; //array to store the occurences of all the characters
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.length())
        {
            store[s[r]]++;
            
            while(store[s[r]]>1)
            {
                store[s[l]]--;
                l++;
            }
            
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
