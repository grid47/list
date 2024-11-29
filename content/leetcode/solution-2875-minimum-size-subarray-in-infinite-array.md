
+++
authors = ["grid47"]
title = "Leetcode 2875: Minimum Size Subarray in Infinite Array"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2875: Minimum Size Subarray in Infinite Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nsgqVWeUI24"
youtube_upload_date="2023-10-04"
youtube_thumbnail="https://i.ytimg.com/vi/nsgqVWeUI24/maxresdefault.jpg"
comments = true
+++



---
You are given an array nums and an integer target. The array infinite_nums is created by infinitely appending nums to itself. You need to find the length of the shortest contiguous subarray in infinite_nums whose sum equals the target. If no such subarray exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums, and an integer target.
- **Example:** `nums = [4, 5, 6], target = 9`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^5
	- 1 <= target <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the shortest contiguous subarray with a sum equal to target. If no such subarray exists, return -1.
- **Example:** `For input nums = [4, 5, 6], target = 9, the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the shortest subarray in infinite_nums whose sum equals target.

- First, identify the minimum length subarray that satisfies the sum condition.
- Utilize sliding window or prefix sum techniques to efficiently find the subarrays.
- Consider the fact that the array repeats infinitely when calculating possible subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- The target will always be a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For input nums = [4, 5, 6], target = 9, the output is 2.`  \
  **Explanation:** The subarray [5, 6] (from index 1 to 2) has a sum of 9, and its length is 2.

{{< dots >}}
## Approach 🚀
The approach involves using a sliding window or prefix sum technique to efficiently find the shortest subarray in the infinite array whose sum equals the target.

### Initial Thoughts 💭
- The array is infinite, but we can work with just 2 copies of the array.
- We need an efficient method to handle large arrays and large target values.
- A sliding window or prefix sum approach can help reduce the complexity from brute force.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element, so no need to handle empty inputs.
- Ensure the algorithm works efficiently for arrays with lengths up to 10^5.
- Consider cases where no subarray exists that meets the target.
- The algorithm should handle large inputs within the time limits.
{{< dots >}}
## Code 💻
```cpp
int minSizeSubarray(vector<int>& A, int target) {
    long sumA = accumulate(A.begin(), A.end(), 0L), su = 0;
    int n = A.size(), k = target / sumA, res = n;
    target %= sumA;
    if (target == 0)
        return k * n;
    unordered_map<long, int> dp{{0L, -1}};
    for (int i = 0; i < 2 * n; ++i) {
        su += A[i % n];
        if (dp.count(su - target))
            res = min(res, i - dp[su - target]);
        dp[su] = i;
    }
    return res < n ? res + k * n : -1;
}
```

This function calculates the minimum size of a subarray whose sum is equal to the target value by using a sliding window and dynamic programming approach. It also handles circular arrays where the subarray can wrap around.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minSizeSubarray(vector<int>& A, int target) {
	```
	This line declares the function that takes a vector of integers 'A' and an integer 'target' as inputs and returns an integer representing the minimum size of the subarray.

2. **Variable Initialization**
	```cpp
	    long sumA = accumulate(A.begin(), A.end(), 0L), su = 0;
	```
	This line computes the sum of all elements in 'A' and stores it in 'sumA'. It also initializes 'su', which will track the sum of the current subarray, to 0.

3. **Variable Initialization**
	```cpp
	    int n = A.size(), k = target / sumA, res = n;
	```
	'n' stores the size of the array 'A', 'k' is the number of times 'sumA' fits into 'target', and 'res' is initialized to 'n', which is the worst-case size of the subarray.

4. **Modulus Operation**
	```cpp
	    target %= sumA;
	```
	This line reduces the target value to the remainder when divided by 'sumA'. This ensures the target is within the bounds of the sum of one cycle of the array.

5. **Condition Check**
	```cpp
	    if (target == 0)
	```
	This condition checks if the target is zero after the modulus operation. If true, the entire array sum can form the target, and the function will return the result immediately.

6. **Early Return**
	```cpp
	        return k * n;
	```
	If the target is zero, it means the subarray can simply consist of the entire array repeated 'k' times, and the minimum size of the subarray is 'k * n'.

7. **Map Initialization**
	```cpp
	    unordered_map<long, int> dp{{0L, -1}};
	```
	This initializes a hashmap 'dp' that stores the cumulative sum up to each index and its respective index. The key-value pair (0L, -1) represents the base case for the sum starting at index -1.

8. **Loop Setup**
	```cpp
	    for (int i = 0; i < 2 * n; ++i) {
	```
	This for loop iterates over the array twice (2*n) to account for possible circular subarrays.

9. **Sliding Window Update**
	```cpp
	        su += A[i % n];
	```
	The current element of the array 'A' is added to 'su', where 'i % n' ensures that the index wraps around if it exceeds the size of the array.

10. **Check for Previous Subarray**
	```cpp
	        if (dp.count(su - target))
	```
	This condition checks if the difference between the current cumulative sum 'su' and the target exists in the 'dp' map. If true, it means a subarray that sums up to 'target' exists.

11. **Result Update**
	```cpp
	            res = min(res, i - dp[su - target]);
	```
	If a valid subarray is found, 'res' is updated to the smaller of its current value or the length of the subarray (i - dp[su - target]).

12. **Update Map**
	```cpp
	        dp[su] = i;
	```
	The current cumulative sum 'su' and its index 'i' are stored in the 'dp' map to track the first occurrence of the sum.

13. **Return Result**
	```cpp
	    return res < n ? res + k * n : -1;
	```
	The function returns 'res' if a valid subarray is found. If no subarray is found, it returns -1. If 'res' is less than 'n', it adds the number of full cycles 'k * n' to the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the efficient use of sliding window or prefix sum.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the extended array and prefix sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/)

---
{{< youtube nsgqVWeUI24 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
