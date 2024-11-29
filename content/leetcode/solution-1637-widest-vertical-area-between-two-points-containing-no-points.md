
+++
authors = ["grid47"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2024-05-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6XnvNCTyJP4"
youtube_upload_date="2023-12-21"
youtube_thumbnail="https://i.ytimg.com/vi/6XnvNCTyJP4/maxresdefault.jpg"
comments = true
+++



---
Given n points on a 2D plane, where points[i] = [xi, yi], return the widest vertical area between two points such that no points are inside the area. A vertical area is defined as a fixed-width region that extends infinitely along the y-axis. The widest vertical area is the one with the maximum width. Note that points on the edge of the vertical area are not considered inside.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of n points on a 2D plane, each represented as a pair of integers, [xi, yi], where xi and yi are the coordinates of the points.
- **Example:** `points = [[1, 4], [3, 1], [9, 0], [4, 6], [7, 2]]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 0 <= xi, yi <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the width of the widest vertical area between two points such that no points lie within the area.
- **Example:** `Output: 5`
- **Constraints:**
	- The width will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the widest vertical area between two points where no points are inside the area.

- Sort the points based on their x-coordinates.
- Compute the horizontal distance between consecutive points in the sorted list.
- Return the maximum distance between consecutive points as the result.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least two points in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `points = [[12, 5], [8, 7], [15, 10], [9, 6]]`  \
  **Explanation:** The points are first sorted by their x-coordinate: [[8, 7], [9, 6], [12, 5], [15, 10]]. The distances between consecutive points are 1, 3, and 3, so the maximum width of the vertical area is 7.

{{< dots >}}
## Approach 🚀
We will approach this problem by sorting the points based on their x-coordinates and then calculating the horizontal distances between consecutive points. The maximum distance will be the answer.

### Initial Thoughts 💭
- Sorting the points by their x-coordinate will allow us to easily compute the distances between adjacent points.
- Sorting the points first is the key step, as it ensures we are considering the widest possible vertical area between points.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will always be at least two points, so there is no need to handle empty inputs.
- For large inputs, the solution should still be efficient with time complexity O(n log n) due to the sorting step.
- The points may have large coordinates up to 10^9, but the solution will handle this without issue as long as the points are sorted first.
- The solution needs to handle arrays with up to 100,000 points efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxWidthOfVerticalArea(vector<vector<int>>& pts) {
    sort(pts.begin(), pts.end());
    int res =0;
    for(int i = 1; i < pts.size(); i++)
        res = max(res, pts[i][0] - pts[i - 1][0]);
    
    return res;
}
};
```

This function calculates the maximum width of vertical areas between consecutive points in a sorted 2D grid, focusing on the x-coordinate values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int maxWidthOfVerticalArea(vector<vector<int>>& pts) {
	```
	Define the method 'maxWidthOfVerticalArea' that takes a 2D vector of points 'pts' as input.

2. **Sorting**
	```cpp
	    sort(pts.begin(), pts.end());
	```
	Sort the points based on their x-coordinates to prepare for calculating the maximum vertical width.

3. **Variable Initialization**
	```cpp
	    int res =0;
	```
	Initialize the variable 'res' to store the maximum vertical width found during the iteration.

4. **Loop Constructs**
	```cpp
	    for(int i = 1; i < pts.size(); i++)
	```
	Start a loop that iterates over the points from the second element to the last.

5. **Mathematical Operations**
	```cpp
	        res = max(res, pts[i][0] - pts[i - 1][0]);
	```
	For each pair of consecutive points, calculate the width (difference between the x-coordinates) and update 'res' if a larger width is found.

6. **Return Statement**
	```cpp
	    return res;
	```
	Return the maximum width found during the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted list of points.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/)

---
{{< youtube 6XnvNCTyJP4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
