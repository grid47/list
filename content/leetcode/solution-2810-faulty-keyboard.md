
+++
authors = ["grid47"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2810: Faulty Keyboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HuCSgRBf-B8"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/HuCSgRBf-B8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto c : s){
            if(c == 'i'){
                if(res.size()){
                    reverse(res.begin(), res.end());
                }
                
            }else
             res+=c;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a string `s`, and you need to transform it based on specific rules. Whenever the character 'i' appears in the string, the string `res` (which is initially empty) should be reversed. For all other characters, append them to the string `res` as they are. Finally, return the modified string `res` after processing all characters in the input string.

The task is to process the string efficiently while handling the reverse operations triggered by the character 'i'. Understanding how to manage string reversals dynamically while iterating through the string is key to solving this problem.

### Approach

The problem requires us to dynamically update the string by reversing it when an 'i' is encountered, while appending other characters without any change. Here’s how we can approach it:

1. **Iterate Over the String**:
   - We will iterate through each character of the input string `s`. For each character:
     - If the character is 'i', we reverse the string `res`.
     - Otherwise, we append the character to `res`.

2. **Use a Temporary Result String (`res`)**:
   - The result string `res` is built incrementally. For each character:
     - If it is 'i', we reverse the current `res`.
     - If it is not 'i', we simply append the character to `res`.

3. **Reversal Logic**:
   - When encountering an 'i', we reverse the string using the built-in `reverse` function in C++ which operates in **O(n)** time, where `n` is the size of the string. 
   - The reversal is done directly on `res`, and we continue appending characters to it after reversing.

4. **Edge Cases**:
   - If there are multiple consecutive 'i's, each one will reverse the string, and every second 'i' effectively cancels the previous reversal.
   - If there are no 'i's in the string, the string will remain unchanged.
   - If the string starts with 'i', the result will be an empty string initially, which will then be reversed upon encountering the first 'i'.

### Code Breakdown (Step by Step)

1. **Function Definition**:
   ```cpp
   string finalString(string s) {
   ```
   - The function `finalString` takes a string `s` as input and returns the modified string after applying the rules described.

2. **Initialize Result String**:
   ```cpp
   string res = "";
   ```
   - We initialize an empty string `res` that will be used to build the result step by step.

3. **Iterate Over the Input String**:
   ```cpp
   for(auto c : s) {
   ```
   - We iterate over each character `c` in the input string `s`.

4. **Handle the Character 'i'**:
   ```cpp
   if(c == 'i') {
       if(res.size()) {
           reverse(res.begin(), res.end());
       }
   }
   ```
   - If the character `c` is 'i', we check if `res` has any content (i.e., its size is greater than 0).
   - If `res` is not empty, we reverse it using `reverse(res.begin(), res.end())`. This is the built-in C++ function to reverse a string in place.

5. **Append Other Characters**:
   ```cpp
   else
       res += c;
   ```
   - If the character is not 'i', we simply append it to `res`.

6. **Return the Result**:
   ```cpp
   return res;
   ```
   - After processing all characters in the string, we return the final string `res`, which contains the transformed string based on the 'i' reversal rule.

### Complexity

1. **Time Complexity**:
   - **Iterating Through the String**: We iterate over all characters in the input string `s` once. This takes **O(n)** time, where `n` is the length of the string.
   - **Reversal Operation**: Every time we encounter 'i', we reverse the string `res`. The reversal operation takes **O(k)** time, where `k` is the size of the current `res` string. In the worst case, `k` could be as large as `n`, leading to a time complexity of **O(n)** for each reversal.
   - **Overall Time Complexity**: Since we iterate over the string once and each reversal operation could take up to **O(n)** time, the worst-case time complexity is **O(n^2)**, where `n` is the length of the input string.

2. **Space Complexity**:
   - We use a string `res` to store the result, and the space required for `res` is proportional to the size of the input string. Therefore, the space complexity is **O(n)**, where `n` is the length of the string.

### Conclusion

This solution efficiently handles the reversal of the string when the character 'i' appears. By using a simple loop and dynamically updating the string, we transform the string according to the given rules. The space complexity is linear, and the time complexity is quadratic in the worst case due to the frequent reversal of the result string. This approach is simple to implement and works for typical input sizes, but performance may degrade if the string is very large due to repeated reversals. 

To optimize the solution for larger strings, additional techniques like counting reversals or using more efficient data structures could be explored. However, for most practical cases, this approach should work fine, as the task is inherently based on iterative string manipulation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/faulty-keyboard/description/)

---
{{< youtube HuCSgRBf-B8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
