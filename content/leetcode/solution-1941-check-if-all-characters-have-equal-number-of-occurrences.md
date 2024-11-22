
+++
authors = ["grid47"]
title = "Leetcode 1941: Check if All Characters Have Equal Number of Occurrences"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1941: Check if All Characters Have Equal Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "PG9qfNf5vLw"
youtube_upload_date="2021-07-24"
youtube_thumbnail="https://i.ytimg.com/vi/PG9qfNf5vLw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {}, m_cnt = 0;
        for (auto ch : s)
            m_cnt = max(m_cnt, ++cnt[ch - 'a']);
        return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to determine whether all characters in a given string occur the same number of times. For example, in the string `"aabbcc"`, each character appears exactly twice, so the output would be `true`. However, in the string `"aaabb"`, the character `'a'` appears three times while `'b'` appears twice, resulting in a `false` output. 

### Approach

To solve this problem, we need to follow these steps:

1. **Count Character Frequencies**: We will create an array to count the occurrences of each character in the string. Since the string consists of lowercase English letters only, we can use a fixed-size array of length 26 to represent the counts for each letter.

2. **Identify Maximum Count**: As we count the characters, we will keep track of the maximum occurrence of any character found.

3. **Check for Consistency**: Finally, we will verify if all non-zero counts are equal to this maximum count. If all characters that occur in the string appear the same number of times, we return `true`; otherwise, we return `false`.

### Code Breakdown (Step by Step)

Let's break down the provided code step-by-step:

```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
```
Here, we define a class named `Solution` and declare a public member function called `areOccurrencesEqual`, which takes a string `s` as its parameter.

```cpp
        int cnt[26] = {}, m_cnt = 0;
```
We initialize an array `cnt` of size 26 to store the count of each character, where the index corresponds to the letters `a` through `z` (with `a` at index 0, `b` at index 1, and so on). The variable `m_cnt` is initialized to zero and will keep track of the maximum count of any character.

```cpp
        for (auto ch : s)
            m_cnt = max(m_cnt, ++cnt[ch - 'a']);
```
This loop iterates over each character `ch` in the string `s`. For each character, we increment its count in the `cnt` array. The expression `ch - 'a'` computes the index for the character (for example, `'a'` becomes 0, `'b'` becomes 1, etc.). We update `m_cnt` to be the maximum of its current value and the newly updated count of the character.

```cpp
        return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
```
Finally, we use the `all_of` function to check whether all the counts in the `cnt` array either equal zero (for characters not present in the string) or match the maximum count `m_cnt`. The lambda function takes each count `t` as an argument and checks if `t` is either zero or equal to `m_cnt`. If this condition holds for all elements in `cnt`, `all_of` returns `true`; otherwise, it returns `false`.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the string `s`. This is because we traverse the string once to count the occurrences and then check the counts in a fixed-size array.

- **Space Complexity**: The space complexity is \(O(1)\) since we are using a fixed-size array of length 26 regardless of the input size. This means our space usage does not scale with the input size.

### Conclusion

The provided solution efficiently determines if all characters in a string occur the same number of times by counting their occurrences and verifying consistency. The algorithm is both time-efficient and space-efficient, making it suitable for processing strings of varying lengths.

### Key Features

1. **Direct Character Counting**: The use of a simple array for counting character frequencies simplifies the logic and reduces the overhead compared to using a map or dictionary.

2. **Single Pass Calculation**: The solution counts character frequencies and identifies the maximum in a single pass over the string, followed by a quick check for uniformity.

3. **Lambda Functions**: Utilization of modern C++ features such as lambda functions enhances readability and conciseness.

### Use Cases

This function can be applied in various scenarios, such as:

- **Data Validation**: Checking if input data has uniform distributions, which may be useful in scenarios like cryptographic analysis or game design where balanced character usage is crucial.
  
- **Statistical Analysis**: Validating datasets to ensure certain properties hold true, such as balanced occurrences in experimental results.

### Implementation Considerations

When implementing this function, consider:

- **Input Validation**: Ensure that the input string is not null or empty before processing.

- **Case Sensitivity**: The current implementation assumes that the input string only contains lowercase letters. If input can include uppercase letters or other characters, additional handling might be required.

- **Performance Testing**: Test the performance with long strings, especially those with repeated characters to ensure the function handles large inputs gracefully.

This breakdown not only explains how the code functions but also discusses its potential applications and considerations for real-world usage, making it an excellent resource for anyone looking to understand or implement this algorithm.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/)

---
{{< youtube PG9qfNf5vLw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
