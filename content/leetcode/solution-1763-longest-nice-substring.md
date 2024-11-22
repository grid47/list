
+++
authors = ["grid47"]
title = "Leetcode 1763: Longest Nice Substring"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1763: Longest Nice Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Bit Manipulation","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6WvZrynlCdk"
youtube_upload_date="2021-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/6WvZrynlCdk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestNiceSubstring(string s, int start = 0, int end = -1) {
        if (end == -1)
            end = s.size();
        int cnt[26][2] = {}, j = start - 1;
        for (auto i = start; i < end; ++i)
            cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
        string res;
        for (auto i = start; i <= end; ++i) {
            int ch = i == end ? -1 : tolower(s[i]) - 'a';
            if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
                if (j == -1 && ch == -1)
                    return s;
                auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
                if (res1.size() > res.size())
                    res = res1;
                j = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to find the longest nice substring within a given string `s`. A substring is defined as "nice" if it contains both the uppercase and lowercase versions of each letter that appears in it. For example, the substring "aA" is nice, while "a" or "A" is not. The challenge is to determine the longest such substring efficiently.

### Approach

The solution utilizes a recursive approach to explore all potential substrings of the input string and checks for their "niceness." Here's how the algorithm operates:

1. **Character Count**: Maintain a count of each character in the substring being analyzed to determine if both the uppercase and lowercase versions are present.

2. **Recursive Exploration**: Iterate through the string, checking character pairs. When encountering a character that breaks the nice condition (either by not having its counterpart or hitting the end of the substring), it triggers a recursive search on the segments created by the split.

3. **Maximize Length**: During the recursive calls, the algorithm compares the lengths of the nice substrings found and retains the longest one.

### Code Breakdown (Step by Step)

The code is structured within the `Solution` class and features a single public method, `longestNiceSubstring`, with optional parameters for specifying the start and end indices of the substring being analyzed.

1. **Class Definition**: The solution is encapsulated within the `Solution` class.

   ```cpp
   class Solution {
   ```

2. **Method Signature**: The `longestNiceSubstring` method accepts a string `s` and two integer parameters, `start` and `end`. The `end` parameter defaults to -1, which signals that the full length of the string should be analyzed.

   ```cpp
   public:
       string longestNiceSubstring(string s, int start = 0, int end = -1) {
   ```

3. **Initialization**: If `end` is not provided, it is set to the length of the string. An array `cnt` is initialized to track character counts, and `j` is initialized to `start - 1`.

   ```cpp
   if (end == -1)
       end = s.size();
   int cnt[26][2] = {}, j = start - 1;
   ```

4. **Counting Characters**: The loop iterates from `start` to `end`, counting the occurrence of both lowercase and uppercase versions of each character.

   ```cpp
   for (auto i = start; i < end; ++i)
       cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
   ```

5. **Iterating through Characters**: A second loop runs from `start` to `end + 1` to check the characters, keeping track of the current character being analyzed.

   ```cpp
   string res;
   for (auto i = start; i <= end; ++i) {
       int ch = i == end ? -1 : tolower(s[i]) - 'a';
   ```

6. **Checking Nice Condition**: If the character is the end marker or the count of both cases for the current character is less than 2, it signifies a break in the nice substring condition.

   ```cpp
   if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
   ```

7. **Recursive Call**: When a break occurs, the function makes a recursive call to find the longest nice substring in the segment formed between `j + 1` and `i`.

   ```cpp
   auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
   ```

8. **Updating Result**: If the newly found substring is longer than the current result, update the result.

   ```cpp
   if (res1.size() > res.size())
       res = res1;
   j = i;
   ```

9. **Return the Result**: Finally, the longest nice substring found during the iterations is returned.

   ```cpp
   return res;
   }
   ```

### Complexity

- **Time Complexity**: The worst-case time complexity is \(O(n^2)\), where \(n\) is the length of the string. This is due to the nested nature of the recursion and substring operations that are performed on each recursive call.

- **Space Complexity**: The space complexity is \(O(n)\) as well, mainly due to the stack space used by the recursive calls and the storage of the substring in each call.

### Conclusion

The `longestNiceSubstring` function provides an elegant solution to finding the longest nice substring in a given string. It efficiently counts the occurrences of characters and utilizes recursion to explore potential substrings, ensuring that both cases of characters are present.

This method highlights important concepts in string manipulation and recursion, showcasing how to break down a problem into manageable subproblems. By maintaining character counts and systematically exploring substrings, the algorithm effectively identifies the longest nice substring.

The solution is not only functional but also illustrative of the divide-and-conquer approach in problem-solving, where larger problems are solved by tackling smaller instances, ultimately leading to an optimal solution for the original problem.

In summary, the `longestNiceSubstring` method is a robust example of handling string problems in C++, demonstrating the power of recursion and careful character tracking. It sets a foundation for tackling similar challenges in competitive programming and algorithmic design, ensuring that students and developers can apply these techniques in their work.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-nice-substring/description/)

---
{{< youtube 6WvZrynlCdk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
