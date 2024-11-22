
+++
authors = ["grid47"]
title = "Leetcode 1033: Moving Stones Until Consecutive"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1033: Moving Stones Until Consecutive in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Brainteaser"]
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
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s {a, b, c};
        sort(s.begin(), s.end());
        
        if(s[2]-s[0] == 2) return {0, 0};
        
        
        
        return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
    }
};
{{< /highlight >}}
---



### Problem Statement
In this problem, we are given three distinct integers representing the positions of three stones placed on a number line. The task is to determine how many moves are needed to position these stones such that they are aligned with each other. A "move" is defined as moving a stone from its current position to an adjacent empty position (i.e., moving it to either the left or the right).

The output should consist of two numbers:
1. The minimum number of moves required to align the stones.
2. The maximum number of moves required to align the stones.

For example, if the positions of the stones are \(a = 1\), \(b = 2\), and \(c = 5\), the output should indicate how to achieve alignment in the minimum and maximum moves possible.

### Approach
To solve this problem, the approach involves the following steps:
1. **Sorting the Positions**: Since the stones can be in any order, sorting their positions helps in easily determining the gaps between them.
2. **Analyzing Gaps**: After sorting, we can check the distances (or gaps) between the stones:
   - If the distance between the stones is exactly 2, they are already aligned and no moves are required.
   - Otherwise, we calculate the minimum and maximum number of moves based on the gaps between the stones.
3. **Return the Result**: Based on the analysis of the gaps, we return the required moves.

### Code Breakdown (Step by Step)
1. **Class Declaration**: The solution is encapsulated within a class named `Solution`.

2. **Function Definition**: The function `numMovesStones` takes three integer parameters representing the positions of the stones.
   ```cpp
   vector<int> numMovesStones(int a, int b, int c) {
   ```

3. **Sorting the Positions**:
   - A vector `s` is created and initialized with the positions of the stones. 
   - The `sort` function is then used to arrange the positions in ascending order.
   ```cpp
   vector<int> s {a, b, c};
   sort(s.begin(), s.end());
   ```

4. **Check for Immediate Alignment**:
   - The first check is to see if the distance between the first and the last stone is exactly 2, which means they are adjacent.
   - If true, return `{0, 0}` as no moves are needed.
   ```cpp
   if(s[2]-s[0] == 2) return {0, 0};
   ```

5. **Calculate Minimum Moves**:
   - The minimum moves required to align the stones is determined by checking the smallest gap between adjacent stones.
   - If the gap between the first and second stone or the second and third stone is less than or equal to 2, it means only one move is needed to bring the stones together.
   - Otherwise, it takes two moves to align them.
   ```cpp
   return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
   ```

6. **Return Statement**:
   - The function returns a vector containing two values:
     - The minimum number of moves (calculated as explained above).
     - The maximum number of moves, which is simply the total distance between the first and last stone minus 2 (to account for the stones themselves).

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(1)\) because we are performing a constant amount of work regardless of the input size. The only significant operation is sorting three numbers, which can be considered constant time.
- **Space Complexity**: The space complexity is also \(O(1)\) since we are only using a fixed amount of additional space for the vector `s`.

### Conclusion
The provided code efficiently computes the minimum and maximum moves required to align three stones on a number line. By utilizing sorting and straightforward calculations of gaps between the stones, the solution elegantly determines the required values in constant time and space. 

This approach is optimal for this problem due to the limited number of stones (three), which allows for rapid calculations and a clean implementation. Such a solution is particularly useful in scenarios where positional alignment or optimization of resources is required, making it relevant in various practical applications such as robotics, game development, and scheduling tasks.

In summary, the `numMovesStones` function provides a robust and efficient means of solving the problem of aligning stones with minimal moves while ensuring clarity and maintainability in the code structure.


[`Link to LeetCode Lab`](https://leetcode.com/problems/moving-stones-until-consecutive/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
