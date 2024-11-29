
+++
authors = ["grid47"]
title = "Leetcode 2013: Detect Squares"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2013: Detect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bahebearrDc"
youtube_upload_date="2021-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/bahebearrDc/maxresdefault.jpg"
comments = true
+++



---
You are given a stream of 2D points on the XY-plane. Your task is to design an algorithm that adds new points into a data structure and counts how many sets of three points, along with a given query point, can form an axis-aligned square. An axis-aligned square is a square where the edges are parallel or perpendicular to the X-axis and Y-axis, with all sides of equal length.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of operations: adding points and querying for squares. Each operation is represented as a list containing a string representing the operation and, if applicable, a list of integers representing the point being added or queried.
- **Example:** `["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]`
- **Constraints:**
	- point.length == 2
	- 0 <= x, y <= 1000
	- At most 3000 calls in total will be made to add and count.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output for each operation is either null (for 'add' operations) or an integer (for 'count' operations) representing the number of ways to form an axis-aligned square with the given query point.
- **Example:** `[null, null, null, null, 1, 0, null, 2]`
- **Constraints:**
	- The result of each count operation is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To design an efficient way to store points and count axis-aligned squares formed with a query point. This involves identifying potential square candidates based on the coordinates of the query point and checking if they can form a valid square with other points in the structure.

- Store each point added to the data structure.
- For each count query, check all stored points to see if they can form a square with the query point, and count the valid squares.
{{< dots >}}
### Problem Assumptions ✅
- Each point is represented as a 2D coordinate in the form of a list with two integers.
- The data structure should allow efficient insertion and querying.
{{< dots >}}
## Examples 🧩
- **Input:** `["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]`  \
  **Explanation:** In this example, we first add points (3, 10), (11, 2), and (3, 2) to the data structure. Then, we query for the number of squares that can be formed with the point (11, 10). We find one square formed by the points [(3, 10), (11, 2), (3, 2), (11, 10)]. The second query for the point (14, 8) returns 0, as no square can be formed with this point. A duplicate point (11, 2) is added, and the query for (11, 10) now returns 2, as two valid squares can be formed.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a data structure to store all points and track how many times each point is added. For each query, we will iterate over the stored points and check if they can form a valid axis-aligned square with the query point.

### Initial Thoughts 💭
- Each square is formed by a set of four points, with one of the points being the query point. The other three points should form the other corners of the square.
- We need an efficient way to store points and query for squares, without checking all possible combinations for every query.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one point added before any count query is made.
- Ensure the solution handles up to 3000 add and count operations efficiently.
- Handle cases where no square can be formed (e.g., when the query point is too far from other points).
- The solution should work efficiently within the given constraints of the problem.
{{< dots >}}
## Code 💻
```cpp
vector<pair<int, int>> pts;
public:
DetectSquares() {
   // cnt.resize(10001, vector<int>(10001));
}

void add(vector<int> point) {
    cnt[point[0]][point[1]]++;
    pts.emplace_back(point[0], point[1]);
}

int count(vector<int> point) {
    int x1 = point[0], y1 = point[1];
    int ans = 0;
    for(auto [x3, y3] : pts) {
        if(abs(x3 - x1) == 0 || abs(x1 - x3) != abs(y1 - y3))
            continue;
        ans += cnt[x1][y3] * cnt[x3][y1];
    }
    return ans;
}
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
```

This code defines a class `DetectSquares` that allows for adding points and counting the number of squares formed by those points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<pair<int, int>> pts;
	```
	This line declares a vector `pts` to store the points added to the object, each represented as a pair of integers (x, y).

2. **Access Modifier**
	```cpp
	public:
	```
	This defines the start of the public section of the class, where methods can be accessed from outside the class.

3. **Constructor Definition**
	```cpp
	DetectSquares() {
	```
	This is the constructor of the `DetectSquares` class, which initializes the object when an instance is created.

4. **Function Definition**
	```cpp
	void add(vector<int> point) {
	```
	This defines the `add` function that takes a point as a vector of two integers and adds it to the object.

5. **Data Update**
	```cpp
	    cnt[point[0]][point[1]]++;
	```
	Increments the count for the point's coordinates in the 2D vector `cnt`.

6. **Data Update**
	```cpp
	    pts.emplace_back(point[0], point[1]);
	```
	Adds the point as a pair to the `pts` vector.

7. **Function Definition**
	```cpp
	int count(vector<int> point) {
	```
	This defines the `count` function that takes a point as input and returns the number of squares that can be formed using that point.

8. **Variable Initialization**
	```cpp
	    int x1 = point[0], y1 = point[1];
	```
	This initializes the variables `x1` and `y1` with the coordinates of the input `point`.

9. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	This initializes the variable `ans` to store the count of squares.

10. **Loop Initialization**
	```cpp
	    for(auto [x3, y3] : pts) {
	```
	This begins a loop that iterates through each point `(x3, y3)` stored in `pts`.

11. **Conditional Check**
	```cpp
	        if(abs(x3 - x1) == 0 || abs(x1 - x3) != abs(y1 - y3))
	```
	Checks if the current point `(x3, y3)` does not form a square with the point `(x1, y1)` by comparing the differences in their x and y coordinates.

12. **Loop Control**
	```cpp
	            continue;
	```
	If the condition is true, it skips the rest of the loop and moves to the next point.

13. **Calculation**
	```cpp
	        ans += cnt[x1][y3] * cnt[x3][y1];
	```
	Calculates the number of squares formed by the current point `(x3, y3)` and the point `(x1, y1)` and adds this to `ans`.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final count of squares that can be formed using the input point.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for add operations.
- **Average Case:** O(n) for count operations, where n is the number of points added.
- **Worst Case:** O(n) for each count operation.

Each add operation is constant time, while each count operation may require iterating over the stored points to check for possible squares.

### Space Complexity 💾
- **Best Case:** O(1) when no points are added.
- **Worst Case:** O(n) where n is the number of points stored.

The space complexity is linear with respect to the number of points stored in the data structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/detect-squares/description/)

---
{{< youtube bahebearrDc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
