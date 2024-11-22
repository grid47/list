
+++
authors = ["grid47"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "kv0O7p0pRvI"
youtube_upload_date="2022-05-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kv0O7p0pRvI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool digitCount(string num) {
    int cnt[10] = {};
    for (auto n : num)
        ++cnt[n - '0'];
    for (int i = 0; i < num.size(); ++i)
        if (cnt[i] != num[i] - '0')
            return false;
    return true;
}
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a string `num` that represents a non-negative integer, and your task is to determine if the number is a "digit count" number. A "digit count" number is a number in which for each digit `i` (where `i` is the index in the string), the count of the digit `i` in the number is equal to the value of the digit at the `i`-th position.

### Example 1:
Input: `"1210"`
Output: `true`
Explanation: 
- The number has 1 zero (`'0'`), 2 ones (`'1'`), 1 two (`'2'`), and 0 threes (`'3'`).
- The digit at the 0th position is 1, which correctly represents the count of zeros in the number.
- The digit at the 1st position is 2, which correctly represents the count of ones.
- The digit at the 2nd position is 1, which correctly represents the count of twos.
- The digit at the 3rd position is 0, which correctly represents the count of threes.

### Example 2:
Input: `"030"`
Output: `false`
Explanation: 
- The number has 1 zero (`'0'`), 1 one (`'1'`), and 1 two (`'2'`).
- The digit at the 0th position is 0, but it should represent the count of zeros, which is 1. Hence, the number is not a digit count number.

### Approach

The problem involves checking if the number satisfies the "digit count" condition. Here's how we can solve it step by step:

1. **Count the Digits**: The first thing we need to do is count the occurrences of each digit in the string `num`. Since the digits range from 0 to 9, we can use an array `cnt[10]` to store the count of each digit. We iterate through the string and increment the respective count for each digit encountered.

2. **Check the Condition**: After counting the occurrences of digits, we need to ensure that the count of each digit matches the value of the digit at the corresponding index in the string. Specifically, for each index `i` in the string `num`, we check if the count of the digit `i` matches the value of `num[i] - '0'`. If at any point this condition is not satisfied, we immediately return `false`.

3. **Return True if All Conditions Hold**: If all conditions hold true (i.e., the count of digits at each index matches the value at that index), we return `true`.

### Code Breakdown (Step by Step)

Let’s break down the code into individual steps:

```cpp
bool digitCount(string num) {
    int cnt[10] = {};  // Step 1: Initialize an array to count occurrences of digits
```
- Here, we declare an integer array `cnt[10]` initialized to zeros. This array will hold the count of each digit from 0 to 9. Each index `i` in the array will store the number of occurrences of the digit `i` in the string `num`.

```cpp
    for (auto n : num)
        ++cnt[n - '0'];  // Step 2: Count the occurrences of each digit
```
- This loop iterates over each character in the string `num`. For each character `n`, we subtract the character `'0'` from it to get the integer representation of the digit (e.g., `'2' - '0'` gives `2`).
- We then increment the corresponding count in the `cnt` array at index `n - '0'`.

```cpp
    for (int i = 0; i < num.size(); ++i)
        if (cnt[i] != num[i] - '0')  // Step 3: Check if the digit count matches the digit at index i
            return false;
```
- In this loop, we iterate over the string `num`. For each index `i`, we compare the count of the digit `i` (stored in `cnt[i]`) with the value of the digit at position `i` in the string (`num[i] - '0'`).
- If at any index, the count does not match the value of the digit, we immediately return `false`.

```cpp
    return true;  // Step 4: If all conditions hold, return true
}
```
- If we complete both loops without returning `false`, it means the string satisfies the "digit count" condition, and we return `true`.

### Complexity

#### Time Complexity

1. **Counting the Digits**: The first loop iterates over the entire string `num`, so its time complexity is **O(n)**, where `n` is the length of the string.
2. **Checking the Condition**: The second loop also iterates over the string, comparing the count of digits at each index with the value of the digit at that index. This loop also has a time complexity of **O(n)**.

Thus, the overall time complexity is:
- **O(n)**, where `n` is the length of the string `num`.

#### Space Complexity

We use an array `cnt[10]` to store the count of each digit, which takes up constant space (since the array size is fixed at 10). Therefore, the space complexity is:
- **O(1)**, as the space usage does not depend on the input size.

### Example Walkthrough

Let’s walk through an example to understand how the solution works in practice:

#### Example 1: `num = "1210"`

1. **Count the Digits**:
   - Initially, `cnt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}`.
   - After processing the string:
     - `cnt[1]` is incremented 2 times.
     - `cnt[2]` is incremented 1 time.
     - `cnt[0]` is incremented 1 time.
   - The final count is `cnt = {1, 2, 1, 0, 0, 0, 0, 0, 0, 0}`.

2. **Check the Condition**:
   - For `i = 0`: `cnt[0] == 1` and `num[0] == 1`, so the condition is not satisfied.
   - For `i = 1`: `cnt[1] == 2` and `num[1] == 2`, so the condition is satisfied.
   - For `i = 2`: `cnt[2] == 1` and `num[2] == 1`, so the condition is satisfied.
   - For `i = 3`: `cnt[3] == 0` and `num[3] == 0`, so the condition is satisfied.
   - Since all conditions are satisfied, we return `true`.

#### Example 2: `num = "030"`

1. **Count the Digits**:
   - Initially, `cnt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}`.
   - After processing the string:
     - `cnt[0]` is incremented 2 times.
     - `cnt[3]` is incremented 1 time.
   - The final count is `cnt = {2, 0, 0, 1, 0, 0, 0, 0, 0, 0}`.

2. **Check the Condition**:
   - For `i = 0`: `cnt[0] == 2` and `num[0] == 0`, so the condition is not satisfied. We return `false`.

### Conclusion

The solution efficiently checks if a given number (represented as a string) is a "digit count" number by using an array to count the occurrences of each digit and then comparing these counts with the digits at the respective positions. With a time complexity of **O(n)**, where `n` is the length of the string, and a constant space complexity of **O(1)**, this approach is both optimal and efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/)

---
{{< youtube kv0O7p0pRvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
