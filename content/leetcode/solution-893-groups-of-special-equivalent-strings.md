
+++
authors = ["grid47"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 893: Groups of Special-Equivalent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tbtXPKkA2Zw"
youtube_upload_date="2020-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tbtXPKkA2Zw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string, string>> s;
        for(const auto& w: words) {
            pair<string, string> p;
            for(int i = 0; i < w.size(); i++) {
                if (i % 2) p.first  += w[i];
                else       p.second += w[i];
            }
            sort(p.first.begin(), p.first.end());
            sort(p.second.begin(), p.second.end());
            s.insert(p);
        }
        return s.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the number of **special equivalent groups** in a given list of strings. Two strings are considered **special equivalent** if one string can be transformed into the other by swapping characters at **even indices** or **odd indices** independently. The goal is to determine how many distinct groups of strings exist where each group contains strings that can be transformed into each other.

For example, the strings "abc" and "cab" are special equivalent because:
- After sorting the characters at the **even indices** (0-based index 0, 2), both strings give the same result: "a" and "b" for "abc" and "c" and "a" for "cab".
- After sorting the characters at the **odd indices** (1-based index 1), both give the same result: "b" and "c".

Given a list of strings, we need to determine how many such distinct groups exist.

### Approach

To solve this problem, the key observation is that the strings in the same special equivalent group must have the same characters at **even indices** and **odd indices** (though their order might differ, they must form the same set of characters). 

#### Key Steps:
1. **Separation of Characters**: For each string, divide it into two parts:
   - One containing the characters at **even indices**.
   - The other containing the characters at **odd indices**.

2. **Sorting to Group Equivalent Characters**: Once the characters are divided into even and odd indexed groups, **sort** these groups to ensure that different permutations of the same characters (like "abc" and "cab") become identical.

3. **Pairing and Grouping**: After sorting the two groups, pair the sorted even-indexed characters with the sorted odd-indexed characters. This unique pair represents a string's "signature", which can be used to group equivalent strings together.

4. **Using a Set to Track Unique Groups**: The set data structure is used to track unique pairs. Each pair represents a unique group of special equivalent strings. By inserting each string's pair into the set, we can automatically ensure that only unique pairs are counted.

5. **Counting Distinct Groups**: The number of unique special equivalent groups is simply the size of the set after processing all the strings.

### Code Breakdown (Step by Step)

1. **Set Initialization**:
   ```cpp
   set<pair<string, string>> s;
   ```
   - A set `s` of pairs is created. Each pair will contain two strings: one for the even-indexed characters and one for the odd-indexed characters. Using a set automatically ensures that only unique pairs are kept.

2. **Looping Through Each Word**:
   ```cpp
   for(const auto& w: words) {
       pair<string, string> p;
   ```
   - The program iterates through each word in the `words` array. For each word, a pair `p` is created to store the two groups (even and odd indexed characters).

3. **Separating Even and Odd Indexed Characters**:
   ```cpp
   for(int i = 0; i < w.size(); i++) {
       if (i % 2) p.first  += w[i];
       else       p.second += w[i];
   }
   ```
   - For each word, a loop iterates through its characters. If the index `i` is **even**, the character is added to `p.second`, which will hold the even-indexed characters. If the index `i` is **odd**, the character is added to `p.first`, which will hold the odd-indexed characters.

4. **Sorting the Characters**:
   ```cpp
   sort(p.first.begin(), p.first.end());
   sort(p.second.begin(), p.second.end());
   ```
   - After collecting the even and odd indexed characters, both groups are **sorted** to ensure that any permutation of characters in the groups is considered the same.

5. **Inserting into Set**:
   ```cpp
   s.insert(p);
   ```
   - The sorted pair `(p.first, p.second)` is inserted into the set. If an identical pair already exists, it will not be added again, ensuring that only unique groups are counted.

6. **Returning the Result**:
   ```cpp
   return s.size();
   ```
   - The size of the set `s` is returned, which represents the number of unique special equivalent groups.

### Complexity

#### Time Complexity:
- **Sorting Each Word**: For each word in the list, we sort the characters in both the even and odd indexed groups. Sorting two halves of the string takes **O(M log M)** time, where `M` is the length of the word.
- **Inserting into Set**: Inserting a pair into a set takes **O(log G)** time, where `G` is the number of distinct pairs. In the worst case, the number of distinct pairs can be as large as the number of words in the list.
  
Thus, the total time complexity for the solution is **O(N * M log M)**, where `N` is the number of words in the list and `M` is the average length of the words.

#### Space Complexity:
- **Space for Set**: The space complexity is dominated by the space needed to store the set of pairs. In the worst case, the set will contain one pair for each word, so the space complexity is **O(N)**, where `N` is the number of words in the list.
- **Auxiliary Space for Sorting**: Sorting the characters of each word requires additional space, leading to a space complexity of **O(M)** for each word's sorting operation.

Thus, the overall space complexity is **O(N * M)**.

### Conclusion

This solution efficiently counts the number of distinct **special equivalent groups** by using sorting and set operations. The sorting of even and odd indexed characters ensures that permutations of characters within those indices are treated as equivalent. By using a set, we automatically eliminate duplicate groups. This method provides a clear and effective approach to solve the problem with a time complexity of **O(N * M log M)**, where `N` is the number of words and `M` is the average length of the words. The space complexity is manageable, making this approach suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/groups-of-special-equivalent-strings/description/)

---
{{< youtube tbtXPKkA2Zw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
