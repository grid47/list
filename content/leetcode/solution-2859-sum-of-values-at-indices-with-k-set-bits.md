
+++
authors = ["grid47"]
title = "Leetcode 2859: Sum of Values at Indices With K Set Bits"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2859: Sum of Values at Indices With K Set Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ditzt6BYVEs"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ditzt6BYVEs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
      int res = 0;

      for(int i = 0; i < nums.size(); i++) {
        int c = 0;
        int copy = i;
        while(copy) {
            c += copy & 1;
            copy >>= 1;
        }
        if(c == k) {
            res += nums[i];
        }
      }

      return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the sum of elements from a given array `nums` where the index of each element has exactly `k` set bits (1s) in its binary representation. The set bits refer to the 1s in the binary form of a number. For example, the number `5` has binary representation `101`, which contains 2 set bits.

### Approach

To solve this problem, we need to evaluate each index in the array and check how many set bits are present in its binary representation. If the number of set bits is equal to `k`, we add the corresponding value from the `nums` array to the sum.

Here’s how the solution works step by step:

1. **Iterate Over Array Indices**: For each index in the array, check how many set bits are present in the binary representation of that index.
  
2. **Count Set Bits**: For each index, count the number of set bits in its binary representation. This can be achieved by continuously applying bitwise operations.
  
3. **Check Condition**: If the number of set bits in the index matches `k`, add the corresponding value from the `nums` array to the result sum.

4. **Return the Result**: After processing all indices, return the computed sum.

### Code Breakdown (Step by Step)

```cpp
int res = 0;
```
- We initialize the variable `res` to zero. This will hold the sum of the elements where the index has exactly `k` set bits.

```cpp
for(int i = 0; i < nums.size(); i++) {
    int c = 0;
    int copy = i;
```
- We begin iterating over the array `nums`. For each index `i`, we initialize `c` to 0. This variable `c` will count the number of set bits (1s) in the binary representation of `i`.
- We store the index `i` in the variable `copy` for manipulation.

```cpp
while(copy) {
    c += copy & 1;
    copy >>= 1;
}
```
- The `while(copy)` loop continues as long as `copy` is non-zero (i.e., there are still bits to check).
- Inside the loop:
  - We use the bitwise AND operation `copy & 1` to check if the least significant bit of `copy` is set (i.e., if it’s 1). If it is, we increment `c`.
  - Then, we use the right shift operation `copy >>= 1` to shift the bits of `copy` one position to the right. This effectively removes the least significant bit that was just checked.
  
The result after the loop is that `c` will hold the number of set bits in the binary representation of the index `i`.

```cpp
if(c == k) {
    res += nums[i];
}
```
- If the number of set bits `c` is equal to the desired value `k`, we add the value `nums[i]` to the result `res`.

```cpp
return res;
```
- After processing all indices in the array, we return the accumulated result stored in `res`, which is the sum of all elements in `nums` whose indices have exactly `k` set bits.

### Complexity

#### Time Complexity:
- **O(n * b)**: Where `n` is the number of elements in the `nums` array, and `b` is the number of bits required to represent the index `i`. In this case, `b` is the number of bits in the maximum possible index, which depends on the size of the array.
  - For each index `i`, we count the set bits in its binary representation, which takes `O(b)` time, where `b` is the number of bits in `i`.
  - In total, we need to process all `n` elements in the array, so the overall time complexity is `O(n * b)`.
  
#### Space Complexity:
- **O(1)**: The space complexity is constant because we are using a fixed amount of extra space to store variables like `c` and `copy`, and we do not use any data structures that grow with the input size. Therefore, the space complexity is O(1).

### Conclusion

This solution efficiently calculates the sum of elements in an array whose indices have exactly `k` set bits in their binary representation. The solution uses bitwise operations to count the set bits for each index, which is an efficient way to work with binary representations. The approach runs in O(n * b) time, where `n` is the number of elements in the array, and `b` is the number of bits needed to represent the indices, which is efficient for typical input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/)

---
{{< youtube Ditzt6BYVEs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
