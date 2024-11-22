
+++
authors = ["grid47"]
title = "Leetcode 647: Palindromic Substrings"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 647: Palindromic Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/647.webp"
youtube = "EU5xSa5ZHGY"
youtube_upload_date="2023-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/EU5xSa5ZHGY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/647.webp" 
    alt="A string where palindromic substrings glow softly, each valid palindrome softly illuminated."
    caption="Solution to LeetCode 647: Palindromic Substrings Problem"
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
    vector<vector<int>> mem;
    string s;
    int dp(int i, int j) {
        if(i >= j) return 1;
        if(mem[i][j] != -1) return mem[i][j];
        return mem[i][j] = (s[i] == s[j])? dp(i + 1, j - 1): 0;
    }
    
    int countSubstrings(string s) {
        this->s = s;
        int n = s.size();
        mem.resize(n, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        for(int j = i; j < s.size(); j++)
            ans += dp(i, j);        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to count all the palindromic substrings in a given string `s`. A substring is defined as any contiguous sequence of characters in the string, and a palindrome is a string that reads the same forward as backward. For example, the string `"aba"` contains three palindromic substrings: `"a"`, `"b"`, and `"aba"`.

Our goal is to return the total number of palindromic substrings in the string `s`.

### Approach

To solve this problem, we will use **dynamic programming (DP)**, specifically focusing on recognizing palindromic substrings and efficiently counting them. Here's how we can approach this:

1. **Understanding Palindromes**:
   - A string is a palindrome if the first and last characters are the same, and the substring in between is also a palindrome.
   - For example, `"aba"` is a palindrome because `s[0] == s[2]` and the substring `s[1]` (which is `"b"`) is trivially a palindrome.

2. **Dynamic Programming (DP)**:
   - We define `dp(i, j)` as a function that returns `1` if the substring `s[i..j]` is a palindrome and `0` otherwise.
   - The recurrence for `dp(i, j)` is:
     - If `i >= j`, then `s[i..j]` is trivially a palindrome (a single character or an empty string).
     - If `s[i] == s[j]` and `dp(i + 1, j - 1) == 1`, then `s[i..j]` is a palindrome.
     - Otherwise, it's not a palindrome.

3. **Memoization**:
   - Instead of recalculating `dp(i, j)` for the same indices repeatedly, we use memoization to store the results of subproblems.
   - We initialize a 2D memoization table `mem[i][j]` where `mem[i][j]` stores the result of whether `s[i..j]` is a palindrome.
   - Initially, we fill this table with `-1` (indicating uncalculated subproblems), and we calculate it as needed.

4. **Count Palindromic Substrings**:
   - We iterate over all possible substrings in the string using two nested loops: one for the starting index `i` and one for the ending index `j`.
   - For each pair `(i, j)`, we use the `dp(i, j)` function to determine whether the substring `s[i..j]` is a palindrome. If it is, we increment our count.

### Code Breakdown (Step by Step)

Let's break down the code step by step to understand its logic:

#### 1. **Helper Function - `dp(i, j)`**:
```cpp
int dp(int i, int j) {
    if(i >= j) return 1;  // Base case: single character or empty string
    if(mem[i][j] != -1) return mem[i][j];  // If already calculated, return the result
    return mem[i][j] = (s[i] == s[j]) ? dp(i + 1, j - 1) : 0;  // Check if characters match and inner substring is palindrome
}
```
- This function takes two indices `i` and `j` and returns `1` if the substring `s[i..j]` is a palindrome, and `0` otherwise.
- The base case is when `i >= j`, meaning we have a single character or an empty substring, which is always a palindrome.
- If `s[i] == s[j]`, the substring `s[i..j]` is a palindrome if the inner substring `s[i+1..j-1]` is also a palindrome. Thus, we recursively call `dp(i + 1, j - 1)`.
- Memoization is used to avoid recalculating the same values, making the algorithm more efficient.

#### 2. **Main Function - `countSubstrings(s)`**:
```cpp
int countSubstrings(string s) {
    this->s = s;  // Assign input string to class member
    int n = s.size();
    mem.resize(n, vector<int>(n, -1));  // Initialize memoization table with -1
    int ans = 0;  // Variable to count the palindromic substrings
    for(int i = 0; i < s.size(); i++)  // Iterate over all starting indices
        for(int j = i; j < s.size(); j++)  // Iterate over all ending indices
            ans += dp(i, j);  // Add result of dp(i, j) to count
    return ans;  // Return total number of palindromic substrings
}
```
- The `countSubstrings` function initializes the memoization table `mem` and iterates over all possible pairs of start and end indices `(i, j)` in the string `s`.
- For each pair, it calls `dp(i, j)` to check if the substring `s[i..j]` is a palindrome.
- It accumulates the results of these checks in the variable `ans`, which is eventually returned as the total count of palindromic substrings.

#### 3. **Memoization Table**:
```cpp
mem.resize(n, vector<int>(n, -1));  // Initialize memoization table with -1
```
- The memoization table `mem` is a 2D vector of size `n x n` (where `n` is the size of the string `s`), initialized to `-1`. This ensures that all subproblems start as uncomputed.
- As we calculate `dp(i, j)`, we store the result in `mem[i][j]`, so subsequent calls for the same pair `(i, j)` can return the result in constant time.

### Complexity

#### Time Complexity:
- **Filling the memoization table**: For each pair `(i, j)`, we check if `s[i] == s[j]` and recursively check if the inner substring is a palindrome. This gives a time complexity of `O(1)` for each `dp(i, j)` because of memoization.
- We iterate over all pairs `(i, j)` where `i <= j`. There are `n(n + 1) / 2` pairs, which simplifies to `O(n^2)` operations.
- Thus, the overall time complexity is **O(n^2)**.

#### Space Complexity:
- We use a 2D memoization table of size `n x n` to store the results of all subproblems. Therefore, the space complexity is **O(n^2)**.
- Additionally, we store the string `s`, but this doesn’t impact the space complexity significantly as the main space usage comes from the memoization table.

### Conclusion

This solution efficiently counts the number of palindromic substrings in a given string `s` using dynamic programming with memoization. The time complexity is **O(n^2)**, where `n` is the length of the string, and the space complexity is also **O(n^2)** due to the memoization table.

The approach leverages the properties of palindromes and ensures that we only calculate the results for each substring once. This makes it much more efficient than a brute-force solution that might involve checking each substring independently. The use of memoization optimizes the recursive solution and ensures that overlapping subproblems are not recomputed, leading to a significant performance boost. 

This solution works well for strings of moderate length and is a good example of how dynamic programming can be applied to problems involving substrings and palindromes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/palindromic-substrings/description/)

---
{{< youtube EU5xSa5ZHGY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
