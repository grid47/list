
+++
authors = ["grid47"]
title = "Leetcode 2716: Minimize String Length"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2716: Minimize String Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "aMJ3T0K8LjI"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi/aMJ3T0K8LjI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizedStringLength(string s) {
    unordered_set<char> st;
    for(auto c: s) st.insert(c);
    return st.size();
}
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the minimized length of a string by removing all duplicate characters. Specifically, the goal is to determine the number of unique characters in the given string `s`. This is because once all duplicate characters are removed, only the distinct characters remain, and the length of the resultant string is the count of these unique characters.

### Approach

The problem boils down to counting the number of distinct characters in the string. A simple and efficient way to accomplish this is by utilizing a **hash set** (unordered set in C++) to store characters. The reason we use a hash set is that it allows efficient insertion and checking for the existence of a character. By iterating over the string and adding each character to the set, the set automatically ensures that only unique characters are stored.

Once we have iterated through the entire string and added each character to the set, the size of the set will give us the number of unique characters in the string. This size will be the answer to the problem.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Set
```cpp
unordered_set<char> st;
```
- Here, we declare an unordered set `st` to store the unique characters from the string `s`. An unordered set is chosen because it allows for average time complexity of **O(1)** for both insertion and membership check.

#### Step 2: Iterate Through the String and Add Characters to the Set
```cpp
for(auto c: s) st.insert(c);
```
- This line iterates over each character `c` in the string `s`. The `insert(c)` method is called for each character. If the character is not already present in the set, it is added. If it is already in the set, the set ignores the insertion (thus ensuring that each character appears only once).
- The loop runs for all `n` characters in the string `s`, where `n` is the length of the string.

#### Step 3: Return the Size of the Set
```cpp
return st.size();
```
- After all characters have been processed, the size of the set `st` will be equal to the number of unique characters in the string.
- The `size()` method of the unordered set returns the number of unique elements in the set, which is the minimized length of the string after removing duplicates.

### Complexity

#### Time Complexity
- **O(n)**: The time complexity is **O(n)**, where `n` is the length of the string `s`. This is because the code iterates over the string once and performs an **O(1)** insertion operation into the unordered set for each character. Thus, the overall time complexity is linear with respect to the length of the string.

#### Space Complexity
- **O(k)**: The space complexity is **O(k)**, where `k` is the number of unique characters in the string. In the worst case, if all characters in the string are distinct, the unordered set will store all `n` characters, so the space complexity will be **O(n)**. In general, the space complexity will be proportional to the number of distinct characters in the string.

### Conclusion

The problem of minimizing the string length by removing duplicate characters is efficiently solved by utilizing an unordered set to track unique characters. By iterating over the string and inserting characters into the set, we ensure that only distinct characters are counted. The solution works in linear time and uses a minimal amount of extra space relative to the number of unique characters in the string. This makes it optimal for solving this problem, and the approach is simple yet effective.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-string-length/description/)

---
{{< youtube aMJ3T0K8LjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
