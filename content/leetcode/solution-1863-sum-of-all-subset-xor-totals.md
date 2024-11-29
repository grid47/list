
+++
authors = ["grid47"]
title = "Leetcode 1863: Sum of All Subset XOR Totals"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1863: Sum of All Subset XOR Totals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Backtracking","Bit Manipulation","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "LI7YR-bwNYY"
youtube_upload_date="2024-05-20"
youtube_thumbnail="https://i.ytimg.com/vi/LI7YR-bwNYY/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers `nums`. The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty. For every subset of `nums`, calculate the XOR total and return the sum of all XOR totals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array `nums` consisting of integers.
- **Example:** `nums = [1, 3]`
- **Constraints:**
	- 1 <= nums.length <= 12
	- 1 <= nums[i] <= 20

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the sum of all XOR totals for every subset of the array `nums`.
- **Example:** `Output = 6`
- **Constraints:**
	- The output is the sum of XOR totals for every subset of the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the XOR total for every subset and return their sum.

- Step 1: Generate all subsets of the array.
- Step 2: For each subset, calculate the XOR total by performing a bitwise XOR of all elements in the subset.
- Step 3: Add the XOR totals of all subsets and return the sum.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [1, 3]`  \
  **Explanation:** There are 4 subsets: the empty subset, [1], [3], and [1,3]. The XOR totals for each subset are 0, 1, 3, and 2, respectively. The sum of these totals is 6.

- **Input:** `Input: [4, 1, 7]`  \
  **Explanation:** The eight subsets of [4, 1, 7] and their corresponding XOR totals are: 0, 4, 1, 7, 5, 3, 6, and 2. The sum of these totals is 35.

{{< dots >}}
## Approach 🚀
To solve this problem, we generate all possible subsets of the array and compute the XOR total for each subset. Then, we sum all these XOR totals.

### Initial Thoughts 💭
- The problem requires generating all subsets and computing XOR totals for each subset.
- Given that the number of elements in the array is small (at most 12), generating all subsets (2^n subsets) is feasible.
{{< dots >}}
### Edge Cases 🌐
- The input array is never empty as per the constraints.
- The maximum length of the array is 12, so generating subsets and calculating XOR totals will work efficiently within the time limits.
- Consider cases where all elements are the same, which will result in subsets with identical XOR totals.
- The array contains between 1 and 12 elements, each between 1 and 20.
{{< dots >}}
## Code 💻
```cpp
int subsetXORSum(vector<int>& nums) {
    int res = 0;
    for (auto i = 1; i < (1 << nums.size()); ++i) {
        int total = 0;
        for (auto j = 0; j < nums.size(); ++j)
            if (i & (1 << j))
                total ^= nums[j];
        res += total;
    }
    return res;
}
```

The `subsetXORSum` function calculates the sum of XORs of all subsets of the given array `nums`. It iterates through all subsets using bitwise operations and computes the XOR of each subset's elements, adding the result to a running total.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int subsetXORSum(vector<int>& nums) {
	```
	Define the function `subsetXORSum`, which takes a reference to a vector `nums` containing integers and returns an integer.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a variable `res` to store the cumulative XOR sum of all subsets.

3. **Outer Loop (Subset Generation)**
	```cpp
	    for (auto i = 1; i < (1 << nums.size()); ++i) {
	```
	Start a loop to iterate through all possible subsets of `nums` by generating numbers from 1 to `2^n - 1` using bitwise operations.

4. **Variable Initialization (Subset XOR)**
	```cpp
	        int total = 0;
	```
	Initialize a variable `total` to store the XOR of the current subset.

5. **Inner Loop (Element Check)**
	```cpp
	        for (auto j = 0; j < nums.size(); ++j)
	```
	Start a loop to iterate through each element of the `nums` array to check if the current element belongs to the current subset.

6. **Bitwise Check**
	```cpp
	            if (i & (1 << j))
	```
	Check if the `j`-th element is included in the current subset by using a bitwise AND operation. If the `j`-th bit of `i` is set, the element is included.

7. **Subset XOR Calculation**
	```cpp
	                total ^= nums[j];
	```
	XOR the value of the `j`-th element of `nums` with the current `total` to update the XOR for the current subset.

8. **Update Result**
	```cpp
	        res += total;
	```
	Add the XOR result of the current subset (`total`) to the running total `res`.

9. **Return Result**
	```cpp
	    return res;
	```
	Return the final result `res`, which contains the sum of XORs of all subsets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n * n)
- **Average Case:** O(2^n * n)
- **Worst Case:** O(2^n * n)

The time complexity is O(2^n * n), where n is the length of the input array. There are 2^n subsets and for each subset, we need to compute the XOR total which takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(2^n)
- **Worst Case:** O(2^n)

The space complexity is O(2^n) due to the space needed for storing the subsets and the XOR totals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

---
{{< youtube LI7YR-bwNYY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
