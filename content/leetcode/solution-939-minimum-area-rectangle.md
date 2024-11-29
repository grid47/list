
+++
authors = ["grid47"]
title = "Leetcode 939: Minimum Area Rectangle"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 939: Minimum Area Rectangle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Geometry","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pFgBZFKJ2Co"
youtube_upload_date="2020-08-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pFgBZFKJ2Co/maxresdefault.webp"
comments = true
+++



---
You are given a set of points in a 2D plane, represented by an array where each point is a pair of integers [xi, yi]. Your task is to find the minimum area of a rectangle that can be formed using these points, with sides parallel to the X and Y axes. If no such rectangle can be formed, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array where each element represents a point in the X-Y plane. Each point is a pair of integers [xi, yi].
- **Example:** `Input: points = [[1,1],[2,2],[3,3],[1,3],[3,1]]`
- **Constraints:**
	- 1 <= points.length <= 500
	- points[i].length == 2
	- 0 <= xi, yi <= 40000
	- All the given points are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum area of the rectangle formed by these points, or 0 if no such rectangle exists.
- **Example:** `Output: 4`
- **Constraints:**
	- If no rectangle can be formed, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify all possible rectangles formed by four distinct points. The sides of the rectangle should be parallel to the X and Y axes, so we need to check for pairs of points with the same X or Y coordinates.

- 1. Store the points in a hash map grouped by their X-coordinates.
- 2. For each pair of points, check if the remaining two points can form a rectangle with sides parallel to the axes.
- 3. Calculate the area of the rectangle formed by the points.
- 4. Keep track of the minimum area found.
{{< dots >}}
### Problem Assumptions ✅
- All points are distinct and can potentially form a rectangle.
- The rectangle sides are parallel to the X and Y axes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: points = [[1,1],[2,2],[3,3],[1,3],[3,1]]`  \
  **Explanation:** In this case, the points (1,1), (1,3), (3,1), and (3,3) form a rectangle. The minimum area is calculated as (3 - 1) * (3 - 1) = 4.

- **Input:** `Input: points = [[1,1],[1,2],[2,2],[2,1]]`  \
  **Explanation:** The points form a perfect rectangle with sides parallel to the axes. The area is (2 - 1) * (2 - 1) = 1.

{{< dots >}}
## Approach 🚀
We will utilize a hash map to store the X-coordinates of the points, and for each pair of points, we check if the other two points necessary for a rectangle exist. If they do, we calculate the area of the rectangle and keep track of the minimum area.

### Initial Thoughts 💭
- The problem is essentially about identifying pairs of points that can form opposite corners of a rectangle.
- Using a hash map will help efficiently group points by their X-coordinates, allowing us to check for matching Y-coordinates quickly.
{{< dots >}}
### Edge Cases 🌐
- If the input has less than four points, return 0 as no rectangle can be formed.
- If there are a large number of points (up to 500), ensure that the solution is efficient enough to handle this within the time limits.
- If all the points are collinear (either all on the same vertical or horizontal line), return 0 as no rectangle can be formed.
- Ensure that each point is distinct, as duplicates would make it impossible to form a rectangle.
{{< dots >}}
## Code 💻
```cpp
int minAreaRect(vector<vector<int>>& pts) {
    
    unordered_map<int, set<int>> mp;
    for(auto &it: pts)
    mp[it[0]].insert(it[1]);
    
    int n = pts.size();
    int area = INT_MAX;
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
        
        int x1 = pts[i][0], y1 = pts[i][1];
        int x2 = pts[j][0], y2 = pts[j][1];
        
        if(x1 != x2 && y1 != y2) {
            
            if(mp[x1].find(y2) != mp[x1].end() &&
              mp[x2].find(y1) != mp[x2].end())
            {
                area = min(area, abs(x1 - x2) * abs(y1 - y2));
            }
        }
        
    }
    
    return area == INT_MAX? 0: area;
}
```

This function calculates the area of the smallest rectangle that can be formed by a set of points in a 2D plane. It uses a map to store coordinates and checks each pair of points to find the rectangle with the minimum area.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minAreaRect(vector<vector<int>>& pts) {
	```
	This line defines the function `minAreaRect`, which takes a vector of points `pts` and returns the minimum area of a rectangle that can be formed using these points.

2. **Variable Declaration**
	```cpp
	    unordered_map<int, set<int>> mp;
	```
	An unordered map `mp` is created to store each x-coordinate as a key and the set of corresponding y-coordinates as the value.

3. **Point Insertion**
	```cpp
	    for(auto &it: pts)
	```
	Iterate through each point in the `pts` vector.

4. **Map Population**
	```cpp
	    mp[it[0]].insert(it[1]);
	```
	For each point, insert the y-coordinate into the set corresponding to the x-coordinate in the map.

5. **Variable Initialization**
	```cpp
	    int n = pts.size();
	```
	Store the number of points in the variable `n`.

6. **Area Initialization**
	```cpp
	    int area = INT_MAX;
	```
	Initialize `area` to the maximum integer value to store the minimum area found.

7. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start an outer loop to iterate over each point in the list.

8. **Inner Loop**
	```cpp
	    for(int j = i + 1; j < n; j++) {
	```
	Start an inner loop to iterate over points that come after the current point in the outer loop.

9. **Point Extraction**
	```cpp
	        int x1 = pts[i][0], y1 = pts[i][1];
	```
	Extract the x and y coordinates of the first point in the pair.

10. **Point Extraction**
	```cpp
	        int x2 = pts[j][0], y2 = pts[j][1];
	```
	Extract the x and y coordinates of the second point in the pair.

11. **Rectangle Check**
	```cpp
	        if(x1 != x2 && y1 != y2) {
	```
	Check if the two points form the potential diagonal of a rectangle (i.e., their x and y coordinates must differ).

12. **Map Check**
	```cpp
	            if(mp[x1].find(y2) != mp[x1].end() && mp[x2].find(y1) != mp[x2].end())
	```
	Check if the other two points of the rectangle (which would complete the rectangle) exist in the map.

13. **Area Update**
	```cpp
	                area = min(area, abs(x1 - x2) * abs(y1 - y2));
	```
	Update the `area` variable to store the minimum area found by comparing it with the area of the current rectangle.

14. **Return Statement**
	```cpp
	    return area == INT_MAX? 0: area;
	```
	Return the minimum area found. If no valid rectangle is found, return 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we need to check all pairs of points, leading to a time complexity of O(n^2), where n is the number of points.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of points in the hash map, where n is the number of points.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-area-rectangle/description/)

---
{{< youtube pFgBZFKJ2Co >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
