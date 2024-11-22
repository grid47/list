
+++
authors = ["grid47"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2390: Removing Stars From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Qln1aXh2kvQ"
youtube_upload_date="2023-04-11"
youtube_thumbnail="https://i.ytimg.com/vi/Qln1aXh2kvQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') s[j++] = s[i];
            else {
                j--;
            }
        }
        return s.substr(0, j);
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a string `s` that may contain asterisks (`*`). Each asterisk in the string indicates the need to remove the previous character in the string. You are tasked with removing characters according to this rule and returning the resulting string. If an asterisk appears at the beginning of the string or after another asterisk, it should be ignored because there is no character to remove.

For example:
- Input: `"leet**cod*e"`
- Output: `"lecoe"`

The challenge is to process the string and efficiently remove characters based on the asterisk rules.

### Approach

To solve this problem efficiently, we need to traverse the string and handle each character depending on whether it is an asterisk or a regular character. The main idea is to maintain a pointer or an index (`j`) that will track where the characters in the final string will go.

1. **Iterate Through the String**: We loop through the string character by character.
2. **Character Handling**: 
   - If the current character is not an asterisk (`*`), we add it to the result at the position tracked by `j` and then increment `j`.
   - If the current character is an asterisk, we decrement `j`, effectively removing the last valid character added to the result (since the asterisk indicates that the previous character should be deleted).
3. **Construct the Final String**: After processing all characters in the string, the first `j` characters of the string will form the final result.

This approach ensures that we traverse the string only once, making the solution both time and space efficient.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Index Tracker
The first thing we do in the function is initialize a variable `j` to 0. This variable will act as a pointer that tracks where we should insert the next character in the result string.

```cpp
int j = 0;
```

#### Step 2: Iterate Through the String
Next, we loop over each character in the string `s` using a `for` loop. The loop runs from `i = 0` to `i < s.size()`, where `i` is the index of the current character.

```cpp
for(int i = 0; i < s.size(); i++) {
```

#### Step 3: Handle Non-Asterisk Characters
Inside the loop, we check if the current character `s[i]` is not an asterisk (`*`). If it is not an asterisk, we insert the character at the position `j` in the string and then increment `j`.

```cpp
if(s[i] != '*') s[j++] = s[i];
```

Here, `s[j++] = s[i]` means we store `s[i]` at the index `j` and then increment `j`. This allows us to build the resultant string by overwriting characters in the string `s`.

#### Step 4: Handle Asterisk Characters
If the current character is an asterisk (`*`), we need to "remove" the previous character by decrementing the `j` index. This indicates that the last valid character added to the result should be erased.

```cpp
else {
    j--;
}
```

By decrementing `j`, we essentially "undo" the last valid character insertion, simulating the removal of the character before the asterisk.

#### Step 5: Construct the Final String
After processing all the characters in the string, we now need to return the result. The final string will consist of the first `j` characters of the string `s`, which we obtain using `substr(0, j)`.

```cpp
return s.substr(0, j);
```

This returns a substring of `s` from index 0 to `j`, which contains the valid characters after all asterisks have been processed.

### Complexity

#### Time Complexity
The time complexity of this algorithm is **O(n)**, where `n` is the length of the string `s`. This is because we iterate through the string exactly once, performing constant-time operations (character comparisons and assignments) for each character in the string.

#### Space Complexity
The space complexity of this solution is **O(1)**, meaning the algorithm uses constant extra space. We only use a single variable `j` to track the position of the result string, and we modify the input string `s` in-place (without requiring additional storage for a result string).

### Conclusion

This solution efficiently solves the problem of removing characters based on asterisk rules with a single pass through the string. By maintaining a pointer `j` to track the position of the result string and modifying the string `s` in-place, we avoid the need for additional space and ensure the solution is optimal in terms of both time and space complexity.

The key to solving this problem lies in recognizing that each asterisk simply undoes the last character added to the result, and by iterating through the string and maintaining this rule, we can construct the final string without needing to repeatedly modify or rebuild the string from scratch.

The simplicity and efficiency of this solution make it an ideal approach for this problem, ensuring it works well even for long strings. The linear time complexity ensures that the solution scales well with input size, while the constant space complexity guarantees minimal memory usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---
{{< youtube Qln1aXh2kvQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
