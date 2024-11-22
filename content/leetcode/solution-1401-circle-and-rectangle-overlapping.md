
+++
authors = ["grid47"]
title = "Leetcode 1401: Circle and Rectangle Overlapping"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1401: Circle and Rectangle Overlapping in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1 -= xCenter;
        x2 -= xCenter;
        y1 -= yCenter;
        y2 -= yCenter;
        int mx = x1 * x2 > 0? min(x1 * x1, x2 * x2): 0;
        int my = y1 * y2 > 0? min(y1 * y1, y2 * y2): 0;
        return mx + my <= radius * radius;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves determining whether a circle and a rectangle overlap. The circle is defined by its center coordinates and radius, while the rectangle is specified by its lower-left and upper-right corner coordinates. The goal is to ascertain whether there is any intersection between the two shapes.

### Approach

To solve this problem, we need to follow a geometric approach to determine the relationship between the circle and the rectangle. The solution involves the following key steps:

1. **Coordinate Adjustment**: First, we will adjust the rectangle’s coordinates based on the center of the circle. This allows us to simplify the overlap check by shifting the coordinate system such that the circle’s center is at the origin (0,0).

2. **Distance Calculation**: We need to find the distance from the circle's center (now at the origin) to the nearest edge of the rectangle. The overlap condition is based on comparing this distance to the circle’s radius.

3. **Edge Cases Handling**: If the rectangle is entirely to the left, right, above, or below the circle, there is no overlap. We must also account for scenarios where the circle intersects with the corners of the rectangle.

### Code Breakdown (Step by Step)

Here is a breakdown of the provided C++ code, detailing each part of the implementation:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - We define a class named `Solution` which contains the method for checking overlap.

2. **Method Signature**:
   ```cpp
       bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
   ```
   - The `checkOverlap` method takes six integer parameters:
     - `radius`: The radius of the circle.
     - `xCenter`: The x-coordinate of the circle's center.
     - `yCenter`: The y-coordinate of the circle's center.
     - `x1`, `y1`: The coordinates of the bottom-left corner of the rectangle.
     - `x2`, `y2`: The coordinates of the top-right corner of the rectangle.

3. **Coordinate Adjustment**:
   ```cpp
           x1 -= xCenter;
           x2 -= xCenter;
           y1 -= yCenter;
           y2 -= yCenter;
   ```
   - The coordinates of the rectangle are adjusted by subtracting the circle's center coordinates. This transforms the coordinate system so that the circle's center is at the origin (0,0). After this adjustment, `x1`, `y1`, `x2`, and `y2` represent the rectangle’s corners relative to the circle's center.

4. **Distance Calculation**:
   ```cpp
           int mx = x1 * x2 > 0? min(x1 * x1, x2 * x2): 0;
           int my = y1 * y2 > 0? min(y1 * y1, y2 * y2): 0;
   ```
   - Here, we calculate the minimum squared distance from the center of the circle to the edges of the rectangle:
     - `mx` computes the x-axis contribution. If `x1` and `x2` have the same sign (both are positive or both are negative), we find the minimum squared distance to the rectangle's edges using `min(x1 * x1, x2 * x2)`. If they are on opposite sides of the center, we set `mx` to 0.
     - `my` performs a similar calculation for the y-axis.

5. **Overlap Check**:
   ```cpp
           return mx + my <= radius * radius;
   ```
   - Finally, we check if the sum of the squared distances (`mx + my`) is less than or equal to the square of the radius (`radius * radius`). If this condition holds, it means that the circle and rectangle overlap, and the function returns `true`. Otherwise, it returns `false`.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \( O(1) \) since we are only performing a constant number of arithmetic operations regardless of the size of the inputs.

- **Space Complexity**:
  - The space complexity is also \( O(1) \) because we are using a fixed amount of space for variables and not allocating any additional data structures that depend on input size.

### Conclusion

This implementation provides an efficient method to determine if a circle and a rectangle overlap based on geometric principles. By translating the problem into a simple coordinate system, we can use basic arithmetic operations to ascertain overlap without the need for more complex geometrical computations.

#### Key Takeaways:

- **Geometric Intuition**: Understanding how to manipulate coordinates based on geometric shapes is crucial for solving problems in computational geometry.
- **Efficiency**: The approach achieves constant time complexity, making it suitable for high-performance applications where rapid computations are necessary.
- **Scalability**: Since the solution does not depend on the size of the inputs beyond a fixed number of variables, it is scalable for large coordinate values.

This solution serves as a prime example of how to effectively tackle geometric overlap problems in computer science and algorithm design, offering a blend of mathematical understanding and programming techniques.

[`Link to LeetCode Lab`](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
