
+++
authors = ["grid47"]
title = "Leetcode 2843:   Count Symmetric Integers"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2843:   Count Symmetric Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KHRfRTVqpVc"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/KHRfRTVqpVc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; ++i) {
            string s = to_string(i);
            int t = 0, n = s.size();
            for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
            if(n%2 == 0 && t == 0) ans++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to count the number of symmetric integers within a given range `[low, high]`. A number is symmetric if the sum of the first half of its digits equals the sum of the second half of its digits. For example, `123321` is symmetric because the sum of the first three digits (`1+2+3 = 6`) equals the sum of the last three digits (`3+2+1 = 6`).

We are given two integers, `low` and `high`, and we need to determine how many numbers within this range are symmetric integers.

### Approach

The solution involves checking each number in the given range to determine if it is symmetric. We can approach this problem by converting each number to a string, then splitting the string into two halves. The digits of the first half are compared with the digits of the second half, and if the sum of the digits in both halves is equal, the number is symmetric.

### Code Breakdown (Step by Step)

#### Step 1: Loop Through the Range
```cpp
for(int i = low; i <= high; ++i) {
```
- We loop through each integer in the range `[low, high]`. For each integer, we will check if it is symmetric.

#### Step 2: Convert the Integer to a String
```cpp
string s = to_string(i);
```
- The number `i` is converted into a string `s` for easier manipulation of individual digits. This allows us to directly access each digit by its index.

#### Step 3: Initialize Variables for the Sum of Digits
```cpp
int t = 0, n = s.size();
```
- We initialize `t` to 0, which will be used to store the difference between the corresponding digits from the first and second halves of the number. 
- `n` is the size of the string, which represents the number of digits in the current number.

#### Step 4: Compare the First and Second Halves
```cpp
for(int j = 0; j < n/2; ++j) {
    t += s[j] - s[n - j - 1];
}
```
- We loop over the first half of the digits (up to `n/2`). For each index `j`, we subtract the value of the digit at position `n - j - 1` (which corresponds to the digits from the second half of the number) from the digit at position `j` (the first half of the number).
- The idea is to compare corresponding digits from the start and end. If the sums of corresponding digits from both halves match, then `t` should equal 0 at the end of this loop.

#### Step 5: Check for Even-Length Numbers and Update the Count
```cpp
if(n % 2 == 0 && t == 0) ans++;
```
- After the loop, we check if the number of digits `n` is even (`n % 2 == 0`). Symmetric numbers must have an even number of digits to split them into two equal halves.
- If the number of digits is even and the sum of the digit differences (`t`) equals 0, then the number is symmetric, and we increment the answer `ans`.

#### Step 6: Return the Final Count
```cpp
return ans;
```
- After iterating through all numbers in the given range, we return the count of symmetric integers, stored in `ans`.

### Complexity

#### Time Complexity:
- **O(N * D)**, where `N` is the number of integers in the range `[low, high]`, and `D` is the maximum number of digits in any number in this range.
  - The outer loop runs for each number between `low` and `high`, so it runs `N` times.
  - For each number, we convert it into a string and check if it is symmetric. This involves checking `n/2` pairs of digits, where `n` is the number of digits in the number. In the worst case, this is proportional to `D`, the number of digits in the largest number in the range.
  - Thus, the time complexity is O(N * D).

#### Space Complexity:
- **O(D)**, where `D` is the number of digits in the current number. We use a string `s` to store the digits of the current number, which has a space complexity of O(D) for each number. In practice, this space is reused for each iteration of the loop.

### Conclusion

This solution uses a simple approach to solve the problem by iterating through the numbers in the range and checking whether each number is symmetric. It leverages string manipulation to check the sum of digits in the first and second halves of each number. This solution works efficiently for a reasonable range of numbers, and the time complexity is directly related to the number of integers and their length in the range `[low, high]`. The solution is easy to understand and implement, making it a good fit for problems involving digit-based comparisons.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-symmetric-integers/description/)

---
{{< youtube KHRfRTVqpVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
