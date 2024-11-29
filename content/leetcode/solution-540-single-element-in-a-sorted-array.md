
+++
authors = ["grid47"]
title = "Leetcode 540: Single Element in a Sorted Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 540: Single Element in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/540.webp"
youtube = "T4nRgIxka18"
youtube_upload_date="2020-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/T4nRgIxka18/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/540.webp" 
    alt="An array where the single unique element glows softly as it is found among duplicates."
    caption="Solution to LeetCode 540: Single Element in a Sorted Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array where every element appears exactly twice, except for one element which appears only once. Find and return the single element that does not have a pair.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a sorted array of integers where every element appears exactly twice, except for one element.
- **Example:** `Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the single element that appears only once in the array.
- **Example:** `Output: 2`
- **Constraints:**
	- The returned element will be the one that appears only once.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the single element that appears only once in the sorted array.

- Initialize a result variable to 0.
- Iterate through the array and XOR each element with the result.
- After completing the loop, the result will contain the single element that appears only once.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain at least one element.
- The array is sorted.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]`  \
  **Explanation:** The only element that doesn't have a pair is 2, so the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we use the XOR operation which helps to cancel out duplicate elements. Since every element except one appears exactly twice, XORing all elements will result in the unique element.

### Initial Thoughts 💭
- The XOR operation can be used to identify the unique element because it cancels out identical numbers.
- Since the array is sorted, and we only need to find one unique element, XOR provides a time-efficient way to solve this problem in O(n) time with constant space.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty, as the problem guarantees at least one element.
- Ensure the solution handles up to 10^5 elements efficiently.
- Handle arrays with the smallest and largest values, ensuring the XOR operation works for all integers within the given range.
- The input list contains valid integers within the specified range.
{{< dots >}}
## Code 💻
```cpp
int singleNonDuplicate(vector<int>& nums) {
    int res = 0;
    for(int num : nums)
    res ^= num;

    return res;
}
```

This function uses the XOR operation to find the single non-duplicate element in a vector. Every element in the vector appears twice except for one, which is the non-duplicate element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int singleNonDuplicate(vector<int>& nums) {
	```
	Defines the function `singleNonDuplicate`, which takes a vector of integers `nums` as input and returns the single non-duplicate element using the XOR bit manipulation technique.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes a variable `res` to 0, which will store the result of the XOR operations. This will eventually hold the single non-duplicate element.

3. **Loop**
	```cpp
	    for(int num : nums)
	```
	Begins a loop that iterates over each element in the `nums` vector.

4. **XOR Operation**
	```cpp
	    res ^= num;
	```
	Applies the XOR operation between `res` and the current element `num`. The XOR operation helps to cancel out duplicate elements, leaving only the non-duplicate element.

5. **Empty Line**
	```cpp
	
	```
	Represents an empty line in the code, separating different sections.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result stored in `res`, which is the single non-duplicate element in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a constant amount of extra space for the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

---
{{< youtube T4nRgIxka18 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
