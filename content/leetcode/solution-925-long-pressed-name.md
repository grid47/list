
+++
authors = ["grid47"]
title = "Leetcode 925: Long Pressed Name"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 925: Long Pressed Name in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
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
        bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        return i == m;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine if a name can be considered validly "typed" by comparing it with a given typed string. In particular, the typed string might contain additional letters, which result from the key being "long-pressed," meaning some characters may appear consecutively more than once. To solve this, we check if the typed string can be produced by long-pressing characters from the name. If every character in the name matches with a character in the typed string, including possible repetitions in typed, we conclude it is a validly typed name.

### Approach

The problem is solved using two pointers: one iterating over `name` and the other iterating over `typed`. Here’s the approach:

1. **Pointer Setup**:
   - Let `i` point to the current position in `name` and `j` point to the current position in `typed`.
   - Both pointers start at the beginning of their respective strings.
   - `m` is the length of `name` and `n` is the length of `typed`.

2. **Traversing `typed`**:
   - We iterate through `typed` with `j`, checking if each character matches the current character in `name` pointed by `i`.
   - If `typed[j]` matches `name[i]`, it means this character is a valid character that can be part of the typed result, so we increment `i` to move to the next character in `name`.
   - If `typed[j]` does not match `name[i]`:
     - We check if it is the same as `typed[j - 1]`. If it is, then it’s a valid long-pressed character, and we continue to the next `j`.
     - If `typed[j]` is not the same as `typed[j - 1]`, we return `false` since this indicates that `typed` includes an extra character that cannot be explained by long-pressing.

3. **Final Check**:
   - After the loop, we check if `i == m`. If `i` has reached the end of `name`, it means that all characters in `name` have been successfully matched in `typed`, possibly with some characters being long-pressed. If `i` has not reached the end of `name`, this means some characters in `name` were not matched, so we return `false`.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   int i = 0, m = name.length(), n = typed.length();
   ```
   - `i` is initialized to 0 to iterate over `name`.
   - `m` and `n` are initialized to store the lengths of `name` and `typed`, respectively.

2. **Traverse the Typed String**:
   ```cpp
   for (int j = 0; j < n; ++j) {
       if (i < m && name[i] == typed[j])
           ++i;
       else if (!j || typed[j] != typed[j - 1])
           return false;
   }
   ```
   - `j` iterates through each character in `typed`.
   - **Character Match**:
     - If `name[i]` equals `typed[j]`, increment `i` to move to the next character in `name`.
   - **Long-Press Validation**:
     - If `typed[j]` doesn’t match `name[i]`, check if it matches `typed[j - 1]`. If it does, continue since it’s a valid long-press of the previous character.
     - If it doesn’t, return `false` immediately as this extra character cannot be explained by long-pressing.

3. **Final Validation**:
   ```cpp
   return i == m;
   ```
   - Return `true` if `i` has reached the end of `name`, indicating that all characters in `name` have been matched correctly in `typed`. Otherwise, return `false`.

### Complexity

1. **Time Complexity**:
   - The time complexity is **O(n)**, where `n` is the length of `typed`. The algorithm iterates over `typed` and checks each character against the characters in `name`.

2. **Space Complexity**:
   - The space complexity is **O(1)** since only a few variables are used to track the state, and no additional data structures are required for storage.

### Conclusion

This solution effectively checks if `typed` is a valid representation of `name` when long-pressing is considered. By using a two-pointer approach, it ensures each character in `name` has a matching character in `typed`, including cases where characters are repeated due to long-pressing. This approach is efficient with a linear time complexity, making it suitable for handling long strings. The solution handles edge cases such as unmatched characters, initial characters without previous values, and complete matches, ensuring robust handling of various inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/long-pressed-name/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
