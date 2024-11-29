
+++
authors = ["grid47"]
title = "Leetcode 2717: Semi-Ordered Permutation"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2717: Semi-Ordered Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "u4bKt4MBHUU"
youtube_upload_date="2023-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/u4bKt4MBHUU/maxresdefault.jpg"
comments = true
+++



---
You are given a permutation of integers from 1 to n. A permutation is called semi-ordered if the first element equals 1 and the last element equals n. You can perform the operation of swapping two adjacent elements as many times as needed to make the permutation semi-ordered. Your task is to return the minimum number of swaps required.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of integers `nums` representing a permutation of numbers from 1 to `n`.
- **Example:** `nums = [3, 1, 4, 2]`
- **Constraints:**
	- 2 <= nums.length <= 50
	- nums contains a permutation of integers from 1 to n.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of adjacent swaps required to make the permutation semi-ordered.
- **Example:** `3`
- **Constraints:**
	- The output is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the minimum number of adjacent swaps needed to make the permutation semi-ordered.

- Identify the positions of the numbers 1 and n.
- Calculate the number of swaps required to move the 1 to the start and n to the end.
- Adjust for the case where 1 and n are out of order in relation to each other.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid permutation with no duplicates.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In the case of `nums = [3, 1, 4, 2]`, the required number of swaps is 3. First, we swap `3` and `1`, then swap `4` and `2`, and finally swap `3` and `2`.

- **Input:** `Example 2`  \
  **Explanation:** In the case of `nums = [2, 4, 1, 3]`, the required number of swaps is 4. First, we swap `2` and `1`, then swap `4` and `3`, and finally swap `2` and `3`.

- **Input:** `Example 3`  \
  **Explanation:** In the case of `nums = [1, 3, 4, 2, 5]`, the required number of swaps is 2. First, we swap `4` and `2`, then swap `3` and `2`.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to calculate the positions of the first and last elements in the permutation, then determine the minimum number of swaps needed to reorder the permutation into the desired form.

### Initial Thoughts 💭
- The first number in the sequence must be `1` and the last number must be `n`.
- We need to count how far `1` is from the first position and `n` is from the last position.
- We can calculate the required swaps by determining the positions of `1` and `n` in the permutation.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the length of `nums` is always at least 2.
- For large inputs, we handle arrays with up to 50 elements.
- If `nums` is already semi-ordered, no swaps are required.
- The solution must handle arrays of up to 50 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int semiOrderedPermutation(vector<int>& A) {
    int n = A.size(), 
    i = find(A.begin(), A.end(), 1) - A.begin(), 
    j = find(A.begin(), A.end(), n) - A.begin();
    return i + n - 1 - j - (i > j);
}
```

This function calculates the number of swaps required to semi-order a permutation of numbers from 1 to n. The permutation is considered semi-ordered if the smallest number (1) appears before the largest number (n).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int semiOrderedPermutation(vector<int>& A) {
	```
	The function `semiOrderedPermutation` is defined, taking a reference to a vector `A` as its parameter. The function returns an integer, representing the number of swaps required.

2. **Variable Initialization**
	```cpp
	    int n = A.size(), 
	```
	The variable `n` is initialized to the size of the vector `A`, which represents the total number of elements in the permutation.

3. **Find Position of 1**
	```cpp
	    i = find(A.begin(), A.end(), 1) - A.begin(), 
	```
	The variable `i` is assigned the index of the element `1` in the vector `A`. This is done using the `find` function, which returns an iterator, and the index is calculated by subtracting `A.begin()` from the iterator.

4. **Find Position of n**
	```cpp
	    j = find(A.begin(), A.end(), n) - A.begin();
	```
	The variable `j` is assigned the index of the element `n` in the vector `A`, similarly using the `find` function.

5. **Return Swap Calculation**
	```cpp
	    return i + n - 1 - j - (i > j);
	```
	The function returns the number of swaps required to semi-order the permutation. The formula accounts for the positions of `1` and `n` and adjusts the count if `i` (position of `1`) is greater than `j` (position of `n`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution runs in linear time due to finding the positions of `1` and `n` in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need to store a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/semi-ordered-permutation/description/)

---
{{< youtube u4bKt4MBHUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
