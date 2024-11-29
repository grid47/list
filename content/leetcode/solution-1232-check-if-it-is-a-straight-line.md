
+++
authors = ["grid47"]
title = "Leetcode 1232: Check If It Is a Straight Line"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1232: Check If It Is a Straight Line in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_tfiTQNZCbs"
youtube_upload_date="2019-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_tfiTQNZCbs/maxresdefault.webp"
comments = true
+++



---
You are given an array of coordinates, where each coordinate represents a point in the 2D plane. Your task is to check if all the points in the array lie on the same straight line.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of points, where each point is represented by two integers [x, y].
- **Example:** `coordinates = [[2, 3], [4, 5], [6, 7], [8, 9], [10, 11]]`
- **Constraints:**
	- 2 <= coordinates.length <= 1000
	- coordinates[i].length == 2
	- -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
	- coordinates contains no duplicate point.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value indicating whether all points lie on the same straight line.
- **Example:** `true`
- **Constraints:**
	- Return 'true' if all points are collinear, otherwise return 'false'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the slope between consecutive points remains the same across the entire list of points.

- Calculate the slope between the first two points.
- For each subsequent point, calculate the slope between it and the first point.
- If the slopes are not equal, return false.
- If all slopes are equal, return true.
{{< dots >}}
### Problem Assumptions ✅
- The input coordinates represent valid points in a 2D plane.
- The points are given in no particular order.
{{< dots >}}
## Examples 🧩
- **Input:** `coordinates = [[2, 3], [4, 5], [6, 7], [8, 9], [10, 11]]`  \
  **Explanation:** The points have the same slope between consecutive pairs, meaning they lie on the same straight line, so the output is 'true'.

- **Input:** `coordinates = [[1, 1], [2, 3], [3, 5], [4, 7]]`  \
  **Explanation:** The slope between the first two points is different from the slopes between the other points, meaning they do not lie on the same straight line, so the output is 'false'.

{{< dots >}}
## Approach 🚀
To determine if the points are collinear, we calculate the slope between the first point and the second, then compare it to the slope between the first point and each subsequent point.

### Initial Thoughts 💭
- The slope between two points is given by the formula (y2 - y1) / (x2 - x1).
- If the slopes between consecutive points are all equal, the points must lie on the same straight line.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the input will always contain at least two points.
- The solution should handle up to 1000 points efficiently.
- The coordinates can include negative values, but the slope calculation remains unaffected.
- Ensure that there are no duplicate points in the input.
{{< dots >}}
## Code 💻
```cpp
bool checkStraightLine(vector<vector<int>>& cord) {
    double slopt = (cord[1][0] - cord[0][0]) == 0? INT_MAX: (double)(cord[1][1] - cord[0][1]) / (double)(cord[1][0] - cord[0][0]);
    for(int i = 2; i < cord.size(); i++) {
        double slp = (cord[i][0] - cord[0][0]) == 0?INT_MAX: (double)(cord[i][1] - cord[0][1]) / (double)(cord[i][0] - cord[0][0]);
        if(slp != slopt) return false;
    }
    return true;
}
```

This function checks if a given set of points (represented as coordinates in `cord`) form a straight line by comparing the slopes between consecutive points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkStraightLine(vector<vector<int>>& cord) {
	```
	This is the function definition for `checkStraightLine`. The function takes a 2D vector of coordinates and checks whether the points lie on a straight line.

2. **Slope Calculation**
	```cpp
	    double slopt = (cord[1][0] - cord[0][0]) == 0? INT_MAX: (double)(cord[1][1] - cord[0][1]) / (double)(cord[1][0] - cord[0][0]);
	```
	The slope between the first two points is calculated. If the x-values of the points are the same, the slope is set to `INT_MAX` to represent an undefined slope (vertical line).

3. **Iteration Over Points**
	```cpp
	    for(int i = 2; i < cord.size(); i++) {
	```
	The function iterates over all the remaining points starting from the third point.

4. **Slope Comparison**
	```cpp
	        double slp = (cord[i][0] - cord[0][0]) == 0?INT_MAX: (double)(cord[i][1] - cord[0][1]) / (double)(cord[i][0] - cord[0][0]);
	```
	For each point, the slope with respect to the first point is calculated. If the x-values are the same, the slope is set to `INT_MAX`.

5. **Slope Check**
	```cpp
	        if(slp != slopt) return false;
	```
	If the calculated slope of any point does not match the slope of the first two points, the function returns `false`, indicating the points do not form a straight line.

6. **Return True**
	```cpp
	    return true;
	```
	If all slopes are the same, the function returns `true`, indicating the points form a straight line.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the points exactly once, so the time complexity is O(n), where n is the number of points.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables for slope calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-it-is-a-straight-line/description/)

---
{{< youtube _tfiTQNZCbs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
