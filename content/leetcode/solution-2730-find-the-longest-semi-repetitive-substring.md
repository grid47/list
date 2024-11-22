
+++
authors = ["grid47"]
title = "Leetcode 2730: Find the Longest Semi-Repetitive Substring"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2730: Find the Longest Semi-Repetitive Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "x_tHB_M7a_g"
youtube_upload_date="2023-06-10"
youtube_thumbnail="https://i.ytimg.com/vi/x_tHB_M7a_g/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        vector<int> sem(10, 0);
        int cnt = 0;
        
        int j = 0, len = 1;        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                sem[s[i] - '0']++;
            }
            while(cnt > 1 && j < i) {
                if(s[j] == s[j + 1]) {
                    sem[s[j] - '0']--;
                    cnt--;
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the length of the longest semi-repetitive substring in a given string `s`. A semi-repetitive substring is defined as a substring that contains at most one pair of consecutive repeating characters. This means that the substring can contain one occurrence of two consecutive characters being the same, but no more. 

### Approach

To solve this problem, we need to find the longest possible substring such that there is at most one pair of consecutive repeating characters. To efficiently handle this, we can use the sliding window technique, where we maintain a dynamic window of characters and adjust its size based on the number of consecutive repeating characters within it.

The sliding window technique allows us to maintain a substring and gradually expand or contract the window based on certain conditions, helping us to find the longest substring that satisfies the condition of having at most one pair of consecutive repeating characters.

### Step-by-Step Explanation

#### Step 1: Initialize Variables
```cpp
vector<int> sem(10, 0);
int cnt = 0;
int j = 0, len = 1;
```
- `sem` is an array that tracks the frequency of each digit (0-9) within the current sliding window.
- `cnt` is a counter that tracks the number of consecutive repeating characters in the current window.
- `j` is the left pointer of the sliding window, which moves when we encounter more than one pair of consecutive repeating characters.
- `len` is the variable that keeps track of the length of the longest valid semi-repetitive substring found so far.

#### Step 2: Traverse the String with the Right Pointer
```cpp
for(int i = 1; i < s.size(); i++) {
    if(s[i] == s[i - 1]) {
        cnt++;
        sem[s[i] - '0']++;
    }
```
- We iterate through the string using a loop starting from the second character (`i = 1`). 
- For each character at index `i`, we compare it with the previous character (`s[i - 1]`).
- If the current character is equal to the previous one (`s[i] == s[i - 1]`), it means we have encountered a consecutive repeating character. 
- We increment the `cnt` variable to keep track of how many such consecutive pairs are in the current window.
- Additionally, we update the `sem` array for the digit that repeats, to keep track of the frequency of each digit in the current window.

#### Step 3: Adjust the Window to Satisfy the Condition
```cpp
while(cnt > 1 && j < i) {
    if(s[j] == s[j + 1]) {
        sem[s[j] - '0']--;
        cnt--;
    }
    j++;
}
```
- If at any point `cnt` exceeds 1, it means we have encountered more than one pair of consecutive repeating characters in the window.
- To correct this, we start moving the left pointer (`j`) to the right to reduce the window size, effectively removing characters from the start of the window.
- For each character removed from the window, if it forms a consecutive pair with the next character (`s[j] == s[j + 1]`), we decrement the `sem` count for that digit and decrease `cnt` by 1.
- This ensures that we always maintain a window with at most one pair of consecutive repeating characters.

#### Step 4: Update the Maximum Length
```cpp
len = max(len, i - j + 1);
```
- After adjusting the window to satisfy the condition, we compute the current window length as `i - j + 1` and update the `len` variable to keep track of the maximum length of valid semi-repetitive substrings found so far.

#### Step 5: Return the Result
```cpp
return len;
```
- Finally, once we have iterated through the entire string, we return the maximum length of the semi-repetitive substring found.

### Complexity Analysis

#### Time Complexity
The time complexity of this solution is **O(n)**, where `n` is the length of the input string `s`. This is because the sliding window technique ensures that each character is processed at most twice: once when expanding the window with the right pointer (`i`) and once when contracting the window with the left pointer (`j`). Therefore, the algorithm runs in linear time relative to the size of the input string.

#### Space Complexity
The space complexity is **O(1)**, as the algorithm only uses a fixed-size array `sem` of length 10 to store the frequency of digits and a few integer variables (`cnt`, `j`, and `len`). The space required does not depend on the size of the input string, so it is constant.

### Conclusion

The problem of finding the longest semi-repetitive substring in a string can be efficiently solved using the sliding window technique. The sliding window approach ensures that we examine each character only a limited number of times, making the solution optimal with a time complexity of **O(n)**. This approach also uses constant space, which makes it very space-efficient.

The key insight in solving this problem is to track the number of consecutive repeating characters in the current window and adjust the window size to ensure that there is at most one such pair. By using this approach, we can find the longest valid semi-repetitive substring in linear time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/)

---
{{< youtube x_tHB_M7a_g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
