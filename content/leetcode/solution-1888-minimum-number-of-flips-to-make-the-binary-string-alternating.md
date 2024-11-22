
+++
authors = ["grid47"]
title = "Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MOeuK6gaC2A"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/MOeuK6gaC2A/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1 = "", s2 = "";
        for(int i = 0; i < s.size(); i++) {
            s1 += i % 2? '0': '1';
            s2 += i % 2? '1': '0';
        }
        
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for(int i = 0; i < s.size(); i++) {
            if(s1[i] != s[i]) ans1++;
            if(s2[i] != s[i]) ans2++;
            if(i >= n) {
                if(s1[i - n] != s[i - n]) ans1--;
                if(s2[i - n] != s[i - n]) ans2--;
            }
            if(i >= n - 1)
                ans = min({ans1, ans2, ans});
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the minimum number of flips required to make a given binary string alternate between '0's and '1's. An alternating string is one that consists of characters that change with each position, such as "010101" or "101010". The challenge is to find the fewest number of character flips (changing '0' to '1' or '1' to '0') necessary to achieve this alternating pattern.

### Approach

To solve this problem, we will take the following steps:

1. **Duplicate the String**: Concatenate the original string with itself. This allows us to easily check for alternating patterns over the length of the string without running into index issues.
2. **Create Target Patterns**: Generate two target patterns, `s1` and `s2`, which represent the two possible valid alternating strings. `s1` will start with '0' and `s2` will start with '1'.
3. **Count Flips**: As we iterate through the concatenated string, we will maintain counts of how many flips are needed to match either `s1` or `s2`.
4. **Sliding Window Technique**: Implement a sliding window of size `n` (the length of the original string) to determine the minimum flips needed as we move through the concatenated string.

### Code Breakdown (Step by Step)

1. **Class Definition**: We define the `Solution` class to contain our method.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Declaration**: The `minFlips` function is declared, taking a string `s` as an input.

   ```cpp
       int minFlips(string s) {
   ```

3. **Variable Initialization**: We initialize variables to store the length of the string `n`, and create two target strings `s1` and `s2`.

   ```cpp
           int n = s.size();
           s += s; // Duplicate the string
           string s1 = "", s2 = "";
   ```

4. **Generate Target Patterns**: We loop through the length of the duplicated string to fill `s1` and `s2` with the appropriate alternating characters.

   ```cpp
           for(int i = 0; i < s.size(); i++) {
               s1 += i % 2 ? '0' : '1'; // Alternating pattern starting with '1'
               s2 += i % 2 ? '1' : '0'; // Alternating pattern starting with '0'
           }
   ```

5. **Initialize Flip Counters**: Initialize counters for the number of flips needed for both patterns (`ans1` and `ans2`), as well as a variable to store the minimum flips found.

   ```cpp
           int ans1 = 0, ans2 = 0, ans = INT_MAX;
   ```

6. **Count Flips**: We iterate through the concatenated string, comparing each character to the corresponding character in `s1` and `s2`. We increment the respective flip counters when there is a mismatch.

   ```cpp
           for(int i = 0; i < s.size(); i++) {
               if(s1[i] != s[i]) ans1++;
               if(s2[i] != s[i]) ans2++;
   ```

7. **Sliding Window Adjustment**: If we have reached the length of the original string, we check if any characters that are sliding out of the window need to be decremented from our flip counts.

   ```cpp
               if(i >= n) {
                   if(s1[i - n] != s[i - n]) ans1--;
                   if(s2[i - n] != s[i - n]) ans2--;
               }
   ```

8. **Update Minimum Flips**: When the window size is sufficient (i.e., `i >= n - 1`), we check the minimum flips needed across both patterns.

   ```cpp
               if(i >= n - 1)
                   ans = min({ans1, ans2, ans});
           }
   ```

9. **Return Result**: Finally, return the minimum number of flips required to convert the original string into an alternating string.

   ```cpp
           return ans;
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the length of the original string. This is because we perform a constant amount of work (comparisons and arithmetic operations) for each character in the string during the iteration.
  
- **Space Complexity**: The space complexity is \( O(n) \) due to the creation of the duplicated string and the two target patterns.

### Conclusion

The provided solution effectively calculates the minimum number of flips required to convert a binary string into one of two alternating patterns. By leveraging string duplication, character comparison, and a sliding window technique, it optimally determines the fewest operations needed.

This solution showcases the application of fundamental algorithmic concepts such as string manipulation, counting, and windowing, making it suitable for similar problems in competitive programming and software development.

In conclusion, this approach is efficient, clear, and easily adaptable to variations of the problem, demonstrating a solid understanding of string handling and algorithm design principles. Such techniques can be valuable in a range of programming tasks, from basic challenges to complex applications in data processing and analysis.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/)

---
{{< youtube MOeuK6gaC2A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
