
+++
authors = ["grid47"]
title = "Leetcode 2047: Number of Valid Words in a Sentence"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2047: Number of Valid Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "sl4thQAqnJg"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sl4thQAqnJg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
// Time: O(N)
// Space: O(N)
class Solution {
    bool valid(string &s) {
        int hyphen = 0, N = s.size();
        for (int i = 0; i < N; ++i) {
            if (isdigit(s[i])) return false; // no digit
            if (isalpha(s[i])) continue; // skip letters
            if (s[i] == '-') {
                if (++hyphen > 1) return false; // at most one hyphen allowed
                if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
            } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
        }
        return true;
    }
public:
    int countValidWords(string s) {
        string w;
        istringstream ss(s);
        int ans = 0;
        while (ss >> w) ans += valid(w);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires counting "valid" words in a given string `s`. A word is considered valid if it meets these criteria:
1. **No Digits**: The word must not contain any digits.
2. **Hyphens**: The word can have at most one hyphen, and if it has a hyphen, it must be surrounded by alphabetic characters on both sides.
3. **Punctuation**: If there is punctuation (like `!`, `,`, or `.`), it must appear at the end of the word.

### Approach

This code utilizes a two-step approach: first breaking down the input string into individual words and then validating each word based on the criteria. A helper function, `valid`, is used to check if each word meets all required conditions. If a word is valid, it contributes to the final count.

### Code Breakdown (Step by Step)

Let’s look at each part of the code in detail:

1. **Class and Helper Function Definition**: We define a class `Solution` with two main components: 
   - A helper function `valid` that checks if a word meets all criteria.
   - The main function `countValidWords` that counts and returns the number of valid words.

    ```cpp
    class Solution {
    ```

2. **Helper Function `valid`**: This function takes a reference to a string `s` and checks if it meets the requirements. Inside `valid`, we use a variable `hyphen` to count hyphens in the word and `N` to store the word’s length.

    ```cpp
    bool valid(string &s) {
        int hyphen = 0, N = s.size();
    ```

3. **Loop Over Each Character**: The function iterates over each character in `s`, applying the validation rules.

    ```cpp
    for (int i = 0; i < N; ++i) {
    ```

4. **Check for Digits**: If a character is a digit, the word is invalid, so the function immediately returns `false`.

    ```cpp
    if (isdigit(s[i])) return false; // no digit
    ```

5. **Handle Alphabetic Characters**: If the character is a letter, we simply continue to the next character, as letters are allowed without any special checks.

    ```cpp
    if (isalpha(s[i])) continue; // skip letters
    ```

6. **Handle Hyphens**: If the character is a hyphen, we perform additional checks:
   - **One Hyphen Limit**: We increment `hyphen` to keep track of the number of hyphens. If it exceeds 1, the function returns `false`.
   - **Position Check**: If there is a hyphen, it must be surrounded by alphabetic characters on both sides. If not, we return `false`.

    ```cpp
    if (s[i] == '-') {
        if (++hyphen > 1) return false; // at most one hyphen allowed
        if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
    }
    ```

7. **Punctuation Check**: If the character is not a letter or hyphen, it is considered punctuation, which must be the last character in the word. If punctuation appears anywhere else, the function returns `false`.

    ```cpp
    else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
    ```

8. **Return True if All Conditions are Met**: If none of the above conditions are violated, the word is valid, and we return `true`.

    ```cpp
    return true;
    }
    ```

9. **Count Valid Words**: The main function `countValidWords` initializes a string `w` and an input string stream `ss` to read each word from the input string `s`. It then iterates over each word in `s`, incrementing the result `ans` if `valid(w)` returns `true`.

    ```cpp
    int countValidWords(string s) {
        string w;
        istringstream ss(s);
        int ans = 0;
        while (ss >> w) ans += valid(w);
        return ans;
    }
    ```

### Complexity

- **Time Complexity**: The code operates in O(N), where N is the length of the input string `s`. Each word in the string is checked individually for validity, which involves iterating over its characters at most once.
- **Space Complexity**: The space complexity is O(N), where `N` is the number of words in the input string `s`, as we store the words in the string stream `ss` and count them if valid.

### Conclusion

In summary, this solution provides an efficient and systematic approach to count valid words in a sentence by employing straightforward character-based checks in each word. The `valid` helper function ensures that each word meets the conditions for validity, and `countValidWords` effectively counts each valid word. By leveraging the properties of alphabetic, numeric, hyphen, and punctuation characters, this code achieves its goal with optimized time and space complexity. This solution provides a strong, reliable foundation for processing input sentences in applications that require validation of complex word structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/)

---
{{< youtube sl4thQAqnJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
