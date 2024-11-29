
+++
authors = ["grid47"]
title = "Leetcode 1401: Circle and Rectangle Overlapping"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1401: Circle and Rectangle Overlapping in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a circle represented by its radius and center coordinates, as well as an axis-aligned rectangle represented by its bottom-left and top-right corners. Determine if the circle and the rectangle overlap, i.e., if there is any point inside both the circle and the rectangle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the radius and coordinates of the center of the circle, along with the coordinates of the bottom-left and top-right corners of the rectangle.
- **Example:** `[2, 1, 2, 0, 0, 3, 3]`
- **Constraints:**
	- 1 <= radius <= 2000
	- -10^4 <= xCenter, yCenter <= 10^4
	- -10^4 <= x1 < x2 <= 10^4
	- -10^4 <= y1 < y2 <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value. Return `true` if the circle and rectangle overlap, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The output is `true` if the circle and rectangle overlap, otherwise `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the circle and rectangle share any common points.

- Shift the coordinates of the rectangle to the circle's center by subtracting the circle's center from the rectangle's coordinates.
- Check if any part of the rectangle intersects the circle by comparing the distance from the circle's center to the rectangle's edges and corners.
{{< dots >}}
### Problem Assumptions ✅
- The circle's radius is a positive integer.
- The rectangle's corners are distinct and follow the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [2, 1, 2, 0, 0, 3, 3]`  \
  **Explanation:** In this case, the circle with radius 2 and center (1, 2) intersects with the rectangle from (0, 0) to (3, 3), as the two shapes share a common point.

- **Input:** `Input: [2, 0, 0, 3, -1, 5, 1]`  \
  **Explanation:** Here, the circle does not overlap with the rectangle, as there is no point that lies in both the circle and the rectangle.

{{< dots >}}
## Approach 🚀
The approach involves checking if the circle and rectangle share any common points by considering their geometric properties.

### Initial Thoughts 💭
- A circle can be represented by its center and radius, while a rectangle is defined by its corner coordinates.
- The challenge is to determine if any part of the rectangle lies within the circle.
- We can check if the rectangle intersects with the circle using distance calculations between the rectangle's corners and the circle's center.
{{< dots >}}
### Edge Cases 🌐
- What if the radius is 0?
- Ensure the solution can handle inputs at the upper bounds of the constraints.
- What if the rectangle is just a point?
- The solution should be efficient enough for large values of `radius` and large coordinates of the rectangle.
{{< dots >}}
## Code 💻
```cpp
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    x1 -= xCenter;
    x2 -= xCenter;
    y1 -= yCenter;
    y2 -= yCenter;
    int mx = x1 * x2 > 0? min(x1 * x1, x2 * x2): 0;
    int my = y1 * y2 > 0? min(y1 * y1, y2 * y2): 0;
    return mx + my <= radius * radius;
}
```

This code defines the `checkOverlap` function, which checks if the given rectangle overlaps with a circle using the circle's radius and center and the rectangle's coordinates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
	```
	Defines the `checkOverlap` method, which checks if a rectangle overlaps with a circle. The method takes in the radius and center of the circle, and the coordinates of the rectangle.

2. **Coordinate Adjustment**
	```cpp
	    x1 -= xCenter;
	```
	Adjusts the x-coordinate of the bottom-left corner of the rectangle relative to the circle's center by subtracting the x-coordinate of the circle's center.

3. **Coordinate Adjustment**
	```cpp
	    x2 -= xCenter;
	```
	Adjusts the x-coordinate of the top-right corner of the rectangle relative to the circle's center.

4. **Coordinate Adjustment**
	```cpp
	    y1 -= yCenter;
	```
	Adjusts the y-coordinate of the bottom-left corner of the rectangle relative to the circle's center.

5. **Coordinate Adjustment**
	```cpp
	    y2 -= yCenter;
	```
	Adjusts the y-coordinate of the top-right corner of the rectangle relative to the circle's center.

6. **Intersection Calculation**
	```cpp
	    int mx = x1 * x2 > 0? min(x1 * x1, x2 * x2): 0;
	```
	Calculates the minimum squared distance in the x-direction between the center of the circle and the rectangle. If the rectangle extends on both sides of the circle's center, the minimum distance is used.

7. **Intersection Calculation**
	```cpp
	    int my = y1 * y2 > 0? min(y1 * y1, y2 * y2): 0;
	```
	Calculates the minimum squared distance in the y-direction between the center of the circle and the rectangle. If the rectangle extends on both sides of the circle's center, the minimum distance is used.

8. **Return Statement**
	```cpp
	    return mx + my <= radius * radius;
	```
	Returns `true` if the total minimum squared distances in both x and y directions are less than or equal to the squared radius of the circle, indicating that the rectangle and circle overlap.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), as the circle and rectangle may not overlap at all and the check can terminate quickly.
- **Average Case:** O(1), since the solution involves constant-time calculations for the overlap check.
- **Worst Case:** O(1), as the solution performs a fixed set of operations regardless of input size.



### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required beyond basic variable storage.
- **Worst Case:** O(1), as the space complexity does not grow with input size.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
