
+++
authors = ["grid47"]
title = "Leetcode 2429: Minimize XOR"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2429: Minimize XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mWUMfdloybo"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mWUMfdloybo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            if(((num1 >> i) & 1) == 1) {
                if(n > 0) {
                    res |= (1 << i);
                    n--;
                    if(n == 0) return res;
                }
            }
        }
        int i = 0;
        while(n > 0) {
            if(((res >> i) & 1) == 0) {
                res |= (1 << i);
                n--;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to minimize the XOR of two numbers `num1` and `num2` while changing the bits of `num1` such that the number of `1` bits in the result is equal to the number of `1` bits in `num2`. This task requires an optimal approach to achieve the minimum possible value of the XOR by manipulating the bits of `num1` and `num2` strategically.

### Approach

To solve this problem efficiently, we need to take advantage of the properties of the XOR operation and bit manipulation. XOR is a binary operation that outputs `1` if the bits are different and `0` if they are the same. The goal is to minimize this difference by adjusting the bits of `num1` while ensuring the number of `1` bits in the result matches that of `num2`.

### Key Steps

The steps to minimize the XOR are as follows:

1. **Count the `1` bits in `num2`:**
   The first step is to determine how many `1` bits are in `num2`. This can be done using the `__builtin_popcount()` function, which counts the number of `1` bits in an integer. We will need to match this number of `1` bits in the resulting number.

2. **Set `1` bits in `num1`:**
   We then go through the bits of `num1` from the most significant bit (MSB) to the least significant bit (LSB). For each `1` bit in `num1`, we try to keep it in the result as long as there are still `1` bits required (i.e., the number of `1` bits left to place in the result is greater than 0).

3. **Set `0` bits where necessary:**
   Once we have placed all the `1` bits from `num1`, if there are still `1` bits remaining to be placed, we set the lowest unset bits in the result until the required number of `1` bits is reached.

4. **Return the result:**
   After all the bits are adjusted, we return the modified number, which now has the same number of `1` bits as `num2`, and we have minimized the XOR value.

### Code Breakdown (Step by Step)

#### Step 1: Count the `1` bits in `num2`

```cpp
int n = __builtin_popcount(num2);
```

- We use the `__builtin_popcount()` function to count the number of `1` bits in `num2` and store this value in `n`. This tells us how many `1` bits we need in the final result.

#### Step 2: Iterate over the bits of `num1`

```cpp
int res = 0;
for(int i = 30; i >= 0; i--) {
    if(((num1 >> i) & 1) == 1) {
        if(n > 0) {
            res |= (1 << i);
            n--;
            if(n == 0) return res;
        }
    }
}
```

- We initialize `res` to `0`. This will hold the result.
- We start iterating over the bits of `num1` from the most significant bit (bit 30) to the least significant bit (bit 0). We do this because we want to prioritize setting the most significant bits first, which helps in minimizing the XOR value.
- For each bit `i` of `num1`, we check if the bit is `1` using `((num1 >> i) & 1) == 1`. If the bit is `1`, we check if there are still `1` bits left to place (i.e., `n > 0`). If so, we set this bit in `res` by performing `res |= (1 << i)`, and we decrement `n`.
- If `n` reaches `0` (i.e., we have placed all the `1` bits required), we return `res`.

#### Step 3: Set remaining `1` bits in `res`

```cpp
int i = 0;
while(n > 0) {
    if(((res >> i) & 1) == 0) {
        res |= (1 << i);
        n--;
    }
    i++;
}
```

- If `n` is still greater than `0` after iterating through all the bits of `num1`, we need to place the remaining `1` bits in the result. We do this by iterating from the least significant bit (bit 0) upwards and setting the bits of `res` to `1` where they are currently `0`.
- We check if the bit `i` is `0` in `res` using `((res >> i) & 1) == 0`. If it is `0`, we set it to `1` using `res |= (1 << i)` and decrement `n`.
- We continue this process until all the `1` bits required are placed in `res`.

#### Step 4: Return the Result

```cpp
return res;
```

- Finally, we return the result `res`, which now contains the minimal XOR value with the same number of `1` bits as `num2`.

### Complexity Analysis

#### Time Complexity:

- The function iterates over the bits of `num1` and `res`, both of which are integers and have at most 32 bits (assuming a 32-bit integer). The total number of iterations is thus constant, specifically `O(32)`.
- The operations inside the loop (bit shifting, bitwise AND, OR, and comparison) are all constant time operations.
- Therefore, the overall time complexity of the solution is:
  \[
  O(1)
  \]
  This is because the number of bits is fixed, and the algorithm processes each bit in constant time.

#### Space Complexity:

- The algorithm uses a constant amount of extra space, only requiring a few integer variables (`n`, `res`, and `i`).
- Therefore, the space complexity is:
  \[
  O(1)
  \]

### Example Walkthrough

Let's walk through an example to see how the algorithm works.

#### Example 1: `num1 = 3`, `num2 = 5`

1. **Count the `1` bits in `num2`:**
   - `num2 = 5` has two `1` bits, so `n = 2`.

2. **Iterate over `num1`:**
   - `num1 = 3` has two `1` bits in positions 1 and 0.
   - Start with `res = 0`.
   - For `i = 1` (bit 1 of `num1`), the bit is `1` and `n > 0`, so we set the bit in `res`: `res |= (1 << 1)` gives `res = 2`. Decrement `n` to 1.
   - For `i = 0` (bit 0 of `num1`), the bit is `1` and `n > 0`, so we set the bit in `res`: `res |= (1 << 0)` gives `res = 3`. Decrement `n` to 0.
   - Since `n == 0`, return `res = 3`.

3. **Result:**
   - The result is `3`.

#### Example 2: `num1 = 6`, `num2 = 7`

1. **Count the `1` bits in `num2`:**
   - `num2 = 7` has three `1` bits, so `n = 3`.

2. **Iterate over `num1`:**
   - `num1 = 6` has two `1` bits at positions 2 and 1.
   - Start with `res = 0`.
   - For `i = 2` (bit 2 of `num1`), the bit is `1` and `n > 0`, so we set the bit in `res`: `res |= (1 << 2)` gives `res = 4`. Decrement `n` to 2.
   - For `i = 1` (bit 1 of `num1`), the bit is `1` and `n > 0`, so we set the bit in `res`: `res |= (1 << 1)` gives `res = 6`. Decrement `n` to 1.
   - For `i = 0` (bit 0 of `num1`), the bit is `0`. We move to the next step to place the remaining `1` bits.

3. **Place remaining `1` bits:**
   - `n = 1`, and we need to place one `1` bit. For `i = 0`, `res = 6` (bit 0 is `0`), so we set it: `res |= (1 << 0)` gives `res = 7`. Decrement `n` to 0.

4. **Result:**
   - The result is `7`.

### Conclusion

This solution uses bitwise operations and a greedy approach to efficiently minimize the XOR of two numbers while ensuring that the result has the same number of `1` bits as `num2`. The time and space complexity of the solution are both constant, making it an optimal solution for this problem. The algorithm is both efficient and easy to understand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-xor/description/)

---
{{< youtube mWUMfdloybo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
