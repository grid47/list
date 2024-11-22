
+++
authors = ["grid47"]
title = "Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IJzs5-NDAxc"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/IJzs5-NDAxc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        // Edges 0->1 / 1 -> 0, start has no conseq
        vector<string>ans;
        int flag=-1;
        for(int i=0;i<n;i++){
            if(groups[i]!=flag){
                flag=groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the longest subsequence of words such that each word in the sequence is part of a distinct group. Given a list of words and a corresponding list of groups, the task is to pick words in a way that maximizes the subsequence length while ensuring each selected word belongs to a unique group. This means, for each word we add to the subsequence, the group it belongs to should not match the previous word's group.

### Approach

The approach to solve this problem is straightforward, relying on tracking the group of the last word added to the answer list and only adding a new word if it belongs to a different group. This can be achieved by iterating over the `words` list and checking the group of each word against the last selected group. If the current word belongs to a different group, we add it to the final subsequence; otherwise, it’s skipped. 

This method provides an efficient way to construct the longest possible subsequence that meets the distinct-group requirement.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
vector<string> ans;
int flag = -1;
```

- `ans` is a vector where we will store the resulting longest subsequence of words.
- `flag` is initialized to `-1` as a placeholder to track the group of the last word that was added to `ans`. It will help in checking if the current word's group is different from the last word's group.

#### Step 2: Iterating Over the Words and Building the Subsequence

```cpp
for (int i = 0; i < n; i++) {
    if (groups[i] != flag) {
        flag = groups[i];
        ans.push_back(words[i]);
    }
}
```

- We loop through each word in the `words` list, where `n` is the length of `words`.
- For each word at index `i`, we check if the group of the word (`groups[i]`) is different from the `flag`.
    - If `groups[i]` is not equal to `flag`, it means the word belongs to a different group than the previous word added to `ans`. Therefore:
        - We update `flag` to the current group `groups[i]`.
        - We add the word `words[i]` to `ans`.
    - If `groups[i]` is equal to `flag`, we skip adding `words[i]` to ensure that each word in `ans` is part of a unique group sequence.

#### Step 3: Return the Result

```cpp
return ans;
```

- After the loop completes, `ans` contains the longest subsequence of words where each word belongs to a distinct group, in the order they appear in `words`.
- We return `ans` as the final result.

### Complexity

#### Time Complexity:
- The time complexity is `O(n)`, where `n` is the length of the `words` list. This is because we iterate over the list only once, and each check and insertion operation is constant time.

#### Space Complexity:
- The space complexity is `O(k)`, where `k` is the number of distinct groups in the `groups` list. In the worst case, we may store a subset of `n` words in the `ans` vector if every word belongs to a unique group. Thus, the space complexity is bounded by `O(n)` in the worst case.

### Conclusion

This solution effectively constructs the longest subsequence of words that belong to unique groups using a greedy approach. By iterating through each word and selectively adding it based on its group, the algorithm guarantees that each word in the resulting subsequence meets the distinct group criterion, creating a valid solution with optimal complexity. This efficient and easy-to-understand solution ensures that we achieve the longest possible subsequence with minimal computation, making it suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/)

---
{{< youtube IJzs5-NDAxc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
