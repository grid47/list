
+++
authors = ["grid47"]
title = "Leetcode 2033: Minimum Operations to Make a Uni-Value Grid"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2033: Minimum Operations to Make a Uni-Value Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "c90k-5HigWs"
youtube_upload_date="2021-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/c90k-5HigWs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size(), n = grid[0].size();
        
        int num = grid[0][0];
        
        vector<int> arr;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            arr.push_back(grid[i][j]);
            if(abs(num - grid[i][j]) % x != 0) return -1;
        }
        
        sort(arr.begin(), arr.end());
        
        int pos = arr.size() / 2;

        int res = 0;
        for(int i = 0; i < arr.size(); i++)        
            res += (abs(arr[pos] - arr[i]) / x);
        
        return res;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

We are given a 2D grid of integers and an integer `x`. Our goal is to transform every element in the grid so they all match a single target value, but each change must be made by either adding or subtracting `x` from the value of a grid cell. The objective is to determine the minimum number of operations needed to make all elements equal. If it’s impossible to achieve this, the function should return -1.

### Approach

To solve this problem, we need to make every number in the grid the same by applying an operation that either adds or subtracts `x` from a grid cell value. To achieve this:

1. **Initial Feasibility Check**:
   - To ensure all elements can reach the same target, each element in the grid must have the same remainder when divided by `x`. This condition ensures that each number can be reached from any other number in the grid using a multiple of `x`.

2. **Median Strategy for Minimum Operations**:
   - If all elements in the grid pass the feasibility check, we then need to determine a target number that will minimize the total number of operations. The median value of the elements is the optimal target, as it minimizes the sum of absolute deviations from all points to the target.
   - By sorting all the grid elements, we can easily find this median value.

3. **Calculate the Minimum Operations**:
   - Once we have the median, we calculate the total number of operations required to make each element in the grid equal to this median by determining the number of `x`-sized steps needed for each element.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
```
- Here, we define the `Solution` class and the function `minOperations`, which takes a grid of integers and an integer `x`.

```cpp
        int m = grid.size(), n = grid[0].size();
```
- We get the dimensions of the grid, `m` and `n`.

```cpp
        int num = grid[0][0];
        
        vector<int> arr;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            arr.push_back(grid[i][j]);
            if(abs(num - grid[i][j]) % x != 0) return -1;
        }
```
- `num` is initialized to the first element in the grid. As we iterate through the grid, each element is added to a 1D vector, `arr`. During this iteration, we also check if each element is "reachable" by ensuring the difference between `num` and the current element is divisible by `x`. If it isn’t, we return -1, meaning it’s impossible to make all elements equal.

```cpp
        sort(arr.begin(), arr.end());
        
        int pos = arr.size() / 2;
```
- The vector `arr` is sorted to allow easy access to the median element. We then set `pos` to be the middle index of `arr`, which corresponds to the median.

```cpp
        int res = 0;
        for(int i = 0; i < arr.size(); i++)        
            res += (abs(arr[pos] - arr[i]) / x);
        
        return res;
    }
```
- We initialize `res` to zero, which will store our total number of operations. We then iterate through `arr` and calculate the number of operations needed to make each element equal to the median. For each element, the difference to the median is divided by `x` to determine how many steps are needed. This total is stored in `res` and returned as the final answer.

### Complexity

- **Time Complexity**: Sorting the 1D array `arr` takes O(m * n * log(m * n)), where `m` and `n` are the grid dimensions. The subsequent traversal of `arr` to compute the operations takes O(m * n). Thus, the overall time complexity is O(m * n * log(m * n)).

- **Space Complexity**: O(m * n), as we create an auxiliary array `arr` to store grid elements in a 1D format.

### Conclusion

This solution effectively checks the feasibility of making all grid elements equal by adding or subtracting multiples of `x`. By leveraging the median, we achieve the minimum total operations required. The solution is efficient and applies mathematical reasoning to simplify the operations, ultimately providing a clear and optimized answer.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

---
{{< youtube c90k-5HigWs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
