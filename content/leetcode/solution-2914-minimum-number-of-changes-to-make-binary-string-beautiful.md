
+++
authors = ["grid47"]
title = "Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mzozXxrB_fk"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mzozXxrB_fk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    // time/space: O(n)/O(1)
    int minChanges(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            const char& a = s[i];
            const char& b = s[i + 1];
            if (a != b) result++;
        }        
        return result;
    }
};
{{< /highlight >}}
---

### Problem Statement

We are given a string `s` consisting of characters, and the goal is to determine the minimum number of changes required to make the string alternate between two characters. Specifically, the string should alternate between two characters, meaning that every two consecutive characters should be equal. If the characters are different at any index, one of them needs to be changed to make them equal. The task is to find how many such changes are necessary.

### Approach

We need to make changes in the string such that each pair of adjacent characters (i.e., characters at index `i` and `i+1`) should be the same. If any such pair differs, we count it as a change.

To solve this problem, we can follow these steps:

1. **Iterate Over the String in Pairs**:
   - Start by iterating over the string `s` with a step size of `2`, so that we examine two adjacent characters at a time.
   - Compare the characters at each index `i` and `i + 1`.
   - If the two characters are different (`s[i] != s[i+1]`), increment the result counter by 1, as this means a change is required to make them equal.

2. **Edge Cases**:
   - If the string has an odd length, the last character doesn’t have a pair to compare to, and no change is needed for it.

### Code Breakdown

Let's break down the code into parts:

```cpp
int minChanges(string s) {
    int result = 0;    // Variable to store the number of changes needed
    int n = s.size();  // Length of the string

    // Iterate through the string, considering pairs of consecutive characters
    for (int i = 0; i < n; i += 2) {
        const char& a = s[i];            // The character at position i
        const char& b = s[i + 1];        // The character at position i+1

        // If the two characters are different, a change is needed
        if (a != b) result++;            // Increment the result counter for a change
    }        
    return result; // Return the total number of changes required
}
```

1. **Initialization**:
   - The variable `result` is initialized to `0`, which will hold the total number of changes required.
   - The variable `n` holds the size of the string `s`.

2. **Iterating Over String**:
   - A `for` loop is used to iterate over the string with a step of `2`. The loop compares two adjacent characters at a time: `s[i]` and `s[i + 1]`.

3. **Comparison**:
   - For each pair of adjacent characters, we check if they are equal (`a == b`). If they are not, we increment the result variable by 1, as this indicates a change is needed.

4. **Return**:
   - After completing the iteration, the function returns the total count of changes required, which is stored in the `result` variable.

### Complexity

- **Time Complexity**: 
  - The time complexity of this approach is `O(n)`, where `n` is the size of the string `s`. We iterate over the string once, comparing adjacent pairs of characters.
  - Each operation within the loop (comparison and increment) takes constant time, so the overall complexity is linear with respect to the size of the string.

- **Space Complexity**:
  - The space complexity is `O(1)` because we only use a constant amount of extra space (the variables `result` and `n`), regardless of the size of the input string.

### Conclusion

The solution efficiently counts the number of changes required to make a string alternate between characters by iterating through the string in pairs and comparing them. If a pair of characters is different, a change is counted. The approach works in linear time and constant space, making it optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

---
{{< youtube mzozXxrB_fk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
