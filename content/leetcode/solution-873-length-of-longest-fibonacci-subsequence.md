
+++
authors = ["grid47"]
title = "Leetcode 873: Length of Longest Fibonacci Subsequence"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 873: Length of Longest Fibonacci Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BWj2qT3aTrA"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/BWj2qT3aTrA/maxresdefault.jpg"
comments = true
+++



---
A sequence is called Fibonacci-like if for all indices i, the following condition holds: xi + xi+1 == xi+2. You are given a strictly increasing sequence of positive integers, and your task is to find the length of the longest subsequence that is Fibonacci-like. If no such subsequence exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence arr of strictly increasing positive integers.
- **Example:** `Input: arr = [2, 4, 6, 10, 16, 26, 42]`
- **Constraints:**
	- 3 <= arr.length <= 1000
	- 1 <= arr[i] < arr[i + 1] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest Fibonacci-like subsequence. If no such subsequence exists, return 0.
- **Example:** `Output: 6`
- **Constraints:**
	- The output should be a single integer indicating the length of the longest Fibonacci-like subsequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subsequence of arr that satisfies the Fibonacci-like property.

- Iterate over all pairs of elements arr[i] and arr[j], with i < j, and try to extend the sequence by checking if arr[i] + arr[j] exists in arr.
- Track the length of the Fibonacci-like subsequences found using dynamic programming or hash-based methods.
- Return the length of the longest Fibonacci-like subsequence.
{{< dots >}}
### Problem Assumptions ✅
- The input array is strictly increasing.
- A subsequence is obtained by removing some or none of the elements from the original array while maintaining the relative order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [2, 4, 6, 10, 16, 26, 42]`  \
  **Explanation:** The longest Fibonacci-like subsequence is [2, 4, 6, 10, 16, 26] which has length 6.

- **Input:** `Input: arr = [1, 2, 3, 5, 8, 13, 21]`  \
  **Explanation:** The longest Fibonacci-like subsequence is [1, 2, 3, 5, 8, 13] which has length 6.

{{< dots >}}
## Approach 🚀
We will utilize dynamic programming and hash sets to efficiently track and extend possible Fibonacci-like subsequences.

### Initial Thoughts 💭
- We need to check all pairs (i, j) where i < j, then check if arr[i] + arr[j] is also present in arr.
- By using a hash set for fast lookups, we can avoid checking each possible subsequence manually.
- Dynamic programming can help track the lengths of valid Fibonacci-like subsequences efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the input array has fewer than 3 elements, return 0, as no Fibonacci-like subsequence can be formed.
- For large inputs (with up to 1000 elements), the solution should be efficient enough to handle the worst-case scenario within the time limits.
- The array may contain elements with values up to 10^9, so we need to ensure efficient lookups and handling of large numbers.
- The solution must handle inputs with up to 1000 elements and values up to 10^9.
{{< dots >}}
## Code 💻
```cpp
int lenLongestFibSubseq(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int res = 2, n = arr.size();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int a = arr[i], b = arr[j], l = 2;
            while(s.count(a + b))
            b = a + b, a = b - a, l++;
            res = max(res, l);
        }            
    }

    return res > 2? res: 0;
}
```

This code implements a solution to find the longest Fibonacci-like subsequence in an array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lenLongestFibSubseq(vector<int>& arr) {
	```
	The function definition starts by accepting an integer vector `arr`, which represents the input sequence to be processed.

2. **Data Structures**
	```cpp
	    unordered_set<int> s(arr.begin(), arr.end());
	```
	An unordered set `s` is created from the elements of the array `arr` for constant time lookup during the subsequence search.

3. **Initialization**
	```cpp
	    int res = 2, n = arr.size();
	```
	Initializes the result `res` to 2 (the minimum length of a Fibonacci-like subsequence) and calculates the size `n` of the input array `arr`.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer loop starts, iterating through each element `arr[i]` in the array.

5. **Nested Loop**
	```cpp
	        for(int j = i + 1; j < n; j++) {
	```
	The inner loop starts, iterating over the elements after `arr[i]`, creating all pairs for potential Fibonacci subsequences.

6. **Variable Assignment**
	```cpp
	            int a = arr[i], b = arr[j], l = 2;
	```
	Assigns the values of `arr[i]` and `arr[j]` to `a` and `b`, and initializes the length of the current Fibonacci-like subsequence `l` to 2.

7. **While Loop**
	```cpp
	            while(s.count(a + b))
	```
	Checks if the sum of `a` and `b` exists in the set `s`. If it does, it continues to build the subsequence.

8. **Update Values**
	```cpp
	            b = a + b, a = b - a, l++;
	```
	Updates the values of `a` and `b` to continue forming the subsequence and increments the subsequence length `l`.

9. **Update Result**
	```cpp
	            res = max(res, l);
	```
	Updates the result `res` with the maximum length of the Fibonacci-like subsequence found so far.

10. **Return Statement**
	```cpp
	    return res > 2? res: 0;
	```
	Returns the result `res` if it is greater than 2 (valid Fibonacci-like subsequence), otherwise returns 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is quadratic due to the nested iteration over all pairs of elements.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear due to the space required for storing the elements of the array and any intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/)

---
{{< youtube BWj2qT3aTrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
