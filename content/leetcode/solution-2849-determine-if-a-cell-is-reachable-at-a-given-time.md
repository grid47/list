
+++
authors = ["grid47"]
title = "Leetcode 2849: Determine if a Cell Is Reachable at a Given Time"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2849: Determine if a Cell Is Reachable at a Given Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r4MaK8AhoLI"
youtube_upload_date="2023-09-10"
youtube_thumbnail="https://i.ytimg.com/vi/r4MaK8AhoLI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int mn = min(abs(fy - sy), abs(fx - sx));
        int asdf = (abs(fy - sy) - mn)+ (abs(fx - sx) - mn) + mn;
        if(abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
        return asdf <= t;

    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks whether it is possible to reach a target point `(fx, fy)` from a starting point `(sx, sy)` in exactly `t` units of time. Movement is allowed along both the x-axis and y-axis simultaneously, meaning you can move diagonally as well as in straight lines. The task is to determine if you can reach the destination in the given time `t`.

### Approach

To solve this problem, we need to calculate the number of steps required to reach the destination from the starting point. The key idea is to use the concept of Manhattan distance for this problem. 

Manhattan distance between two points `(sx, sy)` and `(fx, fy)` is the sum of the absolute differences of their x and y coordinates:
\[
\text{distance} = |fx - sx| + |fy - sy|
\]

Since we are allowed to move diagonally, we can reduce this distance by moving in both the x and y directions at the same time. However, after moving diagonally for as long as possible, we will need to cover any remaining horizontal or vertical distance.

We need to ensure that the time `t` is sufficient to cover the entire distance but also not too large such that the exact time `t` is exhausted but we cannot reach the destination in exactly `t` time.

### Code Breakdown (Step by Step)

#### Step 1: Calculate the Minimum Moves Required
```cpp
int mn = min(abs(fy - sy), abs(fx - sx));
```
- The variable `mn` calculates the minimum of the horizontal distance (`abs(fx - sx)`) and the vertical distance (`abs(fy - sy)`). This represents the maximum number of diagonal steps we can take, as we can reduce both the x and y distances simultaneously by 1 unit with each diagonal move. We move diagonally until one of the coordinates (either x or y) is exhausted.

#### Step 2: Calculate the Remaining Distance
```cpp
int asdf = (abs(fy - sy) - mn) + (abs(fx - sx) - mn) + mn;
```
- After moving diagonally, we calculate how much distance remains for both the x and y directions. The expression `(abs(fy - sy) - mn)` computes the remaining vertical distance, and `(abs(fx - sx) - mn)` computes the remaining horizontal distance. The total distance `asdf` is the sum of these remaining distances along with the diagonal distance (`mn`).

#### Step 3: Special Case When Already at Destination
```cpp
if (abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
```
- This line checks if the starting point is the same as the destination, meaning `(sx, sy)` equals `(fx, fy)`. If we are already at the destination and the time `t` is exactly 1, it would be impossible to stay at the destination for 1 unit of time (since the problem specifies reaching the destination, not staying there), so it returns `false`.

#### Step 4: Check if Reaching the Target is Possible in Time `t`
```cpp
return asdf <= t;
```
- Finally, the code checks if the total calculated distance `asdf` is less than or equal to the given time `t`. If it is, it means we can reach the destination in the given time. If `asdf` is greater than `t`, it would be impossible to reach the target in exactly `t` units of time, and the function returns `false`.

### Complexity

#### Time Complexity:
- **O(1)**: The algorithm involves only a few constant-time operations, such as calculating absolute differences, the minimum of two values, and a few condition checks. Hence, the time complexity is constant, O(1), regardless of the size of the input.

#### Space Complexity:
- **O(1)**: The space complexity is constant because the algorithm uses a fixed amount of space for storing variables such as `mn` and `asdf`. No additional data structures or dynamic memory allocation are used.

### Conclusion

This solution is both time and space efficient, achieving constant time complexity (O(1)) and constant space complexity (O(1)). The approach leverages simple geometry (Manhattan distance and diagonal movement) to determine whether it's possible to reach the target in the given time. By calculating the minimal number of diagonal moves and considering the remaining horizontal and vertical movements, the code ensures that the result is computed efficiently.

The special case when the starting point and the destination are the same is also correctly handled. This solution avoids unnecessary calculations and provides an accurate answer with minimal computational effort.

The simplicity and efficiency of the approach make it a solid solution for solving this problem in a wide range of scenarios where a time-efficient algorithm is necessary.

[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/)

---
{{< youtube r4MaK8AhoLI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
