
+++
authors = ["grid47"]
title = "Leetcode 2414: Length of the Longest Alphabetical Continuous Substring"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2414: Length of the Longest Alphabetical Continuous Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TBVr58ynqsI"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/TBVr58ynqsI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int x = 1, ans = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i -1] +1) {
                x++;
            } else x = 1;
            ans = max(x, ans);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the length of the longest continuous substring of a given string `s`, where each character in the substring follows a continuous increasing order. This means that for a valid substring, each character should be one greater than the previous character in terms of their ASCII values.

For example:
- Given the string `"abc"`, the longest continuous increasing substring is `"abc"` with a length of 3.
- Given the string `"abzcd"`, the longest continuous increasing substring is `"ab"` with a length of 2 because `"z"` breaks the increasing pattern.

### Approach

The task is to find the longest substring where each character follows an increment pattern (i.e., the ASCII value of each character is one more than the previous character). To achieve this, we can iterate through the string while keeping track of the current length of the valid increasing substring. If a character is not in the expected continuous increasing order, we reset the length counter.

The solution proceeds as follows:
1. We initialize two variables:
   - `x` to track the length of the current increasing substring.
   - `ans` to keep track of the maximum length found so far.
   
2. We iterate over the string starting from the second character, comparing each character with the previous one:
   - If the current character is one greater than the previous character (i.e., `s[i] == s[i - 1] + 1`), we increase the current length counter `x`.
   - Otherwise, we reset `x` to 1, as the increasing pattern has been broken.

3. After each comparison, we update the result `ans` with the maximum value between the current length `x` and the previous maximum `ans`.

4. At the end of the loop, `ans` will hold the length of the longest continuous increasing substring.

### Code Breakdown (Step by Step)

#### 1. Initialization

```cpp
int x = 1, ans = 1;
```
- We initialize two variables:
  - `x` is set to 1 because the minimum length of any valid substring is at least 1.
  - `ans` is also set to 1 to store the maximum length of any increasing substring found during the iteration.

#### 2. Iteration Through the String

```cpp
for(int i = 1; i < s.size(); i++) {
    if(s[i] == s[i - 1] + 1) {
        x++;
    } else x = 1;
    ans = max(x, ans);
}
```
- We start a loop from `i = 1` (the second character) and go through the entire string.
- Inside the loop:
  - We check if the current character `s[i]` is one greater than the previous character `s[i-1]` (`s[i] == s[i - 1] + 1`). If so, we increment `x` because we are still in a continuous increasing substring.
  - If the characters are not in the expected order (i.e., `s[i] != s[i - 1] + 1`), we reset `x` to 1 because the current substring has broken the increasing order, and the new potential substring starts with the current character.
  
- After each check, we update `ans` to store the maximum length of any valid substring found so far.

#### 3. Return the Result

```cpp
return ans;
```
- Once the loop completes, the `ans` variable contains the length of the longest continuous increasing substring, which is returned as the result.

### Complexity

#### Time Complexity:
- The time complexity of this solution is \( O(n) \), where `n` is the length of the input string `s`. We only need to iterate through the string once, comparing each character with its predecessor. This makes the solution linear in time complexity.

#### Space Complexity:
- The space complexity is \( O(1) \), because we only use a constant amount of extra space for the variables `x` and `ans`. We don't use any additional data structures that grow with the input size.

### Conclusion

The solution effectively solves the problem by using a single pass through the string, maintaining the current length of the increasing substring and updating the maximum length as needed. The simplicity of the approach, with just two variables for tracking the current and maximum lengths, ensures that both time and space complexities are optimal. This solution is efficient and scalable, handling even the largest inputs within the problem constraints. The code is both easy to understand and elegant, making it a reliable and fast approach to solving the problem of finding the longest continuous increasing substring.

[`Link to LeetCode Lab`](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/)

---
{{< youtube TBVr58ynqsI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
