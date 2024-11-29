
+++
authors = ["grid47"]
title = "Leetcode 1043: Partition Array for Maximum Sum"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1043: Partition Array for Maximum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kWhy4ZUBdOY"
youtube_upload_date="2024-02-03"
youtube_thumbnail="https://i.ytimg.com/vi/kWhy4ZUBdOY/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, partition the array into contiguous subarrays where each subarray has a length of at most k. After partitioning, transform each subarray such that all its elements are replaced by the maximum element of that subarray. Your goal is to return the maximum sum of the transformed array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array arr and an integer k, the maximum length of a subarray.
- **Example:** `Input: arr = [2, 7, 3, 4, 8], k = 3`
- **Constraints:**
	- 1 <= arr.length <= 500
	- 0 <= arr[i] <= 10^9
	- 1 <= k <= arr.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest sum of the given array after partitioning, where each subarray is replaced by its maximum value.
- **Example:** `Output: 30`
- **Constraints:**
	- The answer is guaranteed to fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest possible sum after partitioning the array into subarrays, each with a maximum length of k, and transforming the elements of each subarray by replacing them with the maximum value of that subarray.

- 1. Use dynamic programming to store the results of subproblems.
- 2. For each possible partition point, calculate the sum of the maximum values of the subarrays formed.
- 3. Apply a greedy approach to maximize the sum by selecting the optimal partitioning of the array.
{{< dots >}}
### Problem Assumptions ✅
- The array can have at most 500 elements.
- The maximum value for each element is 10^9.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [2, 7, 3, 4, 8], k = 3`  \
  **Explanation:** In this case, the array can be partitioned as [2, 7, 3] and [4, 8]. After replacing each subarray with its maximum value, the transformed array becomes [7, 8]. The sum of this transformed array is 30.

- **Input:** `Input: arr = [1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3], k = 4`  \
  **Explanation:** Here, we can partition the array into subarrays such as [1, 4, 1, 5], [7, 3, 6, 1], and [9, 9, 3]. The transformed array becomes [5, 7, 9], and the maximum sum is 83.

{{< dots >}}
## Approach 🚀
The problem can be solved efficiently using dynamic programming where we try to partition the array at different points and calculate the sum of the maximum values of the subarrays. The key idea is to iteratively calculate the maximum sum by considering all possible partitions of the array.

### Initial Thoughts 💭
- This problem is a dynamic programming problem where we need to maximize the sum by dividing the array into subarrays and transforming them.
- The dynamic programming solution will help us avoid redundant calculations by storing intermediate results for subproblems.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, so no need to handle empty arrays.
- For larger arrays (up to 500 elements), the dynamic programming approach should be efficient enough.
- If k equals the length of the array, then the whole array is a single subarray.
- The array will always contain at least one element and will never exceed 500 elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> memo;
vector<int> arr;
int k;
int dp(int i) {
    if(i == arr.size()) return 0;
    if(memo[i] != -1) return memo[i];
    int res = 0, mx = 0;
    for(int j = i; j < min((int)arr.size(), i + k); j++) {
        mx = max(mx, arr[j]);
        res = max(res, mx * (j - i + 1) + dp(j + 1));
    }
    return memo[i] = res;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    this->arr = arr;
    this->k = k;
    memo.resize(arr.size(), -1);
    return dp(0);
}
```

This function implements a dynamic programming solution to the problem of partitioning an array into subarrays such that the sum of the maximum elements in each subarray, multiplied by the subarray's length, is maximized. The function utilizes memoization to optimize overlapping subproblems.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> memo;
	```
	Declare a memoization vector 'memo' to store the results of subproblems and avoid redundant calculations.

2. **Variable Declaration**
	```cpp
	vector<int> arr;
	```
	Declare a vector 'arr' to hold the input array.

3. **Variable Declaration**
	```cpp
	int k;
	```
	Declare an integer 'k' to store the maximum length of subarrays that can be created during the partitioning process.

4. **Function Definition**
	```cpp
	int dp(int i) {
	```
	Define the recursive function 'dp' that solves the problem for subarrays starting at index 'i'.

5. **Base Case**
	```cpp
	    if(i == arr.size()) return 0;
	```
	If the index 'i' has reached the end of the array, return 0 since no further partitions can be made.

6. **Memoization**
	```cpp
	    if(memo[i] != -1) return memo[i];
	```
	Check if the subproblem for index 'i' has been solved before. If so, return the stored result from the 'memo' vector.

7. **Variable Initialization**
	```cpp
	    int res = 0, mx = 0;
	```
	Initialize the variables 'res' to store the maximum result and 'mx' to store the maximum value of the current subarray.

8. **Loop Through Subarrays**
	```cpp
	    for(int j = i; j < min((int)arr.size(), i + k); j++) {
	```
	Start a loop to explore all possible subarrays starting at index 'i' with a length of at most 'k'.

9. **Update Maximum Value**
	```cpp
	        mx = max(mx, arr[j]);
	```
	Update 'mx' to the maximum value between the current element 'arr[j]' and the previous maximum 'mx'.

10. **Calculate Result**
	```cpp
	        res = max(res, mx * (j - i + 1) + dp(j + 1));
	```
	For each subarray, calculate the potential result by multiplying the maximum value 'mx' by the subarray length and adding the result of the next subarray (recursively).

11. **Memoization Update**
	```cpp
	    return memo[i] = res;
	```
	Store the result of the current subproblem in the 'memo' vector and return it.

12. **Function Definition**
	```cpp
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
	```
	Define the function 'maxSumAfterPartitioning' which serves as the entry point to initialize variables and call the recursive 'dp' function.

13. **Variable Initialization**
	```cpp
	    this->arr = arr;
	```
	Assign the input array 'arr' to the class variable for use in the recursive function.

14. **Variable Initialization**
	```cpp
	    this->k = k;
	```
	Assign the value of 'k' (maximum subarray length) to the class variable.

15. **Memoization Initialization**
	```cpp
	    memo.resize(arr.size(), -1);
	```
	Resize the 'memo' vector to match the size of the input array and initialize all values to -1, indicating that no subproblems have been solved yet.

16. **Return Result**
	```cpp
	    return dp(0);
	```
	Call the 'dp' function starting from index 0 to compute and return the maximum sum after partitioning the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * k)
- **Worst Case:** O(n * k)

The time complexity is O(n * k) because for each element, we check up to k previous elements.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the dp array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-array-for-maximum-sum/description/)

---
{{< youtube kWhy4ZUBdOY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
