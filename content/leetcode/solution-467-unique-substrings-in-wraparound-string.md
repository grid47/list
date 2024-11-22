
+++
authors = ["grid47"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2024-09-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 467: Unique Substrings in Wraparound String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/467.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/467.webp" 
    alt="A glowing string where unique substrings wrap around and light up as they form distinct patterns."
    caption="Solution to LeetCode 467: Unique Substrings in Wraparound String Problem"
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
    int findSubstringInWraproundString(string p) {
        vector<int> len(26, 0);
        int cur = 1;
        len[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); i++) {
            if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
            else cur = 1;
            len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
        }
        return accumulate(len.begin(), len.end(), 0);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the number of unique substrings that can be formed from a string `p` in a wraparound string. A wraparound string is one where after the last character, the string wraps around to the first character in a cyclic manner. The substrings we are interested in must be contiguous, and they need to follow the wraparound rule. The goal is to determine how many distinct substrings can be created from such a string.

### Approach

To solve the problem efficiently, we must think about how we can utilize the cyclic nature of the string and the fact that substrings can overlap. Instead of explicitly generating all substrings and checking for uniqueness, we can leverage dynamic programming (DP) to keep track of the longest possible substring that ends at each character. The key observation is that substrings formed from a continuous sequence of consecutive characters in the alphabet (in a wraparound manner) should be handled effectively using a linear scan.

#### Key Insights:
1. **Wraparound Substrings**: If two consecutive characters in the string `p` form a valid subsequence in a cyclic manner, we should treat them as a part of a larger valid substring.
   - For example, if `p = "abc"`, then the substrings `"a"`, `"b"`, `"c"`, `"ab"`, `"bc"`, and `"abc"` are all valid.
   - Similarly, for wraparound behavior, the substring `"z"` followed by `"a"` should be treated as part of a larger substring.

2. **Dynamic Programming**: We can use a DP approach where:
   - We maintain an array `len[26]` of size 26 to store the maximum length of a substring that ends with each character (`'a'`, `'b'`, ..., `'z'`).
   - As we iterate through the string `p`, we calculate the length of substrings that end at each character, considering the cyclic nature of the string.

3. **Accumulate Results**: The total number of unique substrings can be calculated by summing the values stored in the `len` array, which represent the maximum lengths of substrings that end at each character.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Data Structures

```cpp
vector<int> len(26, 0);
int cur = 1;
len[p[0] - 'a'] = 1;
```

- We initialize a vector `len` of size 26, where each element corresponds to a character of the alphabet. Initially, all values are set to 0.
- We also initialize `cur` to 1, representing the current length of the substring that we are examining.
- The first character in the string `p` is considered as a valid substring of length 1, so we set `len[p[0] - 'a'] = 1`.

#### Step 2: Iterate Through the String

```cpp
for(int i = 1; i < p.size(); i++) {
    if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
    else cur = 1;
    len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
}
```

- We start iterating over the string `p` from the second character (index 1).
- For each character `p[i]`, we check if it forms a valid substring with the previous character `p[i - 1]` based on the wraparound condition.
  - The expression `(p[i] + 26 - p[i - 1]) % 26 == 1` checks whether the characters `p[i]` and `p[i - 1]` are consecutive in the alphabet (considering wraparound).
  - If this condition holds true, it means that we can extend the current valid substring, so we increment the `cur` value.
  - If the condition doesn't hold, we reset `cur` to 1 because we cannot extend the current substring.
- We then update `len[p[i] - 'a']` to store the maximum length of a substring that ends with the character `p[i]`.

#### Step 3: Sum the Results

```cpp
return accumulate(len.begin(), len.end(), 0);
```

- After iterating through the string and updating the `len` array, we simply sum all the values in `len` using `accumulate`. Each value in `len` represents the maximum length of substrings that end with the corresponding character. By summing these values, we get the total number of distinct substrings that can be formed from the string `p` under the wraparound constraint.

### Complexity

#### Time Complexity:
- **Iterating Through the String**: We iterate through the string `p` once, which takes `O(n)` time, where `n` is the length of the string.
- **Accumulate**: We perform a sum operation over the array `len`, which takes `O(26)` time since the array has a fixed size of 26.
- **Overall Time Complexity**: The total time complexity of the solution is `O(n)`, where `n` is the length of the string `p`.

#### Space Complexity:
- **Space for `len` Array**: We use an array `len` of size 26 to store the maximum length of substrings ending with each character, which takes `O(1)` space (constant space).
- **Overall Space Complexity**: The space complexity is `O(1)` because we only use a constant amount of extra space for the `len` array.

### Conclusion

This solution efficiently computes the number of unique substrings in the wraparound string using a dynamic programming approach. The algorithm processes the string in a single pass (`O(n)` time complexity) and uses constant space (`O(1)` space complexity), making it highly efficient. The key insight is to track the longest valid substring that ends at each character and sum the results to get the total number of unique substrings. This approach ensures that we consider all possible wraparound substrings without explicitly generating each one, making it optimal for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
