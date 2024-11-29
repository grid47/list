
+++
authors = ["grid47"]
title = "Leetcode 1131: Maximum of Absolute Value Expression"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1131: Maximum of Absolute Value Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cNEQMhXa1uI"
youtube_upload_date="2022-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/cNEQMhXa1uI/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays arr1 and arr2 of integers, both having equal lengths. Calculate the maximum value of the expression: |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| for all pairs of indices i and j, where 0 <= i, j < arr1.length.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays arr1 and arr2 of integers of equal length.
- **Example:** `Input: arr1 = [3, 1, 4, 5], arr2 = [2, 0, 3, 4]`
- **Constraints:**
	- 2 <= arr1.length == arr2.length <= 40000
	- -10^6 <= arr1[i], arr2[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value of the expression: |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|.
- **Example:** `Output: 9`
- **Constraints:**
	- The answer fits within a 32-bit signed integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum value of the expression |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| for all pairs of indices.

- Iterate through the array using nested loops for indices i and j.
- For each pair of indices, calculate the expression value and update the result if it's larger than the current maximum value.
{{< dots >}}
### Problem Assumptions ✅
- The arrays are guaranteed to have the same length, and there will always be at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr1 = [3, 1, 4, 5], arr2 = [2, 0, 3, 4]`  \
  **Explanation:** For this example, the maximum value of the expression occurs at indices i = 0 and j = 3. The value of the expression is 9.

- **Input:** `Input: arr1 = [1, -2, 3], arr2 = [0, 2, 1]`  \
  **Explanation:** For this example, the maximum value occurs at indices i = 0 and j = 2. The value of the expression is 8.

{{< dots >}}
## Approach 🚀
The solution involves iterating through all pairs of indices and computing the value of the expression for each pair to find the maximum value.

### Initial Thoughts 💭
- We need to evaluate the expression for every possible pair of indices in the arrays.
- Considering the constraints, a brute force solution might be inefficient. We need to think of ways to optimize the approach.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will always be at least two elements in each array.
- The solution should be efficient enough to handle the largest input sizes (up to 40,000 elements).
- Consider arrays where all elements are the same or have maximum and minimum values, as this may affect the result.
- Ensure that the solution works efficiently within the provided constraints.
{{< dots >}}
## Code 💻
```cpp
int maxAbsValExpr(vector<int>& x, vector<int>& y) {
    int res = 0, n = x.size(), smallest, cur;
    for(int p: {1, -1}) {
        for(int q: {1, -1}) {
            smallest = p * x[0] + q * y[0] + 0;
            for(int i = 1; i < n; i++) {
                cur = p * x[i] + q * y[i] + i;
                res = max(res, cur - smallest);
                smallest = min(smallest, cur);
            }
        }
    }
    return res;
}
```

This function calculates the maximum absolute value expression of two arrays `x` and `y` by considering different combinations of sign changes and calculating the maximum difference of the expression values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxAbsValExpr(vector<int>& x, vector<int>& y) {
	```
	This line defines the function `maxAbsValExpr`, which takes two integer arrays `x` and `y` and returns the maximum absolute value expression computed from them.

2. **Variable Initialization**
	```cpp
	    int res = 0, n = x.size(), smallest, cur;
	```
	The variables `res` (to store the result), `n` (the size of the input arrays), `smallest` (to track the smallest computed expression), and `cur` (to store the current expression value) are initialized.

3. **Outer Loop**
	```cpp
	    for(int p: {1, -1}) {
	```
	This outer `for` loop iterates over two values, `1` and `-1`, representing the possible signs to apply to the elements of array `x`.

4. **Inner Loop**
	```cpp
	        for(int q: {1, -1}) {
	```
	The inner `for` loop iterates over two values, `1` and `-1`, representing the possible signs to apply to the elements of array `y`.

5. **Initial Expression Calculation**
	```cpp
	            smallest = p * x[0] + q * y[0] + 0;
	```
	The initial expression for the first pair of elements from `x` and `y` is computed and assigned to `smallest`, where the sign for `x[0]` is determined by `p` and the sign for `y[0]` is determined by `q`.

6. **Loop Over Remaining Elements**
	```cpp
	            for(int i = 1; i < n; i++) {
	```
	This `for` loop iterates over the remaining elements of the arrays `x` and `y` starting from index `1`.

7. **Current Expression Calculation**
	```cpp
	                cur = p * x[i] + q * y[i] + i;
	```
	The current expression value `cur` is computed for each element of the arrays `x` and `y` with the corresponding sign applied based on `p` and `q`, and adding the index `i`.

8. **Update Result**
	```cpp
	                res = max(res, cur - smallest);
	```
	The result `res` is updated with the maximum value between the current result and the difference between `cur` and `smallest`.

9. **Update Smallest Value**
	```cpp
	                smallest = min(smallest, cur);
	```
	The variable `smallest` is updated to store the minimum value between `smallest` and the current expression value `cur`.

10. **Return Statement**
	```cpp
	    return res;
	```
	The final result `res` is returned, which contains the maximum absolute value expression.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the nested iteration over all pairs of indices.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution only requires a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-of-absolute-value-expression/description/)

---
{{< youtube cNEQMhXa1uI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
