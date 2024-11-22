
+++
authors = ["grid47"]
title = "Leetcode 896: Monotonic Array"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 896: Monotonic Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "stkYclqstaA"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/stkYclqstaA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine if an array is **monotonic**. An array is considered **monotonic** if it is either:
- **Non-increasing**: each element is greater than or equal to the next.
- **Non-decreasing**: each element is less than or equal to the next.

Given an array `A`, the task is to return `true` if the array is monotonic, and `false` otherwise.

### Approach

To solve the problem, we need to verify whether the array satisfies either a **non-decreasing** or **non-increasing** condition. This can be done by iterating through the array and comparing adjacent elements. If the array satisfies one of these conditions throughout the entire iteration, we can confidently declare it as monotonic.

We use two flags to track whether the array is non-decreasing and non-increasing:
1. **`inc`**: This flag will be `true` if the array is non-decreasing.
2. **`dec`**: This flag will be `true` if the array is non-increasing.

If, at the end of the iteration, either the `inc` or `dec` flag remains `true`, it means the array satisfies at least one of the conditions and thus is monotonic.

### Code Breakdown (Step by Step)

Let's break down the code and explain each part in detail:

```cpp
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
```

- The class `Solution` contains the method `isMonotonic`, which takes a vector `A` as input.
- We initialize two boolean variables, `inc` and `dec`, both set to `true` initially. These variables track whether the array is non-decreasing (`inc`) or non-increasing (`dec`).

```cpp
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
```

- The `for` loop iterates over the elements of the array starting from the second element (index `1`).
  - For each pair of adjacent elements, we perform two checks:
    - `inc &= A[i - 1] <= A[i]`: This checks if the current element is greater than or equal to the previous element, which ensures the array is non-decreasing. If any element violates this condition, `inc` will be set to `false`.
    - `dec &= A[i - 1] >= A[i]`: This checks if the current element is less than or equal to the previous element, which ensures the array is non-increasing. If any element violates this condition, `dec` will be set to `false`.
  
- The logical AND (`&=`) operator is used in both checks, which means both conditions must hold for `inc` and `dec` to remain `true`. If either of the conditions is violated, the respective flag is set to `false` for the rest of the iteration.

```cpp
        return inc || dec;
    }
};
```

- After the loop completes, we return the result of `inc || dec`. If either `inc` or `dec` is `true`, the array is monotonic, and we return `true`. Otherwise, the array is neither non-decreasing nor non-increasing, so we return `false`.

### Example Walkthrough

Let's walk through an example to understand how the algorithm works:

#### Example 1:
Input: `A = [1, 2, 2, 3]`

- `inc = true`, `dec = true` (initial state)
- Iteration through the array:
  - `i = 1`: Compare `A[0]` (1) and `A[1]` (2). Since 1 <= 2, `inc` remains `true`. Since 1 >= 2 is false, `dec` becomes `false`.
  - `i = 2`: Compare `A[1]` (2) and `A[2]` (2). Since 2 <= 2, `inc` remains `true`. Since 2 >= 2, `dec` remains `false`.
  - `i = 3`: Compare `A[2]` (2) and `A[3]` (3). Since 2 <= 3, `inc` remains `true`. Since 2 >= 3 is false, `dec` remains `false`.
  
- After the iteration, `inc = true` and `dec = false`, so the array is monotonic. The result is `true`.

#### Example 2:
Input: `A = [6, 5, 4, 4]`

- `inc = true`, `dec = true` (initial state)
- Iteration through the array:
  - `i = 1`: Compare `A[0]` (6) and `A[1]` (5). Since 6 >= 5, `dec` remains `true`. Since 6 <= 5 is false, `inc` becomes `false`.
  - `i = 2`: Compare `A[1]` (5) and `A[2]` (4). Since 5 >= 4, `dec` remains `true`. Since 5 <= 4 is false, `inc` remains `false`.
  - `i = 3`: Compare `A[2]` (4) and `A[3]` (4). Since 4 <= 4, `inc` remains `false`. Since 4 >= 4, `dec` remains `true`.
  
- After the iteration, `inc = false` and `dec = true`, so the array is monotonic. The result is `true`.

#### Example 3:
Input: `A = [1, 3, 2]`

- `inc = true`, `dec = true` (initial state)
- Iteration through the array:
  - `i = 1`: Compare `A[0]` (1) and `A[1]` (3). Since 1 <= 3, `inc` remains `true`. Since 1 >= 3 is false, `dec` becomes `false`.
  - `i = 2`: Compare `A[1]` (3) and `A[2]` (2). Since 3 <= 2 is false, `inc` becomes `false`. Since 3 >= 2, `dec` remains `false`.
  
- After the iteration, both `inc = false` and `dec = false`. The array is neither non-decreasing nor non-increasing, so the result is `false`.

### Complexity

#### Time Complexity:
- The algorithm iterates through the array once, making the time complexity **O(n)**, where `n` is the size of the array `A`. Each comparison and logical operation inside the loop takes constant time, so the overall complexity is linear with respect to the array length.

#### Space Complexity:
- The algorithm uses only a constant amount of extra space, as we only store a few boolean flags and an index variable. Therefore, the space complexity is **O(1)**, constant space.

### Conclusion

The `isMonotonic` function efficiently determines whether an array is monotonic by checking if it is either non-decreasing or non-increasing. It uses two boolean flags to track whether the array satisfies either condition and iterates through the array once to make these checks. With a time complexity of **O(n)** and a space complexity of **O(1)**, this solution is optimal for solving the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/monotonic-array/description/)

---
{{< youtube stkYclqstaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
