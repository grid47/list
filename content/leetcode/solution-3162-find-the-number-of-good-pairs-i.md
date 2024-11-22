
+++
authors = ["grid47"]
title = "Leetcode 3162: Find the Number of Good Pairs I"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3162: Find the Number of Good Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "S-Q4eFfzGNc"
youtube_upload_date="2024-05-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/S-Q4eFfzGNc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int res = 0, m = nums1.size(), n = nums2.size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(nums1[i] % (nums2[j] * k) == 0) res++;
        return res;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the **sum of the absolute differences** between the positions of identical characters in two strings, `s` and `t`. Specifically, for each character in string `s`, we need to check every character in string `t` and, if they match, calculate the absolute difference in their indices. The total sum of these absolute differences is the desired output.

### Approach

To solve the problem, we need to:
1. **Iterate Over Both Strings**: For each character in the first string `s`, we need to compare it with every character in the second string `t` to see if they match.
2. **Calculate Absolute Difference**: When we find a match, we calculate the absolute difference between the indices of the matching characters in the two strings.
3. **Accumulate the Result**: Sum all the calculated absolute differences for every match found.

The goal is to output this accumulated sum, which represents the total "permutation difference" between the two strings.

### Code Breakdown (Step by Step)

Let’s walk through the code, breaking it down step by step:

1. **Initialization**:
   - We begin by initializing a variable `sum` to zero. This variable will hold the sum of absolute differences between matching indices.
   
   ```cpp
   int sum = 0;
   ```

2. **Outer Loop (Iterating over string `s`)**:
   - We use a loop to iterate over each character in the string `s`. The loop runs from `i = 0` to `i < s.length()`. The variable `i` represents the index of the current character in string `s`.
   
   ```cpp
   for (int i = 0; i < s.length(); i++) {
   ```

3. **Inner Loop (Iterating over string `t`)**:
   - For every character `s[i]` in string `s`, we use another loop to iterate over each character in string `t`. This second loop runs from `j = 0` to `j < t.length()`. The variable `j` represents the index of the current character in string `t`.

   ```cpp
   for (int j = 0; j < t.length(); j++) {
   ```

4. **Matching Characters**:
   - Inside the inner loop, we check if the characters at the current indices `i` and `j` from `s` and `t` respectively are equal:
   
   ```cpp
   if (s[i] == t[j]) {
   ```

   - If they are equal, it means we have found a match. We then calculate the **absolute difference** between the indices `i` and `j`. This is done using the `abs` function, which returns the absolute value of the difference between `i` and `j`. This represents the "distance" between the two matching characters in the two strings.

   ```cpp
   sum += abs(i - j);
   ```

5. **Final Result**:
   - Once all the characters in both strings have been processed, the `sum` variable will hold the total sum of absolute differences between matching character positions.
   - The function then returns this sum as the final result.

   ```cpp
   return sum;
   ```

### Example Walkthrough

Let’s walk through an example to better understand the code's behavior:

#### Input:
```cpp
string s = "abc";
string t = "cba";
```

#### Process:
1. The outer loop starts by considering the first character of `s`, which is `'a'`. We then compare it with every character in `t`:
   - `s[0] == t[0]` → `'a' == 'c'` (not a match)
   - `s[0] == t[1]` → `'a' == 'b'` (not a match)
   - `s[0] == t[2]` → `'a' == 'a'` (match found at indices 0 and 2, absolute difference `abs(0 - 2) = 2`)
   
   The sum is now `2`.

2. The outer loop moves to the second character of `s`, which is `'b'`, and compares it with every character in `t`:
   - `s[1] == t[0]` → `'b' == 'c'` (not a match)
   - `s[1] == t[1]` → `'b' == 'b'` (match found at indices 1 and 1, absolute difference `abs(1 - 1) = 0`)
   
   The sum remains `2` (no change).

3. Finally, the outer loop moves to the third character of `s`, which is `'c'`, and compares it with every character in `t`:
   - `s[2] == t[0]` → `'c' == 'c'` (match found at indices 2 and 0, absolute difference `abs(2 - 0) = 2`)
   
   The sum is now `4`.

#### Output:
After the loops finish, the sum is `4`, which is returned as the final result.

### Complexity

#### Time Complexity:
- **O(m * n)**: The time complexity of the solution is **O(m * n)**, where `m` is the length of string `s` and `n` is the length of string `t`. This is because we iterate over every character in string `s` (outer loop), and for each character in `s`, we iterate over every character in string `t` (inner loop). Hence, we perform `m * n` comparisons in the worst case.

#### Space Complexity:
- **O(1)**: The space complexity is **O(1)** because we are only using a constant amount of extra space (the `sum` variable and the loop counters `i` and `j`).

### Conclusion

This solution provides an efficient way to compute the sum of absolute differences in positions of matching characters between two strings. The approach is simple yet effective, leveraging two nested loops to compare every character in `s` with every character in `t`. The solution has a linear time complexity proportional to the product of the lengths of the two strings, and it uses constant space. This makes the solution suitable for moderate-sized strings where computational efficiency is important.



[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/)

---
{{< youtube S-Q4eFfzGNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
