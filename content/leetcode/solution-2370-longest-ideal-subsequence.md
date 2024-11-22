
+++
authors = ["grid47"]
title = "Leetcode 2370: Longest Ideal Subsequence"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2370: Longest Ideal Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gR1E2oLQYSY"
youtube_upload_date="2024-04-25"
youtube_thumbnail="https://i.ytimg.com/vi/gR1E2oLQYSY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for(auto &i: s) {
            for(int j = i - k; j <= i + k; j++)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the length of the longest ideal string that can be formed from a given string `s`, where the absolute difference between the ASCII values of consecutive characters is at most `k`. Specifically, you are given a string `s` and an integer `k`, and you must find the longest subsequence of characters from `s` where for any two consecutive characters `x` and `y` in the subsequence, the condition `|x - y| <= k` holds true.

### Approach

This problem can be solved using dynamic programming (DP). We can iterate over each character of the string and track the longest subsequence that can end with each possible character. We use a DP array to store the length of the longest ideal subsequence that can end with each character.

The key idea is as follows:

1. **Define the DP state**: Let `dp[i]` represent the length of the longest ideal subsequence that ends with the character `i` (where `i` represents the ASCII value of the character).
2. **Transition between states**: For each character in the string, check for all possible previous characters (those within the range of `k` differences in ASCII value) and update the `dp` array based on the maximum subsequence length.
3. **Final Answer**: The result will be the maximum value in the `dp` array, which will represent the length of the longest ideal subsequence across all possible characters.

### Code Breakdown (Step by Step)

1. **Class Definition**:
    ```cpp
    class Solution {
    public:
        int longestIdealString(string s, int k) {
    ```
    The `Solution` class contains the method `longestIdealString` that takes two parameters: a string `s` and an integer `k`.

2. **Initialization**:
    ```cpp
        int dp[150] = {}, res = 0;
    ```
    We initialize an array `dp` of size 150 (since there are 150 possible ASCII values for lowercase English letters from 'a' to 'z'). The `dp` array is used to store the length of the longest ideal subsequence that can end with each character. The `res` variable is used to store the maximum length of the ideal subsequence encountered during the iteration over the string.

3. **Iterate over the String**:
    ```cpp
        for(auto &i: s) {
    ```
    We iterate through each character `i` in the string `s`. Here, `auto &i` ensures that we are referencing the character directly and modifying it if necessary.

4. **Update DP Array for Each Character**:
    ```cpp
            for(int j = i - k; j <= i + k; j++)
                dp[i] = max(dp[i], dp[j]);
    ```
    For each character `i`, we check all characters within the range of `k` differences in ASCII value. Specifically, we iterate over all values of `j` from `i - k` to `i + k`, which represent the previous characters that can be part of the subsequence. For each such character `j`, we update `dp[i]` to be the maximum of its current value and the value of `dp[j]`. This means that the longest subsequence ending with character `i` can be extended by adding the character `i` to the subsequence that ends with one of the characters in the range `[i - k, i + k]`.

5. **Update the Result**:
    ```cpp
            res = max(res, ++dp[i]);
    ```
    After updating `dp[i]`, we increment it by 1 (because we are including the current character `i` in the subsequence), and then we update `res` to be the maximum of the current value of `res` and `dp[i]`. This ensures that we keep track of the maximum subsequence length encountered during the iteration.

6. **Return the Result**:
    ```cpp
        return res;
    }
    ```
    After iterating over all characters in the string, the final value of `res` contains the length of the longest ideal subsequence, and we return this value.

### Complexity

1. **Time Complexity**:
    - The outer loop iterates over each character in the string `s`. The string has `n` characters, so this loop runs `O(n)` times.
    - For each character, the inner loop checks all characters in the range `[i - k, i + k]`. Since the size of this range is at most `2k + 1` (depending on the value of `k`), the inner loop runs at most `2k + 1` times for each character.
    
    Therefore, the overall time complexity is **O(n * (2k + 1))**, where `n` is the length of the string `s` and `k` is the maximum allowed difference in ASCII values between two consecutive characters.

2. **Space Complexity**:
    - The `dp` array has a fixed size of 150, which stores the length of the longest ideal subsequence for each possible character (from 'a' to 'z'). Therefore, the space complexity is **O(150)**, which is constant and can be considered as **O(1)**.
    - The space complexity for the string `s` is **O(n)** because we need to store the input string.

### Conclusion

This approach efficiently solves the problem of finding the longest ideal subsequence in a string by using dynamic programming. The `dp` array tracks the length of the longest subsequence that can end with each character, and the algorithm iterates over the string to update the subsequences dynamically. The solution handles the constraints effectively and has a time complexity of **O(n * (2k + 1))**, making it suitable for typical input sizes in competitive programming. The space complexity is constant with respect to the size of the `dp` array, which is small and independent of the string length.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-ideal-subsequence/description/)

---
{{< youtube gR1E2oLQYSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
