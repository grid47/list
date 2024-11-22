
+++
authors = ["grid47"]
title = "Leetcode 1935: Maximum Number of Words You Can Type"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1935: Maximum Number of Words You Can Type in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FLMJwdw9Kqc"
youtube_upload_date="2021-07-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FLMJwdw9Kqc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};
        for (auto ch : brokenLetters)
            broken[ch - 'a'] = true;
        int res = 0, cnt = 0;
        for (auto ch : text)
            if (ch == ' ') {
                res += cnt == 0;
                cnt = 0;
            }
            else
                cnt += broken[ch - 'a'];
        return res + (cnt == 0);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine how many words in a given string of text can be typed using a keyboard that has certain broken letters. Each word is separated by a space, and if a word contains any of the broken letters, it cannot be typed. The goal is to count the number of words that can be fully typed without using any broken letters.

### Approach

To solve the problem, we will follow these steps:

1. **Initialize a Boolean Array**: Create a boolean array of size 26 to keep track of which letters are broken.

2. **Mark Broken Letters**: Iterate through the string of broken letters and mark the corresponding indices in the boolean array.

3. **Count Typable Words**: Iterate through the input text, counting words that do not contain any broken letters by checking the characters against the boolean array.

4. **Handle Word Separation**: Use spaces to identify the boundaries of words in the text.

5. **Return the Count**: Finally, return the count of words that can be typed.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};
```
Here, we declare the class `Solution` and define the public function `canBeTypedWords`, which takes two parameters: `text` (the input string containing words) and `brokenLetters` (a string representing the broken keys on the keyboard). We initialize a boolean array `broken` of size 26 to keep track of broken letters.

```cpp
        for (auto ch : brokenLetters)
            broken[ch - 'a'] = true;
```
In this loop, we iterate over each character in `brokenLetters`. By subtracting `'a'` from each character, we calculate its corresponding index (0 for 'a', 1 for 'b', etc.) in the `broken` array and mark it as `true`.

```cpp
        int res = 0, cnt = 0;
```
We initialize two integer variables: `res` (to count the number of words that can be typed) and `cnt` (to count the characters in the current word).

```cpp
        for (auto ch : text)
            if (ch == ' ') {
                res += cnt == 0;
                cnt = 0;
            }
```
We iterate through each character in the `text`. When we encounter a space character, it indicates the end of a word:
- If `cnt` is zero, it means the previous word could be typed without any broken letters, so we increment `res`.
- We reset `cnt` to zero to start counting the next word.

```cpp
            else
                cnt += broken[ch - 'a'];
```
If the current character is not a space, we check if it is a broken letter using the `broken` array. If it is broken, we increment `cnt`.

```cpp
        return res + (cnt == 0);
    }
};
```
After finishing the iteration through `text`, we return `res` plus one additional count if `cnt` is zero. This accounts for the last word if it was not followed by a space.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n + m)\), where \(n\) is the length of the `text` string and \(m\) is the length of the `brokenLetters` string. This is because we need to iterate through both strings once.

- **Space Complexity**: The space complexity is \(O(1)\) since we are using a fixed-size array of size 26 to store the status of the broken letters, regardless of the size of the input.

### Conclusion

The `canBeTypedWords` function effectively counts the number of words in the given text that can be typed using a keyboard with certain broken letters. By utilizing a boolean array to track broken keys and iterating through the text to identify and count valid words, this solution is efficient and straightforward. 

### Key Features

1. **Efficiency**: The approach ensures that the function runs in linear time relative to the size of the input strings, making it suitable for large inputs.

2. **Simplicity**: The code is simple and easy to understand, leveraging basic programming constructs like loops and conditionals.

3. **Use of Boolean Array**: The boolean array efficiently tracks the status of broken keys, allowing for quick lookups.

### Use Cases

This solution can be applied in various scenarios where input validation against a set of restricted characters is required, such as:

- **Text Editing Applications**: Validating user input against a list of disabled keys.
- **Game Development**: Checking player inputs for allowed actions based on available controls.
- **Data Processing**: Filtering strings based on character availability.

### Implementation Considerations

When implementing the function, keep the following points in mind:

- **Input Constraints**: Ensure that the function handles edge cases such as empty strings for both `text` and `brokenLetters`.

- **Character Set**: The implementation assumes only lowercase English letters. If the input can contain uppercase letters or special characters, additional handling may be necessary.

- **Performance Testing**: It’s essential to test the function with various cases, including extreme cases (e.g., a very long text or many broken letters) to ensure robustness.

By mastering the approach used in this solution, developers can efficiently tackle similar problems in various domains, enhancing their coding capabilities and algorithmic thinking.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/)

---
{{< youtube FLMJwdw9Kqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
