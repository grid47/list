
+++
authors = ["grid47"]
title = "Leetcode 2859: Sum of Values at Indices With K Set Bits"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2859: Sum of Values at Indices With K Set Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ditzt6BYVEs"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ditzt6BYVEs/maxresdefault.webp"
comments = true
+++



---
Given a list of integers and an integer k, return the sum of all elements whose indices have exactly k set bits in their binary representation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer list and an integer k.
- **Example:** `nums = [3, 8, 5, 7, 10], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^5
	- 0 <= k <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the elements whose indices have exactly k set bits.
- **Example:** `Output: 18`
- **Constraints:**
	- The output is an integer representing the sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sum the elements in nums whose indices contain exactly k set bits in their binary representation.

- Initialize a variable to store the result as 0.
- Iterate over the indices of the array.
- For each index, count the number of set bits in the binary representation of the index.
- If the count of set bits equals k, add the corresponding element in nums to the result.
- Return the result after iterating through all indices.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums will not be empty.
- The value of k will always be a valid integer within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 8, 5, 7, 10], k = 2`  \
  **Explanation:** Indices 3 and 5 have exactly 2 set bits in their binary representation. The sum of nums[3] + nums[5] is 18.

- **Input:** `nums = [12, 6, 8, 15], k = 1`  \
  **Explanation:** Indices 1 and 2 have exactly 1 set bit in their binary representation. The sum of nums[1] + nums[2] is 12.

{{< dots >}}
## Approach 🚀
Use bitwise operations to count the set bits of indices and add the corresponding elements from nums if the number of set bits equals k.

### Initial Thoughts 💭
- The problem asks for a sum based on a binary property of the indices.
- A straightforward approach is to iterate over the list and count the set bits in the binary representation of the index.
- Using bitwise operations like AND and shifting can help efficiently count the set bits in the index.
{{< dots >}}
### Edge Cases 🌐
- The input nums array will never be empty according to the constraints.
- The solution should efficiently handle arrays of size up to 1000.
- When k = 0, only indices with no set bits (index 0) will contribute to the sum.
- The algorithm must handle up to 1000 elements in nums efficiently.
{{< dots >}}
## Code 💻
```cpp
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
  int res = 0;

  for(int i = 0; i < nums.size(); i++) {
    int c = 0;
    int copy = i;
    while(copy) {
        c += copy & 1;
        copy >>= 1;
    }
    if(c == k) {
        res += nums[i];
    }
  }

  return res;
}
```

This function calculates the sum of elements in `nums` whose indices have exactly `k` set bits in their binary representation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumIndicesWithKSetBits(vector<int>& nums, int k) {
	```
	Defines the function `sumIndicesWithKSetBits` that accepts a vector `nums` and an integer `k`, and calculates the sum of the elements in `nums` whose indices have exactly `k` set bits.

2. **Variable Initialization**
	```cpp
	  int res = 0;
	```
	Initializes the result variable `res` to store the sum of valid elements whose indices have exactly `k` set bits.

3. **Loop Setup**
	```cpp
	  for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop that iterates through each index `i` of the vector `nums`.

4. **Set Bit Count Initialization**
	```cpp
	    int c = 0;
	```
	Declares an integer `c` to store the count of set bits in the binary representation of index `i`.

5. **Copy Index**
	```cpp
	    int copy = i;
	```
	Creates a copy of the index `i` in the variable `copy` to manipulate its bits.

6. **Counting Set Bits**
	```cpp
	    while(copy) {
	```
	Starts a while loop that continues until all bits of `copy` are processed.

7. **Bitwise Count**
	```cpp
	        c += copy & 1;
	```
	Adds 1 to `c` if the least significant bit of `copy` is 1 (i.e., if it is set).

8. **Shift Bits**
	```cpp
	        copy >>= 1;
	```
	Right shifts `copy` by 1 bit to process the next bit in the next iteration.

9. **Set Bit Check**
	```cpp
	    if(c == k) {
	```
	Checks if the number of set bits `c` in the current index `i` is equal to `k`.

10. **Update Result**
	```cpp
	        res += nums[i];
	```
	If the condition is met, adds the value of `nums[i]` to the result `res`.

11. **Return Statement**
	```cpp
	  return res;
	```
	Returns the sum of elements in `nums` whose indices have exactly `k` set bits.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate over the array of nums once, and counting set bits is O(1) per index.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a few extra variables for the result and the bit count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/)

---
{{< youtube Ditzt6BYVEs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
