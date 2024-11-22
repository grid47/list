
+++
authors = ["grid47"]
title = "Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid"
date = "2024-04-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xf_naKzI_ZI"
youtube_upload_date="2021-12-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xf_naKzI_ZI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int m = s.size(), h = m + n, v = m + n;
        vector<int> hor((h + m) * 2, m), ver((h +m) * 2, m), res(m);
        for(int i = m - 1; i >= 0; i--) {
            hor[h] = ver[v] = i;
            h += s[i] == 'L' ? 1 : s[i] == 'R'? -1 : 0;
            v += s[i] == 'U' ? 1 : s[i] == 'D'? -1 : 0;
            res[i] = min({  m, hor[h - st[1] - 1], hor[h - st[1] + n],
                               ver[v - st[0] - 1], ver[v - st[0] + n]  }) - i;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves simulating the movements of a robot on an \( n \times n \) grid based on a sequence of commands given in the string `s`. The robot starts at a specific position defined by the vector `st`, and the task is to determine how many valid instructions can be executed starting from that position for each command in `s`. The commands can instruct the robot to move left ('L'), right ('R'), up ('U'), or down ('D'). The robot must remain within the bounds of the grid throughout its movements.

### Approach

To solve this problem, we employ a method that utilizes two arrays to track the horizontal and vertical bounds for each command in `s`. The approach can be broken down into the following key steps:

1. **Initialization**:
   - We define the size of the grid \( n \) and the length of the commands \( m \).
   - We initialize two vectors, `hor` and `ver`, to keep track of the last valid positions on the horizontal and vertical axes, respectively. The size of these vectors is determined based on the maximum potential movements in both directions.
   - We also create a result vector `res` to store the count of valid instructions for each command.

2. **Simulating Movements**:
   - We iterate through the commands in reverse order. For each command:
     - We update the current horizontal (`h`) and vertical (`v`) positions based on the command.
     - We update the `hor` and `ver` arrays to reflect the latest valid positions for the current command.
     - We calculate the number of valid movements that can still be made without going out of bounds, considering the current position and the initial starting position.

3. **Boundary Checking**:
   - The calculation for valid moves takes into account the movements in both the positive and negative directions for both axes to ensure the robot remains within the grid boundaries.

### Code Breakdown (Step by Step)

Here’s a step-by-step explanation of the code:

1. **Function Declaration**:
   ```cpp
   vector<int> executeInstructions(int n, vector<int>& st, string s) {
   ```
   - The function `executeInstructions` takes the grid size \( n \), the starting position `st`, and the command string `s` as inputs.

2. **Variable Initialization**:
   ```cpp
   int m = s.size(), h = m + n, v = m + n;
   vector<int> hor((h + m) * 2, m), ver((h + m) * 2, m), res(m);
   ```
   - We initialize `m` to the size of the command string `s`.
   - The variables `h` and `v` are set to an offset to allow easy indexing while considering movements.
   - `hor` and `ver` vectors are initialized to keep track of valid horizontal and vertical positions, respectively, initialized with a default value of \( m \).
   - The `res` vector is created to store the results for each command.

3. **Reverse Iteration Over Commands**:
   ```cpp
   for(int i = m - 1; i >= 0; i--) {
       hor[h] = ver[v] = i;
   ```
   - We iterate over the command string `s` from the last command to the first.
   - For each command, we record the last valid position in `hor` and `ver`.

4. **Updating Positions**:
   ```cpp
   h += s[i] == 'L' ? 1 : s[i] == 'R' ? -1 : 0;
   v += s[i] == 'U' ? 1 : s[i] == 'D' ? -1 : 0;
   ```
   - We update the horizontal and vertical positions based on the command. Depending on whether the command is 'L', 'R', 'U', or 'D', we adjust `h` and `v` accordingly.

5. **Calculating Valid Moves**:
   ```cpp
   res[i] = min({
       m, hor[h - st[1] - 1], hor[h - st[1] + n],
       ver[v - st[0] - 1], ver[v - st[0] + n]
   }) - i;
   ```
   - For each command, we calculate the minimum of:
     - The total number of commands \( m \).
     - The last valid horizontal positions adjusted for the starting column `st[1]`.
     - The last valid vertical positions adjusted for the starting row `st[0]`.
   - The result is the count of valid instructions for the command.

6. **Return Result**:
   ```cpp
   return res;
   ```
   - Finally, the function returns the `res` vector containing the number of valid instructions for each command in `s`.

### Complexity Analysis

- **Time Complexity**: \(O(m)\)
  - The algorithm iterates through the command string once, leading to a linear time complexity relative to the length of `s`.

- **Space Complexity**: \(O(n)\)
  - The space used for the `hor` and `ver` vectors scales with the grid size, resulting in a linear space complexity.

### Conclusion

This solution effectively simulates the robot's movements on a grid based on a sequence of commands while keeping track of valid positions. The use of two arrays to maintain horizontal and vertical boundaries allows for efficient calculation of valid movements for each command. With a time complexity of \(O(m)\) and space complexity of \(O(n)\), the solution is optimal for the given problem constraints, making it suitable for larger inputs while maintaining clarity and readability. The design demonstrates a thoughtful balance between performance and simplicity, ensuring that the logic can be easily understood and maintained.

[`Link to LeetCode Lab`](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/)

---
{{< youtube Xf_naKzI_ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
