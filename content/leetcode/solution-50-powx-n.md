
+++
authors = ["grid47"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 50: Pow(x, n) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/50.webp"
youtube = "g9YQyYi4IQQ"
youtube_upload_date="2021-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/g9YQyYi4IQQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/50.webp" 
    alt="A soft, glowing beam expanding and contracting in gentle rhythmic pulses."
    caption="Solution to LeetCode 50: Pow(x, n) Problem"
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
    double myPow(double x, int n) {
        if(n== 0) return 1;
        if(n < 0) return 1/x * myPow(1/x, -(n + 1));
        
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
    }
};
{{< /highlight >}}
---

### ⚡ Problem Statement

Implement the `myPow` function to calculate `x^n` (x raised to the power of n), where `x` is a floating-point number and `n` is an integer. The function must be efficient and handle both positive and negative exponents, as well as edge cases such as `n = 0`.

### 💡 Approach

To efficiently compute `x^n`, we use **exponentiation by squaring**, a fast algorithm that reduces the time complexity from `O(n)` to `O(log n)`.

- **For even `n`:**
  \[
  x^n = (x^{n/2})^2
  \]
  
- **For odd `n`:**
  \[
  x^n = x \times (x^{n/2})^2
  \]

Additionally, we need to handle the case when `n` is negative:
\[
x^{-n} = \frac{1}{x^n}
\]

### 🧑‍💻 Code Breakdown

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;  // Base case: x^0 = 1 for any x
        
        if (n < 0) return 1 / x * myPow(1 / x, -(n + 1));  // Handle negative exponents
        
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);  // Apply exponentiation by squaring
    }
};
```

#### Step 1: Base Case for `n == 0`

```cpp
if (n == 0) return 1;
```
- **Explanation**: By definition, any non-zero number raised to the power of `0` equals `1`. This handles the edge case where `n` is 0.

#### Step 2: Handling Negative Exponents

```cpp
if (n < 0) return 1 / x * myPow(1 / x, -(n + 1));
```
- **Explanation**: When `n` is negative, we use the identity \( x^{-n} = \frac{1}{x^n} \). The recursive call adjusts `n` to handle the negative exponent. This modification ensures no overflow issues for the minimum integer value (`INT_MIN`), as `-(n + 1)` ensures proper handling of `n` in recursive calls.

#### Step 3: Exponentiation by Squaring (Recursive Case)

```cpp
return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
```
- **Explanation**: This step applies exponentiation by squaring:
  - **Even `n`**: If `n` is even, we compute `myPow(x * x, n / 2)`, since \( x^n = (x^{n/2})^2 \).
  - **Odd `n`**: If `n` is odd, we compute `myPow(x * x, n / 2)` first, then multiply the result by `x`, as \( x^n = x \times (x^{n/2})^2 \).

### ⏱️ **Time Complexity**

The time complexity of this approach is **O(log n)**, where `n` is the exponent. This is because at each step, the size of the problem is reduced by half, leading to a logarithmic number of recursive calls.

- **Why `log n`?**  
  In each recursive call, the exponent `n` is halved, reducing the problem size logarithmically.

### 🧠 **Space Complexity**

The space complexity is **O(log n)** due to the recursive call stack. The depth of the recursion is proportional to `log(n)` since we are halving `n` with each recursive call.

### 📝 **Conclusion**

This implementation of `myPow` efficiently computes `x^n` using **exponentiation by squaring**, which reduces the time complexity to **O(log n)**. The recursive structure handles both positive and negative exponents efficiently, and the base case ensures proper handling of `n = 0`.

- **Advantages**:
  - **Efficient**: The logarithmic time complexity makes this approach suitable even for large values of `n`.
  - **Simplicity**: The recursive approach is both simple to understand and implement.
  - **Handles Negative Exponents**: The solution correctly handles negative exponents without special cases.

This approach is ideal for computing powers efficiently in problems where large exponents are involved.

[`Link to LeetCode Lab`](https://leetcode.com/problems/powx-n/description/)

---
{{< youtube g9YQyYi4IQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
