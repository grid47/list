
+++
authors = ["grid47"]
title = "Leetcode 2825: Make String a Subsequence Using Cyclic Increments"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2825: Make String a Subsequence Using Cyclic Increments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SfXj_8QoeL8"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SfXj_8QoeL8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0, n = s1.size(), m = s2.size();
        for (int i = 0; i < n && j < m; ++i)
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
                ++j;
        return j == m;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining if string `s2` can be made a subsequence of string `s1` under a specific condition: each character in `s1` can either match exactly with the corresponding character in `s2`, or it can be the "next" character or the "previous" character in a cyclic alphabet.

- The alphabet is considered cyclic, meaning after 'z' comes 'a', and before 'a' comes 'z'.
- A subsequence of a string is formed by deleting some or no characters without changing the order of the remaining characters.

In other words, we are checking if we can transform `s1` into `s2` by matching characters in a specific way while maintaining the order of characters in `s1`. Specifically, the character in `s1` can match:
1. The character in `s2` directly.
2. The next character in the alphabet (considering wrap-around from 'z' to 'a').
3. The previous character in the alphabet (considering wrap-around from 'a' to 'z').

### Approach

The approach is to iterate through both strings `s1` and `s2` and check if we can match the characters of `s1` with the characters of `s2` by the rules described. We need to ensure that the order of characters is maintained in both strings. The process can be broken down into the following steps:

1. **Initial Setup**: We will initialize two pointers, one for each string, `i` for `s1` and `j` for `s2`.
2. **Character Matching**: Iterate through `s1` with pointer `i`. For each character in `s1`, check if it matches the character in `s2` pointed by `j` directly, or if it's one character before or after it in the alphabet.
3. **Subsequence Condition**: If a match is found, move the pointer `j` to the next character in `s2`. If we have processed all characters in `s2` (i.e., `j` reaches the length of `s2`), then `s2` can be formed as a subsequence of `s1`, and we return true.
4. **Termination Condition**: If we finish iterating through `s1` and haven't matched all characters of `s2`, we return false because `s2` cannot be formed as a subsequence of `s1`.

### Code Breakdown (Step by Step)

```cpp
bool canMakeSubsequence(string s1, string s2) {
    int j = 0, n = s1.size(), m = s2.size();
```

1. **Initialization**:
   - `j = 0`: This is the pointer for string `s2`, starting from the first character.
   - `n = s1.size()`, `m = s2.size()`: These variables store the lengths of `s1` and `s2` for ease of reference.

```cpp
    for (int i = 0; i < n && j < m; ++i)
```

2. **Main Loop**:
   - The loop iterates through the string `s1` using the index `i` from `0` to `n - 1`. At the same time, we check if we've processed all of `s2` by ensuring `j < m`. If `j` reaches the length of `s2`, we know that all characters of `s2` have been matched.

```cpp
        if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
            ++j;
```

3. **Character Matching**:
   - This condition checks whether the character at `s1[i]` can match the character at `s2[j]`. There are three possibilities:
     - `s1[i] == s2[j]`: The characters match exactly.
     - `s1[i] + 1 == s2[j]`: The character in `s1` is one step before `s2[j]` in the alphabet (i.e., the next character).
     - `s1[i] - 25 == s2[j]`: The character in `s1` is one step after `s2[j]` in the alphabet (i.e., the previous character, considering cyclic behavior from 'a' to 'z' and vice versa).
   - If any of these conditions is true, it means a match is found, and we move to the next character in `s2` by incrementing `j`.

```cpp
    return j == m;
}
```

4. **Final Check**:
   - After the loop finishes, if `j == m`, it means all characters of `s2` have been matched in `s1` in order, so we return `true`. Otherwise, we return `false`, indicating that it is not possible to form `s2` as a subsequence of `s1`.

### Complexity

1. **Time Complexity**:
   - The time complexity is O(n), where `n` is the length of string `s1`. In the worst case, we need to iterate through all characters in `s1` once. The pointer `j` for `s2` only advances when a match is found, so it can never exceed the length of `s2`. Therefore, the algorithm will run in linear time with respect to the length of `s1`, which is O(n).

2. **Space Complexity**:
   - The space complexity is O(1), as we are only using a few integer variables to store the pointers and the sizes of the strings. No additional data structures are used that grow with the input size.

### Conclusion

This solution is efficient and straightforward, leveraging a single loop to iterate over `s1` while maintaining a pointer `j` to track the progress through `s2`. The use of cyclic behavior in character comparisons allows for a flexible matching condition, which is a key feature of this solution. The algorithm runs in linear time relative to the size of `s1`, making it well-suited for handling relatively large inputs efficiently. The solution’s simplicity and clarity make it easy to understand and apply to similar problems involving subsequences and character transformations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

---
{{< youtube SfXj_8QoeL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
