
+++
authors = ["grid47"]
title = "Leetcode 1802: Maximum Value at a Given Index in a Bounded Array"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1802: Maximum Value at a Given Index in a Bounded Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o3H1ccp2ckc"
youtube_upload_date="2021-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/o3H1ccp2ckc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(long long pk, long long n, long long i, long long sum) {
        sum -= n;
        long j = n - i - 1;
        
    long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
        
        return sum - need >= 0;
    }
    
    int maxValue(int n, int index, int mx) {
        
        int ans = 0, l = 0, r = mx;
        
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
            // cout << mid << " ";
            if(can(mid, n, index, mx)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        
        return ans + 1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the maximum value that can be assigned to a specific index in an array while adhering to certain constraints. Given an array of length `n`, the value at a specified index `index` must not exceed `mx`, and the values in the array must be adjusted such that the total sum does not exceed the maximum permissible value. The goal is to maximize the value at the `index` position while ensuring that the total of the array meets the required conditions.

### Approach

To tackle this problem, we employ a binary search technique. The core idea is to find the maximum value that can be assigned to the `index` while checking if the conditions imposed by the problem are satisfied.

1. **Binary Search Initialization**: We set up a binary search between a lower bound (`l = 0`) and an upper bound (`r = mx`), where `mx` is the maximum value allowed at the specified index.

2. **Feasibility Check**: For each midpoint value in the binary search (`mid`), we check if assigning this value to the index is feasible without violating the constraints. This check is performed by a helper function named `can`.

3. **Helper Function - `can`**: The `can` function determines whether it is possible to assign the value `pk` (the candidate value for the index) to the specified `index` under the following conditions:
   - It calculates how much value is needed to fill the array while ensuring that the values on either side of the `index` do not exceed the constraints.
   - The function evaluates the total remaining sum and checks if the required value to maintain the constraints can be accommodated within that sum.

4. **Binary Search Execution**: If assigning the current `mid` value is feasible, it is recorded as a potential answer, and the search continues in the upper half of the range. If not, the search continues in the lower half.

5. **Final Result**: After the binary search completes, the maximum feasible value is returned, adjusted by adding 1 since we want to find the maximum possible value that can be set at the index.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    bool can(long long pk, long long n, long long i, long long sum) {
```
- The `can` function checks whether it is feasible to assign a value `pk` to the `index`. It takes four parameters:
  - `pk`: the proposed value for the index.
  - `n`: the size of the array.
  - `i`: the specific index in question.
  - `sum`: the total allowable sum for the array.

```cpp
        sum -= n;
        long j = n - i - 1;
```
- We adjust the `sum` by subtracting `n` since the proposed value will occupy the `index`. The variable `j` represents the number of elements to the right of the `index`.

```cpp
        long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
```
- This line computes the total value needed to satisfy the constraints imposed by the assignment of `pk` to the `index`. It considers how much value can be added to the left and right of the `index` while adhering to the maximum limit of values.
- The formula calculates the amount required for the left and right segments of the array, factoring in the diminishing returns as the distance from the index increases.

```cpp
        return sum - need >= 0;
    }
```
- The function checks if the remaining sum after assigning `pk` is non-negative after accounting for the `need`. If so, it returns `true`; otherwise, it returns `false`.

```cpp
    int maxValue(int n, int index, int mx) {
```
- The main function `maxValue` begins here, which sets up the binary search for the maximum value.

```cpp
        int ans = 0, l = 0, r = mx;
```
- Initialize `ans` to store the best answer found, and set `l` and `r` to the bounds for binary search.

```cpp
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
```
- The binary search loop continues while the left bound is less than or equal to the right bound.
- We calculate the midpoint `mid`.

```cpp
            if(can(mid, n, index, mx)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
```
- We use the `can` function to check if `mid` can be assigned to the index. If feasible, we update `ans` and adjust the left bound; otherwise, we adjust the right bound.

```cpp
        return ans + 1;
    }
};
```
- Finally, the function returns the maximum value found, incremented by 1 to reflect the maximum feasible assignment.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(\log(mx) \cdot k)\), where \(k\) is the complexity of the `can` function in terms of calculating the required values. Given the constraints and the logarithmic nature of the binary search, the overall complexity remains efficient.

- **Space Complexity**: The space complexity is \(O(1)\) since the algorithm uses a constant amount of space for variables, independent of the input size.

### Conclusion

The algorithm provides an efficient method for determining the maximum value that can be assigned to a specified index within an array while adhering to the problem's constraints. By leveraging binary search and a carefully designed feasibility check, the solution balances efficiency with clarity.

Understanding the interplay between binary search and condition checking is crucial for tackling similar problems in algorithm design. This approach not only optimizes the search for the maximum feasible value but also ensures that the constraints are respected throughout the process.

In summary, this solution exemplifies effective problem-solving in competitive programming contexts and highlights the importance of selecting appropriate data structures and algorithms for efficient computation. The use of binary search in conjunction with a helper function for feasibility checks serves as a robust technique for managing constraints in optimization problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/)

---
{{< youtube o3H1ccp2ckc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
