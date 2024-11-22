
+++
authors = ["grid47"]
title = "Leetcode 372: Super Pow"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 372: Super Pow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Divide and Conquer"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/372.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/372.webp" 
    alt="A glowing number being raised to a power, with the power operations softly highlighted along the way."
    caption="Solution to LeetCode 372: Super Pow Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    int base = 1337;
    int powmod(int a, int k) {
        a %= base;
        int res = 1;
        for(int i = 0; i < k; i++)
        res = (res * a) % base;
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The goal here is to calculate `a^b % 1337`, where `a` is an integer and `b` is an array of digits that represent a very large exponent. The challenge is to efficiently compute this modular exponentiation, especially since `b` can have a large number of digits. We're tasked with calculating this without directly manipulating the large number `b`, and to do this, we’ll leverage some clever mathematical techniques!

---

### 🧠 Approach

To solve this problem efficiently, we’ll break it down into a series of steps that involve **modular arithmetic** and **recursive power reduction**. Here are the key ideas:

1. **Modular Arithmetic**: By taking advantage of the modulus (`1337`), we can simplify each step of the calculation, ensuring we never have to deal with numbers too large to handle. At each recursive step, we compute the modular exponentiation, which avoids overflow and helps us manage big numbers.

2. **Recursive Decomposition**: Since `b` is an array of digits, we don’t need to calculate the entire exponent `a^b` directly. Instead, we recursively reduce `b` by removing one digit at a time, breaking the problem into smaller subproblems that are easier to solve.

3. **Efficient Modular Exponentiation**: Using **exponentiation by squaring**, we can compute `a^k % base` efficiently, which significantly reduces the number of operations required.

---

### 🔨 Step-by-Step Code Breakdown

Now, let’s dive into the code and break it down step by step!

#### 1. `powmod` Function (Efficient Modular Exponentiation)

The `powmod` function computes `a^k % base` efficiently. Here’s how it works:

```cpp
int powmod(int a, int k) {
    a %= base;  // Reduce 'a' modulo base to avoid large numbers
    int res = 1;  // Start with result = 1 (multiplicative identity)
    for (int i = 0; i < k; i++) {  // Loop 'k' times
        res = (res * a) % base;  // Multiply and take modulo
    }
    return res;  // Return the result
}
```

- **Line 1**: We reduce `a` modulo `base` to avoid handling large numbers.
- **Line 2**: We start with `res = 1`, which is the identity for multiplication.
- **Lines 3-4**: We loop `k` times, multiplying the result by `a` and taking modulo `base`.
- **Line 5**: Finally, we return the result, which is `a^k % base`.

This function is crucial for efficiently calculating powers modulo `1337`!

#### 2. `superPow` Function (Recursive Decomposition)

The `superPow` function breaks down the problem of computing `a^b % 1337` (where `b` is an array of digits) using recursion:

```cpp
int superPow(int a, vector<int>& b) {
    if(b.empty()) return 1;  // Base case: if 'b' is empty, return 1
    int last_digit = b.back();  // Get the last digit of 'b'
    b.pop_back();  // Remove the last digit from 'b'
    
    // Recursively calculate the result and reduce the problem
    return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
}
```

- **Line 1**: If `b` is empty, we return `1` because any number raised to the power of `0` is `1`.
- **Line 2**: Extract the last digit of `b` (this is the least significant digit of the exponent).
- **Line 3**: Remove the last digit from `b`, reducing the problem size for the next recursive step.
- **Line 4**: We recursively calculate `superPow(a, b)`, then raise it to the power of 10 using `powmod`. This is crucial for breaking down large powers efficiently.
- **Line 5**: We also compute `powmod(a, last_digit)` to handle the effect of the current digit on the exponent. We multiply the results and take modulo `base`.

This recursive approach reduces the problem step by step, making it manageable and efficient!

#### 3. Base Variable

```cpp
int base = 1337;
```

The modulus `1337` is predefined in the problem, and we use it to ensure the result stays within bounds while preventing overflow.

---

### 📈 Time and Space Complexity

#### Time Complexity

The `superPow` function is called recursively for each digit of `b`. If `n` is the number of digits in `b`, the recursion depth is `O(n)`. For each recursive call, we perform two `powmod` calls, each with an exponent of at most `10`. The time complexity for `powmod` is constant (`O(1)`), so the overall time complexity is **O(n)**, where `n` is the number of digits in `b`.

#### Space Complexity

The space complexity is **O(n)**, where `n` is the number of digits in `b`, because the recursion depth grows with the number of digits.

---

### 🏁 Conclusion

In this problem, we tackled the challenge of computing `a^b % 1337`, where `b` is represented as an array of digits. By using modular exponentiation and recursive decomposition, we efficiently computed the result without dealing directly with the large exponent. The approach is both time and space efficient, with a linear complexity relative to the number of digits in `b`. 

This technique is perfect for handling large numbers and ensures that we can work with numbers that are too large to handle traditionally. Keep practicing, and you’ll soon master these advanced mathematical concepts!

---

### 🌟 Quick Summary

- We used **modular exponentiation** to compute `a^b % 1337` efficiently.
- We broke the problem down recursively by removing one digit from `b` at a time.
- **Time Complexity**: **O(n)** (where `n` is the number of digits in `b`).
- **Space Complexity**: **O(n)** due to recursion depth.
  
Now you’re ready to solve similar problems and tackle even bigger challenges! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/super-pow/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
