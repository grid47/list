
+++
authors = ["grid47"]
title = "Leetcode 217: Contains Duplicate"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 217: Contains Duplicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/217.webp"
youtube = "SFMCxqSeM94"
youtube_upload_date="2020-01-16"
youtube_thumbnail="https://i.ytimg.com/vi/SFMCxqSeM94/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/217.webp" 
    alt="A set of numbers gently rearranging, with duplicates softly fading out and unique ones glowing."
    caption="Solution to LeetCode 217: Contains Duplicate Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, determine if there are any duplicate values present. Return true if any value appears more than once, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums.
- **Example:** `[10, 20, 30, 10]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if there are duplicates in the array, otherwise return false.
- **Example:** `For input [10, 20, 30, 10], the output is true.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify whether there are any duplicate values in the array.

- Use a set or map to track the elements in the array as you iterate through it.
- If you encounter an element that is already in the set or map, return true indicating a duplicate is found.
- If no duplicates are found after processing all elements, return false.
{{< dots >}}
### Problem Assumptions ✅
- The array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the value 10 occurs twice, so the answer is true.

- **Input:** `Example 2`  \
  **Explanation:** In this case, all elements are distinct, so the output is false.

- **Input:** `Example 3`  \
  **Explanation:** Here, several elements such as 7, 8, and 4 repeat, so the output is true.

{{< dots >}}
## Approach 🚀
Use a set or a map to efficiently track elements and identify duplicates.

### Initial Thoughts 💭
- A set or map can help efficiently identify duplicates in O(n) time by keeping track of seen elements.
- By leveraging the properties of a set or map (constant-time lookups), we can check for duplicates while iterating through the array.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element.
- Ensure the solution works efficiently for arrays with 10^5 elements.
- The array may contain very large or very small integers, but the solution must handle all values within the range.
- Handle cases where all elements are the same.
{{< dots >}}
## Code 💻
```cpp
bool containsDuplicate(vector<int>& nums) {
    map<int, int> ma;
    for(int x: nums)
        if(ma.count(x)) return true;
    else ma[x] = 1;
    return false;
}
```

This function checks whether a given vector of integers contains any duplicate elements. It uses a map to track the occurrences of each element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	bool containsDuplicate(vector<int>& nums) {
	```
	Defines the 'containsDuplicate' function which takes a vector of integers 'nums' as input and returns a boolean value indicating whether any element in the vector appears more than once.

2. **Map Initialization**
	```cpp
	    map<int, int> ma;
	```
	Initializes a map 'ma' to keep track of the count of each integer in the 'nums' vector. The key is the integer, and the value is its count.

3. **Loop Iteration**
	```cpp
	    for(int x: nums)
	```
	Iterates over each element 'x' in the 'nums' vector.

4. **Check for Duplicates**
	```cpp
	        if(ma.count(x)) return true;
	```
	Checks if the current element 'x' is already present in the map 'ma'. If it is, that means a duplicate has been found, and the function returns 'true'.

5. **Map Update**
	```cpp
	    else ma[x] = 1;
	```
	If the element 'x' is not found in the map, it is added with a count of 1, indicating that this element has been encountered once.

6. **Return Statement**
	```cpp
	    return false;
	```
	If no duplicates are found after iterating through all elements in the vector, the function returns 'false'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array. This occurs when the first duplicate is encountered early in the iteration.
- **Average Case:** O(n), as we perform one lookup and one insertion for each element.
- **Worst Case:** O(n), when no duplicates are found and we need to process every element.

The solution operates in linear time since the set or map allows constant-time lookups and insertions.

### Space Complexity 💾
- **Best Case:** O(1), if there are no duplicates and only a single element is stored.
- **Worst Case:** O(n), where n is the number of elements in the array, since we may need to store all elements in the set or map.

The space complexity is determined by the number of unique elements in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/contains-duplicate/description/)

---
{{< youtube SFMCxqSeM94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
