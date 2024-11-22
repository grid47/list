
+++
authors = ["grid47"]
title = "Leetcode 371: Sum of Two Integers"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 371: Sum of Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/371.webp"
youtube = "gVUrDV4tZfY"
youtube_upload_date="2021-10-20"
youtube_thumbnail="https://i.ytimg.com/vi/gVUrDV4tZfY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/371.webp" 
    alt="A set of two glowing numbers adding up to a sum, with each number and their sum softly illuminated."
    caption="Solution to LeetCode 371: Sum of Two Integers Problem"
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
    int getSum(int a, int b) {
        return b == 0? a: getSum(a^b, (a&b)<<1);
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this challenge, we're asked to calculate the sum of two integers, `a` and `b`, without using the typical `+` or `-` arithmetic operators. Instead, we're going to solve this by utilizing bitwise operations—how cool is that? 😎

---

### 🧠 Key Insights

To tackle this problem, we need to understand how numbers are added at the **bit level**. Here’s how it works in binary addition:

1. **XOR (exclusive OR)**: This operation gives us the sum of two bits **without considering the carry**. It’s like adding the bits as if there’s no carryover.
2. **AND**: The AND operation helps us **detect where the carry** is. If both bits are 1, there’s a carry.

By combining these two operations, we can compute the sum iteratively without using `+`.

---

### 🔍 Approach

The algorithm works by repeatedly simulating the addition process with the help of bitwise operations:

1. **XOR (`^`)**: The XOR operation computes the sum of two numbers **without carrying over**.
2. **AND (`&`)**: This operation helps **detect where the carry** occurs.
3. **Left shift (`<<`)**: Once we know where the carry is, we shift it left by one bit to move it to the right place for the next addition.

Here’s how the algorithm goes step by step:

- **Step 1**: Compute the partial sum using `a^b` (XOR).
- **Step 2**: Find the carry using `(a&b)`, then shift it left to the correct position with `<<`.
- **Step 3**: Repeat this process until there’s no carry left (i.e., `b == 0`).

Once the carry becomes zero, we have our result!

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through the code:

#### Step 1: Base Case Check
```cpp
return b == 0? a : getSum(a^b, (a&b)<<1);
```
- If `b` is zero, the addition is done! We return `a` because no further calculation is needed.
- If `b` isn’t zero, we call the function recursively with the new arguments:
  - `a^b`: The sum without carry.
  - `(a&b)<<1`: The carry, shifted to the right position.

#### Step 2: XOR Operation (`a^b`)
- The XOR operation gives the **sum without carry**:
  - If the bits are the same (0,0 or 1,1), the result is 0.
  - If the bits are different (0,1 or 1,0), the result is 1.
- Example:
  - `5 ^ 3 = 6` (because `0101 ^ 0011 = 0110`)

#### Step 3: AND and Left Shift Operation (`(a&b)<<1`)
- The AND operation finds where the carry happens:
  - `a&b`: A 1 where both `a` and `b` have 1 at the same position.
  - Then, we shift the result left by one bit to move the carry to the right position for the next iteration.
- Example:
  - `(5 & 3) = 1`, and shifting left by one bit gives `2`.

#### Step 4: Recursion
- The function calls itself recursively with the new values:
  - `a^b`: The new sum without carry.
  - `(a&b)<<1`: The new carry, shifted to the correct position.
- This continues until `b == 0`, and then the result is returned.

---

### 📊 Example Walkthrough

Let’s walk through an example with `a = 5` and `b = 3`:

1. **First Iteration**:
   - `a = 5`, `b = 3`
   - `a^b = 6` (sum without carry)
   - `(a&b)<<1 = 2` (carry)
   - Call `getSum(6, 2)`

2. **Second Iteration**:
   - `a = 6`, `b = 2`
   - `a^b = 4` (sum without carry)
   - `(a&b)<<1 = 4` (carry)
   - Call `getSum(4, 4)`

3. **Third Iteration**:
   - `a = 4`, `b = 4`
   - `a^b = 0` (sum without carry)
   - `(a&b)<<1 = 8` (carry)
   - Call `getSum(0, 8)`

4. **Fourth Iteration**:
   - `a = 0`, `b = 8`
   - `a^b = 8` (sum without carry)
   - `(a&b)<<1 = 0` (carry)
   - Call `getSum(8, 0)`

5. **Base Case**:
   - `a = 8`, `b = 0`
   - Since `b == 0`, we return `a = 8`.

The sum of `5` and `3` is `8`. 🎉

---

### 📈 Time Complexity

The time complexity of this algorithm is **O(log(max(a, b)))**. This is because each recursive call reduces the number of bits in the carry (`b`) by one. Since the number of bits in `a` and `b` is proportional to **log(max(a, b))**, the recursion depth is logarithmic.

---

### 🛠️ Space Complexity

The space complexity is **O(log(max(a, b)))**, as the recursion depth is proportional to the number of bits in `a` and `b`. Each recursive call consumes space on the call stack, leading to logarithmic space complexity.

---

### 🏁 Conclusion

This bitwise approach is a brilliant way to perform addition without using the standard `+` operator! By using XOR for the sum and AND (with a left shift) for the carry, we efficiently compute the result in **logarithmic time**. 🏆

The algorithm is not only **elegant** but also **efficient**, demonstrating the power of bitwise operations. So next time you encounter a problem that seems to require regular arithmetic, remember that bitwise tricks can often come to the rescue! 🔥

---

### 🎯 Quick Recap:

- **Key Operations**: XOR for sum, AND for carry.
- **Time Complexity**: O(log(max(a, b))).
- **Space Complexity**: O(log(max(a, b))).
- **Motivational Note**: You can solve this problem without relying on the typical addition operator, showing just how versatile bitwise operations can be! Keep exploring new techniques to make your solutions even more efficient. 💪

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-two-integers/description/)

---
{{< youtube gVUrDV4tZfY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
