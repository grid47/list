
+++
authors = ["grid47"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1893: Check if All the Integers in a Range Are Covered in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hZ7QlMbyaKw"
youtube_upload_date="2021-06-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hZ7QlMbyaKw/maxresdefault.webp"
comments = true
+++



---
You are given a list of integer ranges and two integers, left and right. Each range is represented by a pair of integers [start, end]. You need to determine if all integers from left to right (inclusive) are covered by at least one of these ranges. An integer x is considered covered by a range [start, end] if start <= x <= end.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer array 'ranges' and two integers, left and right.
- **Example:** `For ranges = [[1,3], [5,6], [2,4]], left = 2, right = 5`
- **Constraints:**
	- 1 <= ranges.length <= 50
	- 1 <= start <= end <= 50
	- 1 <= left <= right <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if every integer between left and right (inclusive) is covered by at least one of the given ranges. Otherwise, return false.
- **Example:** `For ranges = [[1,3], [5,6], [2,4]], left = 2, right = 5, the output will be true.`
- **Constraints:**
	- The output is a boolean value: true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if every integer from left to right is covered by at least one range.

- Create an array to track coverage of each integer from 1 to 50.
- Iterate through each range and mark the covered integers.
- Check if each integer in the range [left, right] is covered by at least one range.
{{< dots >}}
### Problem Assumptions ✅
- The input ranges array will contain valid integer intervals.
- The values of left and right will be within the bounds of the range.
{{< dots >}}
## Examples 🧩
- **Input:** `ranges = [[1,3], [5,6], [2,4]], left = 2, right = 5`  \
  **Explanation:** Each integer between 2 and 5 is covered by at least one range: 2 and 3 are covered by the first range, 5 is covered by the second range, and 4 is covered by the first range.

- **Input:** `ranges = [[1, 2], [3, 4], [5, 6]], left = 2, right = 5`  \
  **Explanation:** All integers between 2 and 5 are covered: 2 is covered by the first range, 3 and 4 are covered by the second range, and 5 is covered by the third range.

- **Input:** `ranges = [[1,10], [10,20]], left = 21, right = 21`  \
  **Explanation:** 21 is not covered by any range, so the answer is false.

{{< dots >}}
## Approach 🚀
The approach involves checking the coverage of each integer between left and right using an array to track the intervals and comparing the intervals with the given ranges.

### Initial Thoughts 💭
- We can use an array of size 52 to efficiently track the coverage of each integer from 1 to 50.
- By updating coverage markers for each range and checking the relevant segment, we can determine if the answer is true or false.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as there will always be at least one range.
- The algorithm should efficiently handle the maximum constraint where the input ranges array has 50 elements.
- When left equals right, ensure that the single integer is covered.
- Ensure the algorithm works within the time limits when processing up to 50 ranges and numbers up to 50.
{{< dots >}}
## Code 💻
```cpp
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    int line[52] = {};
    for (auto &r : ranges) {
        line[r[0]] += 1;
        line[r[1] + 1] -= 1;
    }
    for (int i = 1, overlaps = 0; i <= right; ++i) {
        overlaps += line[i];
        if (i >= left && overlaps == 0)
            return false;
    }
    return true;
}
```

This function checks if all numbers in the range [left, right] are covered by at least one of the given ranges in the input.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
	```
	Define the function `isCovered` which takes a vector of ranges and two integers, left and right, representing the range to check.

2. **Variable Initialization**
	```cpp
	    int line[52] = {};
	```
	Initialize an array `line` of size 52 to keep track of the coverage of each point.

3. **Loop over Ranges**
	```cpp
	    for (auto &r : ranges) {
	```
	Iterate through each range in the `ranges` vector.

4. **Update Coverage**
	```cpp
	        line[r[0]] += 1;
	```
	Increase the coverage count at the starting point of each range.

5. **Update Coverage**
	```cpp
	        line[r[1] + 1] -= 1;
	```
	Decrease the coverage count just after the end point of each range, marking the end of the coverage.

6. **Iterate over Range [1, right]**
	```cpp
	    for (int i = 1, overlaps = 0; i <= right; ++i) {
	```
	Start a loop to check coverage for all points from 1 to `right`.

7. **Update Overlap**
	```cpp
	        overlaps += line[i];
	```
	Add the coverage at the current point `i` to the `overlaps` variable.

8. **Check for Uncovered Points**
	```cpp
	        if (i >= left && overlaps == 0)
	```
	If the current point `i` is within the range [left, right] and there is no coverage, return false.

9. **Return False for Uncovered**
	```cpp
	            return false;
	```
	Return false if any point in the range is uncovered.

10. **Return True**
	```cpp
	    return true;
	```
	Return true if all points in the range are covered.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of ranges (at most 50).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the array size is constant (52).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---
{{< youtube hZ7QlMbyaKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
