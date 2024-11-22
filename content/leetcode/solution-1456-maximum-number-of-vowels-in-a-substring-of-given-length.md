
+++
authors = ["grid47"]
title = "Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tal8tKUr6dU"
youtube_upload_date="2023-05-06"
youtube_thumbnail="https://i.ytimg.com/vi/tal8tKUr6dU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                        0,0,0,0,1, 0,0,0,0,0, 
                        1,0,0,0,0, 0 };
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i = 0, cur = 0; i < s.size(); i++) {
            cur += vowels[s[i] - 'a'];
            if(i >= k) cur -= vowels[s[i-k] - 'a'];
            mx = max(cur, mx);
        }
        return mx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective is to find the maximum number of vowels in any contiguous substring of a given length \( k \) from the input string \( s \). A vowel is defined as one of the characters 'a', 'e', 'i', 'o', or 'u'. The solution should be efficient and should work for strings of varying lengths and compositions.

### Approach

To solve this problem, we can employ a sliding window technique, which allows us to maintain a window of length \( k \) as we traverse through the string. This approach enables us to calculate the number of vowels in each substring of length \( k \) without needing to count the vowels from scratch for each new substring.

1. **Initialize a Vowel Lookup**: Create an array that indicates whether a character is a vowel.
2. **Use a Sliding Window**: Traverse the string while maintaining the count of vowels in the current window.
3. **Update Count Dynamically**: When the window moves, subtract the vowel count of the character that is sliding out of the window and add the count of the character that is sliding into the window.
4. **Track the Maximum**: Throughout the traversal, keep track of the maximum number of vowels encountered in any window of size \( k \).

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

1. **Class Declaration**:
   ```cpp
   class Solution {
   ```

   - The solution is encapsulated within a class named `Solution`, as is typical in competitive programming.

2. **Vowel Lookup Array**:
   ```cpp
   int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                       0,0,0,0,1, 0,0,0,0,0, 
                       1,0,0,0,0, 0 };
   ```

   - An integer array named `vowels` is defined with a size of 26 (for each letter of the alphabet). Each position corresponds to a letter ('a' corresponds to index 0, 'b' to index 1, and so on).
   - The value at each index is `1` if the corresponding letter is a vowel (i.e., 'a', 'e', 'i', 'o', 'u') and `0` otherwise.

3. **Function Declaration**:
   ```cpp
   int maxVowels(string s, int k) {
   ```

   - The function `maxVowels` takes a string `s` and an integer `k`, representing the length of the substring to be evaluated.

4. **Variable Initialization**:
   ```cpp
       int mx = 0;
   ```

   - A variable `mx` is initialized to store the maximum number of vowels found in any substring of length \( k \).

5. **Sliding Window Logic**:
   ```cpp
       for(int i = 0, cur = 0; i < s.size(); i++) {
           cur += vowels[s[i] - 'a'];
   ```

   - A for-loop is initiated to iterate over each character in the string \( s \). The variable `cur` is used to count the number of vowels in the current window.
   - For each character, the code adds `1` to `cur` if the character is a vowel (using the `vowels` array).

6. **Adjusting for Window Size**:
   ```cpp
           if(i >= k) cur -= vowels[s[i-k] - 'a'];
   ```

   - When the index `i` is greater than or equal to \( k \), it indicates that the window has reached its maximum size. The character that is sliding out of the window (at index `i - k`) is subtracted from the count of vowels in `cur`.

7. **Update Maximum Vowel Count**:
   ```cpp
           mx = max(cur, mx);
       }
   ```

   - The maximum number of vowels found so far is updated by comparing `cur` with `mx`.

8. **Return the Result**:
   ```cpp
       return mx;
   }
   ```

   - Finally, the function returns the maximum count of vowels found in any substring of length \( k \).

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the length of the string \( s \). This efficiency is achieved because we make a single pass through the string, updating counts in constant time for each character.
  
- **Space Complexity**: The space complexity is \( O(1) \) because the size of the `vowels` array is constant (26), and we use only a few integer variables regardless of the input size.

### Conclusion

The provided code effectively counts the maximum number of vowels in any substring of a specified length \( k \) using a sliding window approach. 

#### Key Takeaways:

1. **Sliding Window Technique**: This approach is optimal for problems involving contiguous subarrays or substrings, as it allows for efficient updates as the window moves.

2. **Predefined Lookups**: Using an array to mark vowels enables quick access to check whether a character is a vowel or not.

3. **Efficiency**: The method is both time-efficient and space-efficient, making it suitable for larger inputs.

4. **Clarity**: The code is straightforward and easy to understand, demonstrating clear logic that can be easily followed.

In summary, this solution serves as a great example of how to leverage efficient algorithms and data structures to solve common string manipulation problems in a clear and effective manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

---
{{< youtube tal8tKUr6dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
