
+++
authors = ["grid47"]
title = "Leetcode 2266: Count Number of Texts"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2266: Count Number of Texts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LdM0WLfhF_4"
youtube_upload_date="2022-05-08"
youtube_thumbnail="https://i.ytimg.com/vi/LdM0WLfhF_4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] % mod;
            if(i > 1 && s[i - 1] == s[i - 2]) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
                if(i > 2 && s[i - 1] == s[i - 3]) {
                    dp[i] = (dp[i] + dp[i - 3]) % mod;
                    if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
                        dp[i] = (dp[i] + dp[i - 4]) % mod;                        
                    }
                }
            }
        }

        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves counting the total number of ways to transform a string `s` into a sequence of valid text messages, given a specific encoding rule for consecutive digits. The key challenge lies in figuring out how many different valid interpretations or groupings can be made by considering the digits of the string.

Each digit corresponds to a set of potential letter groupings (similar to a T9 predictive text input system). For example:
- Digits `2` through `9` each map to multiple letters:
  - `2 -> "abc"`, `3 -> "def"`, `4 -> "ghi"`, etc.
  - Additionally, digits like `7` and `9` are special because they map to 4 letters (`7 -> "pqrs"` and `9 -> "wxyz"`), meaning certain digits can be grouped in a string in different ways.

The task is to count the number of ways to divide the string into valid segments, adhering to the above rules. 

### Approach

This problem can be solved using **Dynamic Programming** (DP) to store intermediate results, where the `dp[i]` represents the number of valid ways to interpret the first `i` characters of the string `s`. We calculate `dp[i]` by considering different possible valid groupings that can end at position `i`.

The dynamic programming solution relies on the following key ideas:
1. **Base Case**: There is exactly one way to interpret an empty string: `dp[0] = 1`.
2. **Recursion**: For each index `i`, there are multiple possibilities for forming valid groups:
   - We can add just the current digit `s[i-1]` as a valid single-digit group.
   - If the last two digits are the same, we can group them together as a valid two-digit group.
   - If the last three digits are the same, we can group them together as a valid three-digit group.
   - Special consideration is given to digits `7` and `9` as they can form four-character groups (e.g., `7777` or `9999`).

By iterating through the string and using dynamic programming to count valid interpretations, we can compute the result efficiently.

### Code Breakdown (Step by Step)

#### Step 1: Initialization and Setup

```cpp
int mod = 1e9 + 7;
```
- A large modulo value `1e9 + 7` is used to ensure that the result doesn’t overflow, as the answer can be very large.

```cpp
int n = s.size();
vector<int> dp(n + 1, 0);
dp[0] = 1;
```
- `n` is the length of the input string `s`.
- A vector `dp` of size `n + 1` is initialized, where each `dp[i]` stores the number of ways to interpret the first `i` characters of the string. We start by setting `dp[0] = 1`, as there is exactly one way to interpret an empty string.

#### Step 2: Main Loop for Dynamic Programming

```cpp
for(int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] % mod;
```
- The loop iterates through each index of the string `s`, and for each index `i`, we initially set `dp[i]` to `dp[i - 1]` modulo `mod`. This is the case where we consider adding the single character `s[i-1]` as a valid group (i.e., it doesn’t form any special grouping with the previous characters).

#### Step 3: Handle Special Groupings of Two, Three, and Four Digits

##### Case 1: Two Consecutive Identical Digits
```cpp
if(i > 1 && s[i - 1] == s[i - 2]) {
    dp[i] = (dp[i] + dp[i - 2]) % mod;
```
- If the current character `s[i-1]` is equal to the previous character `s[i-2]`, we can form a valid two-digit group, and we add the number of ways to interpret the first `i-2` characters to `dp[i]`.

##### Case 2: Three Consecutive Identical Digits
```cpp
if(i > 2 && s[i - 1] == s[i - 3]) {
    dp[i] = (dp[i] + dp[i - 3]) % mod;
```
- Similarly, if the last three digits are the same, we can group them together and add the number of ways to interpret the first `i-3` characters.

##### Case 3: Four Consecutive Identical Digits for '7' and '9'
```cpp
if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
    dp[i] = (dp[i] + dp[i - 4]) % mod;
}
```
- Special handling is done for digits `7` and `9`, as they map to 4 possible characters. If we encounter four consecutive `7`s or `9`s, we allow this grouping as a valid four-digit group.

#### Step 4: Final Result

```cpp
return dp[n];
```
- Finally, the value at `dp[n]` will contain the total number of ways to interpret the entire string `s` based on the described grouping rules.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the length of the string `s`. This is because we are iterating through the string once and performing constant-time operations for each character (checking for possible two-digit, three-digit, and four-digit groupings).

#### Space Complexity:
The space complexity is **O(n)**, as we store the results for each position in the string in the `dp` array of size `n + 1`.

### Conclusion

This solution efficiently counts the number of valid groupings for the given string `s`, considering the various valid group sizes (1, 2, 3, or 4 digits). By using dynamic programming, we ensure that we compute the result in linear time, making this approach both time-efficient and space-efficient. The use of modulo `1e9 + 7` ensures that the result remains within a manageable range, preventing overflow. The problem is solved optimally with a complexity of **O(n)**, which is suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-texts/description/)

---
{{< youtube LdM0WLfhF_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
