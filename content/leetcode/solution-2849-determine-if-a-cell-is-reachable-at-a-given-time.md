
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
comments = true
+++



---
You are given a starting position (sx, sy) and a target position (fx, fy) on an infinite 2D grid. You need to determine if it's possible to reach the target in exactly t seconds, moving to any adjacent cell each second.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two pairs of integers representing the starting and target positions on the 2D grid, along with an integer t indicating the number of seconds.
- **Example:** `sx = 2, sy = 4, fx = 7, fy = 7, t = 6`
- **Constraints:**
	- 1 <= sx, sy, fx, fy <= 10^9
	- 0 <= t <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to reach the target cell exactly in t seconds, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output is a boolean indicating whether the target can be reached in exactly t seconds.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if the target position can be reached in exactly t seconds by moving to adjacent cells.

- Calculate the minimum time needed to reach the target using the Manhattan distance formula, considering diagonal moves.
- Check if the remaining time after reaching the target can be matched by the time left after taking the shortest path.
{{< dots >}}
### Problem Assumptions ✅
- The coordinates (sx, sy) and (fx, fy) are within the valid range.
- Movement is allowed to any adjacent cell, including diagonals.
{{< dots >}}
## Examples 🧩
- **Input:** `sx = 2, sy = 4, fx = 7, fy = 7, t = 6`  \
  **Explanation:** Starting at (2, 4), you can reach (7, 7) in exactly 6 seconds by following a diagonal path. Hence, the output is true.

- **Input:** `sx = 3, sy = 1, fx = 7, fy = 3, t = 3`  \
  **Explanation:** Starting at (3, 1), the minimum time to reach (7, 3) is 4 seconds. Since t = 3, it's impossible to reach the target in exactly 3 seconds.

{{< dots >}}
## Approach 🚀
The approach involves calculating the minimum number of seconds required to reach the target, considering both horizontal and diagonal moves, and checking if we can use the remaining seconds to reach the target exactly.

### Initial Thoughts 💭
- The Manhattan distance gives the minimum number of moves required if only horizontal and vertical moves are allowed.
- Diagonal moves reduce the required time.
- We need to check if the time remaining after reaching the target is non-negative and even, since extra time can only be used in pairs of moves.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are expected as per the problem statement.
- The solution should handle large values of coordinates and time efficiently.
- When sx == fx and sy == fy, the only way to reach the target in exactly t seconds is if t is even.
- The approach should work for large values up to 10^9.
{{< dots >}}
## Code 💻
```cpp
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

    int mn = min(abs(fy - sy), abs(fx - sx));
    int asdf = (abs(fy - sy) - mn)+ (abs(fx - sx) - mn) + mn;
    if(abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
    return asdf <= t;

}
```

This function checks if a point (fx, fy) is reachable from (sx, sy) within 't' time, using a specific movement rule.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
	```
	Defines the function 'isReachableAtTime' that checks if the destination (fx, fy) is reachable from the source (sx, sy) in the given time 't'.

2. **Minimum Calculation**
	```cpp
	    int mn = min(abs(fy - sy), abs(fx - sx));
	```
	Calculates the minimum of the absolute differences between the y-coordinates and x-coordinates of the source and destination.

3. **Adjusted Distance Calculation**
	```cpp
	    int asdf = (abs(fy - sy) - mn)+ (abs(fx - sx) - mn) + mn;
	```
	Computes the total distance adjusted by the previously calculated minimum value, summing the remaining x and y distances after subtracting 'mn'.

4. **Edge Case Check**
	```cpp
	    if(abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
	```
	Checks if the source and destination are the same and if the time 't' is exactly 1, in which case the point is unreachable, returning false.

5. **Final Check**
	```cpp
	    return asdf <= t;
	```
	Compares the adjusted distance 'asdf' with the time 't' and returns true if the destination is reachable within the given time, otherwise false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1) because we only perform a few arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/)

---
{{< youtube r4MaK8AhoLI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
