
+++
authors = ["grid47"]
title = "Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "U7tKTEdd0Lw"
youtube_upload_date="2022-02-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/U7tKTEdd0Lw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> tsk(26, 0);
        for(char c: s)
        tsk[c - 'a']++;
        for(char c: t)
        tsk[c - 'a']--;

        int ans = 0;
        for(int a: tsk) ans += abs(a);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem asks us to determine the minimum number of steps required to make two strings `s` and `t` anagrams of each other. An anagram of a string is another string that contains the same characters, with the same frequencies, but possibly in a different order. The allowed operation to transform one string into another is to replace any character in one string with another character.

Given two strings `s` and `t`, the goal is to find the minimum number of character replacements needed to make the two strings anagrams. 

### Approach
To solve this problem efficiently, the approach focuses on comparing the character counts of both strings. If the character counts of the two strings differ, then the number of steps required will be the sum of the absolute differences between their respective character counts.

Here’s a step-by-step breakdown of the approach:
1. Count the frequency of each character in both strings `s` and `t`.
2. Compare the character frequencies of both strings. If the frequency of a character in `s` is greater than that in `t`, we need to "remove" the extra characters, and if the frequency is less, we need to "add" the missing characters.
3. The number of operations needed will be the total number of characters that need to be added or removed to balance the two strings’ character counts.

The algorithm works by calculating the difference in character frequencies for each of the 26 lowercase letters (assuming that the strings consist only of lowercase English letters). The sum of the absolute differences in frequencies gives the minimum number of steps required.

### Code Breakdown (Step by Step)
1. **Function Signature:**
   ```cpp
   int minSteps(string s, string t)
   ```
   - The function `minSteps` takes two strings, `s` and `t`, and returns an integer representing the minimum number of steps needed to make `s` and `t` anagrams.

2. **Initialize the Frequency Vector:**
   ```cpp
   vector<int> tsk(26, 0);
   ```
   - A vector `tsk` of size 26 is initialized to zero. Each index in the vector corresponds to one of the 26 lowercase letters (`'a'` to `'z'`), where `tsk[0]` represents the count of 'a', `tsk[1]` represents the count of 'b', and so on.

3. **Count Characters in String `s`:**
   ```cpp
   for(char c: s)
       tsk[c - 'a']++;
   ```
   - Loop through each character `c` in string `s`, and increment the corresponding index in the `tsk` vector. The expression `c - 'a'` converts the character to an index in the range 0-25, corresponding to the position of the letter in the alphabet.

4. **Count Characters in String `t`:**
   ```cpp
   for(char c: t)
       tsk[c - 'a']--;
   ```
   - Loop through each character `c` in string `t`, and decrement the corresponding index in the `tsk` vector. This step ensures that the `tsk` vector reflects the difference in frequencies between the characters in `s` and `t`.

5. **Calculate the Total Steps Needed:**
   ```cpp
   int ans = 0;
   for(int a: tsk)
       ans += abs(a);
   ```
   - Initialize a variable `ans` to 0, which will hold the final result (the minimum number of steps required).
   - Loop through each element `a` in the `tsk` vector, which represents the difference in frequency for each letter. Add the absolute value of each difference to `ans`. The absolute value is used because we care about the number of characters that need to be added or removed, regardless of whether they appear more in `s` or `t`.

6. **Return the Result:**
   ```cpp
   return ans;
   ```
   - After calculating the total number of operations required, return the value of `ans`.

### Complexity
- **Time Complexity**: 
  - The time complexity of this solution is O(n + m), where `n` is the length of string `s` and `m` is the length of string `t`. This is because we need to loop through each string once to count the character frequencies. The final loop through the `tsk` vector has constant time complexity O(26), which can be considered O(1) since 26 is a fixed constant.
  
  - Hence, the time complexity is linear in terms of the total number of characters in both strings, which makes the algorithm very efficient for large inputs.

- **Space Complexity**: 
  - The space complexity is O(1), since the `tsk` vector always has a fixed size of 26, regardless of the size of the input strings. Other than that, only a few integer variables (`ans`) are used, which do not depend on the size of the input.

### Conclusion
The provided solution efficiently solves the problem of determining the minimum number of steps to convert two strings into anagrams of each other. By focusing on character frequency differences, the algorithm avoids unnecessary operations and achieves a time complexity of O(n + m), which is optimal for this problem.

The solution works by maintaining a fixed-size vector to store the frequency differences of each character, making it both space-efficient and simple to implement. With its linear time complexity and constant space usage, this solution is well-suited for handling large strings, providing a fast and efficient way to calculate the minimum number of character replacements needed to make two strings anagrams.

This approach also showcases how simple data structures, such as arrays or vectors, can be leveraged to solve common string manipulation problems efficiently, while also making the code easy to understand and maintain.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/)

---
{{< youtube U7tKTEdd0Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
