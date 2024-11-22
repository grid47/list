
+++
authors = ["grid47"]
title = "Leetcode 2490: Circular Sentence"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2490: Circular Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9Ty_eRjoDNM"
youtube_upload_date="2024-11-02"
youtube_thumbnail="https://i.ytimg.com/vi/9Ty_eRjoDNM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.size();
        if((s[0]) != (s[n - 1]))
            return false;
        for(int i = 1; i < s.size() - 1; i++) {
            if(s[i] == ' ') {
                if((s[i - 1]) != (s[i + 1]))
                    return false;                
            }
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to check whether a given string forms a "circular sentence." A string is defined as a circular sentence if:
1. The first character of the string is the same as the last character.
2. For every space in the string, the character immediately preceding the space must be the same as the character immediately following the space.

For example:
- `"abc cba"` is a circular sentence because:
  - The first character ('a') is the same as the last character ('a').
  - The characters before and after the space ('b' and 'c') are the same for both words.

However:
- `"hello world"` is **not** a circular sentence because:
  - The first character ('h') is not the same as the last character ('d').

### Approach

The problem requires us to check two conditions for a sentence:
1. **First and last character match**: The first and last characters of the sentence must be identical.
2. **Words separated by spaces**: For each space in the string, the character immediately before the space should be the same as the character immediately after the space.

To solve this problem, the approach involves:
1. Checking if the first and last characters of the string are the same.
2. Iterating through the string and for every space encountered, checking if the characters before and after the space match.
3. If both conditions are satisfied, the string is a circular sentence; otherwise, it is not.

The solution must efficiently traverse the string once while checking these conditions, which guarantees an optimal time complexity.

### Code Breakdown (Step by Step)

#### 1. **Initial Setup**

```cpp
int n = s.size();
```

- The size of the string `s` is stored in the variable `n` to avoid repeated calls to `s.size()` throughout the function.

#### 2. **Check if First and Last Characters are the Same**

```cpp
if((s[0]) != (s[n - 1]))
    return false;
```

- The first condition to check is whether the first character `s[0]` is the same as the last character `s[n - 1]`.
- If they are not the same, the string cannot be a circular sentence, so the function immediately returns `false`.

#### 3. **Iterate Through the String to Check Each Space**

```cpp
for(int i = 1; i < s.size() - 1; i++) {
    if(s[i] == ' ') {
        if((s[i - 1]) != (s[i + 1]))
            return false;                
    }
}
```

- The loop starts from the second character (`i = 1`) and goes until the second-to-last character (`i < s.size() - 1`). This avoids unnecessary checks at the boundaries (the first and last characters are already checked).
- The condition `s[i] == ' '` checks if the current character is a space.
- If a space is found, we check if the characters immediately before and after the space are the same (`s[i - 1] == s[i + 1]`).
  - If they are not the same, the function returns `false` because this violates the circular sentence condition.

#### 4. **Return True if All Checks Pass**

```cpp
return true;
```

- If all the checks pass (i.e., the first and last characters match, and the characters around each space match), the function returns `true`, indicating that the string is a circular sentence.

### Complexity Analysis

#### Time Complexity:
- The time complexity of the solution is **O(n)**, where `n` is the length of the string. This is because:
  - The function iterates through the string once to check the characters.
  - Each check (comparing characters or checking for spaces) is performed in constant time.

Thus, the time complexity is **O(n)**, where `n` is the number of characters in the string.

#### Space Complexity:
- The space complexity is **O(1)**, as the solution only uses a few integer variables (`n` and `i`) to store intermediate values and does not create any additional data structures that grow with the input size.

Thus, the space complexity is **O(1)**.

### Conclusion

This solution efficiently checks if a given string is a circular sentence by validating two key conditions:
1. The first and last characters must match.
2. For every space in the string, the characters immediately before and after the space must be identical.

The solution is optimal with a time complexity of **O(n)**, where `n` is the length of the string, and a space complexity of **O(1)**. It uses a single loop to traverse the string and makes constant-time comparisons to ensure the string meets the requirements for being a circular sentence.

This approach is simple and effective for this type of problem, ensuring that it runs efficiently even for long strings. The logic behind the solution is straightforward, involving basic string traversal and comparisons, making it both easy to understand and implement.

[`Link to LeetCode Lab`](https://leetcode.com/problems/circular-sentence/description/)

---
{{< youtube 9Ty_eRjoDNM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
