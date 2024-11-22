
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem requires counting the number of rectangles that can cover each of a set of given points on a 2D grid. Given a list of rectangles and a list of points, you need to determine how many of the rectangles can cover each point. Each rectangle is represented by its bottom-left corner `(x1, y1)` and top-right corner `(x2, y2)`, where `x1 < x2` and `y1 < y2`. A rectangle can cover a point if the point lies within the rectangle, i.e., its x-coordinate lies between `x1` and `x2`, and its y-coordinate lies between `y1` and `y2`.

### Approach

To solve this problem efficiently, we can break it down into a series of steps:

1. **Sort the Rectangles by Y-Coordinate**: Rectangles are sorted by their `y2` value. This is because when processing each point, we want to only consider rectangles that extend up to the y-coordinate of that point and above.

2. **Use a Grid to Track Rectangle Coverage**: The grid will store the x-coordinates of rectangles that have a certain y2-coordinate. This allows quick access to the x-coordinates of rectangles for a given y range.

3. **Binary Search for Efficient Counting**: To count how many rectangles cover a point, we use binary search on the x-coordinates of rectangles in the grid. This enables us to quickly determine how many rectangles have a left edge (x1) to the left of the point's x-coordinate.

4. **Accumulate Rectangle Counts**: For each point, traverse the grid from its y-coordinate upwards to find all rectangles that can cover the point. For each rectangle that may cover the point, count how many rectangles’ x-coordinates are valid by performing a binary search.

### Code Breakdown (Step by Step)

#### Step 1: Initialize and Sort Rectangles

```cpp
int n = pts.size();
vector<int> res(n, 0);
sort(rec.begin(), rec.end());
```

- The first step is to initialize the result vector `res` to store the answer for each point. The vector is initialized to zeros, as initially no rectangles have been considered for any point.
- The rectangles `rec` are sorted by their y-coordinate to make it easier to process them in increasing order of y-values.

#### Step 2: Prepare the Grid for Efficient Counting

```cpp
vector<vector<int>> grid(101);
for(auto it: rec) {
    grid[it[1]].push_back(it[0]);
}
```

- The grid `grid` is a 2D vector of size 101, where each entry corresponds to a specific y-coordinate. We store the x-coordinate values of the rectangles in the grid, grouped by their y-coordinates.
- The loop iterates over each rectangle in `rec` and places its x1-coordinate into the grid at the index corresponding to the rectangle's y2-coordinate (`it[1]`).

#### Step 3: Process Each Point

```cpp
for(int j = 0; j < n; j++) {
    for(int i = pts[j][1]; i <= 100; i++) {
        res[j] += (grid[i].end() - lower_bound(grid[i].begin(), grid[i].end(), pts[j][0]));
    }
}
```

- We process each point in `pts`. For each point `pts[j]`, we check all rectangles that could cover it by iterating over the y-coordinates in the grid from `pts[j][1]` to 100.
- For each y-coordinate `i`, we count how many rectangles can cover the point `(pts[j][0], pts[j][1])` by looking for rectangles whose x1-coordinate is less than or equal to `pts[j][0]`. 
  - We do this using binary search with `lower_bound`. The `lower_bound` function finds the first position in the sorted list of x-coordinates where `pts[j][0]` could be inserted while maintaining the sorted order.
  - The difference between `grid[i].end()` and `lower_bound(grid[i].begin(), grid[i].end(), pts[j][0])` gives the number of rectangles that cover the point.
- We accumulate this count in `res[j]`.

#### Step 4: Return the Result

```cpp
return res;
```

- Once all points have been processed, the `res` vector contains the number of rectangles that can cover each point, which is returned as the final result.

### Complexity

#### Time Complexity

- **Sorting Rectangles**: Sorting the rectangles takes \( O(m \log m) \), where \( m \) is the number of rectangles.
- **Filling the Grid**: For each rectangle, inserting its x-coordinate into the grid is an \( O(1) \) operation, and since there are \( m \) rectangles, this step takes \( O(m) \).
- **Processing Points**: For each point, we check all the y-values from `pts[j][1]` to 100. In the worst case, this involves checking all y-values from 0 to 100. For each y-value, we perform a binary search on the sorted x-coordinates of the rectangles, which takes \( O(\log k) \), where \( k \) is the maximum number of rectangles for any given y-coordinate. 
  - Therefore, the total time complexity for processing all points is \( O(n \times 100 \times \log k) \), where \( n \) is the number of points and \( k \) is the average number of rectangles for each y-coordinate.

- **Overall Time Complexity**: The overall time complexity of the solution is \( O(m \log m + n \times 100 \times \log k) \), where:
  - \( m \) is the number of rectangles,
  - \( n \) is the number of points, and
  - \( k \) is the average number of rectangles for each y-coordinate.

#### Space Complexity

- **Grid Storage**: The grid stores the x-coordinates of rectangles for each y-coordinate, and the maximum number of y-coordinates is 101. In the worst case, each rectangle has a unique y-coordinate and stores its x-coordinate in the grid. Thus, the space complexity for the grid is \( O(m) \).
- **Result Vector**: The result vector `res` stores the answer for each point and has a size of \( n \), so its space complexity is \( O(n) \).

- **Overall Space Complexity**: The space complexity is \( O(m + n) \).

### Conclusion

The solution efficiently counts how many rectangles can cover each point by leveraging sorting, grid-based storage, and binary search. The sorting of rectangles ensures that we can quickly access relevant rectangles for each point, while the grid structure allows efficient access to x-coordinates for each y-coordinate. Binary search speeds up the process of counting valid rectangles for each point. The overall time complexity is manageable given the problem constraints, and the solution provides an optimal balance between time and space efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/)

---
{{< youtube uCTmN3j2hVU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
