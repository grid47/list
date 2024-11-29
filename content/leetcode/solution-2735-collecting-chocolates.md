
+++
authors = ["grid47"]
title = "Leetcode 2735: Collecting Chocolates"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2735: Collecting Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FPkaxgatwoI"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/FPkaxgatwoI/maxresdefault.jpg"
comments = true
+++



---
You are given an array `nums` where each element represents the cost of collecting a chocolate of a specific type. You can perform an operation to change the types of chocolates, and each operation incurs a cost. Your task is to determine the minimum total cost to collect all types of chocolates.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `x`, where `nums[i]` represents the cost of collecting chocolate type `i` and `x` is the cost of performing one operation.
- **Example:** `nums = [10, 5, 20], x = 3`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^9
	- 1 <= x <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum total cost to collect chocolates of all types, given that you can perform the operation any number of times.
- **Example:** `Output: 11`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the total cost by strategically performing the operation while collecting chocolates.

- Loop over all types of chocolates and calculate the minimum cost for collecting them with the operations applied.
- For each type, calculate the cost of the operation and the cost of collecting the chocolate.
- Return the minimum total cost obtained.
{{< dots >}}
### Problem Assumptions ✅
- You can perform the operation any number of times, but the total cost of performing operations should be minimized.
- The array `nums` represents the cost of chocolates of distinct types.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [10, 5, 20], x = 3`  \
  **Explanation:** The initial cost is 35 (10 + 5 + 20). Performing the operation results in the following costs for collecting chocolates, ultimately yielding the minimum cost of 11.

- **Input:** `nums = [5, 1, 5], x = 2`  \
  **Explanation:** Here, the best strategy is to perform one operation to reduce the total cost, resulting in a minimum total of 6.

{{< dots >}}
## Approach 🚀
The problem can be solved by calculating the minimum cost by performing operations optimally and collecting chocolates based on the incurred costs.

### Initial Thoughts 💭
- The operation can be repeated, so we need to find the optimal number of times to perform it.
- It is beneficial to minimize the total cost of collecting chocolates.
- We need to consider all possible shifts of the chocolate types and calculate the total cost for each shift.
{{< dots >}}
### Edge Cases 🌐
- The array `nums` contains only one type of chocolate.
- The array `nums` has the maximum allowed length, and `x` is very large.
- The array `nums` contains chocolates with the same cost.
- The array `nums` is always non-empty.
{{< dots >}}
## Code 💻
```cpp
long long minCost(vector<int>& A, int x) {
    int n = A.size();
    vector<long long> res(n);
    for (int i = 0; i < n; i++) {
        res[i] += 1L * i * x;
        int cur = A[i];
        for (int k = 0; k < n; k++) {
            cur = min(cur, A[(i - k + n) % n]);
            res[k] += cur;
        }
    }
    return *std::min_element(res.begin(), res.end());
}
```

This function calculates the minimum cost based on the input vector `A` and an integer `x`. It iterates over the elements of `A` to compute and accumulate costs, ultimately returning the minimum value from the accumulated results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long minCost(vector<int>& A, int x) {
	```
	The function `minCost` is defined, which takes a vector `A` and an integer `x` as input and returns a `long long` result.

2. **Variable Initialization**
	```cpp
	    int n = A.size();
	```
	The size of the input vector `A` is stored in the variable `n`.

3. **Variable Initialization**
	```cpp
	    vector<long long> res(n);
	```
	A vector `res` of size `n` is initialized to store the accumulated results.

4. **Loop - Outer**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	An outer loop iterates over each index `i` in the range [0, n-1].

5. **Cost Calculation**
	```cpp
	        res[i] += 1L * i * x;
	```
	For each index `i`, the value `1L * i * x` is added to the corresponding element in the `res` vector.

6. **Variable Initialization**
	```cpp
	        int cur = A[i];
	```
	A variable `cur` is initialized to the current element `A[i]`.

7. **Loop - Inner**
	```cpp
	        for (int k = 0; k < n; k++) {
	```
	An inner loop iterates over each index `k` in the range [0, n-1].

8. **Min Calculation**
	```cpp
	            cur = min(cur, A[(i - k + n) % n]);
	```
	In each iteration of the inner loop, the variable `cur` is updated to the minimum of its current value and the element `A[(i - k + n) % n]` (ensuring circular indexing).

9. **Cost Update**
	```cpp
	            res[k] += cur;
	```
	The updated value of `cur` is added to `res[k]` in the `res` vector.

10. **Return Statement**
	```cpp
	    return *std::min_element(res.begin(), res.end());
	```
	The function returns the smallest value from the `res` vector, which is found using `std::min_element`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2) where n is the length of the array.
- **Average Case:** O(n^2) due to iterating over all possible shifts.
- **Worst Case:** O(n^2) since we need to check every shift and calculate the associated cost.

The time complexity is quadratic because for each chocolate type, we are calculating the cost for all possible shifts.

### Space Complexity 💾
- **Best Case:** O(n) if minimal space is used for calculations.
- **Worst Case:** O(n) due to the additional storage for the result array.

The space complexity is linear since we use a result array to store the computed costs for each shift.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/collecting-chocolates/description/)

---
{{< youtube FPkaxgatwoI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
