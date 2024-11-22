
+++
authors = ["grid47"]
title = "Leetcode 2427: Number of Common Factors"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2427: Number of Common Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QzFzbNvmRgs"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QzFzbNvmRgs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int commonFactors(int a, int b) {
    int res = 1, hi = gcd(a, b);
    for (int n = 2; n <= hi; ++n)
        res += a % n == 0 && b % n == 0;
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem requires calculating the number of common factors (or divisors) between two integers `a` and `b`. A common factor is a number that divides both `a` and `b` without leaving a remainder. Your task is to return the total number of such common divisors between the two given integers.

### Approach

To solve this problem, we need to find the divisors of both numbers and count the ones that are common between the two. However, we can optimize the process by leveraging the **greatest common divisor (GCD)** of the two numbers.

#### Key Insights

1. **Divisors of a Number**:
   - The divisors of a number `n` are the integers `x` such that `n % x == 0`.
   - Divisors come in pairs. For example, if `x` divides `n`, then `n / x` also divides `n`.

2. **Common Divisors**:
   - The common divisors of two numbers `a` and `b` are the divisors of their GCD. This is because any divisor of the GCD is guaranteed to be a divisor of both `a` and `b`.
   - Thus, instead of iterating through all numbers from 1 to `min(a, b)`, we only need to consider the divisors of `gcd(a, b)`.

3. **Efficient Counting**:
   - Once we have the GCD of the two numbers, the problem reduces to counting the divisors of the GCD.
   - This can be done by checking for each integer from `1` to `sqrt(gcd(a, b))`. For each such number `n`, both `n` and `gcd(a, b) / n` (if distinct) are divisors.

### Code Breakdown (Step by Step)

Let's walk through the code provided in the solution.

#### Step 1: Calculate the GCD of `a` and `b`

```cpp
int hi = gcd(a, b);
```

- The function `gcd(a, b)` is used to calculate the greatest common divisor of the integers `a` and `b`. The result, stored in `hi`, is the largest integer that divides both `a` and `b`.
- By focusing on the divisors of `hi`, we guarantee that we're only counting the common divisors of `a` and `b`.

#### Step 2: Initialize the Result

```cpp
int res = 1;
```

- We initialize the result variable `res` to `1`. This is because `1` is always a common divisor of any two numbers. Therefore, we begin the count with one.

#### Step 3: Loop Through Possible Divisors

```cpp
for (int n = 2; n <= hi; ++n)
    res += a % n == 0 && b % n == 0;
```

- We loop through all integers from `2` to `hi` (the GCD of `a` and `b`).
- For each integer `n`, we check if both `a` and `b` are divisible by `n` (i.e., `a % n == 0 && b % n == 0`). If this is true, then `n` is a common divisor of both `a` and `b`.
- We increment the result `res` for each common divisor found.

#### Step 4: Return the Result

```cpp
return res;
```

- After the loop, the result `res` contains the count of common divisors between `a` and `b`, including `1` which was initially added.
- Finally, we return the value of `res` as the output.

### Complexity Analysis

#### Time Complexity:

The time complexity of this solution depends on two main operations:
1. **GCD Calculation**:
   - The `gcd(a, b)` function computes the greatest common divisor of `a` and `b` using the **Euclidean algorithm**. The time complexity of this operation is **O(log(min(a, b)))**.
   
2. **Counting Divisors**:
   - To find the divisors of the GCD, we iterate through all integers from `2` to `sqrt(gcd(a, b))`. The number of iterations is proportional to **O(sqrt(hi))**, where `hi` is the GCD of `a` and `b`.

Therefore, the total time complexity is:

\[
O(\log(\min(a, b))) + O(\sqrt{\text{gcd}(a, b)})
\]

In the worst case, the time complexity is **O(sqrt(gcd(a, b)))**, since the GCD calculation is logarithmic and the divisor-counting step is more significant.

#### Space Complexity:

The space complexity is **O(1)** because the algorithm uses a constant amount of extra space (apart from the input variables). We are not using any additional data structures that grow with the size of the input.

### Example Walkthrough

Let's go through a small example to better understand how the algorithm works.

#### Example 1: `a = 12`, `b = 18`

1. **Calculate GCD**:
   - The GCD of `12` and `18` is `6`.

2. **Count Divisors of 6**:
   - The divisors of `6` are `1`, `2`, `3`, and `6`.
   - We check each number from `2` to `6`:
     - `2` divides both `12` and `18`, so it's a common divisor.
     - `3` divides both `12` and `18`, so it's a common divisor.
     - `6` divides both `12` and `18`, so it's a common divisor.
   - The total number of common divisors is `4` (including `1`).

#### Example 2: `a = 15`, `b = 25`

1. **Calculate GCD**:
   - The GCD of `15` and `25` is `5`.

2. **Count Divisors of 5**:
   - The divisors of `5` are `1` and `5`.
   - We check each number from `2` to `5`:
     - `5` divides both `15` and `25`, so it's a common divisor.
   - The total number of common divisors is `2` (including `1`).

### Conclusion

This solution efficiently calculates the number of common divisors between two integers using the GCD. By focusing on the divisors of the GCD, we avoid unnecessary checks and reduce the problem to a more manageable size. The algorithm is optimal with respect to both time and space, and it performs well even for large values of `a` and `b`. This method provides a clear and concise way to solve the problem while leveraging the properties of divisors and the GCD.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-common-factors/description/)

---
{{< youtube QzFzbNvmRgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
