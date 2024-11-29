
+++
authors = ["grid47"]
title = "Leetcode 593: Valid Square"
date = "2024-09-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 593: Valid Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/593.webp"
youtube = "5ErP0_vpzvI"
youtube_upload_date="2020-07-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/5ErP0_vpzvI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/593.webp" 
    alt="A square being validated, with each corner softly glowing as the square is checked for correctness."
    caption="Solution to LeetCode 593: Valid Square Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given four points in a 2D space, determine if these points form a valid square. The points are not necessarily provided in any particular order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four points, each represented as an array of two integers [x, y], where x and y are the coordinates of the point in the 2D plane.
- **Example:** `Input: p1 = [0, 0], p2 = [1, 1], p3 = [1, 0], p4 = [0, 1]`
- **Constraints:**
	- Each point is represented by two integers, xi and yi, where -10^4 ≤ xi, yi ≤ 10^4.
	- The input will always contain exactly four points.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return 'true' if the four points form a valid square, otherwise return 'false'.
- **Example:** `Output: 'true'`
- **Constraints:**
	- The output is a boolean value indicating whether the points form a valid square.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if the four given points form a valid square by ensuring equal side lengths and 90-degree angles.

- Calculate the pairwise distances between the four points.
- Check if there are two unique distances: one for the sides (which should appear four times) and one for the diagonals (which should appear twice).
- Ensure that the diagonals are longer than the sides, as they should be the hypotenuses of the right triangles formed by the sides.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain four valid points, and the points are not guaranteed to be ordered in any way.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]`  \
  **Explanation:** These points form a square as they have equal sides and the diagonals are equal.

- **Input:** `Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]`  \
  **Explanation:** These points do not form a square as the sides are not equal.

{{< dots >}}
## Approach 🚀
To determine whether the points form a valid square, we compute the distances between each pair of points and check for two unique distances: one for the sides and one for the diagonals.

### Initial Thoughts 💭
- A square has equal side lengths and equal diagonals.
- We can calculate the squared Euclidean distance between pairs of points.
- If there are two distinct distances: one for sides (appearing four times) and one for diagonals (appearing twice), then the points form a square.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain four points, so empty inputs are not a concern.
- The input coordinates are within a bounded range, so large inputs are not an issue.
- Points with coordinates on axes or forming degenerate squares (e.g., all points on a straight line) need to be handled.
- The points are not guaranteed to be in any specific order.
{{< dots >}}
## Code 💻
```cpp
int d(vector<int> p, vector<int> q) {
    return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
    return !s.count(0) && s.size() == 2;
}
```

This code defines a function to check if four points form a valid square. The helper function `d` computes the squared distance between two points, and the main function `validSquare` checks whether the set of distances between all pairs of points contains exactly two unique distances (the side length and the diagonal).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int d(vector<int> p, vector<int> q) {
	```
	Declares the function `d` that calculates the squared Euclidean distance between two points, `p` and `q`, represented by 2D vectors.

2. **Distance Calculation**
	```cpp
	    return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
	```
	Calculates the squared distance between the two points `p` and `q`. This avoids the need for a square root calculation, which is computationally expensive.

3. **Function Declaration**
	```cpp
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
	```
	Declares the function `validSquare` that takes four 2D points as input and returns a boolean indicating whether they form a valid square.

4. **Set Initialization**
	```cpp
	    set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
	```
	Creates a set `s` to store the squared distances between all pairs of points. Since sets do not allow duplicates, this step helps in identifying whether there are exactly two unique distances (the side length and diagonal).

5. **Condition Check**
	```cpp
	    return !s.count(0) && s.size() == 2;
	```
	Checks if there are no zero distances (which would indicate overlapping points) and if the set contains exactly two unique distances, which is a characteristic of a square.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(6)

Since there are always exactly four points, the time complexity is constant, O(6), due to the fixed number of pairwise comparisons.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we are only storing a fixed number of distances.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-square/description/)

---
{{< youtube 5ErP0_vpzvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
