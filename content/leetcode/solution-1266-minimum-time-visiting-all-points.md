
+++
authors = ["grid47"]
title = "Leetcode 1266: Minimum Time Visiting All Points"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1266: Minimum Time Visiting All Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jqcmjnXmCaw"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/jqcmjnXmCaw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return ans;
    }
};
{{< /highlight >}}
---


### Problem Statement
The goal of this problem is to determine the minimum time required for a person to visit all specified points on a 2D plane. The person can move from one point to another in a way that allows for diagonal movements. Thus, the time it takes to travel from point A at coordinates \((x_1, y_1)\) to point B at coordinates \((x_2, y_2)\) is determined by the maximum of the absolute differences in the x-coordinates and y-coordinates. Formally, the time \(T\) to move from point A to point B can be calculated using:

\[ 
T = \max(|x_2 - x_1|, |y_2 - y_1|) 
\]

Given an array of points, the task is to compute the total time required to visit all the points in the order they are provided.

### Approach
The approach to solving this problem involves iterating through the list of points and calculating the time taken to move from each point to the next. By accumulating the time required for each pair of consecutive points, we can arrive at the total minimum time required to visit all points. The key steps in the approach are as follows:

1. Initialize a variable to keep track of the total time.
2. Loop through the list of points, starting from the second point.
3. For each point, compute the time to reach it from the previous point using the maximum of the absolute differences in their x and y coordinates.
4. Sum all these times to get the final result.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
```
- **Line 1-3**: The `Solution` class is defined, containing the public member function `minTimeToVisitAllPoints`, which takes a 2D vector `points` representing the coordinates of the points to visit.

```cpp
        int ans = 0;
```
- **Line 4**: We initialize an integer variable `ans` to zero. This variable will accumulate the total time needed to visit all points.

```cpp
        for(int i = 1; i < points.size(); i++) {
```
- **Line 5**: We begin a loop that starts from the second point (index `1`) and continues until the last point in the `points` array.

```cpp
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
```
- **Line 6**: For each point at index `i`, we calculate the time taken to move from the previous point at index `i-1`. The time is computed using the formula discussed earlier:
  - `abs(points[i][1] - points[i - 1][1])` computes the absolute difference in the y-coordinates.
  - `abs(points[i][0] - points[i - 1][0])` computes the absolute difference in the x-coordinates.
  - `max(...)` returns the greater of these two differences, which gives the time required to travel between the two points. This value is then added to `ans`.

```cpp
        return ans;
    }
};
```
- **Line 7**: After completing the loop for all points, we return the accumulated time stored in `ans`, which represents the minimum time to visit all points.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this solution is \(O(n)\), where \(n\) is the number of points in the `points` array. This is because we iterate through the list of points exactly once.

2. **Space Complexity**:
   - The space complexity is \(O(1)\), as we are using only a fixed number of variables (i.e., `ans` and `i`) regardless of the size of the input.

### Conclusion
The `minTimeToVisitAllPoints` function efficiently calculates the minimum time required to visit all specified points on a 2D plane using a straightforward iterative approach. By leveraging the properties of absolute differences and diagonal movement, this solution effectively computes the necessary travel time in linear time complexity, making it suitable for large datasets.

In summary, the function highlights the elegance of mathematical operations in algorithm design, demonstrating how simple computations can lead to efficient and effective solutions to geometric and spatial problems. This technique can be applied to various problems involving movement in multidimensional spaces, making it a valuable addition to an algorithmic toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-visiting-all-points/description/)

---
{{< youtube jqcmjnXmCaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
