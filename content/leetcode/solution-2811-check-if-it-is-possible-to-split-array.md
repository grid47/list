
+++
authors = ["grid47"]
title = "Leetcode 2811: Check if it is Possible to Split Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2811: Check if it is Possible to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BVkYLy-gzcg"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/BVkYLy-gzcg/maxresdefault.jpg"
comments = true
+++



---
You are given an array nums and an integer m. You need to determine if it's possible to split the array into n subarrays of size 1, following the rules that each subarray must either have length 1 or have a sum of elements greater than or equal to m.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array nums of length n and an integer m.
- **Example:** `Input: nums = [1, 3, 2], m = 5`
- **Constraints:**
	- 1 <= n == nums.length <= 100
	- 1 <= nums[i] <= 100
	- 1 <= m <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to split the array into n good arrays, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine whether it's possible to split the array into n good arrays based on the described rules.

- 1. Start with the entire array.
- 2. Check if it's possible to split the array into two smaller subarrays, where both subarrays are good.
- 3. If a valid split is found, continue the process with the smaller subarrays.
- 4. Return true if it's possible to break down the array into n good subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The length of the array is at least 1 and no more than 100.
- Each element of the array is between 1 and 100.
- The value of m is between 1 and 200.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 2], m = 5`  \
  **Explanation:** By splitting the array into subarrays of length 1, we can achieve a valid result, making the output true.

- **Input:** `Input: nums = [1, 2, 3], m = 7`  \
  **Explanation:** The array cannot be split into good arrays since no valid subarrays meet the sum >= m condition, so the output is false.

{{< dots >}}
## Approach 🚀
We need to find a way to split the array into subarrays that meet the good array criteria.

### Initial Thoughts 💭
- The sum of elements in a subarray plays a crucial role in determining if it's a good array.
- We need to try all possible splits to ensure the array can be divided into valid subarrays.
- We can iterate through the array and look for points where the sum of a split subarray meets the required criteria.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the input array.
- Ensure the solution works efficiently for arrays with lengths up to 100.
- If m is large, it may be impossible to split the array in a valid way.
- The solution must be efficient enough to handle the upper limit of input sizes.
{{< dots >}}
## Code 💻
```cpp
bool canSplitArray(vector<int>& nums, int m) {
    for (int i = 0; i < nums.size() - 1; ++i)
        if (nums[i] + nums[i + 1] >= m)
            return true;
    return nums.size() < 3;        
}
```

This function checks whether an array can be split into two parts with a sum greater than or equal to a given value 'm'. It returns 'true' if any two consecutive elements meet this condition, or if the array has fewer than three elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canSplitArray(vector<int>& nums, int m) {
	```
	The function 'canSplitArray' takes a reference to a vector of integers 'nums' and an integer 'm' as input, and returns a boolean value indicating whether the array can be split based on the condition.

2. **Loop Setup**
	```cpp
	    for (int i = 0; i < nums.size() - 1; ++i)
	```
	A loop is initialized to iterate over the elements of the array, from the first element to the second-to-last element, ensuring each pair of consecutive elements is checked.

3. **Condition Check**
	```cpp
	        if (nums[i] + nums[i + 1] >= m)
	```
	Within the loop, check if the sum of the current element and the next element in the array is greater than or equal to the given value 'm'.

4. **Return Statement**
	```cpp
	            return true;
	```
	If the sum of two consecutive elements meets or exceeds 'm', return 'true' immediately, indicating that the array can be split.

5. **Final Return**
	```cpp
	    return nums.size() < 3;        
	```
	If no such pair is found, return 'true' if the array contains fewer than 3 elements (since a split is trivially possible with a small array).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we may need to check multiple possible splits for each element in the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We are storing the intermediate states of the array while attempting to split it into subarrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

---
{{< youtube BVkYLy-gzcg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
