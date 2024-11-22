
+++
authors = ["grid47"]
title = "Leetcode 1910: Remove All Occurrences of a Substring"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1910: Remove All Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d74CJIqw268"
youtube_upload_date="2021-07-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d74CJIqw268/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int m = part.size(), n = s.size(), i, j;
        for(i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to remove all occurrences of a specified substring `part` from a given string `s`. The challenge is to perform this operation efficiently, especially when there are multiple overlapping occurrences of `part` within `s`. The solution should return the modified string after all occurrences of `part` have been removed.

### Approach

To solve this problem, we can use a method that constructs a new string without the unwanted substrings. The key idea is to utilize a single pass through the input string `s` while maintaining a pointer to track the position in the resulting string. We will build the result as we iterate through `s`, and whenever we detect that the end of the current result matches `part`, we remove it by adjusting the pointer. This allows us to efficiently manage overlapping occurrences of `part`.

### Code Breakdown (Step by Step)

Let’s go through the provided code to understand its implementation:

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: The method `removeOccurrences` takes two parameters: a string `s` and a string `part`. It returns a modified version of `s` after removing all occurrences of `part`.

   ```cpp
       string removeOccurrences(string s, string part) {
   ```

3. **Variable Initialization**: We create a new string `x` initialized to `s`. We also obtain the sizes of `part` (m) and `s` (n) for later reference.

   ```cpp
           string x = s;
           int m = part.size(), n = s.size(), i, j;
   ```

4. **Iterating Through the String**: We use a for loop to iterate over each character in `s`. The loop variable `i` runs from 0 to `n - 1`, representing the current character in `s`.

   ```cpp
           for(i = 0, j = 0; i < n; i++) {
   ```

5. **Building the Result**: Inside the loop, we add the current character `s[i]` to the position `j` in the string `x`. We then increment `j` to point to the next available position in `x`.

   ```cpp
               x[j++] = s[i];
   ```

6. **Checking for the Substring**: After adding a character, we check if the last `m` characters in `x` match the substring `part`. This is done using `x.substr(j - m, m)`. If there’s a match, it indicates that we need to remove the last `m` characters by decrementing `j` by `m`.

   ```cpp
               if (j >= m && x.substr(j - m, m) == part)
                   j -= m;
   ```

7. **Returning the Result**: After processing all characters, we return a substring of `x` that goes from the start to the last valid position `j`. This effectively gives us the modified string with all occurrences of `part` removed.

   ```cpp
           return x.substr(0, j);
       }
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is O(n), where n is the length of the string `s`. We make a single pass through the string while constructing the result.
  
- **Space Complexity**: The space complexity is O(n) as well, due to the use of the string `x` which can potentially store the entire input string in the worst case (if no occurrences of `part` exist in `s`).

### Conclusion

The `removeOccurrences` function provides an efficient way to remove all occurrences of a substring from a string by leveraging a single-pass approach. This method avoids unnecessary complexity by using a direct manipulation of the string and minimizes the overhead associated with multiple substring searches or replacements.

### Use Cases

1. **Text Processing**: This approach is particularly useful in text processing applications where certain unwanted substrings need to be filtered out, such as cleaning up input data.

2. **Data Sanitization**: In data entry systems, it may be necessary to remove specific patterns or sensitive information from user inputs.

3. **Game Development**: In games, removing certain commands or inputs can enhance user experience and maintain game integrity.

4. **Natural Language Processing (NLP)**: When preprocessing text for NLP tasks, certain phrases or words might need to be removed to prepare the data for analysis or model training.

By implementing such functionality, applications can efficiently handle and manipulate strings, improving performance and user experience. The direct approach taken in this solution ensures clarity and speed, making it suitable for various real-world applications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

---
{{< youtube d74CJIqw268 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
