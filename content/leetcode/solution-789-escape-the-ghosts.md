
+++
authors = ["grid47"]
title = "Leetcode 789: Escape The Ghosts"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 789: Escape The Ghosts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp"
youtube = "fCx9Fb_ghaA"
youtube_upload_date="2019-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fCx9Fb_ghaA/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp" 
    alt="A set of ghosts where escape routes are traced, with each route softly glowing as it’s followed."
    caption="Solution to LeetCode 789: Escape The Ghosts Problem"
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
    bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        for(auto it: gs)
        if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
        return false;
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks if a person can escape from ghosts on a grid. The grid is represented by two-dimensional coordinates. The person starts at a position `(0, 0)`, and the ghosts start at various other positions, given by the list `gs`. The target position where the person wants to escape is given by the list `t`. The goal is to determine if the person can reach the target without any of the ghosts reaching it first. The movement is constrained by the grid, and the only allowed movements are along the grid axes (left, right, up, down).

We are tasked with finding out if the person can escape the ghosts, given the following conditions:
- The person can move any number of steps in any direction, but each step is taken one at a time.
- The ghosts can also move, but the same conditions apply to them.

The person starts at `(0, 0)`, and their escape point is given in `t`. Each ghost has a starting position provided in `gs`, and we need to check if any ghost can reach the target position faster than the person.

### Approach

The problem boils down to a **Manhattan distance** calculation on a grid. The Manhattan distance between two points `(x1, y1)` and `(x2, y2)` is simply the sum of the absolute differences of their respective coordinates, i.e.,

\[
\text{Manhattan Distance} = |x2 - x1| + |y2 - y1|
\]

For the person to escape successfully, they must reach the target point `(t[0], t[1])` before any ghost can reach it. The strategy is simple:
1. **Compute the Manhattan distance for the person** from the origin `(0, 0)` to the target `t`.
2. **Check the Manhattan distance for each ghost** from their starting point to the target `t`.
3. If any ghost has a distance to the target that is less than or equal to the distance the person must travel, then it is impossible for the person to escape.
4. If none of the ghosts can reach the target faster or simultaneously, the person can escape successfully.

The approach leverages the fact that ghosts and the person are moving in a grid, and their movements are entirely constrained to horizontal or vertical steps, which simplifies the computation to Manhattan distances.

### Code Breakdown (Step by Step)

Let’s break down the code and understand how it works:

1. **Calculate the Manhattan Distance for the Person**:
   The person starts at `(0, 0)`, so their Manhattan distance to the target `t` is calculated by the formula:
   ```cpp
   int d = abs(t[0]) + abs(t[1]);
   ```
   This gives the number of steps the person needs to take to reach the target, given that they can only move along the grid axes (horizontally or vertically).

2. **Iterate Over the Ghosts’ Positions**:
   Next, we iterate through each ghost’s starting position in the list `gs`. The ghosts are also restricted to move along the grid axes. For each ghost, we compute the Manhattan distance from their starting position to the target `t`. If any ghost’s Manhattan distance is less than or equal to the person’s distance to the target, the person cannot escape because the ghost will reach the target first.

   The following loop checks the distance for each ghost:
   ```cpp
   for(auto it: gs)
   if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
   return false;
   ```

   Here, `it` represents the ghost’s position. We check if the person’s distance `d` is greater than or equal to the ghost’s distance. If so, the function immediately returns `false`, indicating that the person cannot escape the ghosts. This breaks out of the loop early for efficiency.

3. **Return the Final Result**:
   If no ghost can reach the target faster than the person, we return `true`, indicating that the person can escape:
   ```cpp
   return true;
   ```

### Complexity Analysis

- **Time Complexity**:
  The time complexity of this solution is **O(g)**, where `g` is the number of ghosts in the list `gs`. For each ghost, we compute the Manhattan distance to the target, which takes constant time **O(1)**. Thus, the time complexity is linear in terms of the number of ghosts.
  
  In the worst case, if the list `gs` contains `n` ghosts, the overall time complexity will be **O(n)**.

- **Space Complexity**:
  The space complexity is **O(1)**, since we are only using a constant amount of extra space. We store a few integer variables (like `d`), but no extra space is required that grows with the input size.

### Conclusion

This solution provides a very efficient method for determining if the person can escape from the ghosts. The problem is reduced to simple Manhattan distance calculations, which are computationally inexpensive. By checking each ghost’s position and ensuring they cannot reach the target before the person, we can make a decision quickly.

- **Key Points**:
  - The algorithm uses **Manhattan distance** to calculate the distance between the person, ghosts, and the target.
  - If any ghost can reach the target faster than the person, the function returns `false`.
  - If none of the ghosts can reach the target before the person, the function returns `true`.
  
- **Efficiency**:
  - **Time Complexity**: O(g), where `g` is the number of ghosts.
  - **Space Complexity**: O(1), using a constant amount of space.
  
This solution is optimal for the problem and provides an elegant, easy-to-understand approach to solving it.

[`Link to LeetCode Lab`](https://leetcode.com/problems/escape-the-ghosts/description/)

---
{{< youtube fCx9Fb_ghaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
