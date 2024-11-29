
+++
authors = ["grid47"]
title = "Leetcode 1674: Minimum Moves to Make Array Complementary"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1674: Minimum Moves to Make Array Complementary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uyV0p6zy9DU"
youtube_upload_date="2020-11-29"
youtube_thumbnail="https://i.ytimg.com/vi/uyV0p6zy9DU/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums` of even length `n` and an integer `limit`. In one move, you can replace any element of `nums` with another integer between `1` and `limit` (inclusive). The array `nums` is complementary if for all indices `i`, `nums[i] + nums[n - 1 - i]` equals the same number. Return the minimum number of moves required to make `nums` complementary.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of even length `n` and an integer `limit`.
- **Example:** `nums = [1, 2, 4, 3], limit = 4`
- **Constraints:**
	- 2 <= n <= 10^5
	- 1 <= nums[i] <= limit <= 10^5
	- n is even

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to make the array complementary.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the minimum number of moves to make `nums` complementary, we need to adjust pairs of elements such that their sums are consistent across the array.

- Iterate over the first half of the array and consider pairs of elements from the beginning and the end of the array.
- For each pair of elements, calculate the range of possible sums (from their minimum to their maximum possible sum).
- Track the frequency of each sum using a differential array.
- Determine the minimum number of moves required by finding the sum with the smallest number of adjustments.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` will always have an even length.
- The value of `limit` will be valid and within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 4, 3], limit = 4`  \
  **Explanation:** In this case, we need to change `nums` to make the sum of each pair equal to 4. This can be achieved by changing the second element `4` to `2`.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a greedy approach with a differential array to track the changes required for each possible sum of the pairs.

### Initial Thoughts 💭
- We need to find the optimal sum for each pair and count the number of changes required to make all sums equal.
- Using a differential array will allow us to efficiently track the changes needed for each sum.
- We need to ensure that we minimize the total number of changes, which can be done by finding the most frequent sum and adjusting all pairs to match that sum.
{{< dots >}}
### Edge Cases 🌐
- The array `nums` will always have an even length, so no empty input scenarios are considered.
- The solution should be optimized to handle input arrays up to the size of 100,000 efficiently.
- The array elements and the limit will always be within the range of 1 to 100,000.
- The value of `limit` must be between 1 and 100,000, and each element in the array `nums` must be between 1 and `limit`.
{{< dots >}}
## Code 💻
```cpp
int minMoves(vector<int>& num, int lmt) {
    int n = num.size();
    vector<int> dp(2*lmt +2,0);
    for(int i = 0; i < n/2; i++) {
        int a = num[i];
        int b = num[n-1-i];
        dp[2] += 2;
        dp[min(a,b)+1] -= 1;
        dp[a+b] -= 1;
        dp[a+b+1] += 1;
        dp[max(a,b) + lmt +1] += 1;
        
        }
    //for(int i = 1; i < n; i++)
       // dp[i] += dp[i - 1];
    
    int cur = 0, res = 2* n;
    for(int i = 2; i < 2 * lmt + 1; i++) {
        cur += dp[i];
        res = min(res, cur);
        }
    return res;
}
```

This is the full implementation of the 'minMoves' function, which calculates the minimum number of moves required to make a given array equal with the constraints provided. It uses dynamic programming (DP) to track and minimize moves based on the values in the array and a limit 'lmt'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minMoves(vector<int>& num, int lmt) {
	```
	Define the function 'minMoves' that accepts a reference to a vector of integers 'num' and an integer 'lmt' representing the limit for the calculation.

2. **Variable Initialization**
	```cpp
	    int n = num.size();
	```
	Store the size of the input array 'num' in variable 'n'.

3. **Dynamic Programming Array Initialization**
	```cpp
	    vector<int> dp(2*lmt +2,0);
	```
	Initialize a dynamic programming array 'dp' of size '2*lmt + 2' with all elements set to 0.

4. **Loop Setup**
	```cpp
	    for(int i = 0; i < n/2; i++) {
	```
	Start a loop to iterate through the first half of the array, where the element pairs are compared.

5. **Variable Assignment**
	```cpp
	        int a = num[i];
	```
	Assign the element at the 'i'-th index of the array 'num' to the variable 'a'.

6. **Variable Assignment**
	```cpp
	        int b = num[n-1-i];
	```
	Assign the element at the corresponding index from the end of the array 'num' to the variable 'b'.

7. **Dynamic Programming Update**
	```cpp
	        dp[2] += 2;
	```
	Increase the value at index 2 in the dynamic programming array 'dp' by 2.

8. **Dynamic Programming Update**
	```cpp
	        dp[min(a,b)+1] -= 1;
	```
	Decrease the value at index 'min(a,b) + 1' in the DP array 'dp' by 1 to track a move.

9. **Dynamic Programming Update**
	```cpp
	        dp[a+b] -= 1;
	```
	Decrease the value at index 'a + b' in the DP array 'dp' by 1 to track a move based on the sum of 'a' and 'b'.

10. **Dynamic Programming Update**
	```cpp
	        dp[a+b+1] += 1;
	```
	Increase the value at index 'a + b + 1' in the DP array 'dp' by 1 to adjust the count based on the sum of 'a' and 'b'.

11. **Dynamic Programming Update**
	```cpp
	        dp[max(a,b) + lmt +1] += 1;
	```
	Increase the value at index 'max(a,b) + lmt + 1' in the DP array 'dp' by 1, considering the maximum value between 'a' and 'b'.

12. **Variable Initialization**
	```cpp
	    int cur = 0, res = 2* n;
	```
	Initialize variables 'cur' to 0 and 'res' to '2 * n'. 'cur' will hold the current cumulative sum of DP values, and 'res' will store the minimum result.

13. **Final Loop**
	```cpp
	    for(int i = 2; i < 2 * lmt + 1; i++) {
	```
	Start a loop to iterate over the DP array from index 2 to '2 * lmt + 1' to find the minimum number of moves.

14. **Dynamic Programming Update**
	```cpp
	        cur += dp[i];
	```
	Update the variable 'cur' by adding the value from the DP array at index 'i'.

15. **Result Calculation**
	```cpp
	        res = min(res, cur);
	```
	Update the result 'res' by taking the minimum between the current 'res' and 'cur'. This keeps track of the least number of moves.

16. **Return Statement**
	```cpp
	    return res;
	```
	Return the final result 'res', which holds the minimum number of moves required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm performs a linear scan of the array and updates the differential array for each pair of elements, leading to O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(limit)
- **Worst Case:** O(limit)

The space complexity is proportional to the size of the `limit` because we maintain a differential array for sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

---
{{< youtube uyV0p6zy9DU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
