
+++
authors = ["grid47"]
title = "Leetcode 2894: Divisible and Non-divisible Sums Difference"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2894: Divisible and Non-divisible Sums Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CXjNaWOdJ34"
youtube_upload_date="2023-10-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CXjNaWOdJ34/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                res -= i;
            } else {
                res += i;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to compute the difference of sums for two categories of integers. Specifically, for a given integer `n` and `m`, we need to:

1. Add all numbers from `1` to `n` that are **not divisible by `m`**.
2. Subtract all numbers from `1` to `n` that **are divisible by `m`**.

The final result will be the difference between the sum of numbers that are **not divisible by `m`** and the sum of numbers that **are divisible by `m`**.

### Approach

We can solve this problem by iterating through all integers from `1` to `n` and for each number `i`, we check if it is divisible by `m`. If it is divisible, we subtract it from the result; otherwise, we add it to the result. Here's a step-by-step breakdown of how we approach the solution:

1. **Iterate through the numbers**: We will iterate from `1` to `n` (both inclusive) and check whether each number is divisible by `m`.

2. **Conditionally add or subtract**: For each number `i`:
   - If `i % m == 0` (i.e., `i` is divisible by `m`), we subtract `i` from the result.
   - If `i % m != 0` (i.e., `i` is **not** divisible by `m`), we add `i` to the result.

3. **Return the final result**: After completing the iteration, we return the accumulated result.

The key operation is checking the remainder of `i` when divided by `m`, which determines if the number should be added or subtracted.

### Code Breakdown (Step by Step)

Let's break the code into smaller parts to understand how the solution works:

#### 1. Initialize the result variable

```cpp
int res = 0;
```

- **`res`**: This variable will store the cumulative result of the operation. It is initialized to 0 because we need to accumulate values from the iteration.

#### 2. Loop through numbers from 1 to n

```cpp
for (int i = 1; i <= n; ++i) {
```

- This `for` loop iterates through each number `i` from `1` to `n`. For every number `i`, we perform a check to decide whether to add or subtract it from `res`.

#### 3. Check divisibility and update result

```cpp
if (i % m == 0) {
    res -= i;
} else {
    res += i;
}
```

- **Divisibility check**: Inside the loop, we check whether `i` is divisible by `m` by using the modulus operation (`i % m == 0`). 
  - If the condition is true, it means `i` is divisible by `m`, and we **subtract** `i` from the result (`res -= i`).
  - Otherwise, we **add** `i` to the result (`res += i`).

This conditional operation ensures that the numbers divisible by `m` are subtracted, while all others are added.

#### 4. Return the final result

```cpp
return res;
```

- After completing the iteration over all numbers from `1` to `n`, the final accumulated value of `res` is returned as the result.

### Example Walkthrough

Let's walk through an example to clarify how the code works:

#### Example 1: `n = 5`, `m = 2`

The numbers from `1` to `5` are `[1, 2, 3, 4, 5]`. Let's evaluate the sum and subtraction process:

1. **Start with `res = 0`.**
2. For `i = 1`: Since `1 % 2 != 0`, we **add** `1` to `res`, so `res = 1`.
3. For `i = 2`: Since `2 % 2 == 0`, we **subtract** `2` from `res`, so `res = 1 - 2 = -1`.
4. For `i = 3`: Since `3 % 2 != 0`, we **add** `3` to `res`, so `res = -1 + 3 = 2`.
5. For `i = 4`: Since `4 % 2 == 0`, we **subtract** `4` from `res`, so `res = 2 - 4 = -2`.
6. For `i = 5`: Since `5 % 2 != 0`, we **add** `5` to `res`, so `res = -2 + 5 = 3`.

**Final result**: `res = 3`.

**Output**:
```cpp
3
```

#### Example 2: `n = 10`, `m = 3`

The numbers from `1` to `10` are `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`. Let's evaluate the sum and subtraction process:

1. **Start with `res = 0`.**
2. For `i = 1`: Since `1 % 3 != 0`, we **add** `1` to `res`, so `res = 1`.
3. For `i = 2`: Since `2 % 3 != 0`, we **add** `2` to `res`, so `res = 3`.
4. For `i = 3`: Since `3 % 3 == 0`, we **subtract** `3` from `res`, so `res = 3 - 3 = 0`.
5. For `i = 4`: Since `4 % 3 != 0`, we **add** `4` to `res`, so `res = 0 + 4 = 4`.
6. For `i = 5`: Since `5 % 3 != 0`, we **add** `5` to `res`, so `res = 9`.
7. For `i = 6`: Since `6 % 3 == 0`, we **subtract** `6` from `res`, so `res = 9 - 6 = 3`.
8. For `i = 7`: Since `7 % 3 != 0`, we **add** `7` to `res`, so `res = 10`.
9. For `i = 8`: Since `8 % 3 != 0`, we **add** `8` to `res`, so `res = 18`.
10. For `i = 9`: Since `9 % 3 == 0`, we **subtract** `9` from `res`, so `res = 18 - 9 = 9`.
11. For `i = 10`: Since `10 % 3 != 0`, we **add** `10` to `res`, so `res = 19`.

**Final result**: `res = 19`.

**Output**:
```cpp
19
```

### Time Complexity

- **Time Complexity**: The algorithm iterates through the array from `1` to `n`. For each iteration, we check the modulus of `i % m`, which takes constant time. Thus, the overall time complexity is **O(n)**, where `n` is the input size.

### Space Complexity

- **Space Complexity**: The space complexity is **O(1)** since the algorithm uses only a few variables (`res`, `i`) for computation. No additional data structures are required.

### Conclusion

The solution efficiently computes the desired result by iterating through the integers from `1` to `n`, adding or subtracting each based on whether it is divisible by `m`. This approach ensures that we can solve the problem in linear time complexity, making it suitable for large values of `n`. The space complexity remains constant, as no extra storage is required.

[`Link to LeetCode Lab`](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/)

---
{{< youtube CXjNaWOdJ34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
