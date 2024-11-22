
+++
authors = ["grid47"]
title = "Leetcode 2220: Minimum Bit Flips to Convert Number"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2220: Minimum Bit Flips to Convert Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yz48myznqQY"
youtube_upload_date="2024-09-11"
youtube_thumbnail="https://i.ytimg.com/vi/yz48myznqQY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};
{{< /highlight >}}
---

### Problem Statement
The task is to determine the minimum number of bit flips required to convert a given integer `start` into another integer `goal`. A bit flip is a binary operation that changes a bit from `0` to `1` or from `1` to `0`. The goal is to find how many bits need to be flipped to make the binary representation of `start` equal to that of `goal`.

### Approach
To solve this problem, the key idea is to use the XOR operation. XORing two numbers highlights the differences between their binary representations. Whenever a bit in the two numbers is different, XOR results in `1`; if the bits are the same, the result is `0`. Therefore, XORing the numbers gives us a number where the bits set to `1` indicate the positions where `start` and `goal` differ.

Once we have the result of the XOR operation, counting the number of `1` bits in the result will tell us how many bit flips are required. The function `__builtin_popcount` is a built-in function that counts the number of `1` bits in an integer.

### Code Breakdown (Step by Step)
1. **XOR Operation:**
   ```cpp
   start ^ goal
   ```
   - The XOR operation between `start` and `goal` compares their binary representations. For each bit position, it returns `1` if the corresponding bits in `start` and `goal` are different, and `0` if they are the same.

2. **Counting the 1-bits:**
   ```cpp
   __builtin_popcount(start^goal);
   ```
   - The function `__builtin_popcount` counts the number of `1` bits in the result of `start ^ goal`. This count corresponds to the number of differing bit positions between `start` and `goal`, which directly gives us the minimum number of flips needed to convert `start` into `goal`.

3. **Returning the Result:**
   ```cpp
   return __builtin_popcount(start^goal);
   ```
   - The result of the bit count is returned as the final answer. This represents the minimum number of bit flips required.

### Complexity
- **Time Complexity**: 
  - The time complexity of the code is O(1), as the XOR operation and counting of `1` bits take constant time. The `__builtin_popcount` function operates in O(1) time because it is highly optimized and typically uses processor-specific instructions.
- **Space Complexity**: 
  - The space complexity is O(1) because no additional data structures are used, and only a few integer variables are involved.

### Conclusion
The solution to the problem of finding the minimum number of bit flips between two integers is elegant and highly efficient. By using the XOR operation, the code captures the differences between the binary representations of `start` and `goal`. The built-in function `__builtin_popcount` provides a quick and optimized way to count the number of differing bits, leading to a solution with constant time and space complexity. This approach is both time-efficient and space-efficient, making it an excellent choice for large numbers or situations requiring frequent bitwise operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)

---
{{< youtube yz48myznqQY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
