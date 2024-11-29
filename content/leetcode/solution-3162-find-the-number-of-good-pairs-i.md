
+++
authors = ["grid47"]
title = "Leetcode 3162: Find the Number of Good Pairs I"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3162: Find the Number of Good Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "S-Q4eFfzGNc"
youtube_upload_date="2024-05-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/S-Q4eFfzGNc/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays `nums1` and `nums2` of lengths `n` and `m` respectively, and a positive integer `k`. A pair `(i, j)` is called good if `nums1[i]` is divisible by `nums2[j] * k` (0 <= i <= n - 1, 0 <= j <= m - 1). Your task is to return the total number of good pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays `nums1` and `nums2`, and a positive integer `k`.
- **Example:** `Example 1:
Input: nums1 = [1,2,5], nums2 = [1,2,3], k = 2
Output: 4`
- **Constraints:**
	- 1 <= n, m <= 50
	- 1 <= nums1[i], nums2[j] <= 50
	- 1 <= k <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of good pairs, where each pair satisfies the divisibility condition.
- **Example:** `Example 1:
Input: nums1 = [1,2,5], nums2 = [1,2,3], k = 2
Output: 4`
- **Constraints:**
	- The output should be an integer representing the count of good pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify all pairs (i, j) where `nums1[i]` is divisible by `nums2[j] * k`.

- Iterate through each element in `nums1`.
- For each element in `nums1`, iterate through each element in `nums2`.
- Check if `nums1[i] % (nums2[j] * k) == 0`.
- Count each valid pair where the condition holds.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `nums1` and `nums2` will always have values between 1 and 50.
- The integer `k` will also be between 1 and 50.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `nums1 = [1, 2, 5]`, `nums2 = [1, 2, 3]`, and `k = 2`, we have the following good pairs:
- (0, 0) because `1 % (1 * 2) == 0`
- (0, 1) because `1 % (2 * 2) == 0`
- (1, 0) because `2 % (1 * 2) == 0`
- (2, 1) because `5 % (2 * 2) == 0`.

{{< dots >}}
## Approach 🚀
The approach is straightforward: iterate over both arrays, check the divisibility condition, and count how many pairs satisfy the condition.

### Initial Thoughts 💭
- The condition involves checking divisibility of each element in `nums1` by the corresponding element in `nums2` multiplied by `k`.
- Since we are working with relatively small arrays (up to length 50), a double loop approach should be efficient enough.
{{< dots >}}
### Edge Cases 🌐
- Both `nums1` and `nums2` will never be empty.
- The solution should efficiently handle the maximum input size (n = 50, m = 50).
- Ensure the solution works when `k` is 1 or when `nums1[i]` and `nums2[j]` have values that are close to the upper limit of 50.
- Make sure the solution does not exceed the allowed time and space limits for the given constraints.
{{< dots >}}
## Code 💻
```cpp
int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    
    int res = 0, m = nums1.size(), n = nums2.size();
    
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(nums1[i] % (nums2[j] * k) == 0) res++;
    return res;
    
}
```

This code defines a function 'numberOfPairs' that calculates the number of pairs where the element in 'nums1' is divisible by the product of the corresponding element in 'nums2' and a constant 'k'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	```
	Defines the function 'numberOfPairs' that takes two vectors, 'nums1' and 'nums2', and an integer 'k', and returns the count of valid pairs.

2. **Variable Initialization**
	```cpp
	    int res = 0, m = nums1.size(), n = nums2.size();
	```
	Initializes the result variable 'res' to 0 and calculates the sizes of 'nums1' and 'nums2', storing them in 'm' and 'n', respectively.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Starts the outer loop that iterates over each element of the vector 'nums1'.

4. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Starts the inner loop that iterates over each element of the vector 'nums2'.

5. **Condition Check**
	```cpp
	        if(nums1[i] % (nums2[j] * k) == 0) res++;
	```
	Checks if the element in 'nums1' at index 'i' is divisible by the product of the element in 'nums2' at index 'j' and 'k'. If true, increments the result counter 'res'.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the value of 'res', which represents the total number of valid pairs found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m), where `n` and `m` are the lengths of `nums1` and `nums2`, respectively.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as no extra space is used other than the input arrays and a counter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/)

---
{{< youtube S-Q4eFfzGNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
