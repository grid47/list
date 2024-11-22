
+++
authors = ["grid47"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1234: Replace the Substring for Balanced String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
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
    int balancedString(string s) {
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        int k = s.size() / 4, j = 0, res = s.size();
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
        while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem requires determining the minimum number of characters that need to be replaced in a given string, `s`, composed of the characters 'Q', 'W', 'E', and 'R', to make the string "balanced." A balanced string has an equal number of each character, which means that in a string of length `n`, each character should appear exactly `n/4` times. The goal is to find the minimum substring length that can be replaced to achieve this balance.

### Approach
To solve the problem efficiently, we can utilize the sliding window technique along with a frequency map to keep track of character counts. The steps involved in the approach are as follows:

1. **Count Frequencies**: First, we count the frequency of each character in the string using a map (or dictionary). This helps in determining how many of each character exist in the string.

2. **Determine Required Count**: We calculate the desired count of each character for the string to be balanced, which is given by `k = s.size() / 4`.

3. **Use Sliding Window Technique**: We then use two pointers (a sliding window) to find the smallest substring that can be replaced to achieve balance:
   - Expand the right pointer to include characters until the substring becomes unbalanced.
   - Once it becomes unbalanced, increment the left pointer to shrink the window while checking if the substring can still maintain balance.
   - Throughout this process, keep track of the minimum length of the valid substring.

4. **Return the Result**: The minimum length of the substring found during the sliding window traversal is returned as the result.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int balancedString(string s) {
```
- **Lines 1-2**: We define the `Solution` class and start the `balancedString` method, which takes a string `s` as input.

```cpp
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
```
- **Lines 3-6**: We initialize a frequency map `ma` to count occurrences of each character in the string. The loop iterates through each character in `s`, incrementing the count for that character in the map.

```cpp
        int k = s.size() / 4, j = 0, res = s.size();
```
- **Line 7**: We calculate `k`, which represents the required frequency of each character in a balanced string. We also initialize `j` as the left pointer for our sliding window and `res` to hold the result, initialized to the maximum possible length of the substring (the entire string).

```cpp
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
```
- **Lines 8-9**: We start iterating with the right pointer `i`. For each character at position `i`, we decrement its count in the frequency map, simulating the addition of that character into our current window.

```cpp
            while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
```
- **Line 10**: We enter a while loop that checks if all characters 'Q', 'W', 'E', and 'R' are within the required frequency limit (less than or equal to `k`). This means the substring from `j` to `i` is balanced or can potentially be balanced by replacing characters.

```cpp
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
            }
        }
```
- **Lines 11-15**: Inside the while loop:
  - We increment the count of the character at position `j` (the left end of the window), effectively removing it from the current window.
  - We update `res` with the minimum of its current value and the length of the current window (`i - j + 1`).
  - Finally, we increment `j` to potentially narrow down the window for the next iteration.

```cpp
        return res;
    }
};
```
- **Lines 16-19**: After completing the loop through all characters, we return the value of `res`, which now contains the length of the minimum substring that can be replaced to achieve balance.

### Complexity
1. **Time Complexity**: The time complexity of the solution is \( O(n) \), where \( n \) is the length of the string `s`. This is because both pointers (`i` and `j`) traverse the string at most once, leading to a linear pass through the data.

2. **Space Complexity**: The space complexity is \( O(1) \), since the frequency map only needs to store a fixed number of characters ('Q', 'W', 'E', 'R') regardless of the input size. The size of the frequency map is constant (4 characters), so it does not grow with the input size.

### Conclusion
The `balancedString` function efficiently determines the minimum number of characters that need to be replaced in a string to make it balanced using a sliding window approach. By utilizing a frequency map to track character counts and dynamically adjusting the window size, the solution finds the optimal result in linear time. This method is effective for solving problems related to string manipulation and balancing character frequencies, making it a valuable technique in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
