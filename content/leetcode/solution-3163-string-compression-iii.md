
+++
authors = ["grid47"]
title = "Leetcode 3163: String Compression III"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3163: String Compression III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RWQ8Q_ID23c"
youtube_upload_date="2024-05-26"
youtube_thumbnail="https://i.ytimg.com/vi/RWQ8Q_ID23c/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string compressedString(string word) {
        
        int i = 0, n = word.size();
        char cur;
        
        string res = "";
        while(i < n) {
            int cnt = 0;
            cur = word[i];
            while(i < n && cnt < 9 && cur == word[i])
                cnt++, i++;
            res += to_string(cnt) + cur;
        }
        return res;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to compress a given string `word` by reducing sequences of the same character into a substring that consists of the character followed by the number of its consecutive occurrences. The maximum number of consecutive characters to be represented is 9. If a character appears more than 9 times consecutively, it will still be compressed into a maximum of 9 occurrences followed by the character.

For example:
- Input: `"aaabbbccccc"`
- Output: `"3a3b5c"`

The goal of the algorithm is to implement an efficient solution that produces this compressed version of the input string `word`.

### Approach

To solve this problem, we can utilize the following approach:
1. **Iterate through the String**: We start by iterating through the string `word` to check for consecutive occurrences of each character.
2. **Count Consecutive Characters**: As we go through the string, we maintain a count of consecutive occurrences of each character. Every time the character changes, we append the count and the character to the result string.
3. **Handle Edge Cases**: For sequences of characters that appear more than 9 times, the count should be capped at 9 as per the problem statement.
4. **Return the Result**: After iterating through the entire string, we return the resultant compressed string.

### Code Breakdown (Step by Step)

Let’s break down the code step by step:

1. **Initialize Variables**:
   - `i`: The index that keeps track of our current position in the string `word`.
   - `n`: The size of the input string `word`.
   - `cur`: A variable that stores the current character we are processing.
   - `res`: The result string that will contain the compressed version of the input string.

   ```cpp
   int i = 0, n = word.size();
   char cur;
   string res = "";
   ```

2. **Iterate Over the String**:
   - The main logic of the function revolves around iterating through the string to count consecutive occurrences of characters.
   - We use a `while` loop, which continues until `i` reaches the end of the string (i.e., `i < n`).

   ```cpp
   while (i < n) {
   ```

3. **Count Consecutive Characters**:
   - For each character in the string, we initialize `cnt` to 0, which will store the count of consecutive occurrences of the current character `cur`.
   - We then use another `while` loop to increment the count of `cnt` while the current character `cur` is equal to the next character and `cnt` is less than 9. This ensures that we do not exceed 9 consecutive occurrences for any character.

   ```cpp
   int cnt = 0;
   cur = word[i];
   while (i < n && cnt < 9 && cur == word[i])
       cnt++, i++;
   ```

   Here, the inner loop continues as long as:
   - We haven't reached the end of the string (`i < n`).
   - The character at the current index is the same as the character `cur`.
   - The count `cnt` is less than 9 (to prevent counting more than 9 occurrences).

4. **Update the Result**:
   - Once the inner loop finishes (i.e., we’ve counted the consecutive occurrences of `cur`), we add the count and the character to the result string `res`.
   - We use the `to_string(cnt)` function to convert the count (an integer) into a string and concatenate it with the character `cur`.

   ```cpp
   res += to_string(cnt) + cur;
   ```

   The result string `res` gradually builds up with each character and its corresponding count of consecutive occurrences.

5. **Return the Compressed String**:
   - After the main loop has processed all characters in the string, we return the `res` string, which contains the compressed version of the input string.

   ```cpp
   return res;
   ```

### Example Walkthrough

Let's walk through an example to see how the function works:

#### Input:
```cpp
string word = "aaabbbccccc";
```

#### Process:

1. **Initial Setup**:
   - `i = 0`, `n = 11` (since the string has 11 characters), and `res = ""`.

2. **First Iteration (`i = 0`)**:
   - The first character is `'a'`.
   - We start counting the occurrences of `'a'`. The count becomes `3` (`aaa`).
   - We add `"3a"` to the result string, so `res = "3a"`.
   - `i` is now updated to `3` (since we've processed 3 characters).

3. **Second Iteration (`i = 3`)**:
   - The next character is `'b'`.
   - We start counting the occurrences of `'b'`. The count becomes `3` (`bbb`).
   - We add `"3b"` to the result string, so `res = "3a3b"`.
   - `i` is now updated to `6` (since we've processed 3 characters).

4. **Third Iteration (`i = 6`)**:
   - The next character is `'c'`.
   - We start counting the occurrences of `'c'`. The count becomes `5` (`ccccc`).
   - We add `"5c"` to the result string, so `res = "3a3b5c"`.
   - `i` is now updated to `11`, and the loop terminates.

5. **Final Result**:
   - The function returns `"3a3b5c"`, which is the compressed version of the input string.

#### Output:
```cpp
"3a3b5c"
```

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity of the solution is **O(n)**, where `n` is the length of the input string `word`. This is because we only iterate over the string once. Each character is processed in the main `while` loop, and the inner loop counts consecutive characters. Each character is visited only once, and the string is processed in linear time.

#### Space Complexity:
- **O(n)**: The space complexity is **O(n)** because the result string `res` will, in the worst case, store a compressed version of the input string. The size of `res` depends on the number of characters in the input string, but it will never be larger than the original string.

### Conclusion

This solution efficiently compresses the input string `word` by counting consecutive occurrences of each character and appending the count followed by the character to the result string. It uses a linear time complexity approach, making it suitable for processing large strings. The function handles edge cases, such as characters occurring more than 9 times consecutively, and ensures that the result remains within the specified constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/string-compression-iii/description/)

---
{{< youtube RWQ8Q_ID23c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
