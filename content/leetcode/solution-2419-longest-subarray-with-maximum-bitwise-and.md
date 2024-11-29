
+++
authors = ["grid47"]
title = "Leetcode 2419: Longest Subarray With Maximum Bitwise AND"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2419: Longest Subarray With Maximum Bitwise AND in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N8lRlRWA_1Q"
youtube_upload_date="2024-09-14"
youtube_thumbnail="https://i.ytimg.com/vi/N8lRlRWA_1Q/maxresdefault.jpg"
comments = true
+++



---
Given an integer array nums of size n, find the length of the longest contiguous subarray that has the maximum possible bitwise AND. The bitwise AND of an array is calculated by performing a bitwise AND operation on all the numbers in it.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers nums of size n.
- **Example:** `nums = [5, 3, 7, 7, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest contiguous subarray that has the maximum possible bitwise AND value.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the subarray with the highest possible bitwise AND and return the length of the longest one.

- 1. Find the maximum number in the array.
- 2. Traverse the array and track the longest contiguous subarray where the bitwise AND of the subarray equals the maximum value found.
- 3. Return the length of this subarray.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 3, 7, 7, 2]`  \
  **Explanation:** The maximum bitwise AND is 7, and the longest subarray with this value is [7, 7], which has length 2.

{{< dots >}}
## Approach 🚀
The solution involves identifying the maximum number in the array, and then checking for the longest contiguous subarray where the bitwise AND equals this maximum value.

### Initial Thoughts 💭
- The highest possible AND value will be the maximum element in the array.
- We need to focus on the contiguous subarrays that contain only this maximum value.
- We can solve this problem by iterating through the array to track the longest sequence of the maximum number.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees at least one element in the array, so this case will not occur.
- The solution should efficiently handle large arrays (up to 100,000 elements).
- If all elements in the array are the same, the entire array is the subarray with the maximum bitwise AND.
- Ensure the solution handles arrays with up to 100,000 elements.
{{< dots >}}
## Code 💻
```cpp
int longestSubarray(vector<int>& nums) {
    int x = *max_element(nums.begin(), nums.end());
    int len = 0, ans = 0;
    for(int ele: nums) {
        if(ele == x) {
            ans = max(ans, ++len);
        } else len = 0;
    }
    return ans;
}
```

This function finds the longest contiguous subarray that contains only the maximum element in the given array. It iterates through the array, keeping track of the current streak of maximum elements and returns the longest such streak.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestSubarray(vector<int>& nums) {
	```
	This line defines the function 'longestSubarray', which takes a vector of integers (nums) as input and returns an integer representing the length of the longest subarray of consecutive maximum values.

2. **Find Maximum Element**
	```cpp
	    int x = *max_element(nums.begin(), nums.end());
	```
	This line finds the maximum element 'x' in the vector 'nums' using the 'max_element' function, which returns an iterator pointing to the largest element.

3. **Variable Initialization**
	```cpp
	    int len = 0, ans = 0;
	```
	Two variables are initialized: 'len' to track the current streak of consecutive maximum elements, and 'ans' to store the maximum streak length found.

4. **Loop**
	```cpp
	    for(int ele: nums) {
	```
	A loop is started to iterate over each element 'ele' in the 'nums' vector.

5. **Condition Check**
	```cpp
	        if(ele == x) {
	```
	This conditional checks if the current element 'ele' is equal to the maximum element 'x'.

6. **Update Streak**
	```cpp
	            ans = max(ans, ++len);
	```
	If the element is equal to the maximum value, 'len' is incremented, and 'ans' is updated to the larger of the current value of 'ans' or 'len'.

7. **Reset Streak**
	```cpp
	        } else len = 0;
	```
	If the element is not equal to the maximum value, the streak ('len') is reset to 0.

8. **Return**
	```cpp
	    return ans;
	```
	The function returns the value of 'ans', which holds the length of the longest contiguous subarray of maximum elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we are making two passes through the array: one to find the maximum and another to determine the longest subarray.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a few variables to keep track of the maximum value and the lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/)

---
{{< youtube N8lRlRWA_1Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
