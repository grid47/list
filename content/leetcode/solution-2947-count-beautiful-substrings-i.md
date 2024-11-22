
+++
authors = ["grid47"]
title = "Leetcode 2947: Count Beautiful Substrings I"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2947: Count Beautiful Substrings I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Enumeration","Number Theory","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AnuZGQmVPQM"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AnuZGQmVPQM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) { return st.find(c) != st.end(); }
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            int vow = 0, con = 0;
            for(int j = i; j < s.size(); ++j) {
                (isVowel(s[j]))? vow++: con++;
                if(vow == con && (vow*con)%k == 0) ans++;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement:
The task is to find all "beautiful" substrings within a given string `s` of lowercase English letters, where a substring is considered beautiful if it contains an equal number of vowels and consonants and the product of the number of vowels and consonants is divisible by a given integer `k`. We need to count how many such substrings exist in the string `s`.

### Approach:
To solve this problem, we need to explore each substring of the string `s` and check if it satisfies the given conditions:
1. The number of vowels equals the number of consonants.
2. The product of the number of vowels and consonants is divisible by `k`.

The approach consists of iterating through all possible substrings, counting vowels and consonants, and checking the two conditions mentioned above.

#### Key Observations:
- **Vowels and Consonants Counting**: We can quickly check whether a character is a vowel using a set of vowels (`'a', 'e', 'i', 'o', 'u'`), and anything that is not a vowel will be treated as a consonant.
- **Efficient Checking**: Instead of checking every possible substring in a brute-force manner, we can keep a running tally of the number of vowels and consonants as we iterate through the string.
  
### Code Breakdown (Step by Step):

#### 1. **Initialization of Vowels Set**:
The `unordered_set` `st` is initialized with the vowels `'a', 'e', 'i', 'o', 'u'`. This set will help quickly check if a character is a vowel or not by using the `find` method.

```cpp
unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
```

We also define the helper function `isVowel`, which checks if a character is in the set `st`.

```cpp
bool isVowel(char c) { return st.find(c) != st.end(); }
```

This function returns `true` if `c` is a vowel and `false` otherwise.

#### 2. **Outer Loop for Starting Index of Substrings**:
We start by iterating over all possible starting points of the substrings, from index `0` to `s.size() - 1`. For each starting index `i`, we will count the number of vowels and consonants as we expand the substring.

```cpp
for(int i = 0; i < s.size(); ++i){
```

#### 3. **Inner Loop for Expanding the Substring**:
For each starting index `i`, we use a second loop to explore substrings that start at `i` and end at index `j` (where `j` ranges from `i` to `s.size() - 1`). For each such substring, we will update the counts of vowels and consonants.

```cpp
int vow = 0, con = 0;
for(int j = i; j < s.size(); ++j) {
    (isVowel(s[j])) ? vow++ : con++;
```

Here, `vow` and `con` track the number of vowels and consonants, respectively. If the character `s[j]` is a vowel (determined by `isVowel`), we increment the vowel counter `vow`, otherwise, we increment the consonant counter `con`.

#### 4. **Check the Conditions**:
After updating the counts of vowels and consonants for the current substring, we check the two conditions:
1. The number of vowels equals the number of consonants.
2. The product of the number of vowels and consonants is divisible by `k`.

```cpp
if(vow == con && (vow * con) % k == 0) ans++;
```

If both conditions are satisfied, we increment the result counter `ans`.

#### 5. **Return the Result**:
Once both loops have iterated through all possible substrings, we return the total count of "beautiful" substrings.

```cpp
return ans;
```

### Complexity:

#### Time Complexity:
- The solution involves two nested loops. The outer loop iterates over all possible starting points of the substrings, and the inner loop iterates over all possible ending points of the substrings for each starting point.
- The total number of substrings in the string `s` is roughly `n * (n + 1) / 2`, where `n` is the length of the string.
- For each substring, checking if the number of vowels equals the number of consonants and if their product is divisible by `k` is constant time, `O(1)`.
- Therefore, the overall time complexity is `O(n^2)`.

#### Space Complexity:
- The space complexity is dominated by the space required for the unordered set `st` that holds the vowels, which is `O(1)` since it always contains a fixed number of vowels (five).
- There are no other significant space requirements, so the space complexity is `O(1)`.

### Conclusion:
This approach efficiently counts the number of "beautiful" substrings in the given string by iterating over all possible substrings and checking if they meet the two conditions: the number of vowels equals the number of consonants, and their product is divisible by `k`. 

#### Key Insights:
- **Vowel and Consonant Counting**: The problem leverages the ability to efficiently count vowels and consonants using a helper function and an unordered set.
- **Efficient Checking**: By iterating over all possible substrings and checking the conditions in constant time, the solution avoids the need for more complex optimizations.
- **Time Complexity**: The time complexity of `O(n^2)` is manageable for strings of moderate length but could become inefficient for very large strings. However, the solution works well within typical problem constraints.

This solution provides a simple and effective way to solve the problem while maintaining clarity and correctness.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-beautiful-substrings-i/description/)

---
{{< youtube AnuZGQmVPQM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
