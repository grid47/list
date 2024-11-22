
+++
authors = ["grid47"]
title = "Leetcode 2645: Minimum Additions to Make Valid String"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2645: Minimum Additions to Make Valid String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7IAA0sdeACw"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7IAA0sdeACw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int addMinimum(string word) {
        int exp = 0, res = 0;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(exp == (word[i] - 'a')) {
                exp = (exp + 1) % 3;
                continue;
            }
            while(exp != (word[i] - 'a')) {
                res++;
                exp = (exp + 1) % 3;
            }
            exp = (exp + 1) % 3;            
            // cout << i << " " << res << " " << exp << "\n";
        }
        if(word[n - 1] == 'a') res += 2;
        if(word[n - 1] == 'b') res += 1;
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to add the minimum number of characters to a given string `word` such that the string alternates between the letters `'a'`, `'b'`, and `'c'` in that order (i.e., `'a' -> 'b' -> 'c' -> 'a' -> 'b' ...`). The string may contain any of the letters `'a'`, `'b'`, and `'c'`, and we are allowed to add extra characters to make the sequence follow the repeating pattern of 'abc'. The task is to determine the minimum number of characters that must be added to `word` to make it match this pattern.

### Approach

To solve this problem, we need to follow these steps:

1. **Initialize the state**:
   - We will start by keeping track of the current expected character (either `'a'`, `'b'`, or `'c'`) as we process each character in `word`.
   - We maintain a counter `res` that counts how many characters need to be added to achieve the desired pattern.

2. **Iterate through the string**:
   - We will loop through each character in `word`, and for each character:
     - Check if it matches the expected character.
     - If it does match, we update the expected character (since the next character in the pattern should follow the repeating sequence 'abc').
     - If it doesn't match the expected character, we add characters until we match the expected character and update the counter.

3. **Edge Handling**:
   - If the last character in the string `word` is `'a'` or `'b'`, we need to account for additional characters that should come after it to complete the repeating pattern.

4. **Final result**:
   - The result will be the total number of characters we added to the string.

### Code Breakdown

Let's break down the code step-by-step:

1. **Variable Initialization**:
   ```cpp
   int exp = 0, res = 0;
   int n = word.size();
   ```
   - `exp` keeps track of the expected character in the pattern (`0` for `'a'`, `1` for `'b'`, and `2` for `'c'`).
   - `res` is the variable that counts the number of characters we need to add to make the string match the pattern.
   - `n` is the size of the input string `word`.

2. **Main Loop to Process Each Character**:
   ```cpp
   for(int i = 0; i < n; i++) {
       if(exp == (word[i] - 'a')) {
           exp = (exp + 1) % 3;
           continue;
       }
       while(exp != (word[i] - 'a')) {
           res++;
           exp = (exp + 1) % 3;
       }
       exp = (exp + 1) % 3;
   }
   ```
   - The loop iterates through each character in the string `word`.
   - The condition `if(exp == (word[i] - 'a'))` checks if the current character matches the expected character:
     - If it matches, we move on to the next expected character in the cycle (`'a' -> 'b' -> 'c' -> 'a'`).
   - If it doesn't match, the `while(exp != (word[i] - 'a'))` loop adds the required characters to match the expected character. After adding each character, the expected character is updated.

3. **Handling Edge Cases (Final Character)**:
   ```cpp
   if(word[n - 1] == 'a') res += 2;
   if(word[n - 1] == 'b') res += 1;
   return res;
   ```
   - After processing all characters in `word`, we check the last character of the string:
     - If the last character is `'a'`, we need two additional characters (`'b'` and `'c'`) to complete the repeating sequence.
     - If the last character is `'b'`, we need one additional character (`'c'`) to complete the pattern.
   - The final value of `res` is returned, which represents the total number of characters added.

### Example Walkthrough

#### Example 1:

Let’s consider the input `word = "ab"`:

1. Initially, `exp = 0` (expecting `'a'`) and `res = 0`.
2. We start with the first character `'a'`:
   - Since `exp = 0` (expecting `'a'`), it matches, so we move to the next expected character, `'b'` (`exp = 1`).
3. The second character is `'b'`:
   - Since `exp = 1` (expecting `'b'`), it matches, so we move to the next expected character, `'c'` (`exp = 2`).
4. Now, the string ends, and the last character is `'b'`. We need to add 1 character (`'c'`) to complete the sequence.
5. The final result is `res = 1`.

#### Example 2:

Let’s consider the input `word = "abc"`:

1. Initially, `exp = 0` (expecting `'a'`) and `res = 0`.
2. The first character is `'a'`:
   - Since `exp = 0` (expecting `'a'`), it matches, so we move to the next expected character, `'b'` (`exp = 1`).
3. The second character is `'b'`:
   - Since `exp = 1` (expecting `'b'`), it matches, so we move to the next expected character, `'c'` (`exp = 2`).
4. The third character is `'c'`:
   - Since `exp = 2` (expecting `'c'`), it matches, so we move back to the next expected character, `'a'` (`exp = 0`).
5. Now, the string ends, and no extra characters are needed.
6. The final result is `res = 0`.

### Time Complexity

The time complexity of this solution is **O(n)**, where `n` is the length of the string `word`.

- The solution involves a single pass through the string, with constant-time operations for each character (checking conditions and updating the expected character). Therefore, the overall time complexity is linear in terms of the size of the input string.

### Space Complexity

The space complexity is **O(1)**, as we are only using a few integer variables (`exp`, `res`, `n`), and no additional data structures proportional to the input size are used.

### Conclusion

The algorithm efficiently solves the problem by iterating over the string `word` and counting how many characters need to be added to match the expected repeating pattern `'abc'`. By maintaining the expected character in the cycle and using a counter to track how many characters are added, the algorithm ensures that we add the minimum number of characters to achieve the desired pattern. The approach is optimal with a time complexity of **O(n)** and a space complexity of **O(1)**, making it suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/)

---
{{< youtube 7IAA0sdeACw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
