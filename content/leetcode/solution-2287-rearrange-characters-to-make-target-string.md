
+++
authors = ["grid47"]
title = "Leetcode 2287: Rearrange Characters to Make Target String"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2287: Rearrange Characters to Make Target String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Mgtl8CIIWX4"
youtube_upload_date="2022-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Mgtl8CIIWX4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> targetFreq ; 
        for(auto a : target) {
             targetFreq[a] ++;
        }
        unordered_map<char , int> sentFreq ; 
        for(auto a : s) {
            sentFreq[a] ++ ; 
        }
        int mn = INT_MAX  ; 
        for(auto a : targetFreq ) {
             mn = min(mn , sentFreq[a.first]/a.second); 
        }
        return mn ; 
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine how many times you can rearrange the characters of a given string `s` to form the string `target`. In other words, you need to find the maximum number of times the string `target` can be created by using characters from string `s`. Each character in `s` can only be used once per rearrangement.

### Approach

The problem can be efficiently solved by counting the frequencies of characters in both the string `s` and the target string. Once we know how many times each character appears in both strings, we can determine how many times we can create the target string by using characters from `s`. The key steps are as follows:

1. **Count the Frequencies of Characters in `target`**: 
   - For each character in `target`, we need to know how many times it appears. This helps us understand the minimum number of times we need that character to form one complete copy of `target`.

2. **Count the Frequencies of Characters in `s`**: 
   - For each character in `s`, we count how many times it appears. This will tell us how many copies of the characters are available in `s` for rearranging.

3. **Determine How Many Complete Rearrangements of `target` Can Be Formed**:
   - For each character in `target`, we check how many times it appears in `s`. The number of complete rearrangements of `target` is determined by the limiting character — i.e., the character in `target` for which there are the fewest available copies in `s` compared to the number required for one complete rearrangement of `target`.

4. **Return the Result**: 
   - The result is the minimum number of times the characters of `target` can be rearranged to form a complete `target`.

### Code Breakdown (Step by Step)

The code implementation follows the steps mentioned in the approach:

```cpp
unordered_map<char,int> targetFreq;
for(auto a : target) {
    targetFreq[a]++; // Count frequency of each character in the target string
}
```
- **`targetFreq`**: This is an unordered map (hash map) that stores the frequency of each character in the `target` string.
- We iterate over each character in `target`, and for each character, we increase its frequency count in the `targetFreq` map. This helps us know how many of each character is required to form one occurrence of the `target` string.

```cpp
unordered_map<char, int> sentFreq;
for(auto a : s) {
    sentFreq[a]++; // Count frequency of each character in the input string `s`
}
```
- **`sentFreq`**: This is another unordered map that stores the frequency of each character in the string `s`.
- We iterate over each character in `s` and update the frequency count in `sentFreq`. This map will give us an idea of how many copies of each character we have in `s`.

```cpp
int mn = INT_MAX;
for(auto a : targetFreq) {
    mn = min(mn, sentFreq[a.first] / a.second); // Determine the minimum number of complete target strings that can be formed
}
```
- **`mn`**: This variable is initialized to `INT_MAX` (the largest possible integer value). It keeps track of the minimum number of complete rearrangements of `target` that can be formed using characters from `s`.
- For each character in `targetFreq`, we calculate how many times the character from `target` can be used based on its frequency in `s`. Specifically, we take the quotient of `sentFreq[a.first] / a.second` for each character `a.first` in `targetFreq` and `a.second` (the number of times it appears in `target`). 
  - This represents how many times we can use the current character from `s` to form the target string. 
  - We take the minimum of these quotients because the overall number of times we can form `target` depends on the most limiting character (i.e., the one that is available the least).

```cpp
return mn; // Return the result: the maximum number of times the target can be formed
```
- Finally, after processing all characters in `target`, we return `mn`, which holds the maximum number of complete rearrangements of `target` that can be made using characters from `s`.

### Example Walkthrough

Let's go through a step-by-step walkthrough of how the solution works using an example.

**Example 1**:
```cpp
string s = "iloveleetcode";
string target = "love";
```

1. **Count the characters in `target`**:
   - `targetFreq` will look like: `{'l': 1, 'o': 1, 'v': 1, 'e': 1}`

2. **Count the characters in `s`**:
   - `sentFreq` will look like: `{'i': 1, 'l': 1, 'o': 2, 'v': 1, 'e': 3, 't': 2, 'c': 1, 'd': 1}`

3. **Determine how many complete target strings can be formed**:
   - For `'l'`: We need 1, but we have 1, so we can use it 1 time.
   - For `'o'`: We need 1, but we have 2, so we can use it 2 times.
   - For `'v'`: We need 1, but we have 1, so we can use it 1 time.
   - For `'e'`: We need 1, but we have 3, so we can use it 3 times.

4. **Calculate the minimum value**:
   - The minimum number of complete rearrangements is `min(1, 2, 1, 3)` which equals 1.

So, the result is `1` — we can form one complete rearrangement of `"love"` from the characters in `"iloveleetcode"`.

**Example 2**:
```cpp
string s = "abcabc";
string target = "abc";
```

1. **Count the characters in `target`**:
   - `targetFreq`: `{'a': 1, 'b': 1, 'c': 1}`

2. **Count the characters in `s`**:
   - `sentFreq`: `{'a': 2, 'b': 2, 'c': 2}`

3. **Determine how many complete target strings can be formed**:
   - For `'a'`: We need 1, and we have 2, so we can use it 2 times.
   - For `'b'`: We need 1, and we have 2, so we can use it 2 times.
   - For `'c'`: We need 1, and we have 2, so we can use it 2 times.

4. **Calculate the minimum value**:
   - The minimum number of complete rearrangements is `min(2, 2, 2)` which equals 2.

So, the result is `2` — we can form two complete rearrangements of `"abc"` from the characters in `"abcabc"`.

### Complexity

#### Time Complexity

- **Building the frequency map for `target`**: Iterating through the `target` string takes `O(m)`, where `m` is the length of `target`.
- **Building the frequency map for `s`**: Iterating through the `s` string takes `O(n)`, where `n` is the length of `s`.
- **Calculating the minimum number of rearrangements**: We iterate over the keys of `targetFreq`, which will have at most 26 entries (since there are only 26 letters in the alphabet). Hence, this step takes `O(1)` time, since the maximum number of unique characters is constant.
- **Overall time complexity**: The time complexity is **O(n + m)**, where `n` is the length of `s` and `m` is the length of `target`.

#### Space Complexity

- **Storing frequency maps**: We use two unordered maps, `targetFreq` and `sentFreq`, each of size at most 26 (since we are only dealing with lowercase English letters). The space complexity is **O(1)** due to the constant size of the alphabet.

- **Overall space complexity**: The space complexity is **O(1)**.

### Conclusion

This solution efficiently counts the number of times the `target` string can be rearranged using characters from string `s` by leveraging frequency counting and finding the limiting character. The algorithm runs in linear time with respect to the sizes of `s` and `target`, making it efficient even for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/)

---
{{< youtube Mgtl8CIIWX4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
