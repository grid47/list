
+++
authors = ["grid47"]
title = "Leetcode 1400: Construct K Palindrome Strings"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1400: Construct K Palindrome Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for(char c: s)
        odd.flip(c - 'a');
        return odd.count() <= k && k <= s.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine if a given string can be divided into **k** palindromic substrings. A palindrome is a string that reads the same backward as forward, such as "racecar" or "madam". The problem requires analyzing the characters in the string to see if it's possible to form **k** such substrings. The key concept to solve this problem involves understanding the characteristics of palindromes, particularly how the frequency of characters affects the ability to form them.

### Approach

To address this problem, we need to leverage the properties of palindromes:

1. **Character Frequency Analysis**: A palindrome can have at most one character with an odd frequency (which can be placed in the middle of the palindrome). For example, the string "aabb" can form "abba" (which is a palindrome) and "aa", while "abc" cannot form any palindromic substring.

2. **Bitset Usage**: In this solution, we use a bitset to track the frequency of characters in the input string. Each bit in the bitset corresponds to a character from 'a' to 'z'. We toggle the bit corresponding to each character we encounter in the string. This will help us keep track of how many characters have an odd frequency.

3. **Checking Conditions**: After processing the string, we need to verify two conditions:
   - The number of characters with an odd frequency should be less than or equal to **k**.
   - The value of **k** should not exceed the length of the string, as you cannot have more palindromic substrings than the total number of characters.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the provided C++ code:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - We define a class `Solution` that contains our method for solving the problem.

2. **Method Signature**:
   ```cpp
       bool canConstruct(string s, int k) {
   ```
   - The method `canConstruct` takes two parameters:
     - `s`: a string for which we need to check if it can be divided into **k** palindromic substrings.
     - `k`: the number of palindromic substrings we want to form.

3. **Bitset Initialization**:
   ```cpp
           bitset<26> odd;
   ```
   - We declare a bitset of size 26 to represent the 26 lowercase letters in the English alphabet. Each bit in the bitset corresponds to a letter ('a' to 'z'), allowing us to efficiently track odd occurrences of characters.

4. **Character Frequency Counting**:
   ```cpp
           for(char c: s)
               odd.flip(c - 'a');
   ```
   - We iterate over each character `c` in the string `s`.
   - The expression `c - 'a'` gives the index of the character in the bitset (0 for 'a', 1 for 'b', ..., 25 for 'z').
   - The `flip` method toggles the corresponding bit for the character. If the bit is currently 0 (even count), it becomes 1 (odd count), and vice versa. This way, we can track how many characters have odd frequencies.

5. **Final Conditions Check**:
   ```cpp
           return odd.count() <= k && k <= s.size();
   ```
   - We check if the count of bits set to 1 in the bitset (which corresponds to characters with odd frequencies) is less than or equal to **k**.
   - Additionally, we ensure that **k** is less than or equal to the length of the string `s`. This ensures we do not ask for more palindromic substrings than the characters available.

### Complexity

- **Time Complexity**: 
  - The time complexity of the solution is \( O(n) \), where \( n \) is the length of the string `s`. This is because we perform a single pass over the string to count character frequencies and determine odd counts.

- **Space Complexity**:
  - The space complexity is \( O(1) \) since the size of the bitset is fixed at 26, regardless of the length of the input string.

### Conclusion

This implementation provides an efficient and straightforward way to determine whether a string can be partitioned into **k** palindromic substrings. By utilizing bit manipulation with a bitset, we achieve optimal performance in both time and space complexity.

#### Key Takeaways:

- **Understanding Palindromes**: The main insight is that a palindrome can have at most one character with an odd frequency.
- **Efficient Character Tracking**: The use of a bitset allows for efficient toggling of character states, leading to a concise solution.
- **Optimal Complexity**: The approach operates in linear time relative to the input size, making it suitable for large strings.

This solution demonstrates a clear understanding of string manipulation and the properties of palindromes, making it a valuable approach for similar problems in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
