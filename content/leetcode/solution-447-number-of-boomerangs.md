
+++
authors = ["grid47"]
title = "Leetcode 447: Number of Boomerangs"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 447: Number of Boomerangs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/447.webp"
youtube = "QPsEA1Ls3jQ"
youtube_upload_date="2019-11-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QPsEA1Ls3jQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/447.webp" 
    alt="A series of points where boomerangs are formed, glowing as each boomerang path is traced."
    caption="Solution to LeetCode 447: Number of Boomerangs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given n distinct points in the 2D plane. A boomerang is defined as a tuple of three points (i, j, k) where the distance between points i and j equals the distance between points i and k. Count the total number of boomerangs that can be formed from the given points.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of n distinct points in the 2D plane, each represented by a pair of integers [xi, yi].
- **Example:** `[[0,0], [1,0], [2,0]]`
- **Constraints:**
	- 1 <= n <= 500
	- -10^4 <= xi, yi <= 10^4
	- All points are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the number of boomerangs formed from the given points.
- **Example:** `2`
- **Constraints:**
	- The number of boomerangs can be zero if no such triplets can be formed.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the total number of boomerangs by comparing distances between points.

- 1. For each point, calculate the distances to all other points.
- 2. Store the frequency of each distance in a map (or hashmap).
- 3. For each distinct distance, calculate the number of ways to pick two points that share the same distance from the current point.
- 4. The number of boomerangs is the sum of all valid pairs for all distances.
{{< dots >}}
### Problem Assumptions ✅
- All points are distinct and represented as pairs of integers.
{{< dots >}}
## Examples 🧩
- **Input:** `[[0,0], [1,0], [2,0]]`  \
  **Explanation:** The two boomerangs formed are: [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

- **Input:** `[[1,1], [2,2], [3,3]]`  \
  **Explanation:** The two boomerangs formed are: [[1,1], [2,2], [3,3]] and [[2,2], [1,1], [3,3]].

{{< dots >}}
## Approach 🚀
The approach involves calculating distances between all pairs of points and counting valid triplets where the distance between two points is equal to the distance between another two points.

### Initial Thoughts 💭
- For each point, we can calculate distances to all other points, which gives us potential boomerangs.
- By storing the frequency of distances, we can efficiently calculate the number of valid boomerangs.
- We can optimize the process by using a hashmap to store the distances from each point.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one point, so no need to handle empty inputs.
- For large inputs (up to 500 points), ensure that the solution efficiently handles the calculations of distances and the counting of pairs.
- Ensure that the solution handles cases with no possible boomerangs, such as when there are fewer than 3 points.
- The algorithm should efficiently handle the maximum constraint of 500 points.
{{< dots >}}
## Code 💻
```cpp
int numberOfBoomerangs(vector<vector<int>>& points) {
    map<int, int> mp;
    int res = 0;
    for(int i = 0; i < points.size(); i++) {
        for(int j = 0; j < points.size(); j++) {
            int d = getDist(points[i], points[j]);
            mp[d]++;
        }
        for(auto [_, val]: mp)
        res += val * (val - 1);
        mp.clear();
    }
    return res;
}

int getDist(vector<int> a, vector<int> b) {
    int x = a[0] - b[0];
    int y = a[1] - b[1];
    return x * x + y * y;
}
```

This solution calculates the number of boomerangs in a set of points. A boomerang is a tuple of points such that the distance between one point and two other points is the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfBoomerangs(vector<vector<int>>& points) {
	```
	Defines the main function to calculate the number of boomerangs in a set of points.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map to store distances and their frequencies for each pair of points.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	The result variable that will store the total number of boomerangs.

4. **Loop**
	```cpp
	    for(int i = 0; i < points.size(); i++) {
	```
	Loop over each point in the list of points.

5. **Nested Loop**
	```cpp
	        for(int j = 0; j < points.size(); j++) {
	```
	Inner loop to compare the current point with every other point.

6. **Distance Calculation**
	```cpp
	            int d = getDist(points[i], points[j]);
	```
	Calculates the squared distance between two points.

7. **Map Operations**
	```cpp
	            mp[d]++;
	```
	Increments the count of the calculated distance in the map.

8. **Map Iteration**
	```cpp
	        for(auto [_, val]: mp)
	```
	Iterate over the map to calculate boomerangs based on the distances.

9. **Result Calculation**
	```cpp
	        res += val * (val - 1);
	```
	For each distance, calculate how many boomerangs can be formed using the frequency of that distance.

10. **Map Reset**
	```cpp
	        mp.clear();
	```
	Clears the map to start fresh for the next point.

11. **Return**
	```cpp
	    return res;
	```
	Returns the final count of boomerangs.

12. **Helper Function Definition**
	```cpp
	int getDist(vector<int> a, vector<int> b) {
	```
	Helper function to calculate the squared distance between two points.

13. **Distance Calculation**
	```cpp
	    int x = a[0] - b[0];
	```
	Calculates the difference in the x-coordinates of the two points.

14. **Distance Calculation**
	```cpp
	    int y = a[1] - b[1];
	```
	Calculates the difference in the y-coordinates of the two points.

15. **Return**
	```cpp
	    return x * x + y * y;
	```
	Returns the squared distance between the two points.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In all cases, we need to calculate the distance between each pair of points, which results in O(n^2) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

In the worst case, we store distances for each point in a hashmap, resulting in O(n^2) space complexity.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-boomerangs/description/)

---
{{< youtube QPsEA1Ls3jQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
