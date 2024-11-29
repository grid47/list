
+++
authors = ["grid47"]
title = "Leetcode 421: Maximum XOR of Two Numbers in an Array"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 421: Maximum XOR of Two Numbers in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/421.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/421.webp" 
    alt="A glowing sequence of numbers where the XOR result is softly highlighted, showing the maximum possible value."
    caption="Solution to LeetCode 421: Maximum XOR of Two Numbers in an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, your task is to find the maximum result of the XOR operation between any two elements from the array. The goal is to maximize the XOR value of any pair of numbers in the array, where the XOR of two numbers is computed using the bitwise XOR operation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array nums, where each element represents an integer in the array.
- **Example:** `Input: nums = [7, 15, 4, 8, 3]`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^5
	- 0 <= nums[i] <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the maximum XOR value achievable by any pair of elements from the given array.
- **Example:** `Output: 15`
- **Constraints:**
	- The result is an integer that represents the maximum XOR of any two numbers in the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The objective is to find the maximum XOR result by efficiently evaluating pairs of numbers in the array.

- Use a trie data structure to store binary representations of numbers in the array.
- For each number, try to find a previously inserted number in the trie that maximizes the XOR result.
- Keep track of the highest XOR value encountered during this process.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one element.
- Numbers are non-negative integers within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: nums = [7, 15, 4, 8, 3]`  \
  **Explanation:** The maximum XOR is achieved by XORing 7 and 15, which gives 15. Hence, the output is 15.

{{< dots >}}
## Approach 🚀
A trie (prefix tree) is used to store the binary representations of the numbers in the array. This helps to efficiently compute the XOR of each number with the previous numbers in the array and maximize the XOR result.

### Initial Thoughts 💭
- The XOR operation benefits from differing bits, so we want to maximize the differences between the bits of two numbers.
- A trie allows us to explore each bit of the number and compare it efficiently with other numbers.
- Using a trie, we can find the best number to XOR with each element, and we do this efficiently in O(1) time per bit.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0 since no XOR operation can be performed.
- For large arrays, ensure that the solution can handle the upper constraint of 200,000 elements efficiently.
- Arrays where all elements are the same should also return 0, as the XOR of two identical numbers is 0.
- The solution should work efficiently even for the largest input sizes, using time complexity close to O(n) with a constant space complexity for each element.
{{< dots >}}
## Code 💻
```cpp
int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = new TrieNode();
    int n = nums.size();
    for(int i = 0; i < n; i++)
        root->add(nums[i]);
    
    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, root->max(nums[i]));
    
    return res;
}
```

This function finds the maximum XOR of two numbers from the given array `nums`. It utilizes a Trie data structure to efficiently calculate the maximum XOR.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int findMaximumXOR(vector<int>& nums) {
	```
	This line declares the function `findMaximumXOR`, which takes a vector of integers `nums` and returns an integer representing the maximum XOR value found from any two numbers in the array.

2. **Trie Initialization**
	```cpp
	    TrieNode* root = new TrieNode();
	```
	Here, we initialize a new TrieNode `root`. This Trie will be used to store the binary representations of the numbers in `nums` to facilitate the XOR calculations.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	This line initializes the variable `n` to store the size of the `nums` array.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This starts a loop that will iterate over each element of the `nums` array.

5. **Trie Insertion**
	```cpp
	        root->add(nums[i]);
	```
	This calls the `add` method of the Trie, which inserts the binary representation of `nums[i]` into the Trie. This helps in optimizing the XOR calculations in later steps.

6. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This initializes a variable `res` to 0. This will store the maximum XOR value found during the iterations over the `nums` array.

7. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This starts another loop to iterate over each element in `nums` again, this time to compute the maximum XOR value.

8. **XOR Calculation**
	```cpp
	        res = max(res, root->max(nums[i]));
	```
	This calculates the maximum XOR of `nums[i]` with the numbers already stored in the Trie by calling the `max` method on `root`. It updates `res` to store the maximum XOR value found so far.

9. **Return Statement**
	```cpp
	    return res;
	```
	This returns the maximum XOR value found after iterating over all the elements in `nums`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of elements in the input array.
- **Average Case:** O(n), as we process each element once.
- **Worst Case:** O(n), due to the linear traversal of the array and trie.

The time complexity is linear with respect to the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(n), since the trie space is proportional to the number of numbers in the array.
- **Worst Case:** O(n), where n is the number of elements in the array, due to the space required for the trie.

The space complexity is linear because of the trie structure storing the binary representations of numbers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
