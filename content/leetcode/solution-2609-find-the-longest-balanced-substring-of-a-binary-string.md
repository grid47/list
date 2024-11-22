
+++
authors = ["grid47"]
title = "Leetcode 2609: Find the Longest Balanced Substring of a Binary String"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2609: Find the Longest Balanced Substring of a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_nyH2TA95yY"
youtube_upload_date="2023-04-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_nyH2TA95yY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zr = 0, ans = 0;
        int cnt[2] = {};
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;                    
                }
                cnt[0]++;
            } else {
                if(cnt[1] < cnt[0]) cnt[1]++;
                else {
                    cnt[0] = 0;
                    cnt[1] = 0;
                }
                ans = max(cnt[1] * 2, ans);
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the length of the longest balanced substring within a binary string. A balanced substring is one where the number of `0`s is equal to the number of `1`s, and these `0`s and `1`s appear in the correct order, i.e., all `0`s come before `1`s.

### Approach

To solve this problem efficiently, we can use a greedy approach with two counters that track the number of `0`s and `1`s in the current substring. The idea is to traverse through the string, updating the counts and checking for balanced substrings as we go. We aim to maintain a substring where the count of `0`s and `1`s is the same, and the `0`s appear before the `1`s.

### Detailed Explanation

1. **Problem Understanding**:
   - A "balanced" substring is defined as having equal numbers of `0`s and `1`s.
   - For example, in the string `"0011"`, the substring `"00"` and `"11"` together form a balanced substring.
   - However, a string like `"0101"` isn't considered balanced because the `1`s are not consecutive to the `0`s.

2. **Core Idea**:
   - We iterate over the string while keeping track of two variables:
     - `cnt[0]`: This tracks the number of consecutive `0`s.
     - `cnt[1]`: This tracks the number of consecutive `1`s.
   - Whenever we encounter a `0`, we check if there are any unmatched `1`s. If there are, we reset the counts since a balanced substring can no longer be formed starting from the current position.
   - If we encounter a `1`, we compare the counts of `1`s and `0`s. If there are fewer `1`s than `0`s, we increment the count of `1`s.
   - Each time the counts of `0`s and `1`s become equal, we update the answer (`ans`) to keep track of the maximum balanced length found.

3. **Steps Involved**:
   - Initialize `cnt[0]` and `cnt[1]` to track the counts of `0`s and `1`s, respectively.
   - Traverse the string from left to right:
     - If the current character is `0`, reset the counts if any `1`s were encountered before.
     - If the current character is `1`, check the current counts of `0`s and `1`s. If the number of `1`s is less than the number of `0`s, increment the count for `1`. Otherwise, reset the counts and start afresh.
   - After processing each character, calculate the length of the balanced substring as `cnt[1] * 2` (since both `0`s and `1`s are counted), and update the answer accordingly.

### Code Breakdown (Step by Step)

#### 1. **Initial Setup**:

```cpp
int zr = 0, ans = 0;
int cnt[2] = {};
```

- **Purpose**: 
  - `zr` is a placeholder that could be used for debugging, though it is not used in the current logic.
  - `ans` stores the length of the longest balanced substring found so far.
  - `cnt[2]` is an array with two elements to count the number of `0`s and `1`s. `cnt[0]` tracks `0`s, and `cnt[1]` tracks `1`s.

#### 2. **Loop Through the String**:

```cpp
for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') {
        if(cnt[1]) {
            cnt[0] = 0;
            cnt[1] = 0;                    
        }
        cnt[0]++;
    } else {
        if(cnt[1] < cnt[0]) cnt[1]++;
        else {
            cnt[0] = 0;
            cnt[1] = 0;
        }
        ans = max(cnt[1] * 2, ans);
    }
}
```

- **Purpose**:
  - We iterate over the string `s` to process each character.
  - If the current character is `0`:
    - We check if there are any unmatched `1`s (i.e., `cnt[1] > 0`). If so, reset both counters as the substring can no longer be balanced starting from the current position.
    - Increment the count of `0`s (`cnt[0]`).
  - If the current character is `1`:
    - If there are fewer `1`s than `0`s, increment the count of `1`s (`cnt[1]`).
    - If the count of `1`s is greater than or equal to the count of `0`s, reset the counters because the substring can't be balanced further.
  - After processing each character, calculate the current balanced substring length (`cnt[1] * 2`) and update the `ans` variable with the maximum found so far.

#### 3. **Return the Final Result**:

```cpp
return ans;
```

- **Purpose**: After iterating through the string, the variable `ans` holds the length of the longest balanced substring found. This value is returned as the result.

### Complexity Analysis

#### Time Complexity:
- **Loop through the string**: We iterate over each character in the string exactly once. Thus, the time complexity is \(O(n)\), where \(n\) is the length of the string.
- **Overall Time Complexity**: The overall time complexity of the solution is \(O(n)\), where \(n\) is the length of the input string.

#### Space Complexity:
- **Auxiliary Space**: We only use a fixed amount of extra space for the array `cnt` and the variables `zr` and `ans`, so the space complexity is \(O(1)\).

#### Conclusion:

This solution uses a greedy approach to efficiently find the longest balanced substring in a binary string. The approach processes each character once and updates the balance count of `0`s and `1`s as it goes. By using two counters (`cnt[0]` for `0`s and `cnt[1]` for `1`s), the solution ensures that the substring remains balanced, and the longest balanced substring is tracked and updated. The overall time complexity of \(O(n)\) makes this approach efficient even for larger strings, and the space complexity of \(O(1)\) ensures minimal memory usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/)

---
{{< youtube _nyH2TA95yY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
