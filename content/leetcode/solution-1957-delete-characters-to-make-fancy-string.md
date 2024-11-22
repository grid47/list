
+++
authors = ["grid47"]
title = "Leetcode 1957: Delete Characters to Make Fancy String"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1957: Delete Characters to Make Fancy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wdve85GSjO8"
youtube_upload_date="2021-08-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wdve85GSjO8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeFancyString(string s) {
        int j = 2;
        for (int i = 2; i < s.size(); ++i)
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        s.resize(min(j, (int)s.size()));
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to transform a given string by removing consecutive duplicate characters such that no character appears more than twice in a row. For example, given the input string `"leeetcode"`, the output should be `"leetcode"` because the letter "e" appears consecutively more than twice. The goal is to implement a function that processes the string efficiently while maintaining its original order.

### Approach

To solve this problem, we can utilize a two-pointer technique to build the modified string in-place. The idea is to use one pointer (`i`) to iterate through the input string and another pointer (`j`) to track the position in the modified string. The algorithm will check the last two characters added to the modified string to ensure that the next character to be added does not create a sequence of three consecutive identical characters.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
```
The class `Solution` is defined, and the public member function `makeFancyString` is declared.

```cpp
    string makeFancyString(string s) {
```
The `makeFancyString` function takes a string `s` as input and will return a new string that meets the specified conditions.

```cpp
        int j = 2;
```
We initialize an integer variable `j` to `2`. This variable is used as an index to track the position in the modified string. The first two characters can always be added to the new string since they cannot form a triplet.

```cpp
        for (int i = 2; i < s.size(); ++i)
```
A `for` loop starts with `i` initialized to `2`. This loop will iterate through the characters of the string `s` starting from the third character.

```cpp
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
```
Inside the loop, we check if the current character `s[i]` is different from the last two characters added to the modified string (`s[j - 1]` and `s[j - 2]`). If `s[i]` is not equal to either of the last two characters, it means adding `s[i]` will not create a triplet.

```cpp
                s[j++] = s[i];
```
If the condition is true, we assign `s[i]` to the `j`-th position in the string and increment `j`. This effectively adds the character to the modified string.

```cpp
        s.resize(min(j, (int)s.size()));
```
After the loop, we resize the string `s` to keep only the first `j` characters, which contain the modified content. The `min` function is used to ensure we do not exceed the original string's size.

```cpp
        return s;
    }
```
Finally, we return the modified string.

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the length of the input string. This is because we only traverse the string once with the two-pointer technique.

- **Space Complexity**: The space complexity is \( O(1) \) since we are modifying the string in-place without using any additional data structures that depend on the size of the input.

### Conclusion

The `makeFancyString` function efficiently transforms the input string by ensuring no character appears more than twice consecutively. The use of the two-pointer technique allows us to achieve this in a single pass, making the solution optimal in terms of both time and space complexity.

### Key Features

1. **In-Place Modification**: The algorithm modifies the input string directly, which saves memory and improves efficiency.
  
2. **Two-Pointer Technique**: This technique allows us to track the valid position for inserting characters while checking the last two added characters to prevent triplets.

3. **Simple Logic**: The condition to check for duplicates is straightforward, making the code easy to understand and maintain.

### Use Cases

This function can be beneficial in various scenarios, including:
- **Text Processing**: When formatting strings for display or storage where limits on consecutive characters are required.
- **Data Cleaning**: Useful in preprocessing textual data to ensure consistency in formats.

### Implementation Considerations

When implementing this solution, consider the following:

- **Edge Cases**: Handle edge cases where the input string may be empty or have fewer than three characters. The current implementation already accommodates these situations gracefully.

- **Character Set**: The function is designed to work with ASCII characters but can be adjusted if needed to handle wider character sets, such as Unicode.

### Example Usage

To demonstrate how the function can be used, consider the following example:

```cpp
Solution sol;
string result = sol.makeFancyString("aaaabaaaa");
cout << result;  // Output: "aababaa"
```

This example shows how the function effectively removes the excessive consecutive characters while preserving the order of the remaining characters. By understanding this approach, one can easily adapt the logic for other string manipulation problems that involve constraints on character occurrences.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

---
{{< youtube wdve85GSjO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
