
+++
authors = ["grid47"]
title = "Leetcode 3178: Find the Child Who Has the Ball After K Seconds"
date = "2023-12-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3178: Find the Child Who Has the Ball After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JX-J9LZxqvk"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/JX-J9LZxqvk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfChild(int n, int k) {
        int up = false, idx = 0;
        for(int i = 0; i < k; i++) {

            if (idx == n - 1 || idx == 0) up = !up;

            if (up) idx++;
            else    idx--;

        }
        return idx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine the position of a child after `k` steps in a line of `n` children arranged from left to right. The child begins at position `0` (the first child) and moves according to a pattern. If the child is at either end of the line, the movement direction is reversed. The problem requires us to compute the final position of the child after `k` steps.

### Approach

We can solve this problem by simulating the movement of the child based on the given rules. Here's a breakdown of the approach:

1. **Direction Control**: We keep track of the direction the child is moving. Initially, the child moves forward (right). If the child is at either end of the line (i.e., position `0` or `n-1`), the direction is reversed. This is handled by the `up` variable, which toggles between `true` and `false`.

2. **Tracking the Child's Position**: The child starts at position `0` (the first child). As we simulate the steps, we adjust the child's position either by incrementing or decrementing the index (`idx`) based on the current direction.

3. **Simulating the Steps**: We iterate `k` times, each time adjusting the child's position based on the current direction. If the child reaches either end of the line, the direction is reversed.

4. **Final Result**: After simulating `k` steps, the variable `idx` holds the final position of the child.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
    int numberOfChild(int n, int k) {
        int up = false, idx = 0;  // Initial direction (false for left, true for right), start at position 0.
        
        // Iterate through the k steps.
        for(int i = 0; i < k; i++) {
            
            // If the child is at the edge, reverse direction.
            if (idx == n - 1 || idx == 0) up = !up;
            
            // Move the child based on the current direction.
            if (up) idx++;  // Move right if direction is true.
            else    idx--;  // Move left if direction is false.
        }
        
        // Return the final position of the child.
        return idx;
    }
};
```

Let’s break down each part of the code:

1. **Initial Setup**:
   ```cpp
   int up = false, idx = 0;
   ```
   - `up`: This boolean variable controls the direction of movement. Initially, it is set to `false`, which means the child will start moving left (decreasing the index).
   - `idx`: This variable tracks the child's current position. Initially, the child starts at position `0`.

2. **Iterating Through `k` Steps**:
   ```cpp
   for(int i = 0; i < k; i++) {
   ```
   - This loop runs `k` times, simulating each step the child takes.

3. **Direction Reversal Check**:
   ```cpp
   if (idx == n - 1 || idx == 0) up = !up;
   ```
   - If the child is at the leftmost position (`idx == 0`) or the rightmost position (`idx == n - 1`), the direction is reversed. The `up` variable is toggled to change the direction of movement. If it was `true` (moving right), it becomes `false` (moving left), and vice versa.

4. **Moving the Child**:
   ```cpp
   if (up) idx++;  // Move right if direction is true.
   else    idx--;  // Move left if direction is false.
   ```
   - If the direction is `true` (moving right), we increment `idx` to move the child to the right.
   - If the direction is `false` (moving left), we decrement `idx` to move the child to the left.

5. **Returning the Final Position**:
   ```cpp
   return idx;
   ```
   - After all `k` steps, the final position of the child is returned, which is stored in the `idx` variable.

### Example Walkthrough

Let’s go through an example to see how this code works.

#### Input 1:
```cpp
n = 5, k = 7
```
- The child starts at position `0` and moves as follows:
  1. Move right (position 1).
  2. Move right (position 2).
  3. Move right (position 3).
  4. Move right (position 4).
  5. Move left (position 3).
  6. Move left (position 2).
  7. Move left (position 1).
- The final position after `7` steps is `1`.

#### Input 2:
```cpp
n = 5, k = 10
```
- The child starts at position `0` and moves as follows:
  1. Move right (position 1).
  2. Move right (position 2).
  3. Move right (position 3).
  4. Move right (position 4).
  5. Move left (position 3).
  6. Move left (position 2).
  7. Move left (position 1).
  8. Move left (position 0).
  9. Move right (position 1).
  10. Move right (position 2).
- The final position after `10` steps is `2`.

#### Input 3:
```cpp
n = 6, k = 12
```
- The child starts at position `0` and moves as follows:
  1. Move right (position 1).
  2. Move right (position 2).
  3. Move right (position 3).
  4. Move right (position 4).
  5. Move right (position 5).
  6. Move left (position 4).
  7. Move left (position 3).
  8. Move left (position 2).
  9. Move left (position 1).
  10. Move left (position 0).
  11. Move right (position 1).
  12. Move right (position 2).
- The final position after `12` steps is `2`.

### Complexity

#### Time Complexity:
- **O(k)**: The loop runs `k` times, and in each iteration, the child either moves left or right and checks the boundary conditions (which are constant time operations). Therefore, the time complexity is **O(k)**.

#### Space Complexity:
- **O(1)**: We are only using a constant amount of extra space (`up`, `idx`), so the space complexity is **O(1)**.

### Conclusion

This solution efficiently computes the final position of the child after `k` steps. By keeping track of the direction of movement and handling boundary conditions (when the child reaches the edges), we can simulate the movement in linear time. The time complexity of **O(k)** ensures that this approach will perform well even for large inputs. The constant space complexity makes the solution efficient in terms of memory usage as well.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

---
{{< youtube JX-J9LZxqvk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
