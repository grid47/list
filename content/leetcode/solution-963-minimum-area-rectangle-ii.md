
+++
authors = ["grid47"]
title = "Leetcode 963: Minimum Area Rectangle II"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 963: Minimum Area Rectangle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FcWK8CJReUo"
youtube_upload_date="2020-08-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FcWK8CJReUo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    size_t d2(int x1, int y1, int x2, int y2) {
      return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
      unordered_map<size_t, unordered_map<size_t, vector<vector<int>>>> m;
      for (auto i = 0; i < ps.size(); ++i)
        for (auto j = i + 1; j < ps.size(); ++j) {
          auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
          auto len = d2(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
          m[center][len].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
        }
      for (auto it_c = begin(m); it_c != end(m); ++it_c)
        for (auto it_l = begin(it_c->second); it_l != end(it_c->second); ++it_l)
          for (auto i = 0; i < it_l->second.size(); ++i)
            for (auto j = i + 1; j < it_l->second.size(); ++j) {
              auto &p1 = it_l->second[i], &p2 = it_l->second[j];
              auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
              if (res == 0 || res > area) res = area;
            }
      return sqrt(res);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves finding the minimum area of a rectangle that can be formed from a set of given points in a 2D plane. The rectangle must have its sides parallel to the axes, and its four corners must be among the provided points. You are tasked with implementing a function that computes the minimum area of such a rectangle, or returns `0` if no rectangle can be formed.

### Approach

The approach to solving this problem relies on the following insights:

1. **Rectangle Properties**:
   - A rectangle aligned with the coordinate axes requires two pairs of points with the same x or y coordinates. Thus, any two points can define one diagonal of a rectangle, and the other two corners of the rectangle can be inferred if the other pair of points is available.
   - Given two points, we need to find the other two points that complete the rectangle.

2. **Using Pairwise Distances**:
   - We first calculate all pairwise distances between the points to help identify possible diagonals of the rectangle.
   - By keeping track of the distances between each pair of points and grouping them by the center of the diagonal (midpoint), we can look for two diagonals that share the same center.

3. **Efficient Search**:
   - For each pair of points `(i, j)` that are diagonally opposite corners of a potential rectangle, we use the midpoint and the distance between them to help identify if the other two corners can be found in the set of given points.
   - Once we identify a valid rectangle, we calculate its area using the distance between two adjacent sides.

4. **Optimizing Search with Hashmaps**:
   - By utilizing hashmaps to store distances and midpoints, we can efficiently look up the other diagonal points and check for potential rectangles. This allows us to process the points in an optimized manner without having to exhaustively check all pairs of points.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    size_t d2(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
```

1. **Distance Function**: 
   - The `d2` function calculates the squared Euclidean distance between two points `(x1, y1)` and `(x2, y2)`. Squaring the distances avoids the computational overhead of square roots and is sufficient for comparing relative distances.

```cpp
    double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
        unordered_map<size_t, unordered_map<size_t, vector<vector<int>>>> m;
```

2. **Main Function Setup**:
   - The function `minAreaFreeRect` takes a list of points `ps` and calculates the minimum area of a rectangle that can be formed using these points. 
   - We use a nested hashmap `m` to store pairs of points by their **midpoint** and **squared distance**. The structure `m[center][len]` keeps track of the points that are connected by a diagonal of length `len` and share the same midpoint.

```cpp
        for (auto i = 0; i < ps.size(); ++i)
            for (auto j = i + 1; j < ps.size(); ++j) {
                auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
                auto len = d2(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
                m[center][len].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
            }
```

3. **Generating Midpoints and Distances**:
   - We iterate over all pairs of points `(i, j)` to compute their **center** (midpoint) and **distance** (`len`). 
   - The center is computed as the sum of the x-coordinates and y-coordinates of the two points, and the distance is computed using the `d2` function.
   - The pair of points is then stored in the hashmap `m` under the corresponding center and distance.

```cpp
        for (auto it_c = begin(m); it_c != end(m); ++it_c)
            for (auto it_l = begin(it_c->second); it_l != end(it_c->second); ++it_l)
                for (auto i = 0; i < it_l->second.size(); ++i)
                    for (auto j = i + 1; j < it_l->second.size(); ++j) {
                        auto &p1 = it_l->second[i], &p2 = it_l->second[j];
                        auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
                        if (res == 0 || res > area) res = area;
                    }
```

4. **Identifying Rectangles**:
   - After populating the hashmap, we iterate over each entry to check for pairs of diagonally opposite corners. 
   - If two pairs of points share the same center and distance, they can form a rectangle. We calculate the area of the rectangle formed by these two pairs using the squared distances of the sides.
   - If the area is smaller than the current minimum (`res`), we update `res`.

```cpp
        return sqrt(res);
    }
};
```

5. **Returning the Result**:
   - After checking all possible pairs of diagonals and calculating their areas, the function returns the square root of the smallest area found. If no rectangle is found, `res` remains 0, and the function returns `0`.

### Complexity

- **Time Complexity**: The time complexity of this solution is **O(n^2)**, where `n` is the number of points. This is because we iterate over all pairs of points to calculate the midpoints and distances, and we then perform checks for potential rectangles. The overall complexity is dominated by the double iteration over the points, which results in a quadratic time complexity.

- **Space Complexity**: The space complexity is also **O(n^2)** due to the use of the nested hashmaps to store the midpoints and distances. The hashmap may store up to `n^2` pairs of points, each associated with a midpoint and distance.

### Conclusion

This solution efficiently calculates the minimum area of a rectangle that can be formed by a set of points in the 2D plane. By leveraging hashmaps to store midpoints and distances between pairs of points, we reduce the problem to an efficient search for possible rectangles. The approach is optimized for performance by avoiding unnecessary checks and focusing on the geometric properties of the points. The overall time and space complexity are manageable for moderate-sized input sets, making this solution a good choice for solving this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-area-rectangle-ii/description/)

---
{{< youtube FcWK8CJReUo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
