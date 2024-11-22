
+++
authors = ["grid47"]
title = "Leetcode 1160: Find Words That Can Be Formed by Characters"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1160: Find Words That Can Be Formed by Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "riRpJLMdrXs"
youtube_upload_date="2022-06-28"
youtube_thumbnail="https://i.ytimg.com/vi/riRpJLMdrXs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
        for (auto ch : chars) 
            ++cnt[ch - 'a'];
        for (auto &w : words) {
            int cnt1[26] = {}, match = true;
            for (auto ch : w)
            if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
                match = false;
                break;
            }
            if (match) 
                res += w.size();
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The goal of the `countCharacters` function is to determine how many characters are in words that can be formed using a specified set of characters. We are given an array of words, `words`, and a string of characters, `chars`. For each word, if all the letters in that word can be made using the letters in `chars` (with each letter used at most as many times as it appears in `chars`), then the length of the word is added to the result. Ultimately, the function returns the sum of the lengths of such words.

### Approach
The function utilizes character frequency counting to ensure each word can be formed from the characters in `chars`:
1. **Frequency Counting**:
   - An array `cnt` of size 26 (representing each letter in the English alphabet) counts the frequency of each character in `chars`.
   - For each character in `chars`, the respective count is incremented in `cnt`.
2. **Validation Check for Each Word**:
   - For each word in `words`, a separate frequency array, `cnt1`, is used to track character counts within that word.
   - As we iterate over each character in the word, we check if adding that character would exceed its count in `cnt`. If it does, the word cannot be formed, so we move to the next word.
   - If all characters in the word stay within the limits of `cnt`, we add the word’s length to the result.
3. **Result Accumulation**:
   - The function accumulates the length of each valid word into `res`, which is returned at the end.

### Code Breakdown (Step by Step)
Here's a line-by-line breakdown of the function and what each section accomplishes:

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
```
- **Lines 3-4**: The function starts by declaring a `cnt` array to store character frequencies for `chars`, initialized to zero for each of the 26 letters. An integer `res` is also initialized to accumulate the result.

```cpp
        for (auto ch : chars) 
            ++cnt[ch - 'a'];
```
- **Lines 5-6**: We populate the `cnt` array by iterating over each character in `chars`. The `ch - 'a'` operation calculates the index for each letter, storing its count.

```cpp
        for (auto &w : words) {
            int cnt1[26] = {}, match = true;
```
- **Lines 7-8**: For each word in `words`, we declare `cnt1` to store frequencies of the word’s characters and initialize a `match` flag to `true`. This flag will track whether the word can be constructed from `chars`.

```cpp
            for (auto ch : w)
            if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
                match = false;
                break;
            }
```
- **Lines 9-12**: As we iterate over each character in the word, `cnt1` records the frequency. If any character’s count in `cnt1` exceeds its count in `cnt`, `match` is set to `false` and we exit the loop.

```cpp
            if (match) 
                res += w.size();
        }
```
- **Lines 13-15**: If `match` remains `true` (indicating the word can be formed from `chars`), we add the word’s length to `res`.

```cpp
        return res;
    }
};
```
- **Line 16**: Finally, we return `res`, which is the total length of words that can be formed using `chars`.

### Complexity
1. **Time Complexity**:
   - The time complexity is \(O(N \times M)\), where \(N\) is the number of words, and \(M\) is the average length of the words in `words`. 
   - For each word, we iterate through its characters and perform checks against the `cnt` array.
2. **Space Complexity**:
   - The space complexity is \(O(1)\) because the `cnt` and `cnt1` arrays are of fixed size (26) regardless of the input size.

### Conclusion
The `countCharacters` function provides an efficient solution for finding the total length of words that can be constructed from a given set of characters. It relies on frequency counting for quick validation, allowing each word to be checked in constant time relative to its length. This approach is especially efficient for cases with a large number of words and characters, providing a clear and scalable solution.

By focusing on character frequency comparison, this function avoids unnecessary complexity and ensures optimal performance. Its structure, using auxiliary arrays and conditional checks, demonstrates a common pattern in string and character counting problems, making it applicable to similar challenges in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/)

---
{{< youtube riRpJLMdrXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
