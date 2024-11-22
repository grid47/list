
+++
authors = ["grid47"]
title = "Leetcode 190: Reverse Bits"
date = "2024-10-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 190: Reverse Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp"
youtube = "epFf0wlbng0"
youtube_upload_date="2020-07-13"
youtube_thumbnail="https://i.ytimg.com/vi/epFf0wlbng0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp" 
    alt="A series of bits glowing as they reverse, shifting smoothly from 1 to 0 and back."
    caption="Solution to LeetCode 190: Reverse Bits Problem"
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
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
        n = (n & 0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8;
        n = (n & 0x0f0f0f0f) << 4  | (n & 0xf0f0f0f0) >> 4;
        n = (n & 0x33333333) << 2  | (n & 0xcccccccc) >> 2;
        n = (n & 0x55555555) << 1  | (n & 0xaaaaaaaa) >> 1;        
        return n;
    }
};
{{< /highlight >}}
---

### 🌟 Reverse Bits of a 32-bit Unsigned Integer

The task is to reverse the bits of a given 32-bit unsigned integer. For example, if the integer `n` is represented in binary as `00000010100101000001111010011100`, after reversing the bits, the result should be `00111001011110000010100101000000`.

#### Example:
- **Input**: `n = 43261596` (binary: `00000010100101000001111010011100`)
- **Output**: `964176192` (binary: `00111001011110000010100101000000`)

### 💡 Approach

To solve this problem efficiently, we will use **bitwise manipulation**. Rather than converting the number to a binary string, reversing it, and converting it back to an integer, we will manipulate the bits directly. The process breaks down the reversal task into smaller chunks using bitwise masks and shifts. This allows us to gradually reverse the bits in an optimal way.

Here are the detailed steps:

1. **Pairwise Reversal**: Swap adjacent pairs of bits.
2. **Nibbles Reversal**: Swap 4-bit blocks (nibbles).
3. **Bytes Reversal**: Swap 8-bit blocks (bytes).
4. **16-bit Blocks Reversal**: Swap 16-bit blocks.
5. **Final Reversal**: After performing all the smaller block reversals, the full 32-bit number will be reversed.

### 🛠 Code Breakdown

The code uses bitwise operations to reverse the bits in the number. Here's the implementation:

```cpp
uint32_t reverseBits(uint32_t n) {
    // Step 1: Swap 16-bit blocks
    n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
    
    // Step 2: Swap 8-bit blocks
    n = (n & 0x00ff00ff) << 8 | (n & 0xff00ff00) >> 8;
    
    // Step 3: Swap 4-bit blocks
    n = (n & 0x0f0f0f0f) << 4 | (n & 0xf0f0f0f0) >> 4;
    
    // Step 4: Swap 2-bit blocks
    n = (n & 0x33333333) << 2 | (n & 0xcccccccc) >> 2;
    
    // Step 5: Swap individual bits
    n = (n & 0x55555555) << 1 | (n & 0xaaaaaaaa) >> 1;
    
    return n;
}
```

### Explanation of Each Step:

#### 1. **Swapping 16-bit blocks**:
```cpp
n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
```
- The mask `0xffffffff` doesn't change the bits. This step swaps the lower 16 bits with the upper 16 bits by shifting the left and right halves.

#### 2. **Swapping 8-bit blocks**:
```cpp
n = (n & 0x00ff00ff) << 8 | (n & 0xff00ff00) >> 8;
```
- The mask `0x00ff00ff` isolates the lower 8 bits in each 16-bit block. These bits are shifted 8 positions to the left. The mask `0xff00ff00` isolates the higher 8 bits, which are shifted 8 positions to the right.

#### 3. **Swapping 4-bit blocks**:
```cpp
n = (n & 0x0f0f0f0f) << 4 | (n & 0xf0f0f0f0) >> 4;
```
- The mask `0x0f0f0f0f` isolates each 4-bit block, and these are shifted 4 positions to the left. The mask `0xf0f0f0f0` isolates the upper 4 bits, which are shifted 4 positions to the right.

#### 4. **Swapping 2-bit blocks**:
```cpp
n = (n & 0x33333333) << 2 | (n & 0xcccccccc) >> 2;
```
- This step works at the granularity of 2-bit blocks. The mask `0x33333333` isolates pairs of bits, and they are shifted 2 positions to the left. The mask `0xcccccccc` isolates the other pair of bits, which are shifted 2 positions to the right.

#### 5. **Swapping individual bits**:
```cpp
n = (n & 0x55555555) << 1 | (n & 0xaaaaaaaa) >> 1;
```
- Finally, this step swaps each pair of adjacent bits. The mask `0x55555555` isolates the odd-numbered bits, and they are shifted to the left. The mask `0xaaaaaaaa` isolates the even-numbered bits, and they are shifted to the right.

At this point, the 32-bit number has been completely reversed.

### 📊 Complexity Analysis

#### Time Complexity:
- **O(1)**: The time complexity is constant because the number of operations required to reverse the bits is fixed (32 bits). Each operation is performed in constant time, independent of the input value.

#### Space Complexity:
- **O(1)**: The space complexity is constant since we only use a few variables and perform the reversal in-place without requiring any additional storage that scales with the input.

### ✅ Conclusion

This solution efficiently reverses the bits of a 32-bit unsigned integer using **bitwise manipulation**. The approach divides the reversal task into smaller steps (swapping 16-bit blocks, 8-bit blocks, etc.), which guarantees optimal performance. The solution works in constant time **O(1)** and constant space **O(1)**, making it ideal for bit manipulation tasks, especially in performance-sensitive scenarios like competitive programming.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-bits/description/)

---
{{< youtube epFf0wlbng0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
