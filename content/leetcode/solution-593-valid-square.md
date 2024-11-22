
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int d(vector<int> p, vector<int> q) {
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
        return !s.count(0) && s.size() == 2;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given the coordinates of four points in a 2D plane. The task is to determine whether these points can form a valid square. A valid square is one where:
1. All four sides are of equal length.
2. The diagonals are of equal length, and they intersect at right angles (i.e., they are perpendicular).

The input consists of four points, each represented by a vector of two integers indicating the x and y coordinates of the points. The goal is to return `true` if the points form a valid square, and `false` otherwise.

### Approach

To solve this problem, we can break it down into the following steps:

1. **Distance Calculation**: For a valid square, we need to calculate the distances between the points. This includes the distances between adjacent points (sides of the square) and the distances between opposite points (diagonals). 
   
2. **Set of Distances**: We can utilize a set to store the distances. A valid square will have exactly two unique distances in the set:
   - The shorter distance will correspond to the sides of the square.
   - The longer distance will correspond to the diagonals of the square.
   
3. **Conditions for Valid Square**:
   - The distance between two points cannot be zero (i.e., no two points can coincide).
   - There should only be two distinct distances in the set: one for the sides and one for the diagonals.
   - The diagonals should be longer than the sides.

### Code Breakdown (Step by Step)

#### Step 1: Distance Calculation
```cpp
int d(vector<int> p, vector<int> q) {
    return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
}
```
- The function `d` computes the squared distance between two points `p` and `q` in the 2D plane. The squared distance formula is:
  \[
  \text{distance}^2 = (x_2 - x_1)^2 + (y_2 - y_1)^2
  \]
  This avoids calculating the square root, which is computationally expensive and unnecessary for this problem since we are only interested in comparing distances.
  
- This function is called multiple times in the solution to calculate the distance between pairs of points.

#### Step 2: Valid Square Check
```cpp
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
    return !s.count(0) && s.size() == 2;
}
```
- In this step, the function `validSquare` checks if the four points form a valid square:
  - We compute the distances between all pairs of points: `d(p1, p2)`, `d(p2, p3)`, `d(p3, p4)`, `d(p4, p1)`, `d(p1, p3)`, and `d(p2, p4)`. These represent the distances between adjacent points (sides) and opposite points (diagonals).
  - These distances are stored in a `set<int> s`. A set automatically removes duplicates, ensuring that we only store unique distances. If there are no duplicate distances, the set will contain exactly two unique distances — one for the sides and one for the diagonals.
  - The function then checks two conditions:
    1. `!s.count(0)`: This ensures that there are no duplicate points, as a distance of `0` would indicate that two points coincide.
    2. `s.size() == 2`: This ensures that there are exactly two unique distances — one for the sides and one for the diagonals.

### Complexity

#### Time Complexity:
- **O(1)**: The time complexity is constant because we are always working with exactly six distances (the six unique pairs of points), regardless of the specific values of the points. The set operations (insertion and checking size) are constant time because the set has a maximum of two distinct distances.

#### Space Complexity:
- **O(1)**: The space complexity is constant because we are only storing six distances in the set, which does not grow with the size of the input. Therefore, the space complexity is fixed.

### Conclusion

This solution provides an efficient way to determine whether four points can form a valid square. By leveraging the properties of distances between points and utilizing a set to store unique distances, the code is able to quickly and accurately check the conditions for a valid square. 

The key steps include:
1. **Calculating the distances** between all pairs of points.
2. **Storing the distances in a set** to ensure uniqueness and checking if there are exactly two distinct distances (sides and diagonals).
3. **Checking for duplicate points** to ensure no two points overlap.

This approach ensures correctness while maintaining optimal time and space complexity, making it an ideal solution for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-square/description/)

---
{{< youtube 5ErP0_vpzvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
