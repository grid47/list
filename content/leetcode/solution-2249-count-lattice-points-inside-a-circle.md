
+++
authors = ["grid47"]
title = "Leetcode 2249: Count Lattice Points Inside a Circle"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2249: Count Lattice Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Geometry","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HCLinlC-JWY"
youtube_upload_date="2022-04-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HCLinlC-JWY/maxresdefault.webp"
comments = true
+++



---
You are given a 2D integer array `circles`, where each element `circles[i] = [xi, yi, ri]` represents a circle with center at `(xi, yi)` and radius `ri`. The task is to find the number of lattice points that lie inside at least one of the given circles. A lattice point is defined as a point with integer coordinates, and points lying on the circumference of a circle are also considered inside.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of circles, where each circle is defined by its center coordinates and radius.
- **Example:** `circles = [[3, 4, 2], [6, 7, 1]]`
- **Constraints:**
	- 1 <= circles.length <= 200
	- circles[i].length == 3
	- 1 <= xi, yi <= 100
	- 1 <= ri <= min(xi, yi)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of distinct lattice points inside at least one circle.
- **Example:** `Output: 14`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the distinct lattice points that are inside or on the circumference of at least one of the given circles.

- Iterate through each circle in the input.
- For each circle, iterate through all points in the bounding square defined by the circle's radius.
- Check whether each point lies inside or on the circle using the distance formula.
- Use a data structure like a set to keep track of unique lattice points.
{{< dots >}}
### Problem Assumptions ✅
- Circle centers and radii are positive integers.
- The grid is large enough to accommodate all specified circles.
{{< dots >}}
## Examples 🧩
- **Input:** `circles = [[3, 3, 2]]`  \
  **Explanation:** The circle with center (3, 3) and radius 2 includes lattice points (1, 3), (2, 2), (2, 3), (2, 4), (3, 1), (3, 2), (3, 3), (3, 4), (3, 5), (4, 2), (4, 3), (4, 4), (5, 3). The total count is 13.

- **Input:** `circles = [[2, 2, 1], [4, 4, 1]]`  \
  **Explanation:** The circles include lattice points (1, 2), (2, 1), (2, 2), (2, 3), (3, 2), (3, 4), (4, 3), (4, 4), (4, 5), (5, 4). After merging overlapping points, the total count is 10.

{{< dots >}}
## Approach 🚀
Use brute-force bounding box iteration for each circle and a set to ensure unique points.

### Initial Thoughts 💭
- A lattice point inside or on a circle satisfies the equation (x - xi)^2 + (y - yi)^2 <= ri^2.
- Overlap between circles requires merging results to avoid duplicate counts.
- Using a set data structure ensures that duplicate lattice points are not counted multiple times.
{{< dots >}}
### Edge Cases 🌐
- No circles are provided; return 0.
- Handle up to 200 circles with maximum radius efficiently.
- Circles with a radius of 1 will include only the center and nearby lattice points.
- Bounding box iteration should remain within computational limits for given constraints.
{{< dots >}}
## Code 💻
```cpp
int countLatticePoints(vector<vector<int>>& cir) {
    set<int> cnt;
    
    for(auto it: cir) {
        
        for(int i = it[0] - it[2]; i <= it[0] + it[2]; i++)
        for(int j = it[1] - it[2]; j <= it[1] + it[2]; j++)                
            if((i - it[0]) * (i - it[0]) + (j - it[1]) * (j - it[1]) <= (it[2] * it[2]))
                cnt.insert(i * 1000 + j);
        
    }
    return cnt.size();
}
```

This function counts the number of distinct lattice points within multiple circles. Each circle is defined by its center and radius, and the function checks if points fall inside any of the circles using the equation for a circle.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countLatticePoints(vector<vector<int>>& cir) {
	```
	This is the start of the 'countLatticePoints' function, which takes a vector of circles (defined by their center coordinates and radius) and calculates the number of unique lattice points contained within these circles.

2. **Variable Initialization**
	```cpp
	    set<int> cnt;
	```
	A set 'cnt' is declared to store unique lattice points. The set ensures that duplicate points are automatically handled.

3. **Loop Through Circles**
	```cpp
	    for(auto it: cir) {
	```
	This loop iterates over each circle in the 'cir' vector. Each circle is represented by a vector with its center (x, y) and radius.

4. **Loop Through x-coordinates**
	```cpp
	        for(int i = it[0] - it[2]; i <= it[0] + it[2]; i++)
	```
	This loop iterates over the x-coordinates that might lie within the circle, considering the range from the leftmost to the rightmost points based on the center's x-coordinate and radius.

5. **Loop Through y-coordinates**
	```cpp
	        for(int j = it[1] - it[2]; j <= it[1] + it[2]; j++)                
	```
	This loop iterates over the y-coordinates that might lie within the circle, considering the range from the bottommost to the topmost points based on the center's y-coordinate and radius.

6. **Point Inside Circle Check**
	```cpp
	            if((i - it[0]) * (i - it[0]) + (j - it[1]) * (j - it[1]) <= (it[2] * it[2]))
	```
	This line checks whether the point (i, j) lies inside the circle. The condition is derived from the equation of a circle, where the sum of the squares of the differences in coordinates must be less than or equal to the square of the radius.

7. **Insert Point**
	```cpp
	                cnt.insert(i * 1000 + j);
	```
	If the point (i, j) lies inside the circle, it is inserted into the 'cnt' set. The points are stored as a unique identifier by combining the x and y coordinates.

8. **Return Unique Count**
	```cpp
	    return cnt.size();
	```
	Returns the size of the set 'cnt', which represents the number of unique lattice points that lie within the given circles.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * r^2)
- **Average Case:** O(n * r^2)
- **Worst Case:** O(n * r^2)

Each circle's bounding box involves iterating over r^2 points, where n is the number of circles.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is determined by the number of unique lattice points m.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/)

---
{{< youtube HCLinlC-JWY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
