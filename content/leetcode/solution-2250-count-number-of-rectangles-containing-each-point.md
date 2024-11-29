
+++
authors = ["grid47"]
title = "Leetcode 2250: Count Number of Rectangles Containing Each Point"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2250: Count Number of Rectangles Containing Each Point in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Binary Indexed Tree","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uCTmN3j2hVU"
youtube_upload_date="2022-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/uCTmN3j2hVU/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D integer array `rectangles`, where each element `rectangles[i] = [li, hi]` represents a rectangle with a bottom-left corner at (0, 0), a length `li`, and a height `hi`. Additionally, you are provided a 2D integer array `points`, where each element `points[j] = [xj, yj]` represents a point on a 2D plane. The task is to determine the number of rectangles that contain each point. A rectangle contains a point if the point satisfies `0 <= xj <= li` and `0 <= yj <= hi`. Points on the edges of rectangles are also considered to be inside.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of rectangles and a list of points.
- **Example:** `rectangles = [[2, 3], [3, 4], [4, 5]], points = [[2, 2], [1, 4]]`
- **Constraints:**
	- 1 <= rectangles.length, points.length <= 5 * 10^4
	- rectangles[i].length == points[j].length == 2
	- 1 <= li, xj <= 10^9
	- 1 <= hi, yj <= 100
	- All rectangles and points are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array where each element corresponds to the number of rectangles that contain the respective point.
- **Example:** `Output: [3, 2]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** For each point, count the number of rectangles that contain it by comparing its coordinates against the dimensions of each rectangle.

- Sort the rectangles by their lengths.
- Group rectangles by their heights to optimize search operations.
- For each point, iterate over possible rectangle groups based on the point's height and check if the point's x-coordinate lies within the rectangle's length.
- Use binary search to efficiently count rectangles that meet the conditions.
{{< dots >}}
### Problem Assumptions ✅
- All rectangles are axis-aligned and start from the origin.
- The number of rectangles and points may vary independently.
{{< dots >}}
## Examples 🧩
- **Input:** `rectangles = [[3, 2], [4, 3]], points = [[2, 2], [3, 1]]`  \
  **Explanation:** The point (2, 2) is contained by both rectangles, while the point (3, 1) is contained only by the second rectangle. Thus, the result is [2, 1].

- **Input:** `rectangles = [[1, 1], [2, 2], [3, 3]], points = [[2, 3], [1, 1]]`  \
  **Explanation:** The point (2, 3) is contained only by the third rectangle, while the point (1, 1) is contained by all three rectangles. Thus, the result is [1, 3].

{{< dots >}}
## Approach 🚀
Utilize sorting and grouping techniques to efficiently count rectangles for each point while minimizing redundant checks.

### Initial Thoughts 💭
- Rectangles with larger heights can potentially contain points that are valid for rectangles with smaller heights.
- Sorting rectangles by length and grouping by height can help optimize the lookup process.
- A binary search within sorted groups can quickly identify eligible rectangles for a given point.
{{< dots >}}
### Edge Cases 🌐
- If no rectangles or points are provided, return an empty array.
- Handle up to 50,000 rectangles and points efficiently without exceeding time limits.
- Points located at the origin (0, 0) should be contained by all rectangles.
- Ensure binary search is correctly implemented for large input sizes.
{{< dots >}}
## Code 💻
```cpp
vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& pts) {
    
    int n = pts.size();
    
    vector<int> res(n, 0);
    
    sort(rec.begin(), rec.end());
    
    vector<vector<int>> grid(101);
    
    for(auto it: rec) {
        grid[it[1]].push_back(it[0]);
    }
    
    for(int j = 0; j < n; j++) {
        
        for(int i = pts[j][1]; i <= 100; i++) {
            res[j] += (grid[i].end() - lower_bound(grid[i].begin(), grid[i].end(), pts[j][0]));
        }
        
    }
    return res;
}
```

This function calculates how many rectangles contain each given point. For each point, it finds all rectangles that contain the point by using a sorted grid and binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& pts) {
	```
	This is the function definition for 'countRectangles', which takes two parameters: a list of rectangles and a list of points. The goal is to count how many rectangles contain each point.

2. **Variable Initialization**
	```cpp
	    int n = pts.size();
	```
	This initializes 'n', the number of points for which we need to calculate the number of containing rectangles.

3. **Result Vector Initialization**
	```cpp
	    vector<int> res(n, 0);
	```
	A result vector 'res' is initialized to store the count of rectangles for each point. It is initialized with zeros, one for each point.

4. **Sort Rectangles**
	```cpp
	    sort(rec.begin(), rec.end());
	```
	The list of rectangles is sorted by the y-coordinate of their bottom-left corner. Sorting helps optimize the search for containing rectangles later.

5. **Grid Initialization**
	```cpp
	    vector<vector<int>> grid(101);
	```
	A 2D grid is initialized with 101 rows, each representing a different y-coordinate. The grid will store the x-coordinates of the rectangles for each corresponding y-coordinate.

6. **Populate Grid**
	```cpp
	    for(auto it: rec) {
	```
	This loop iterates over each rectangle in 'rec' and populates the grid with the x-coordinates of rectangles that correspond to each y-coordinate.

7. **Insert Rectangle Coordinates**
	```cpp
	        grid[it[1]].push_back(it[0]);
	```
	For each rectangle, its x-coordinate is added to the grid at the row corresponding to its y-coordinate.

8. **Loop Through Points**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This loop iterates over each point in 'pts' to calculate how many rectangles contain that point.

9. **Loop Through y-coordinates**
	```cpp
	        for(int i = pts[j][1]; i <= 100; i++) {
	```
	This inner loop iterates over the y-coordinates starting from the point's y-coordinate and going up to 100. It checks all rectangles whose bottom-left corner's y-coordinate is less than or equal to the point's y-coordinate.

10. **Binary Search for x-coordinates**
	```cpp
	            res[j] += (grid[i].end() - lower_bound(grid[i].begin(), grid[i].end(), pts[j][0]));
	```
	This line uses binary search (lower_bound) to count how many rectangles at the current y-coordinate contain the point's x-coordinate.

11. **Return Result**
	```cpp
	    return res;
	```
	The function returns the result vector 'res', which contains the count of rectangles for each point.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m log k)
- **Average Case:** O(n log n + m log k)
- **Worst Case:** O(n log n + m log k)

n = number of rectangles, m = number of points, k = average number of rectangles per group.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(n + h)

h = maximum height value for grouping rectangles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/)

---
{{< youtube uCTmN3j2hVU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
