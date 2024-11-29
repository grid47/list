
+++
authors = ["grid47"]
title = "Leetcode 1828: Queries on Number of Points Inside a Circle"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1828: Queries on Number of Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fU4oOBSsVMg"
youtube_upload_date="2021-04-19"
youtube_thumbnail="https://i.ytimg.com/vi/fU4oOBSsVMg/maxresdefault.jpg"
comments = true
+++



---
You are given an array of points, each represented by its coordinates [xi, yi] on a 2D plane. You are also given an array of queries, where each query describes a circle defined by its center at (xj, yj) and its radius rj. For each query, your task is to compute how many points lie inside or on the border of the circle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays. The first array, points, consists of pairs of integers where each pair represents the coordinates of a point. The second array, queries, consists of triplets where each triplet represents the center coordinates (xj, yj) and the radius rj of a circle.
- **Example:** `For example, points = [[1,3], [3,3], [5,3], [2,2]] represents 4 points, and queries = [[2,3,1], [4,3,1], [1,1,2]] represents 3 circles.`
- **Constraints:**
	- 1 <= points.length <= 500
	- points[i].length == 2
	- 0 <= xi, yi <= 500
	- 1 <= queries.length <= 500
	- queries[j].length == 3
	- 0 <= xj, yj <= 500
	- 1 <= rj <= 500

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element is the number of points inside or on the border of the corresponding circle defined in the queries array.
- **Example:** `For points = [[1,3],[3,3],[5,3],[2,2]] and queries = [[2,3,1],[4,3,1],[1,1,2]], the output will be [3, 2, 2], as there are 3 points inside or on the first circle, 2 points inside or on the second, and 2 points inside or on the third circle.`
- **Constraints:**
	- Each answer in the result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** For each query, calculate how many points are inside the circle. The circle includes the points on its border as well.

- 1. For each query, loop through each point and calculate the squared distance from the point to the center of the circle.
- 2. If the squared distance is less than or equal to the squared radius, increment the count for that query.
- 3. After processing all points for a query, store the count as the result for that query.
{{< dots >}}
### Problem Assumptions ✅
- Each point is represented as a pair of integers (xi, yi), and each query as a triplet (xj, yj, rj).
- A point is considered inside or on the border of the circle if its distance from the center is less than or equal to the radius.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: points = [[1,3], [3,3], [5,3], [2,2]], queries = [[2,3,1], [4,3,1], [1,1,2]]`  \
  **Explanation:** The first circle is centered at (2,3) with radius 1, which includes the points [1,3], [2,2], and [3,3], so the answer is 3. The second circle at (4,3) with radius 1 includes points [3,3] and [5,3], so the answer is 2. The third circle at (1,1) with radius 2 includes points [1,3] and [2,2], so the answer is 2.

- **Input:** `Input: points = [[1,1], [2,2], [3,3], [4,4], [5,5]], queries = [[1,2,2], [2,2,2], [4,3,2], [4,3,3]]`  \
  **Explanation:** The first circle includes the points [1,1] and [2,2], so the answer is 2. The second circle includes [1,1], [2,2], and [3,3], so the answer is 3. The third circle includes [4,4] and [5,5], so the answer is 2. The fourth circle includes all points, so the answer is 4.

{{< dots >}}
## Approach 🚀
We can solve this problem by checking each point for each query, calculating the distance to the center of the circle, and counting how many points fall inside the circle.

### Initial Thoughts 💭
- A point is inside or on the border of the circle if the squared distance from the point to the center is less than or equal to the squared radius of the circle.
- The brute force solution checks each point against every query, which results in O(n * q) time complexity, where n is the number of points and q is the number of queries.
{{< dots >}}
### Edge Cases 🌐
- If no points are provided, the result should be an array of zeros.
- If the number of points and queries is large (up to 500 each), ensure the algorithm can handle the maximum input size.
- If all points are identical, consider that all queries should include these points based on their radius.
- Ensure the solution handles large values efficiently within the given time limits.
{{< dots >}}
## Code 💻
```cpp
class Solution {
typedef vector<vector<int>> mo;
public:
vector<int> countPoints(mo& pts, mo& qrs) {
    vector<int> res;

    for(auto &q: qrs) {
        int cnt = 0, rr = q[2] * q[2];
        for(auto &p: pts)
            cnt += (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= rr;
        res.push_back(cnt);
    }

    return res;
}
```

This code defines the class `Solution` with a method `countPoints`. It calculates how many points in a list are within a given radius for each query circle. For each query, it checks the distance from all points and counts those within the circle's radius.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class, which contains the method `countPoints` to solve the problem.

2. **Typedef Declaration**
	```cpp
	typedef vector<vector<int>> mo;
	```
	This line defines a shorthand type `mo` for a 2D vector of integers. It is used to represent both the list of points and queries in the method.

3. **Public Access Modifier**
	```cpp
	public:
	```
	Marks the start of the public section of the class, where methods are accessible outside the class.

4. **Function Definition**
	```cpp
	vector<int> countPoints(mo& pts, mo& qrs) {
	```
	Defines the function `countPoints`, which takes two 2D vectors: `pts` (points) and `qrs` (queries). It returns a vector of integers representing the count of points within the radius for each query.

5. **Result Initialization**
	```cpp
	    vector<int> res;
	```
	Initializes an empty vector `res` to store the result: the count of points inside each query's circle.

6. **Loop Through Queries**
	```cpp
	    for(auto &q: qrs) {
	```
	Begins a loop to iterate through each query in `qrs`. Each query represents a circle defined by its center coordinates and radius.

7. **Query Initialization**
	```cpp
	        int cnt = 0, rr = q[2] * q[2];
	```
	Initializes `cnt` to 0 to count the points within the circle and calculates `rr`, the square of the radius (radius squared) for distance comparison.

8. **Loop Through Points**
	```cpp
	        for(auto &p: pts)
	```
	Starts a nested loop to iterate over each point in the `pts` vector.

9. **Distance Check**
	```cpp
	            cnt += (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= rr;
	```
	For each point `p`, this line calculates the squared distance between the point and the center of the query circle. If the squared distance is less than or equal to `rr`, it increments the count `cnt`.

10. **Store Result**
	```cpp
	        res.push_back(cnt);
	```
	After checking all points for the current query, the count of points within the circle (`cnt`) is added to the result vector `res`.

11. **Return Result**
	```cpp
	    return res;
	```
	Returns the result vector `res` containing the counts of points within each query circle.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * q) when the points are sparse and the circles have small radii.
- **Average Case:** O(n * q), where n is the number of points and q is the number of queries.
- **Worst Case:** O(n * q), which occurs when every point must be checked for every query.

The time complexity is O(n * q) because we are iterating over each query and checking each point.

### Space Complexity 💾
- **Best Case:** O(n + q), which is required to store the points and queries.
- **Worst Case:** O(n + q), which is required to store the points and the queries.

The space complexity is O(n + q) because we store both the points and queries arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/)

---
{{< youtube fU4oOBSsVMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
