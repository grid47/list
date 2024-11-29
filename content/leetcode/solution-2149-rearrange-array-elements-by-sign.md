
+++
authors = ["grid47"]
title = "Leetcode 2149: Rearrange Array Elements by Sign"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2149: Rearrange Array Elements by Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SoPmcGzz9-E"
youtube_upload_date="2024-02-14"
youtube_thumbnail="https://i.ytimg.com/vi/SoPmcGzz9-E/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array 'nums' of even length consisting of an equal number of positive and negative integers. Rearrange the array such that every consecutive pair of integers has opposite signs, the order of integers with the same sign is preserved, and the array begins with a positive integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 0-indexed integer array 'nums' of even length.
- **Example:** `nums = [6, 3, -1, -5, 2, -4]`
- **Constraints:**
	- 2 <= nums.length <= 2 * 10^5
	- nums.length is even
	- 1 <= |nums[i]| <= 10^5
	- nums consists of an equal number of positive and negative integers.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the rearranged array where consecutive elements have opposite signs and the order of same-signed integers is preserved.
- **Example:** `Output: [6, -1, 3, -5, 2, -4]`
- **Constraints:**
	- The array must start with a positive integer and alternate between positive and negative integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to rearrange the elements such that positive and negative integers alternate, and the order of elements with the same sign remains intact.

- Iterate over the 'nums' array and segregate the positive and negative integers.
- Place positive integers at even indices and negative integers at odd indices.
- Return the rearranged array.
{{< dots >}}
### Problem Assumptions ✅
- The array is guaranteed to contain an equal number of positive and negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [6, 3, -1, -5, 2, -4]`  \
  **Explanation:** The positive integers are [6, 3, 2] and the negative integers are [-1, -5, -4]. The only valid rearrangement is [6, -1, 3, -5, 2, -4] which alternates signs while preserving the order of positive and negative integers.

{{< dots >}}
## Approach 🚀
The goal is to rearrange the array such that positive and negative integers alternate while keeping the order of the same-signed integers intact.

### Initial Thoughts 💭
- The input guarantees an equal number of positive and negative integers, which simplifies the process.
- We need a way to efficiently place the positive integers at even indices and negative integers at odd indices.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not possible based on the problem constraints.
- The solution should efficiently handle arrays with a length up to 2 * 10^5.
- Arrays with the minimum possible length of 2 will follow the same rearrangement logic.
- The input array is guaranteed to have an equal number of positive and negative integers.
{{< dots >}}
## Code 💻
```cpp
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    int idxpos = 0, idxneg = 1;
    for(int num: nums) {
        if(num > 0) {
            ans[idxpos] = num;
            idxpos += 2;
        }
        if(num < 0) {
            ans[idxneg] = num;
            idxneg += 2;
        }
    }
    return ans;
}
```

This function rearranges an array such that positive numbers are placed in the even indices and negative numbers in the odd indices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> rearrangeArray(vector<int>& nums) {
	```
	Function declaration to rearrange the array with positive numbers at even indices and negative numbers at odd indices.

2. **Variable Initialization**
	```cpp
	    vector<int> ans(nums.size(), 0);
	```
	Initialize a vector 'ans' of the same size as the input 'nums', with all elements set to 0.

3. **Variable Initialization**
	```cpp
	    int idxpos = 0, idxneg = 1;
	```
	Initialize two indices, 'idxpos' to place positive numbers at even indices and 'idxneg' to place negative numbers at odd indices.

4. **Loop**
	```cpp
	    for(int num: nums) {
	```
	Iterate through each number in the input 'nums' array.

5. **Condition Check**
	```cpp
	        if(num > 0) {
	```
	Check if the current number is positive.

6. **Array Assignment**
	```cpp
	            ans[idxpos] = num;
	```
	Place the positive number at the current 'idxpos' index in the 'ans' array.

7. **Index Update**
	```cpp
	            idxpos += 2;
	```
	Increment the 'idxpos' index by 2 to move to the next even index.

8. **Condition Check**
	```cpp
	        if(num < 0) {
	```
	Check if the current number is negative.

9. **Array Assignment**
	```cpp
	            ans[idxneg] = num;
	```
	Place the negative number at the current 'idxneg' index in the 'ans' array.

10. **Index Update**
	```cpp
	            idxneg += 2;
	```
	Increment the 'idxneg' index by 2 to move to the next odd index.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Return the rearranged array 'ans' with positive numbers at even indices and negative numbers at odd indices.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we are iterating through the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use an extra array of size n to store the rearranged elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

---
{{< youtube SoPmcGzz9-E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
