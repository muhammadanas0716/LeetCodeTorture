/*
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 

Constraints:

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
		int start, end;
		for(int i = 0; i<= arr.size()-1; i++){
			int target = arr[i];
			if (target < 0){
				start = 0;
				end = i - 1;
			}
			else{
				start = i + 1;
				end = arr.size() - 1;
			}
			while(start <= end){
				int mid = start + (end - start)/2;
				if(target*2 == arr[mid]) return true;
				else if(target*2 < arr[mid]) end = mid - 1;
				else start = mid + 1;
			}
		}
		return false;
    }
};
