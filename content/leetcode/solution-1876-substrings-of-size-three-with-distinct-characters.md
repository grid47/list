
+++
authors = ["grid47"]
title = "Leetcode 1876: Substrings of Size Three with Distinct Characters"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1876: Substrings of Size Three with Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QIyWjKNstAA"
youtube_upload_date="2021-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QIyWjKNstAA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int cnt = 0;
        for(int i = 2; i < s.size(); i++)
            if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;

            return cnt;

    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to count the number of "good substrings" of length 3 in a given string \( s \). A substring is defined as "good" if all three characters in that substring are distinct. This requires us to traverse the string and evaluate each substring of length 3, checking whether the characters at the three indices are different from one another.

### Approach

To efficiently count the good substrings, we can utilize a straightforward loop that iterates through the string while checking each triplet of consecutive characters. The approach can be broken down into the following steps:

1. **Initialization**: Start by creating a counter `cnt` that will keep track of the number of good substrings found.

2. **Iterate Through the String**: Begin iterating from the third character (index 2) to the end of the string, since we need to form substrings of length 3.

3. **Check Conditions**: For each index \( i \):
   - Check if the character at index \( i \) is different from the character at index \( i-1 \).
   - Check if the character at index \( i-1 \) is different from the character at index \( i-2 \).
   - Check if the character at index \( i-2 \) is different from the character at index \( i \).
   - If all three conditions are satisfied, increment the counter `cnt`.

4. **Return the Result**: After finishing the iteration, return the value of `cnt`, which will represent the total number of good substrings found in the string.

### Code Breakdown (Step by Step)

1. **Class Definition**: The code is encapsulated within a class called `Solution`, which follows the common pattern used in competitive programming and coding interviews.

    ```cpp
    class Solution {
    public:
    ```

2. **Function Declaration**: The function `countGoodSubstrings` is declared, which takes a string \( s \) as input and returns an integer representing the count of good substrings.

    ```cpp
    int countGoodSubstrings(string s) {
    ```

3. **Initialization**: Inside the function, we initialize a counter variable `cnt` to zero, which will track the number of good substrings.

    ```cpp
    int cnt = 0;
    ```

4. **Iterate Through the String**: We begin a loop starting from index 2, as we need to check triplets of characters.

    ```cpp
    for(int i = 2; i < s.size(); i++)
    ```

5. **Check for Good Substrings**: Within the loop, we perform the necessary checks to determine if the substring formed by the characters at indices \( i-2 \), \( i-1 \), and \( i \) is good:

    ```cpp
    if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;
    ```

6. **Return the Count**: After the loop, we return the total count of good substrings.

    ```cpp
    return cnt;
    }
    ```

### Complexity

The time complexity of this solution is \( O(n) \), where \( n \) is the length of the string \( s \). This is because we are iterating through the string a single time, performing constant-time checks for each triplet of characters. The space complexity is \( O(1) \) since we are only using a fixed number of extra variables regardless of the input size.

### Conclusion

In conclusion, the `countGoodSubstrings` function efficiently counts the number of good substrings of length 3 in a given string by leveraging a simple iterative approach. The use of basic comparisons allows the solution to maintain a linear time complexity, making it scalable for longer strings. This approach demonstrates the effective use of straightforward logic and conditions to solve substring-related problems.

This solution not only serves as a practical method for counting distinct-character triplets but also lays the groundwork for more complex string manipulation problems encountered in various competitive programming scenarios. Understanding and applying these principles will enhance problem-solving skills and prepare one for tackling similar challenges in the future.

[`Link to LeetCode Lab`](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

---
{{< youtube QIyWjKNstAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
