
+++
authors = ["grid47"]
title = "Leetcode 836: Rectangle Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 836: Rectangle Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "o6hHUk4DOW0"
youtube_upload_date="2020-01-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o6hHUk4DOW0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int fx1=rect1[0];
        int fx2=rect1[2];
        int fy1=rect1[1];
        int fy2=rect1[3];

        int sx1=rect2[0];
        int sx2=rect2[2];
        int sy1=rect2[1];
        int sy2=rect2[3];

        return !((sy1>=fy2) ||
               (fy1>=sy2) ||
               (fx1>=sx2) ||
               (fx2<=sx1));
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given two rectangles defined by their corner coordinates in a 2D plane. The task is to determine whether the two rectangles overlap or not.

Each rectangle is represented by an array of four integers:
- `rect1 = [x1, y1, x2, y2]` and `rect2 = [x3, y3, x4, y4]`.
  - `(x1, y1)` and `(x2, y2)` are the coordinates of the bottom-left and top-right corners of the first rectangle.
  - Similarly, `(x3, y3)` and `(x4, y4)` represent the coordinates of the bottom-left and top-right corners of the second rectangle.

The problem asks to return a boolean value:
- `true` if the two rectangles overlap.
- `false` if they do not overlap.

### Approach

To solve this problem, the key observation is that two rectangles will **not overlap** if any of the following conditions are met:
1. One rectangle is completely to the left of the other (i.e., the right edge of one rectangle is to the left of the left edge of the other).
2. One rectangle is completely to the right of the other (i.e., the left edge of one rectangle is to the right of the right edge of the other).
3. One rectangle is completely above the other (i.e., the bottom edge of one rectangle is above the top edge of the other).
4. One rectangle is completely below the other (i.e., the top edge of one rectangle is below the bottom edge of the other).

If none of these conditions are true, then the rectangles overlap. The algorithm will check these conditions and return the appropriate result.

### Code Breakdown (Step by Step)

#### Step 1: Assign Variables for Rectangle Coordinates

```cpp
int fx1 = rect1[0];
int fx2 = rect1[2];
int fy1 = rect1[1];
int fy2 = rect1[3];

int sx1 = rect2[0];
int sx2 = rect2[2];
int sy1 = rect2[1];
int sy2 = rect2[3];
```
- Here, we extract the coordinates of both rectangles `rect1` and `rect2`:
  - For `rect1`, we extract the bottom-left corner `(fx1, fy1)` and the top-right corner `(fx2, fy2)`.
  - For `rect2`, we extract the bottom-left corner `(sx1, sy1)` and the top-right corner `(sx2, sy2)`.

#### Step 2: Check for Overlap Conditions

```cpp
return !((sy1 >= fy2) ||
         (fy1 >= sy2) ||
         (fx1 >= sx2) ||
         (fx2 <= sx1));
```

- The condition checks if **none** of the following overlap conditions are true:
  - **Condition 1**: `(sy1 >= fy2)` — This checks if `rect2` is completely above `rect1`. If the bottom of `rect2` (`sy1`) is greater than or equal to the top of `rect1` (`fy2`), then there is no overlap.
  - **Condition 2**: `(fy1 >= sy2)` — This checks if `rect2` is completely below `rect1`. If the top of `rect2` (`sy2`) is less than or equal to the bottom of `rect1` (`fy1`), then there is no overlap.
  - **Condition 3**: `(fx1 >= sx2)` — This checks if `rect2` is completely to the left of `rect1`. If the right of `rect2` (`sx2`) is to the left of the left of `rect1` (`fx1`), then there is no overlap.
  - **Condition 4**: `(fx2 <= sx1)` — This checks if `rect2` is completely to the right of `rect1`. If the left of `rect2` (`sx1`) is to the right of the right of `rect1` (`fx2`), then there is no overlap.

- If **any** of these conditions is `true`, then there is no overlap, and the function will return `false`. If **none** of these conditions is true, the rectangles overlap, and the function returns `true`.

- The `!` operator negates the condition. Therefore, if any of these four conditions are true (i.e., no overlap), we return `false`. Otherwise, we return `true`, indicating that the rectangles do overlap.

### Complexity

#### Time Complexity

The solution performs a constant number of comparisons (just four in total) between the coordinates of the two rectangles. Each comparison involves only basic arithmetic operations, which are constant time operations. Therefore, the time complexity is:

- **O(1)** — constant time.

#### Space Complexity

The algorithm uses a fixed amount of extra space to store the coordinates of the two rectangles (`fx1, fx2, fy1, fy2, sx1, sx2, sy1, sy2`). No additional space is needed that depends on the size of the input. Therefore, the space complexity is:

- **O(1)** — constant space.

### Conclusion

The solution efficiently determines whether two rectangles overlap by checking the basic geometric properties of their positions. By breaking down the problem into simple conditions that test for non-overlapping cases, we can determine the result in constant time. This approach is optimal and works well even for large inputs since the time and space complexities are both constant. 

This solution provides a clear and intuitive method to solve the problem of determining whether two rectangles overlap, and it is computationally efficient with constant time and space complexities.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rectangle-overlap/description/)

---
{{< youtube o6hHUk4DOW0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
