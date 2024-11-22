
+++
authors = ["grid47"]
title = "Leetcode 3110: Score of a String"
date = "2024-01-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3110: Score of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "imbrLFL20tQ"
youtube_upload_date="2024-06-01"
youtube_thumbnail="https://i.ytimg.com/vi/imbrLFL20tQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum+=abs(s[i]-s[i+1]);
        }
        return sum;        
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given a string `s`, and we are tasked with computing a score based on the absolute differences between the ASCII values of consecutive characters in the string. The score is defined as the sum of the absolute differences between each pair of consecutive characters. We need to return the computed score.

For example:
- For the string `"abc"`, the score will be `abs('a' - 'b') + abs('b' - 'c') = 1 + 1 = 2`.
- For the string `"xyz"`, the score will be `abs('x' - 'y') + abs('y' - 'z') = 1 + 1 = 2`.

### Approach

The problem requires calculating the score of a string by summing up the absolute differences of the ASCII values of consecutive characters. This can be done efficiently by iterating through the string once and performing the necessary calculations.

#### Approach Outline:
1. **Iterate through the string**: We need to traverse through the string and compute the absolute difference between the ASCII values of each pair of consecutive characters.
2. **Calculate the absolute difference**: For each pair of consecutive characters, we calculate the absolute difference between their ASCII values.
3. **Accumulate the score**: Sum all the absolute differences to get the final score.
4. **Return the score**: After iterating through the string, return the accumulated score.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Sum
```cpp
int sum = 0;
```
- A variable `sum` is initialized to store the accumulated score. Initially, it's set to zero because the score starts from zero and will be incremented as we calculate the differences.

#### Step 2: Loop Through the String
```cpp
for(int i = 0; i < s.size() - 1; i++) {
    sum += abs(s[i] - s[i + 1]);
}
```
- The loop iterates through the string from the first character (`i = 0`) to the second-last character (`i < s.size() - 1`). 
- We stop at `s.size() - 1` because we are comparing consecutive characters, so the last character doesn't have a next character to compare with.
- **Inside the loop**: For each character at position `i` and its consecutive character at position `i+1`, the absolute difference between their ASCII values is calculated using the `abs` function. This difference is added to the running total `sum`.

#### Step 3: Return the Final Score
```cpp
return sum;
```
- After finishing the iteration through the string, we return the accumulated sum as the result. This value represents the score of the string.

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity is **O(n)**, where `n` is the length of the string `s`. We only need to iterate through the string once to calculate the score. In each iteration, we perform constant-time operations (computing the absolute difference and updating the sum). Thus, the time complexity is linear with respect to the size of the input string.

#### Space Complexity:
- **O(1)**: The space complexity is **O(1)**, as we are using only a constant amount of extra space. The only extra memory used is for the `sum` variable, and there are no additional data structures that grow with the input size. Therefore, the space complexity is constant.

### Conclusion

This problem involves calculating the score of a string based on the absolute differences between the ASCII values of consecutive characters. The solution leverages a simple linear pass through the string, making it both time-efficient and space-efficient.

By iterating through the string once and summing up the absolute differences of consecutive characters, we achieve a solution with **O(n)** time complexity and **O(1)** space complexity. This is optimal for this type of problem, as every character in the string must be inspected to compute the score.

The solution is straightforward and efficiently solves the problem by using a simple loop and the built-in `abs` function to calculate absolute differences. This makes the implementation clean and easy to understand while ensuring good performance even for larger input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/score-of-a-string/description/)

---
{{< youtube imbrLFL20tQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
