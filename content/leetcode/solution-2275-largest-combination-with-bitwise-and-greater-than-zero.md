
+++
authors = ["grid47"]
title = "Leetcode 2275: Largest Combination With Bitwise AND Greater Than Zero"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2275: Largest Combination With Bitwise AND Greater Than Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OyyfVofM_MM"
youtube_upload_date="2022-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OyyfVofM_MM/maxresdefault.webp"
comments = true
+++



---
You are given an array of positive integers `candidates`. Your task is to evaluate the bitwise AND of every possible combination of numbers in the array and return the size of the largest combination where the result of the AND operation is greater than 0. Each number in the array may only be used once in each combination.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `candidates` where each element represents a positive integer.
- **Example:** `Input: candidates = [32, 16, 24, 64, 128]`
- **Constraints:**
	- 1 <= candidates.length <= 10^5
	- 1 <= candidates[i] <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the size of the largest combination where the bitwise AND of the numbers in that combination is greater than 0.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest combination of numbers such that their bitwise AND is greater than 0.

- Iterate through all possible powers of 2 (bits).
- For each power of 2, count how many numbers in the array have the current bit set.
- Track the maximum count across all bits.
{{< dots >}}
### Problem Assumptions ✅
- Each element in the array is unique.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: candidates = [32, 16, 24, 64, 128]`  \
  **Explanation:** For this input, the largest combination with a bitwise AND greater than 0 is [32, 64, 128]. The AND operation of these numbers gives 32, so the result is 3.

- **Input:** `Input: candidates = [8, 8]`  \
  **Explanation:** The largest combination is [8, 8], which gives a bitwise AND of 8. Therefore, the answer is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we will evaluate the bitwise AND for each combination of numbers by iterating over different bits in the binary representation of the numbers. For each bit, we will count how many numbers have that bit set, and track the largest such group.

### Initial Thoughts 💭
- The AND operation is sensitive to individual bits. If two numbers share a 1 at the same position, the AND result will have that bit set.
- To find the largest group with a non-zero AND, we can focus on each bit position and count how many numbers have that bit set.
- By focusing on bits and counting how many numbers share each bit, we can efficiently find the largest combination.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the array length is guaranteed to be at least 1.
- Ensure that the solution works efficiently when there are 100,000 elements in the input array.
- If all numbers are identical, the result will be the size of the array.
- The solution must handle values up to 10^7 efficiently.
{{< dots >}}
## Code 💻
```cpp

int largestCombination(vector<int>& candidates) {
    int res = 0, cur = 0;
    for(int  i = 1; i < 10000000; i <<= 1) {
        cur = 0;
        for(int a: candidates)
            if(a & i)
            cur++;
        res = max(res, cur);
    }
    return res;
}
```

This code defines the function `largestCombination`, which calculates the largest number of candidates in the vector `candidates` that share the same bit set at a particular position. The function iterates through bit positions to find the combination with the most common bits set.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int largestCombination(vector<int>& candidates) {
	```
	This is the function header for `largestCombination`, which calculates the largest combination of candidates sharing the same bit at a certain position in their binary representations.

2. **Variable Initialization**
	```cpp
	    int res = 0, cur = 0;
	```
	Initializes two variables: `res` to 0 (to store the maximum number of candidates sharing the same bit), and `cur` to 0 (to count the candidates with the current bit set).

3. **Loop Start**
	```cpp
	    for(int  i = 1; i < 10000000; i <<= 1) {
	```
	Starts a loop where `i` represents the current bit position, initialized at 1 (the least significant bit) and doubles in value with each iteration, checking higher bit positions.

4. **Variable Reset**
	```cpp
	        cur = 0;
	```
	Resets `cur` to 0 for each bit position to count the candidates that have the current bit set.

5. **Inner Loop Start**
	```cpp
	        for(int a: candidates)
	```
	Starts an inner loop to iterate over each element `a` in the `candidates` vector.

6. **Bitwise AND Operation**
	```cpp
	            if(a & i)
	```
	Performs a bitwise AND operation between the candidate `a` and the current bit `i`. If the result is non-zero, it means the current candidate has the bit `i` set.

7. **Count Matching Bits**
	```cpp
	            cur++;
	```
	Increments the counter `cur` each time a candidate has the current bit set.

8. **Update Maximum**
	```cpp
	        res = max(res, cur);
	```
	Updates the `res` variable to the maximum of the current `res` and `cur`, which ensures that the largest count of candidates with a shared bit is retained.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the value of `res`, which represents the largest number of candidates that share the same bit set at the same position.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log M)
- **Average Case:** O(n log M)
- **Worst Case:** O(n log M)

The time complexity is O(n log M), where n is the number of candidates and M is the maximum possible value (10^7). This is because we iterate through each candidate for every bit position.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of intermediate results for each candidate.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/)

---
{{< youtube OyyfVofM_MM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
