
+++
authors = ["grid47"]
title = "Leetcode 836: Rectangle Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 836: Rectangle Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "o6hHUk4DOW0"
youtube_upload_date="2020-01-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o6hHUk4DOW0/maxresdefault.webp"
comments = true
+++



---
You are given two axis-aligned rectangles represented by two lists, rec1 and rec2. Each list contains four integers: [x1, y1, x2, y2], where (x1, y1) represents the bottom-left corner and (x2, y2) represents the top-right corner of the rectangle. You need to determine if the two rectangles overlap. Two rectangles overlap if their intersection area is positive. Rectangles that only touch at the edges or corners do not count as overlapping.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two lists representing two axis-aligned rectangles. Each list contains four integers: [x1, y1, x2, y2].
- **Example:** `Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]`
- **Constraints:**
	- rec1.length == 4
	- rec2.length == 4
	- -10^9 <= rec1[i], rec2[i] <= 10^9
	- Both rec1 and rec2 represent valid rectangles with a non-zero area.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the two rectangles overlap, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value indicating whether the rectangles overlap.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if there is a positive intersection area between the two given rectangles.

- Step 1: Compare the horizontal and vertical ranges of both rectangles.
- Step 2: Check if there is no overlap by ensuring the rectangles do not meet in either direction (horizontal or vertical).
- Step 3: Return true if there is an overlap, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- Both rec1 and rec2 represent valid axis-aligned rectangles.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]`  \
  **Explanation:** These two rectangles overlap because their intersection has a positive area.

- **Input:** `Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]`  \
  **Explanation:** These rectangles do not overlap because they only touch at the edges, not overlapping in area.

{{< dots >}}
## Approach 🚀
The approach is to compare the boundaries of both rectangles and check for any overlap. If one rectangle is entirely to the left, right, above, or below the other, then they do not overlap.

### Initial Thoughts 💭
- The rectangles will overlap if and only if their projections on both the x and y axes intersect.
- If either the horizontal or vertical projections do not overlap, the rectangles do not overlap.
{{< dots >}}
### Edge Cases 🌐
- Empty rectangles (with zero area) should not be considered valid inputs.
- Ensure that large input values (up to 10^9) are handled efficiently.
- Consider edge cases where the rectangles touch at the edges or corners but do not overlap.
- Check that both rectangles are valid and the coordinates form a non-zero area.
{{< dots >}}
## Code 💻
```cpp
bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
    int fx1=rect1[0];
    int fx2=rect1[2];
    int fy1=rect1[1];
    int fy2=rect1[3];

    int sx1=rect2[0];
    int sx2=rect2[2];
    int sy1=rect2[1];
    int sy2=rect2[3];

    return !((sy1>=fy2) ||
           (fy1>=sy2) ||
           (fx1>=sx2) ||
           (fx2<=sx1));
}
```

This function checks if two rectangles overlap by comparing their coordinates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
	```
	This line defines the function 'isRectangleOverlap' which takes two vectors representing the coordinates of two rectangles.

2. **Variable Declaration**
	```cpp
	    int fx1=rect1[0];
	```
	This line extracts the x-coordinate of the bottom-left corner of the first rectangle (rect1).

3. **Variable Declaration**
	```cpp
	    int fx2=rect1[2];
	```
	This line extracts the x-coordinate of the top-right corner of the first rectangle (rect1).

4. **Variable Declaration**
	```cpp
	    int fy1=rect1[1];
	```
	This line extracts the y-coordinate of the bottom-left corner of the first rectangle (rect1).

5. **Variable Declaration**
	```cpp
	    int fy2=rect1[3];
	```
	This line extracts the y-coordinate of the top-right corner of the first rectangle (rect1).

6. **Variable Declaration**
	```cpp
	    int sx1=rect2[0];
	```
	This line extracts the x-coordinate of the bottom-left corner of the second rectangle (rect2).

7. **Variable Declaration**
	```cpp
	    int sx2=rect2[2];
	```
	This line extracts the x-coordinate of the top-right corner of the second rectangle (rect2).

8. **Variable Declaration**
	```cpp
	    int sy1=rect2[1];
	```
	This line extracts the y-coordinate of the bottom-left corner of the second rectangle (rect2).

9. **Variable Declaration**
	```cpp
	    int sy2=rect2[3];
	```
	This line extracts the y-coordinate of the top-right corner of the second rectangle (rect2).

10. **Return Statement**
	```cpp
	    return !((sy1>=fy2) ||
	```
	This checks if the second rectangle is to the left, right, above, or below the first rectangle. If any of these conditions are true, there is no overlap.

11. **Return Statement**
	```cpp
	           (fy1>=sy2) ||
	```
	This checks if the second rectangle is entirely below the first rectangle.

12. **Return Statement**
	```cpp
	           (fx1>=sx2) ||
	```
	This checks if the second rectangle is entirely to the right of the first rectangle.

13. **Return Statement**
	```cpp
	           (fx2<=sx1));
	```
	This checks if the second rectangle is entirely to the left of the first rectangle.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), the solution involves constant time checks.
- **Average Case:** O(1), the solution requires only constant time comparisons.
- **Worst Case:** O(1), only a fixed number of comparisons are made.

The time complexity is constant, as we are only performing a few comparisons.

### Space Complexity 💾
- **Best Case:** O(1), the space complexity remains constant.
- **Worst Case:** O(1), the space complexity is constant as we only store the rectangle coordinates.

The space complexity is constant since only a fixed amount of data is needed to perform the checks.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rectangle-overlap/description/)

---
{{< youtube o6hHUk4DOW0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
