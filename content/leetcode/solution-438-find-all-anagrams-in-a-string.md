
+++
authors = ["grid47"]
title = "Leetcode 438: Find All Anagrams in a String"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 438: Find All Anagrams in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/438.webp"
youtube = "G8xtZy0fDKg"
youtube_upload_date="2021-11-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/G8xtZy0fDKg/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/438.webp" 
    alt="A glowing string where anagrams light up and form matching groups as they are found."
    caption="Solution to LeetCode 438: Find All Anagrams in a String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0), sc(26, 0);
        for(char x: p)
            pc[x-'a']++;
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i >= p.size()) {
                sc[s[i - p.size()] - 'a']--;
            }
            sc[s[i]-'a']++;
            if(sc == pc) ans.push_back(i - p.size() +1);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find all the starting indices of anagrams of a string `p` within another string `s`. An anagram of a string is a rearrangement of its characters. For example, the anagrams of "abc" are "abc", "acb", "bac", "bca", "cab", and "cba". Given two strings `s` and `p`, you need to return the list of start indices of `p`'s anagrams in `s`.

### Approach

To solve this problem, we will use a **sliding window** approach combined with **frequency counting**. The sliding window allows us to efficiently check substrings of length `p.length()` within `s` as we move across the string. Frequency counting helps us determine whether a substring of `s` is an anagram of `p`.

The core idea is:
- Both the strings `s` and `p` consist of lowercase English letters, so we can use an array of size 26 to count the frequency of each character in the strings.
- The sliding window will check each substring of `s` that has the same length as `p`, adjusting the frequency counts as the window slides across the string.
- If the frequency count of the current window matches the frequency count of `p`, it means the substring is an anagram of `p`.

### Code Breakdown (Step by Step)

1. **Initialization**:
   - First, we initialize two vectors `pc` and `sc` to store the frequency counts of characters for `p` and the current sliding window in `s`. Each vector has 26 elements (one for each letter of the alphabet), initialized to 0.
   - We also initialize an empty vector `ans` to store the indices where anagrams are found.

```cpp
vector<int> pc(26, 0), sc(26, 0);
for (char x: p)
    pc[x - 'a']++;
```

   - The above code initializes the frequency vector `pc` for string `p`. We loop over each character in `p` and increment its corresponding index in the `pc` array (using `x - 'a'` to map the character to its index in the alphabet).

2. **Sliding Window**:
   - We use a for-loop to iterate through the string `s` and build the sliding window:
   - If the current window size exceeds the length of `p`, we adjust the sliding window by removing the leftmost character from the window (i.e., decrementing the frequency count of the character that’s leaving the window).
   - We then add the new character at the right end of the window.

```cpp
for (int i = 0; i < s.size(); i++) {
    if (i >= p.size()) {
        sc[s[i - p.size()] - 'a']--;
    }
    sc[s[i] - 'a']++;
```

   - In the above code:
     - If the index `i` is greater than or equal to the length of `p`, we reduce the count of the character at index `i - p.size()`, effectively sliding the window.
     - We then increment the count of the character at index `i` to include the new character in the window.

3. **Checking for Anagram**:
   - After updating the frequency count for the current window, we check if the frequency count `sc` of the current window matches the frequency count `pc` of string `p`.
   - If the counts match, it means that the current window is an anagram of `p`, so we add the start index of the window to the result vector `ans`.

```cpp
if (sc == pc)
    ans.push_back(i - p.size() + 1);
```

   - Here, `sc == pc` checks if the current window is an anagram of `p`. If the counts are equal, we push the index of the start of the window (`i - p.size() + 1`) into the result list `ans`.

4. **Return Result**:
   - After iterating through the entire string `s`, we return the `ans` vector, which contains all the start indices of the anagrams of `p` found in `s`.

```cpp
return ans;
```

### Complexity

#### Time Complexity:
- **Building the Frequency Count**: The frequency count for `p` is computed in `O(m)`, where `m` is the length of `p`.
- **Sliding Window**: The sliding window runs for every character in `s`. For each character, the frequency array update takes constant time, `O(1)`. Thus, iterating over `s` takes `O(n)`, where `n` is the length of `s`.
- **Comparison of Frequency Arrays**: Comparing the frequency arrays `sc` and `pc` also takes constant time `O(26)` because the arrays are of fixed size (26 for the 26 letters of the alphabet).
- **Overall Time Complexity**: The total time complexity is `O(n + m)`, where `n` is the length of `s` and `m` is the length of `p`. This is efficient because we only need to traverse `s` once and perform constant-time operations for each character.

#### Space Complexity:
- We use two arrays of size 26 to store the frequency counts for `p` and the sliding window in `s`. Thus, the space complexity is `O(26)`, which simplifies to `O(1)` because it is a constant space usage.
- Additionally, we store the result in the `ans` vector, but the space used by `ans` depends on the number of anagrams found, which could be up to `n - m + 1` in the worst case. Thus, the space complexity is `O(n)` for storing the result.

### Conclusion

This solution efficiently finds all starting indices of anagrams of `p` in `s` using the sliding window technique with frequency counting. By maintaining frequency counts for both the target string `p` and the current sliding window in `s`, the solution checks for anagrams in linear time, making it suitable for large strings. The overall time complexity of `O(n + m)` ensures that the algorithm can handle typical input sizes effectively. The solution is space-efficient, using only constant extra space for frequency counting, with the result space depending on the number of found anagrams.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)

---
{{< youtube G8xtZy0fDKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
