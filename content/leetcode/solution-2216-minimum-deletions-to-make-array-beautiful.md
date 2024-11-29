
+++
authors = ["grid47"]
title = "Leetcode 2216: Minimum Deletions to Make Array Beautiful"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2216: Minimum Deletions to Make Array Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VgyrTbLZie8"
youtube_upload_date="2022-03-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/VgyrTbLZie8/maxresdefault.webp"
comments = true
+++



---
You are given an integer array nums. The array is considered beautiful if it satisfies the following conditions: the length of nums is even, and for every index i that is even (i % 2 == 0), nums[i] should not be equal to nums[i + 1]. You can remove any number of elements from nums to make it beautiful. Your goal is to return the minimum number of elements that need to be removed to make the array beautiful.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed integer array nums.
- **Example:** `nums = [4, 4, 6, 7, 8, 9]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of elements to delete from nums to make it beautiful.
- **Example:** `Output: 1`
- **Constraints:**
	- The array may have duplicates that need to be removed.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum number of deletions required to make the array beautiful.

- Iterate through the array and identify the elements that need to be removed.
- Check for pairs of adjacent elements where nums[i] == nums[i + 1] and ensure the length remains even.
- Count the number of deletions required and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The array may contain duplicate elements.
- The array must be modified by deletion of elements only.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 4, 6, 7, 8, 9]`  \
  **Explanation:** For this input, the first two elements are the same, so one of them must be deleted. The final beautiful array will be [4, 6, 7, 8, 9]. Hence, the minimum number of deletions required is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find and remove adjacent duplicate elements in the array while ensuring the final array length is even.

### Initial Thoughts 💭
- Adjacent duplicates should be deleted to meet the criteria of a beautiful array.
- After deletion, the array should still maintain an even length.
- We can use a greedy approach to iterate through the array, checking adjacent elements, and remove them when necessary.
{{< dots >}}
### Edge Cases 🌐
- An empty array is considered beautiful by definition.
- The solution should efficiently handle arrays with up to 100,000 elements.
- The array may have all elements identical, or no duplicates at all.
- Ensure that the input size is within the constraints and handle edge cases appropriately.
{{< dots >}}
## Code 💻
```cpp
int minDeletion(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size() - 1; i++)
        if(nums[i] == nums[i + 1] && (i - ans) % 2 == 0) ans++;
    
    return ans + (nums.size() - ans) % 2;
}
```

This is the complete solution for finding the minimum number of deletions needed to make the elements of the array alternate. The function `minDeletion` loops through the array and checks for consecutive duplicate elements that would violate the alternating condition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minDeletion(vector<int>& nums) {
	```
	This is the function declaration for `minDeletion`, which takes a vector of integers `nums` and returns an integer representing the minimum deletions required.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0. This will keep track of the number of deletions made to ensure the array alternates.

3. **For Loop**
	```cpp
	    for(int i = 0; i < nums.size() - 1; i++)
	```
	This loop iterates through the array `nums`, stopping at the second-to-last element to compare each element with the next one.

4. **Conditional Check**
	```cpp
	        if(nums[i] == nums[i + 1] && (i - ans) % 2 == 0) ans++;
	```
	This conditional checks if two consecutive elements are equal and if the difference between the current index `i` and `ans` is even. If both conditions are true, it increments `ans` to indicate a necessary deletion.

5. **Return Statement**
	```cpp
	    return ans + (nums.size() - ans) % 2;
	```
	Return the result by adding the number of deletions (`ans`) to the parity correction, which ensures the final array has an even number of elements after deletions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the input array, as we only iterate through the array once.
- **Average Case:** O(n) where n is the length of the input array.
- **Worst Case:** O(n) where n is the length of the input array.

The solution processes the array in a single pass.

### Space Complexity 💾
- **Best Case:** O(1) for the space used during the iteration.
- **Worst Case:** O(1) for the space used during the iteration.

The solution only uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/)

---
{{< youtube VgyrTbLZie8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
