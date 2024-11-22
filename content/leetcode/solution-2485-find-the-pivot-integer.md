
+++
authors = ["grid47"]
title = "Leetcode 2485: Find the Pivot Integer"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2485: Find the Pivot Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xfw3A8uOdFw"
youtube_upload_date="2022-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xfw3A8uOdFw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2, x = sqrt(sum);
        return x * x == sum ? x : -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine whether a given integer `n` has a pivot integer. A pivot integer `x` is an integer such that the sum of the integers from 1 to `x` is equal to the sum of the integers from `x` to `n`. The task is to find such a pivot integer `x`, if it exists, and return it. If no such pivot exists, return `-1`.

Mathematically, we are given:
- The sum of the first `x` integers: `1 + 2 + 3 + ... + x = x * (x + 1) / 2`
- The sum of the integers from `x` to `n`: `x + (x+1) + (x+2) + ... + n`

The objective is to check if there exists an integer `x` such that the sum of the integers from 1 to `x` equals the sum of the integers from `x` to `n`.

### Approach

To solve this problem, we leverage the following mathematical insights:
1. The total sum of integers from `1` to `n` is given by the formula:
   \[
   \text{total\_sum} = \frac{n \cdot (n + 1)}{2}
   \]
2. For a pivot integer `x` to exist, the sum of integers from 1 to `x` must equal the sum of integers from `x` to `n`.
   The sum of integers from 1 to `x` is:
   \[
   \text{sum\_left} = \frac{x \cdot (x + 1)}{2}
   \]
   And the sum of integers from `x` to `n` is:
   \[
   \text{sum\_right} = \text{total\_sum} - \text{sum\_left} + x
   \]
   For the pivot integer `x` to exist, the following equation should hold:
   \[
   \text{sum\_left} = \text{sum\_right}
   \]
   After simplifying, this turns into:
   \[
   2 \cdot \text{sum\_left} = \text{total\_sum}
   \]
   The problem now reduces to checking if the total sum is a perfect square. If it is, we can find the pivot integer `x` as the square root of this total sum. If it isn't, no such pivot exists.

### Code Breakdown (Step by Step)

Let’s break down the solution code and its components:

#### 1. **Initialization**

```cpp
int sum = n * (n + 1) / 2, x = sqrt(sum);
```

- First, we calculate the total sum of integers from 1 to `n` using the formula:
  \[
  \text{sum} = \frac{n \cdot (n + 1)}{2}
  \]
  This gives us the sum of the first `n` integers.
  
- Then, we calculate the square root of this sum and store it in the variable `x`. This is because, to check if there exists a valid pivot integer, the sum must be a perfect square, as shown earlier.

#### 2. **Check if the Total Sum is a Perfect Square**

```cpp
return x * x == sum ? x : -1;
```

- The condition `x * x == sum` checks whether the total sum is a perfect square. If it is, the value of `x` is the square root of the total sum.
- If the sum is indeed a perfect square, we return `x` as the pivot integer. Otherwise, we return `-1`, indicating that no such pivot integer exists.

### Complexity Analysis

#### Time Complexity:
- The time complexity of this solution is **O(1)**. This is because:
  - The calculation of the total sum of integers from 1 to `n` is done in constant time.
  - Calculating the square root of a number is also a constant-time operation in most modern compilers for integers.
  
Thus, the overall time complexity is **O(1)**.

#### Space Complexity:
- The space complexity is also **O(1)**. We only use a few integer variables (`sum` and `x`) to store intermediate values, and there are no data structures that grow with input size.

Thus, the space complexity is **O(1)**.

### Conclusion

This solution efficiently determines whether a given integer `n` has a pivot integer by leveraging mathematical insights about the sums of integers and their properties. It works in constant time and space, making it very efficient even for large values of `n`. The key idea is recognizing that the problem reduces to checking whether the sum of the first `n` integers is a perfect square, and if so, returning its square root. If it is not a perfect square, the answer is `-1`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-pivot-integer/description/)

---
{{< youtube Xfw3A8uOdFw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
