
+++
authors = ["grid47"]
title = "Leetcode 963: Minimum Area Rectangle II"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 963: Minimum Area Rectangle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FcWK8CJReUo"
youtube_upload_date="2020-08-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FcWK8CJReUo/maxresdefault.webp"
comments = true
+++



---
You are given a set of points in a 2D plane, represented as an array where each point is in the format [xi, yi]. Your task is to find the minimum possible area of any rectangle formed by these points, where the sides of the rectangle do not need to be parallel to the X or Y axes. If no rectangle can be formed, return 0. Answers within 10^-5 of the actual area are considered correct.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of unique points in a 2D plane. Each point is represented as a pair of integers [xi, yi], where xi and yi denote the coordinates of the point.
- **Example:** `Input: points = [[0,2],[1,1],[2,0],[1,3],[3,1]]`
- **Constraints:**
	- 1 <= points.length <= 50
	- points[i].length == 2
	- 0 <= xi, yi <= 40,000
	- All points are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a floating-point number representing the minimum possible area of a rectangle formed by the given points. If no rectangle can be formed, return 0.
- **Example:** `Output: 1.00000`
- **Constraints:**
	- The result must be accurate within 10^-5 of the actual area.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum area of a rectangle that can be formed using the given points. If no rectangle exists, return 0.

- 1. Use combinations of two points to define potential rectangle sides.
- 2. Use a hashing technique to group points by their center and length for efficient pair comparisons.
- 3. Calculate the area for each possible rectangle, keeping track of the minimum value.
- 4. If no rectangle is formed, return 0.
{{< dots >}}
### Problem Assumptions ✅
- The input points are unique and will not have duplicates.
- It is possible for no rectangle to be formed, in which case the output should be 0.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: points = [[0,2],[2,0],[1,1],[3,3]]`  \
  **Explanation:** The minimum area rectangle is formed by points [0,2],[2,0],[1,1],[3,3] with an area of 2.00000.

- **Input:** `Input: points = [[1,0],[2,2],[3,1],[0,3]]`  \
  **Explanation:** No valid rectangle can be formed from these points, so the output is 0.

- **Input:** `Input: points = [[0,0],[0,2],[2,0],[2,2]]`  \
  **Explanation:** The minimum area rectangle is formed by points [0,0],[0,2],[2,0],[2,2] with an area of 4.00000.

{{< dots >}}
## Approach 🚀
To solve the problem, consider all pairs of points that define diagonals of a rectangle. Use hashing to efficiently group potential rectangles based on shared center and diagonal lengths. Compute the area for each valid rectangle.

### Initial Thoughts 💭
- A rectangle can be identified by its diagonals, as they share the same midpoint and length.
- Using a hash map allows efficient grouping of diagonals to form rectangles.
- Iterate through all pairs of points, calculate their center and diagonal length, and group them using a hash map.
- Check for rectangles in each group and compute their area, keeping track of the minimum area.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one point, so empty input is not possible.
- Even with the maximum constraint of 50 points, the solution must efficiently handle O(n^2) pairwise comparisons.
- All points lying on a single line (horizontal, vertical, or diagonal) will not form any rectangle.
- All points are unique, and their coordinates lie within the valid range.
{{< dots >}}
## Code 💻
```cpp
size_t d2(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
  unordered_map<size_t, unordered_map<size_t, vector<vector<int>>>> m;
  for (auto i = 0; i < ps.size(); ++i)
    for (auto j = i + 1; j < ps.size(); ++j) {
      auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
      auto len = d2(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
      m[center][len].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
    }
  for (auto it_c = begin(m); it_c != end(m); ++it_c)
    for (auto it_l = begin(it_c->second); it_l != end(it_c->second); ++it_l)
      for (auto i = 0; i < it_l->second.size(); ++i)
        for (auto j = i + 1; j < it_l->second.size(); ++j) {
          auto &p1 = it_l->second[i], &p2 = it_l->second[j];
          auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
          if (res == 0 || res > area) res = area;
        }
  return sqrt(res);
}
```

This function calculates the minimum area of a rectangle that can be formed by four points in a 2D plane. It uses geometric properties and hash maps to efficiently find candidate rectangles.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	size_t d2(int x1, int y1, int x2, int y2) {
	```
	Declares the helper function to calculate the squared distance between two points.

2. **Distance Calculation**
	```cpp
	  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	```
	Computes the squared Euclidean distance to avoid using square root for performance.

3. **Main Function Declaration**
	```cpp
	double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
	```
	Declares the main function to calculate the minimum rectangle area.

4. **Hash Map Initialization**
	```cpp
	  unordered_map<size_t, unordered_map<size_t, vector<vector<int>>>> m;
	```
	Initializes a hash map to group point pairs by their center and distance.

5. **Outer Loop**
	```cpp
	  for (auto i = 0; i < ps.size(); ++i)
	```
	Iterates through all points as the first point of a pair.

6. **Inner Loop**
	```cpp
	    for (auto j = i + 1; j < ps.size(); ++j) {
	```
	Iterates through subsequent points to form a pair with the current point.

7. **Center Calculation**
	```cpp
	      auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
	```
	Calculates a unique key representing the center of the line segment formed by the pair.

8. **Distance Calculation**
	```cpp
	      auto len = d2(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
	```
	Computes the squared length of the line segment formed by the pair.

9. **Group Pairs**
	```cpp
	      m[center][len].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
	```
	Groups the pair into the hash map based on center and distance.

10. **Iterate Groups**
	```cpp
	  for (auto it_c = begin(m); it_c != end(m); ++it_c)
	```
	Iterates over each center group in the hash map.

11. **Iterate Lengths**
	```cpp
	    for (auto it_l = begin(it_c->second); it_l != end(it_c->second); ++it_l)
	```
	Iterates over each length group within a center group.

12. **Compare Pairs**
	```cpp
	      for (auto i = 0; i < it_l->second.size(); ++i)
	```
	Iterates over pairs in the current group to compare them.

13. **Pair Comparisons**
	```cpp
	        for (auto j = i + 1; j < it_l->second.size(); ++j) {
	```
	Compares pairs to check if they form a rectangle.

14. **Rectangle Properties**
	```cpp
	          auto &p1 = it_l->second[i], &p2 = it_l->second[j];
	```
	Extracts the two pairs of points to calculate rectangle properties.

15. **Area Calculation**
	```cpp
	          auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
	```
	Calculates the area of the rectangle formed by the pairs.

16. **Update Result**
	```cpp
	          if (res == 0 || res > area) res = area;
	```
	Updates the minimum area if a smaller rectangle is found.

17. **Return Result**
	```cpp
	  return sqrt(res);
	```
	Returns the square root of the minimum area found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the nested loop for generating pairs of points.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is determined by the size of the hash map storing potential diagonals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-area-rectangle-ii/description/)

---
{{< youtube FcWK8CJReUo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
