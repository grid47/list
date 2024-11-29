
+++
authors = ["grid47"]
title = "Leetcode 477: Total Hamming Distance"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 477: Total Hamming Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/477.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/477.webp" 
    alt="A sequence of binary strings where the total Hamming distance is calculated, with each distance step gently highlighted"
    caption="Solution to LeetCode 477: Total Hamming Distance Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
The Hamming distance between two integers is the number of positions at which the corresponding bits differ. Given an integer array `nums`, return the sum of Hamming distances between all pairs of integers in `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums`.
- **Example:** `nums = [3, 10, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of Hamming distances between all pairs of integers in `nums`.
- **Example:** `Output: 8`
- **Constraints:**
	- The answer will fit in a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total Hamming distance between all pairs of integers in the array.

- 1. Loop through each bit position (from 0 to 31, as numbers are within the 32-bit range).
- 2. For each bit position, count how many numbers have that bit set (1).
- 3. For each bit position, the total number of differing bits is `bitCount * (n - bitCount)`, where `n` is the size of the array and `bitCount` is the number of 1s in the current bit position.
- 4. Sum up the contributions from all bit positions.
{{< dots >}}
### Problem Assumptions ✅
- The values in `nums` are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 10, 5]`  \
  **Explanation:** The binary representations of 3, 10, and 5 are compared bit by bit to calculate the Hamming distances between all pairs.

- **Input:** `nums = [2, 3, 2]`  \
  **Explanation:** In this case, the binary representations of 2, 3, and 2 are used to calculate the Hamming distances.

{{< dots >}}
## Approach 🚀
The approach involves calculating the Hamming distance by iterating through each bit position and counting how many numbers have a 1 at each position.

### Initial Thoughts 💭
- The problem is a bitwise problem, which makes it suitable for bit manipulation techniques.
- By considering each bit position separately, we can efficiently calculate the total Hamming distance.
- We can process each bit independently to determine how many numbers have differing bits in that position.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the array, as per the constraints.
- The solution needs to handle large arrays of size up to 10^4 efficiently.
- If all numbers in `nums` are the same, the Hamming distance between any pair will be 0.
- The solution must work within the constraints, where the array size is up to 10^4 and the numbers can be as large as 10^9.
{{< dots >}}
## Code 💻
```cpp
int totalHammingDistance(vector<int>& nums) {
    int total = 0, n = nums.size();
    for(int i = 0; i < 32; i++) {
        int bitCnt = 0;
        for(int j = 0; j < nums.size(); j++)
            bitCnt += (nums[j] >> i) & 1;
        
        total += bitCnt * (n - bitCnt);
    }
    return total;
}
```

The `totalHammingDistance` function computes the total Hamming distance between all pairs of integers in the input vector `nums`. The Hamming distance is calculated by comparing the bits of the integers. The function iterates through all 32 bits of each number and calculates how many times the bits differ across all integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int totalHammingDistance(vector<int>& nums) {
	```
	Defines the `totalHammingDistance` function that takes a vector of integers `nums` and calculates the total Hamming distance between all pairs of integers.

2. **Variable Initialization**
	```cpp
	    int total = 0, n = nums.size();
	```
	Initializes two variables: `total` to accumulate the total Hamming distance, and `n` to store the size of the `nums` vector.

3. **Bit Manipulation**
	```cpp
	    for(int i = 0; i < 32; i++) {
	```
	Begins a loop that iterates over all 32 bits (assuming 32-bit integers) to calculate the Hamming distance for each bit position.

4. **Variable Initialization**
	```cpp
	        int bitCnt = 0;
	```
	Initializes the `bitCnt` variable to count how many numbers have a `1` at the current bit position `i`.

5. **Bitwise Operation**
	```cpp
	        for(int j = 0; j < nums.size(); j++)
	```
	Begins a loop that iterates through each number in the `nums` vector.

6. **Bitwise Operation**
	```cpp
	            bitCnt += (nums[j] >> i) & 1;
	```
	Performs a bitwise right shift on `nums[j]` to examine the `i`th bit. If the bit is `1`, increments `bitCnt`.

7. **Accumulation**
	```cpp
	        total += bitCnt * (n - bitCnt);
	```
	Updates the `total` by adding the number of differing bits between pairs. For each bit, the number of differing bits is the product of `bitCnt` and `(n - bitCnt)`.

8. **Return Statement**
	```cpp
	    return total;
	```
	Returns the total Hamming distance.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * 32)
- **Average Case:** O(n * 32)
- **Worst Case:** O(n * 32)

The time complexity is O(n * 32), where n is the size of the `nums` array, and 32 is the number of bits to consider.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the solution uses only a few variables to track the bit counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/total-hamming-distance/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
