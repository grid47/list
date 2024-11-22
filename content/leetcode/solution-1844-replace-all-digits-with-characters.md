
+++
authors = ["grid47"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1844: Replace All Digits with Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "L5P6zYBLP3s"
youtube_upload_date="2021-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/L5P6zYBLP3s/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string replaceDigits(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to manipulate a given string \( s \) consisting of lowercase letters and digits. The goal is to replace each digit in the string with a character that is determined by adding the digit's value to the preceding character (the letter immediately before it). This operation must be applied to all digits at odd indices in the string. For instance, in the string "a1c1e1", the transformations would be:

- The digit '1' at index 1 (preceded by 'a') should be replaced by 'b' (i.e., 'a' + 1).
- The digit '1' at index 3 (preceded by 'c') should be replaced by 'd' (i.e., 'c' + 1).
- The digit '1' at index 5 (preceded by 'e') should be replaced by 'f' (i.e., 'e' + 1).

After all transformations, the resultant string for "a1c1e1" would be "abcde".

### Approach

To solve this problem, we can follow a straightforward approach:

1. **Iterate Through the String**: Start iterating from index 1 and step through the string in increments of 2 to target only the digits.

2. **Replace Digits**: For each digit encountered, convert it into its corresponding integer value and add it to the ASCII value of the preceding character. The result will be a new character that replaces the digit in the string.

3. **Return the Result**: After processing all relevant indices, return the modified string.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
    string replaceDigits(string s) {
```
- A class named `Solution` is defined, containing a public method called `replaceDigits` that takes a string \( s \) as its parameter.

```cpp
        for (auto i = 1; i < s.size(); i += 2)
```
- A `for` loop is initiated, starting from index 1 and iterating through the string while incrementing by 2. This ensures we are only examining odd indices, where digits are located.

```cpp
            s[i] += s[i - 1] - '0';
```
- Inside the loop, we replace the digit at index \( i \) with the sum of the character at index \( i-1 \) (the preceding letter) and the integer value of the digit. The expression `s[i - 1] - '0'` converts the character representing a digit into its integer form (for example, '1' becomes 1). The result of this addition is a new character which will replace the digit at index \( i \).

```cpp
        return s;
    }
};
```
- After processing all relevant indices in the string, the modified string \( s \) is returned.

### Complexity

- **Time Complexity**: The time complexity of this approach is \( O(n) \), where \( n \) is the length of the input string \( s \). This is because we traverse the string once, modifying characters in place.

- **Space Complexity**: The space complexity is \( O(1) \) for the operations conducted, as the modifications are made directly on the original string without the need for additional data structures that grow with input size.

### Conclusion

The `replaceDigits` function provides a concise and efficient way to transform a string by replacing specific digits based on their preceding characters. This solution is optimal for the problem constraints and demonstrates an effective application of basic string manipulation techniques in C++.

This code effectively showcases the use of character arithmetic and how ASCII values can be manipulated to achieve desired transformations. The approach is straightforward, making it easy to understand and implement, especially for those learning about string handling in programming.

In practical applications, such a function could be beneficial in scenarios where encoding or decoding string data is necessary, or in any case where character transformation is required based on adjacent characters. The clarity and efficiency of the code also contribute to its usability in larger systems, emphasizing good coding practices.

This solution not only solves the problem efficiently but also demonstrates the importance of understanding data types and character representations in programming, which is fundamental for effective software development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-all-digits-with-characters/description/)

---
{{< youtube L5P6zYBLP3s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
