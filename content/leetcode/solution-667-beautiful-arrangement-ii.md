
+++
authors = ["grid47"]
title = "Leetcode 667: Beautiful Arrangement II"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 667: Beautiful Arrangement II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/667.webp"
youtube = "A8-_z6gurGc"
youtube_upload_date="2021-04-12"
youtube_thumbnail="https://i.ytimg.com/vi/A8-_z6gurGc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/667.webp" 
    alt="A set of arrangements where the beautiful ones glow softly, based on the rules of arrangement."
    caption="Solution to LeetCode 667: Beautiful Arrangement II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integers n and k, construct a list of n different positive integers from 1 to n such that the absolute differences between consecutive elements contain exactly k distinct integers. Return any valid solution.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers n and k, where n is the size of the list and k is the number of distinct differences to be present.
- **Example:** `n = 4, k = 1`
- **Constraints:**
	- 1 <= k < n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of n distinct integers between 1 and n that satisfies the condition of having exactly k distinct differences.
- **Example:** `[1, 2, 3, 4]`
- **Constraints:**
	- The answer list must contain distinct integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct the list such that the differences between consecutive elements have exactly k distinct values.

- 1. Start by choosing numbers from 1 to n.
- 2. Arrange these numbers in a way that the absolute differences between consecutive numbers contain exactly k distinct values.
- 3. Adjust the placement of numbers to ensure exactly k distinct differences.
{{< dots >}}
### Problem Assumptions ✅
- The integers in the output list must be distinct.
- There can be multiple valid answers.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4, k = 1`  \
  **Explanation:** The differences between consecutive elements in the list [1, 2, 3, 4] are all 1, so there is exactly 1 distinct difference.

- **Input:** `n = 5, k = 2`  \
  **Explanation:** The list [1, 5, 2, 4, 3] has differences of [4, 3, 2, 1], with exactly 2 distinct values: 1 and 3.

{{< dots >}}
## Approach 🚀
The approach for constructing the list involves systematically selecting elements such that the absolute differences between consecutive numbers meet the requirements.

### Initial Thoughts 💭
- We need to control the number of distinct absolute differences between consecutive elements.
- The arrangement of the numbers must balance the number of unique differences.
- By alternating between the smallest and largest remaining numbers, we can ensure a controlled difference distribution.
{{< dots >}}
### Edge Cases 🌐
- The input will always have valid n and k, so no empty cases need to be handled.
- For large values of n and k, ensure that the algorithm is efficient enough to handle up to 10^4 elements.
- If k = 1, the list will have identical differences, which means the sequence must be in increasing or decreasing order.
- Ensure that the list contains distinct integers between 1 and n.
{{< dots >}}
## Code 💻
```cpp
vector<int> constructArray(int n, int k) {
    vector<int> res;
    for(int i = 1, j = n; i <= j; ) {
        if(k > 0) {
            res.push_back(k--%2? i++: j--);
        } else res.push_back(i++);
    }
    return res;
}
```

This function constructs an array of integers from 1 to n such that the absolute difference between consecutive integers is as large as possible for the first k elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> constructArray(int n, int k) {
	```
	This is the function definition for `constructArray`, which takes two parameters: `n` (the size of the array) and `k` (the number of elements with the largest absolute difference between consecutive numbers). It returns a vector of integers.

2. **Result Initialization**
	```cpp
	    vector<int> res;
	```
	Initialize an empty vector `res` that will hold the result of the constructed array.

3. **Main Loop**
	```cpp
	    for(int i = 1, j = n; i <= j; ) {
	```
	Start a `for` loop with two pointers: `i` initialized to 1 (the first number) and `j` initialized to `n` (the last number). The loop continues until `i` exceeds `j`.

4. **Condition Check**
	```cpp
	        if(k > 0) {
	```
	Check if `k` is greater than 0, indicating that we should alternate between the smallest and largest numbers to maximize the difference.

5. **Push Number with Alternating Direction**
	```cpp
	            res.push_back(k--%2? i++: j--);
	```
	If `k > 0`, decrement `k` and decide whether to push the next smallest (`i++`) or largest (`j--`) number, alternating between them. This maximizes the difference between consecutive numbers for the first `k` elements.

6. **Push Incremented Number**
	```cpp
	        } else res.push_back(i++);
	```
	If `k` is 0, just push the next smallest number (`i++`) into the result vector. This ensures that the rest of the array is filled in increasing order.

7. **Return Result**
	```cpp
	    return res;
	```
	Return the constructed result vector `res`, which contains the integers arranged with the maximum difference for the first `k` elements and the rest in increasing order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we are constructing a list of size n and performing constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the list of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/beautiful-arrangement-ii/description/)

---
{{< youtube A8-_z6gurGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
