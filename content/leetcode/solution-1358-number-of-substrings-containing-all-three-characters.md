
+++
authors = ["grid47"]
title = "Leetcode 1358: Number of Substrings Containing All Three Characters"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1358: Number of Substrings Containing All Three Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSubstrings(string s) {
        return atmost(s, 3) - atmost(s, 2);
    }
    int atmost(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
            if(ma[s[i]] == 1) k--;
            while(k < 0) {
                ma[s[j]]--;
                if(ma[s[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to count the number of substrings within a given string `s` that contain at most `k` distinct characters. The method implemented is specifically designed to count the substrings that contain exactly 1, 2, or 3 distinct characters. The overall goal is to find the count of substrings with exactly 3 distinct characters by utilizing the counts of substrings with at most 2 and 3 distinct characters.

### Approach
1. **Two-Pointer Technique**: This approach employs the two-pointer or sliding window technique to efficiently count the number of valid substrings. 
2. **Counting Substrings with At Most k Distinct Characters**: The function `atmost` is implemented to count the number of substrings that have at most `k` distinct characters. This function is called twice:
   - Once for `k = 3` to count substrings with at most 3 distinct characters.
   - Once for `k = 2` to count substrings with at most 2 distinct characters.
3. **Subtracting Counts**: The difference between the results of these two calls gives the count of substrings with exactly 3 distinct characters.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        // Calculate the number of substrings with exactly 3 distinct characters
        return atmost(s, 3) - atmost(s, 2);
    }

    int atmost(string s, int k) {
        map<char, int> ma; // To store the count of each character
        int res = 0, j = 0; // res to store the result, j for the left pointer
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++; // Increment count of the current character
            if(ma[s[i]] == 1) k--; // New character found, decrement k
            // Adjust the left pointer j to maintain at most k distinct characters
            while(k < 0) {
                ma[s[j]]--; // Decrease the count of the character at j
                if(ma[s[j]] == 0) k++; // If count becomes 0, increment k
                j++; // Move the left pointer to the right
            }
            // Count the number of valid substrings ending at i
            res += (i - j + 1);
        }
        return res; // Return the total count of valid substrings
    }
};
```

1. **Function `numberOfSubstrings`**: This function orchestrates the counting process. It returns the difference between the number of substrings with at most 3 and at most 2 distinct characters. This effectively counts substrings with exactly 3 distinct characters.
   
2. **Function `atmost`**: This function takes a string and an integer `k`, and counts all substrings that contain at most `k` distinct characters:
   - **Map Initialization**: It uses a map `ma` to keep track of the frequency of characters in the current window.
   - **Iterating Through the String**: The outer loop iterates through the string using index `i` (right pointer). For each character, its count in the map is incremented.
   - **Updating Distinct Count**: If a new character is added to the window, `k` is decremented. If `k` becomes negative (indicating more than `k` distinct characters), the inner loop adjusts the left pointer `j` to reduce the window size until there are at most `k` distinct characters.
   - **Counting Valid Substrings**: The count of valid substrings that end at index `i` is added to `res`, which is calculated as the size of the current window (`i - j + 1`).
   
3. **Return Statement**: The function returns the total count of valid substrings.

### Complexity Analysis
- **Time Complexity**:
  - The overall time complexity of the algorithm is \(O(n)\), where \(n\) is the length of the string. This is due to the two-pointer technique, where each character is processed a limited number of times as the pointers `i` and `j` traverse the string.
  
- **Space Complexity**:
  - The space complexity is \(O(k)\), where \(k\) is the number of distinct characters being tracked. In the worst case (where all characters are distinct), this would be \(O(1)\) since the character set size is constant (26 for lowercase English letters).

### Conclusion
The `numberOfSubstrings` method effectively counts the number of substrings in a given string that contain exactly 3 distinct characters. By leveraging the two-pointer technique and a frequency map, the solution remains efficient even for larger input sizes. This approach not only optimizes the counting process but also highlights the importance of understanding distinct character constraints in substring problems.

This explanation serves as an educational resource for understanding how to tackle substring-related problems using efficient algorithms and data structures, providing insight into both the coding aspect and the underlying logic.


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
