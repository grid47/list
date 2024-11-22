
+++
authors = ["grid47"]
title = "Leetcode 2068: Check Whether Two Strings are Almost Equivalent"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2068: Check Whether Two Strings are Almost Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l_KAgx9c8Mc"
youtube_upload_date="2021-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/l_KAgx9c8Mc/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to determine whether two given strings, `s` and `t`, can be considered "almost equivalent." Specifically, two strings are defined as almost equivalent if the absolute difference in the frequency of any character between the two strings does not exceed three. This means that for each character from 'a' to 'z', the difference between the counts of that character in `s` and `t` should be at most 3.

### Approach

To solve this problem, we can follow these steps:

1. **Character Count Calculation**: We will maintain a frequency count of characters for both strings. This involves iterating through each character in the strings and updating a count array that records the frequency of each character.

2. **Difference Evaluation**: Once we have the character frequencies, we will check the differences in frequency for each character. If the difference for any character exceeds 3, the strings are not almost equivalent. Otherwise, they are considered almost equivalent.

3. **Return Result**: Finally, based on the evaluation of differences, we will return `true` if the strings are almost equivalent and `false` otherwise.

### Code Breakdown (Step by Step)

1. **Character Count Array Initialization**: We declare an integer array `cnt` of size 26 (for each letter of the English alphabet) and initialize it to zero. This array will help us keep track of the frequency differences between the two strings.

   ```cpp
   int cnt[26] = {};
   ```

2. **Count Characters from String `s`**: We iterate through each character in the string `s`. For each character, we calculate its corresponding index (based on its ASCII value) and increment the count at that index. This step effectively counts how many times each character appears in `s`.

   ```cpp
   for (char c : s) cnt[c - 'a']++;
   ```

3. **Count Characters from String `t`**: We perform a similar iteration for string `t`, but instead of incrementing the count, we decrement it. This will allow us to evaluate the frequency differences directly within the same count array.

   ```cpp
   for (char c : t) cnt[c - 'a']--;
   ```

4. **Evaluate Frequency Differences**: After processing both strings, we loop through the count array to check the absolute values of the counts. If any count exceeds 3, we immediately return `false`, indicating that the strings are not almost equivalent.

   ```cpp
   for (int i = 0; i < 26; ++i) {
       if (abs(cnt[i]) > 3) return false;
   }
   ```

5. **Return Result**: If we complete the loop without finding any differences greater than 3, we return `true`, indicating that the strings are almost equivalent.

   ```cpp
   return true;
   ```

### Complexity

- **Time Complexity**: O(n + m), where `n` is the length of string `s` and `m` is the length of string `t`. The algorithm iterates through both strings once to calculate character counts and then once more through the count array, resulting in a linear time complexity relative to the size of the input.

- **Space Complexity**: O(1). The space complexity is constant because we use a fixed-size array of size 26, regardless of the input size. This means that the space requirement does not grow with the input size, making the solution efficient in terms of memory usage.

### Conclusion

The solution provided efficiently determines whether two strings are almost equivalent by leveraging a simple character frequency counting approach combined with a constant space evaluation of differences. This method is effective and straightforward, ensuring clarity and maintainability. The time complexity remains optimal for the problem, and the space usage is minimal, making it a robust solution for scenarios where such string comparison tasks are needed. 

Overall, this implementation serves as an excellent example of how to handle string manipulation problems in competitive programming and software development, offering both performance and ease of understanding for future adaptations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/)

---
{{< youtube l_KAgx9c8Mc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
