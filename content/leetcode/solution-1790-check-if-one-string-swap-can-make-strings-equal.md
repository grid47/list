
+++
authors = ["grid47"]
title = "Leetcode 1790: Check if One String Swap Can Make Strings Equal"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1790: Check if One String Swap Can Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n4pxnAHTfeU"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/n4pxnAHTfeU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int chg = 0, cnt = 0;
        vector<int> frq1(26, 0), frq2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
            if(s1[i] != s2[i]) cnt++;
        }

        return frq1 == frq2 && (cnt == 2 || cnt == 0);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine whether two strings, `s1` and `s2`, can be considered "almost equal." Specifically, two strings are defined as almost equal if they can become identical by performing at most one swap of two characters in one of the strings. The goal is to implement a function that checks for this condition efficiently.

### Approach

To solve this problem, we can use the following approach:

1. **Character Frequency Count**: We will first count the frequency of each character (a-z) in both strings. This helps in quickly determining if the two strings have the same set of characters.

2. **Count Differences**: As we iterate through both strings, we will also count the number of positions where the characters in the two strings differ.

3. **Condition Check**: For the strings to be almost equal:
   - They must have the same frequency of characters.
   - If there are no differences (`cnt == 0`), the strings are already equal.
   - If there are exactly two differences (`cnt == 2`), we can potentially make them equal by swapping the two differing characters.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
```
- We start by defining a class `Solution` with a public method `areAlmostEqual`, which takes two strings `s1` and `s2` as input parameters.

```cpp
        int chg = 0, cnt = 0;
        vector<int> frq1(26, 0), frq2(26, 0);
```
- We initialize two integer counters: `chg` to count the number of changes (this variable is not used in the final logic) and `cnt` to count the number of positions where the characters of `s1` and `s2` differ.
- We create two frequency vectors `frq1` and `frq2` of size 26 (for each letter in the alphabet) initialized to 0 to keep track of the frequency of characters in both strings.

```cpp
        for(int i = 0; i < s1.size(); i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
            if(s1[i] != s2[i]) cnt++;
        }
```
- We loop through each character of the strings `s1` and `s2` simultaneously.
- For each character, we increment the corresponding index in the frequency vectors based on the ASCII value of the character (subtracting `'a'` converts a character to its respective index in the alphabet).
- If the characters at the same position are different, we increment the `cnt` counter.

```cpp
        return frq1 == frq2 && (cnt == 2 || cnt == 0);
    }
};
```
- Finally, we return the result of two conditions:
  - The frequency vectors `frq1` and `frq2` must be equal, indicating that both strings contain the same characters in the same quantities.
  - The count of differing positions must be either 0 (the strings are identical) or 2 (indicating that we can swap two characters to make them equal).

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the strings. This is because we are iterating through each string once to compute character frequencies and count differences.

- **Space Complexity**: The space complexity is \(O(1)\) since the size of the frequency arrays is constant (26) and does not depend on the input size.

### Conclusion

The `areAlmostEqual` function provides an efficient way to determine if two strings can be made identical with at most one swap. By leveraging character frequency counts and a simple condition check, this solution effectively reduces the problem to linear time complexity, making it suitable for larger input sizes.

This algorithm is particularly useful in applications where string manipulations and comparisons are frequent, such as in text processing, data validation, and similarity detection tasks. Understanding this method can also enhance your skills in solving similar problems in coding interviews and competitive programming, where efficiency and correctness are key.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

---
{{< youtube n4pxnAHTfeU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
