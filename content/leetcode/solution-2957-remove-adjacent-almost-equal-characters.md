
+++
authors = ["grid47"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2957: Remove Adjacent Almost-Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PjIWjV-Y5YQ"
youtube_upload_date="2023-12-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PjIWjV-Y5YQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int i = 1, cnt = 0;
        while(i < n) {
            if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
            else i++;
        }
        return cnt;        
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks to remove "almost equal" characters from a string. Two adjacent characters are considered almost equal if:
- They are the same character (i.e., `s[i] == s[i - 1]`).
- They differ by exactly 1 in their ASCII values (i.e., `abs(s[i] - s[i - 1]) == 1`).

The goal is to remove all pairs of such characters, counting how many such pairs exist, and returning the total count of removals. Once a pair is removed, skip the next adjacent character because it's part of a valid removal operation.

### Approach:
This problem can be solved using a **greedy approach** where we traverse the string while checking each pair of adjacent characters:
1. For each character, check if it forms a valid "almost equal" pair with the previous character.
2. If it does, increment a counter (`cnt`), and skip the next character by advancing the index by 2.
3. If it doesn't form a valid pair, simply move to the next character.
4. The process continues until the entire string is processed.

This approach ensures that we efficiently check for pairs and remove them, while also keeping track of how many pairs we removed.

### Code Breakdown:

#### 1. **Initialization**:
The first step in the code is to initialize two variables:
- `n`: The length of the string `s`, which will be used to ensure we do not exceed the string bounds.
- `i`: A pointer (index) used to traverse through the string.
- `cnt`: A counter initialized to 0. This will track how many "almost equal" character pairs we remove from the string.

```cpp
int n = s.size();
int i = 1, cnt = 0;
```
- `i` starts from `1` because we will compare each character `s[i]` with its previous character `s[i - 1]`.
- `cnt` will count the number of pairs removed.

#### 2. **While Loop to Traverse the String**:
A `while` loop is used to traverse the string `s`. The loop continues until `i` is less than `n`, ensuring that we do not go beyond the string length.

```cpp
while (i < n) {
    // Check if current and previous characters are almost equal
    if (s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) {
        cnt++, i += 2;  // If so, increment cnt and skip the next character
    }
    else {
        i++;  // Otherwise, just move to the next character
    }
}
```

- Inside the loop, we check if the character `s[i]` is either the same as the previous character `s[i-1]` or if the difference between their ASCII values is 1 (i.e., `abs(s[i] - s[i - 1]) == 1`).
- If either of these conditions is true, we have found an "almost equal" pair. Therefore:
  - Increment the `cnt` counter to signify that we've removed a pair.
  - Skip the next character by incrementing `i` by `2` (since both characters are part of the removal).
- If the characters don't form a valid pair, we simply move to the next character by incrementing `i` by 1.

#### 3. **Return the Result**:
Once the loop is finished, the total number of "almost equal" pairs removed is stored in `cnt`. The final result is returned as the output.

```cpp
return cnt;
```

This value represents the total number of removals.

### Complexity:

#### Time Complexity:
- **Traversal of the string**: The string is traversed once, and for each character, we either increment `i` by 1 or 2. Thus, the total number of iterations is linear, i.e., O(n), where `n` is the length of the string.
- The operations inside the loop (such as checking for equality or the difference between ASCII values) are constant time operations, i.e., O(1).
  
Thus, the **time complexity** is **O(n)**, where `n` is the length of the input string `s`.

#### Space Complexity:
- We only use a few extra variables (`n`, `i`, and `cnt`), and the space used does not depend on the input size. Therefore, the **space complexity** is **O(1)**, i.e., constant space.

### Conclusion:
This solution efficiently solves the problem by using a greedy approach with a single pass through the string. It correctly handles the removal of "almost equal" character pairs while maintaining a low time complexity of O(n) and constant space complexity. This approach ensures that the problem is solved efficiently even for large input strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---
{{< youtube PjIWjV-Y5YQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
