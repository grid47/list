
+++
authors = ["grid47"]
title = "Leetcode 777: Swap Adjacent in LR String"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 777: Swap Adjacent in LR String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/777.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/777.webp" 
    alt="A string where adjacent characters are swapped, glowing softly with each swap."
    caption="Solution to LeetCode 777: Swap Adjacent in LR String Problem"
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
    bool canTransform(string start, string end) {
        int n = start.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) 
            if (start[i] != 'X') s1 += start[i];
        for (int i = 0; i < n; ++i) 
            if (end[i] != 'X') s2 += end[i];
        if (s1 != s2) return false;

        int p1 = 0, p2 = 0;
        while(p1 < start.size() && p2 < end.size()) {
            while(p1 < start.size() && start[p1] == 'X') p1++;
            while(p2 < end.size()   && end[p2]   == 'X') p2++;

            if(p1 == start.size() && p2 == end.size()) return true;
            if(p1 == start.size() || p2 == end.size()) return false;

            if(start[p1] != end[p2]) return false;

            if(start[p1] == 'L' && p2 > p1) return false;
            if(start[p1] == 'R' && p2 < p1) return false;
            p1++;
            p2++;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks whether it's possible to transform one string, `start`, into another string, `end`, by following a specific set of transformation rules. The string consists of characters 'L', 'R', and 'X'. The transformation rules are:

1. You can move characters 'L' and 'R' left or right across the string, but they can only move in the direction that respects their inherent meaning:
   - 'L' can only move left (it cannot move right).
   - 'R' can only move right (it cannot move left).
2. The 'X' characters in the string are placeholders that can be ignored. They do not affect the transformation.
3. A character 'L' at position `i` in the `start` string can only be transformed into a character 'L' at position `j` in the `end` string if `j <= i` (i.e., 'L' can only move left). Similarly, a character 'R' at position `i` in the `start` string can only be transformed into a character 'R' at position `j` in the `end` string if `j >= i` (i.e., 'R' can only move right).

### Approach

To solve the problem, the approach involves two main steps:
1. **Check if the non-'X' characters match**: This is the first condition that must be satisfied for a transformation to be possible. We remove all 'X' characters from both `start` and `end` and compare the remaining characters. If the characters in the transformed strings don't match, we immediately return `false`.

2. **Simulate the movement of 'L' and 'R' characters**: After confirming that the non-'X' characters are in the same order, we then simulate the movement of 'L' and 'R' characters across both strings:
   - For each non-'X' character in `start`, we check if it can be moved to the corresponding position in `end` according to the movement rules for 'L' and 'R'.
   - Specifically:
     - 'L' should not appear at a position greater than the corresponding position in `end` (i.e., 'L' cannot move right).
     - 'R' should not appear at a position smaller than the corresponding position in `end` (i.e., 'R' cannot move left).

By following this procedure, we can determine if the transformation is possible.

### Code Breakdown (Step by Step)

#### Step 1: Remove 'X' Characters

```cpp
string s1, s2;
for (int i = 0; i < n; ++i) 
    if (start[i] != 'X') s1 += start[i];
for (int i = 0; i < n; ++i) 
    if (end[i] != 'X') s2 += end[i];
```

- We initialize two empty strings `s1` and `s2`, which will hold the non-'X' characters from `start` and `end` respectively.
- We iterate over both strings (`start` and `end`) and append each character to `s1` and `s2` if it is not 'X'.

#### Step 2: Compare the Non-'X' Characters

```cpp
if (s1 != s2) return false;
```

- Once we have the strings `s1` and `s2`, we check if they are equal. If they are not, we immediately return `false` because the non-'X' characters in `start` and `end` do not match, making the transformation impossible.

#### Step 3: Initialize Pointers and Start Moving Characters

```cpp
int p1 = 0, p2 = 0;
while (p1 < start.size() && p2 < end.size()) {
    while (p1 < start.size() && start[p1] == 'X') p1++;
    while (p2 < end.size() && end[p2] == 'X') p2++;
```

- We initialize two pointers `p1` and `p2` to keep track of our current positions in `start` and `end`.
- We use the `while` loops to skip over all 'X' characters in both `start` and `end`. These loops ensure that we only compare non-'X' characters.

#### Step 4: Check for Matching Characters and Movement Rules

```cpp
if (p1 == start.size() && p2 == end.size()) return true;
if (p1 == start.size() || p2 == end.size()) return false;

if (start[p1] != end[p2]) return false;

if (start[p1] == 'L' && p2 > p1) return false;
if (start[p1] == 'R' && p2 < p1) return false;
```

- After skipping over 'X' characters, we check if both `p1` and `p2` have reached the end of their respective strings. If they have, we return `true`, meaning the transformation is complete.
- If either pointer reaches the end while the other has not, we return `false` because the transformation is impossible.
- We then compare the characters at `p1` and `p2`. If the characters are different, we return `false` because we cannot transform one character into another.
- Next, we check the movement rules:
  - If `start[p1]` is 'L' and `p2 > p1`, we return `false` because 'L' cannot move to the right.
  - If `start[p1]` is 'R' and `p2 < p1`, we return `false` because 'R' cannot move to the left.

#### Step 5: Increment Pointers

```cpp
p1++;
p2++;
```

- If all conditions are met, we increment both pointers to check the next non-'X' characters.

#### Final Step: Return True if All Conditions are Satisfied

```cpp
return true;
```

- If we reach the end of both strings without violating any conditions, we return `true`, indicating that it is possible to transform `start` into `end`.

### Complexity

#### Time Complexity:

- **O(n)**: The solution iterates through both strings twice—once to remove 'X' characters and once to compare the characters and check the movement rules. This results in a linear time complexity, where `n` is the length of the strings.

#### Space Complexity:

- **O(n)**: We store the non-'X' characters from both strings in `s1` and `s2`, so the space complexity is proportional to the size of the input strings.

### Conclusion

This approach solves the problem efficiently by first checking if the non-'X' characters match and then simulating the valid movement of 'L' and 'R' characters. It ensures that we only perform necessary operations, resulting in an optimal solution with linear time and space complexity.

#### Key Insights:

- By removing 'X' characters, we simplify the problem and focus only on the positions of 'L' and 'R' characters.
- The movement rules for 'L' and 'R' are critical and help us determine if the transformation is feasible.
- The time complexity of **O(n)** ensures the solution can handle large inputs efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/swap-adjacent-in-lr-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
