
+++
authors = ["grid47"]
title = "Leetcode 3179: Find the N-th Value After K Seconds"
date = "2023-12-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3179: Find the N-th Value After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4sO18TX7Qzw"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4sO18TX7Qzw/maxresdefault.webp"
comments = true
+++



---
You are given two integers, `n` and `k`. Initially, you have an array `a` of size `n`, where each element is initialized to 1. After each second, every element in the array is updated to be the sum of all preceding elements plus the element itself. The process repeats for `k` seconds. You need to return the value of the last element of the array, `a[n - 1]`, after `k` seconds. Since the result may be very large, return it modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: `n` (the number of elements in the array) and `k` (the number of seconds the array undergoes updates).
- **Example:** `Example 1:
Input: n = 4, k = 3
Output: 20
Explanation: After 3 seconds, the last element becomes 20.`
- **Constraints:**
	- 1 <= n, k <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the value of the last element of the array after `k` seconds, modulo (10^9 + 7).
- **Example:** `Example 2:
Input: n = 5, k = 4
Output: 35
Explanation: After 4 seconds, the last element becomes 35.`
- **Constraints:**
	- The output will be an integer modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the update of the array for `k` seconds and compute the value of the last element modulo (10^9 + 7).

- Initialize an array `a` of size `n` with all elements set to 1.
- For each second, update each element of the array such that each element becomes the sum of all preceding elements plus the element itself.
- Repeat this for `k` seconds.
- Return the value of the last element modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are initially set to 1.
- The number of seconds is limited to 1000, making an iterative approach feasible.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `n = 4` and `k = 3`, the array starts as [1, 1, 1, 1]. After 1 second, the array becomes [1, 2, 3, 4]. After 2 seconds, it becomes [1, 3, 6, 10], and after 3 seconds, it becomes [1, 4, 10, 20]. Therefore, the last element after 3 seconds is 20.

- **Input:** `Example 2:`  \
  **Explanation:** For `n = 5` and `k = 4`, the array starts as [1, 1, 1, 1, 1]. After 1 second, the array becomes [1, 2, 3, 4, 5], after 2 seconds it becomes [1, 3, 6, 10, 15], after 3 seconds it becomes [1, 4, 10, 20, 35], and after 4 seconds, the array becomes [1, 5, 15, 35, 70]. Thus, the last element after 4 seconds is 35.

{{< dots >}}
## Approach 🚀
We will simulate the array updates for `k` seconds. After each second, every element of the array is updated based on the sum of all previous elements. This can be efficiently implemented using dynamic programming.

### Initial Thoughts 💭
- The problem can be solved through dynamic programming by iterating over the seconds and updating the array in-place.
- The last element after `k` seconds is influenced by all the previous elements.
- We need to be mindful of performance given that both `n` and `k` can go up to 1000. Using dynamic programming with a 2D array should work efficiently within these limits.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the problem always provides values for `n` and `k`.
- The approach should handle the maximum values of `n = 1000` and `k = 1000` efficiently, using dynamic programming.
- For `n = 1` and `k = 1`, the result is trivially 1 because the array does not change.
- The solution should be able to handle the constraints up to `n = 1000` and `k = 1000` efficiently.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
int valueAfterKSeconds(int n, int k) {
    vector<vector<long>> mtx(k + 1, vector<long>(n, 1));
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j < n; j++) {
            mtx[i][j] = (mtx[i - 1][j] + mtx[i][j - 1]) % mod;   
        }
    }
    return mtx[k][n - 1];
}
```

This function calculates the value after `k` seconds using a dynamic programming approach with a 2D matrix, where the value is computed based on the sum of previous states modulo `1e9 + 7`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Modulo Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	The modulo value `mod` is initialized to `1e9 + 7`, a common modulus used to prevent overflow in large numbers.

2. **Function Definition**
	```cpp
	int valueAfterKSeconds(int n, int k) {
	```
	The function `valueAfterKSeconds` is defined, taking two parameters: `n` (the number of positions) and `k` (the number of seconds).

3. **Matrix Initialization**
	```cpp
	    vector<vector<long>> mtx(k + 1, vector<long>(n, 1));
	```
	A 2D matrix `mtx` is initialized with dimensions `(k + 1) x n`, and all elements are set to `1`.

4. **Outer Loop Start**
	```cpp
	    for(int i = 1; i <= k; i++) {
	```
	The outer loop begins, iterating over `k` seconds (from `1` to `k`).

5. **Inner Loop Start**
	```cpp
	        for(int j = 1; j < n; j++) {
	```
	The inner loop starts, iterating over `n` positions (from `1` to `n-1`).

6. **Matrix Update**
	```cpp
	            mtx[i][j] = (mtx[i - 1][j] + mtx[i][j - 1]) % mod;   
	```
	The current matrix element `mtx[i][j]` is updated by adding the values from the previous row and the previous column, and then applying the modulo operation to avoid overflow.

7. **Return Statement**
	```cpp
	    return mtx[k][n - 1];
	```
	The function returns the final value located at the `k`-th row and the `n-1`-th column of the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k * n)
- **Average Case:** O(k * n)
- **Worst Case:** O(k * n)

The time complexity is O(k * n) because we update the array for each second, and each element takes constant time to update.

### Space Complexity 💾
- **Best Case:** O(k * n)
- **Worst Case:** O(k * n)

The space complexity is O(k * n) due to the storage of the 2D array `mtx` used for dynamic programming.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/)

---
{{< youtube 4sO18TX7Qzw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
