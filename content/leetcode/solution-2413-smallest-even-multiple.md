
+++
authors = ["grid47"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2413: Smallest Even Multiple in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MTdr8qNSWf8"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MTdr8qNSWf8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the smallest even multiple of a given integer `n`. The task is to determine the smallest positive integer `m` such that `m` is a multiple of `n` and is also an even number. 

To achieve this, you must implement a function that will compute the smallest such `m` for a given value of `n`.

### Approach

The problem can be approached with a simple observation about the properties of even and odd numbers:
- If `n` is already an even number, then `n` itself is the smallest even multiple of `n`.
- If `n` is an odd number, then the smallest even multiple will be `2 * n`, as multiplying an odd number by 2 results in an even number.

With this in mind, the solution becomes straightforward: we need to check if `n` is even or odd and return either `n` itself (if it's even) or `2 * n` (if it's odd).

### Code Breakdown (Step by Step)

#### 1. Check if the Number is Even or Odd

```cpp
return n % 2 == 0 ? n : n * 2;
```

- This line uses the modulo operation (`n % 2`) to check if the number `n` is even.
    - If `n % 2 == 0`, then `n` is even. In this case, we simply return `n` because `n` itself is the smallest even multiple.
    - If `n % 2 != 0`, then `n` is odd. In this case, we return `n * 2` because multiplying an odd number by 2 will give us the smallest even multiple of `n`.

#### 2. Ternary Operator for Decision Making

- The ternary operator (`? :`) is used to make a concise decision based on the result of `n % 2 == 0`. This operator allows us to handle both cases in a single line:
  - `n % 2 == 0 ? n` means if `n` is even, return `n`.
  - `: n * 2` means if `n` is odd, return `n * 2`.

#### 3. Return the Result

- Once the condition is checked, the function directly returns the appropriate value: either `n` or `2 * n`, depending on whether `n` is even or odd.

### Complexity

#### Time Complexity:

The time complexity of this solution is \( O(1) \). This is because the modulo operation (`n % 2`) and the multiplication operation (`n * 2`) are constant-time operations. No loops or recursive calls are involved, and the solution involves only basic arithmetic and condition checks.

#### Space Complexity:

The space complexity of the solution is also \( O(1) \). The function uses a constant amount of space to store the input `n` and the result, and there are no additional data structures or memory allocations that grow with the size of the input.

### Conclusion

The solution is optimal for this problem, as it computes the smallest even multiple of a given integer `n` in constant time. By leveraging the properties of even and odd numbers, the solution provides an efficient way to determine the smallest even multiple using a simple conditional check. This approach guarantees that the computation is fast and efficient, with both time and space complexity being \( O(1) \). Thus, the solution is well-suited for handling large inputs and provides an elegant and minimalistic solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-even-multiple/description/)

---
{{< youtube MTdr8qNSWf8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
