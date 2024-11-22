
+++
authors = ["grid47"]
title = "Leetcode 997: Find the Town Judge"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 997: Find the Town Judge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xR2Qg9ENtKQ"
youtube_upload_date="2020-05-10"
youtube_thumbnail="https://i.ytimg.com/vi/xR2Qg9ENtKQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n + 1, 0);
        for(auto x: trust) {
            deg[x[1]]++;
            deg[x[0]]--;
        }
        for(int i = 1; i <= n; i++)
            if(deg[i] == n - 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to identify the "judge" in a town where there are `n` people. The town judge is defined as follows:
- The judge is trusted by everyone else (i.e., all `n-1` other people trust the judge).
- The judge trusts no one.
We are given a list `trust` where each element `[a, b]` indicates that person `a` trusts person `b`. The task is to find the person who satisfies the above conditions, if such a person exists. If no such person exists, we return `-1`.

### Approach

To solve this problem efficiently, we can take advantage of a **degree-based approach**. The idea is to use an array (or list) to track the trust relationship for each person. This can be done by adjusting the "trust count" for each person:
1. **Increase the trust count** for person `b` when `a` trusts `b`.
2. **Decrease the trust count** for person `a` since they trust someone (indicating they cannot be the judge).

At the end, the judge will be the person who:
- Has a trust count of `n-1` (trusted by everyone except themselves).
- Has a trust value of `0` for themselves (since they trust no one).

If no such person exists, return `-1`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n + 1, 0);  // Initialize an array to track trust/degrees of each person
```

1. **Initialization**:
   - We create a vector `deg` of size `n + 1` (because people are numbered from `1` to `n`), where each element represents the "trust degree" of a person. Initially, all values are set to `0`.
   - The index of the vector corresponds to the person number.

```cpp
        for(auto x: trust) {
            deg[x[1]]++;  // Person `x[1]` is trusted by `x[0]`, so increase their trust degree
            deg[x[0]]--;  // Person `x[0]` trusts someone, so decrease their trust degree
        }
```

2. **Updating Trust Degrees**:
   - For each pair in the `trust` array, we do the following:
     - We increment `deg[x[1]]` to indicate that person `x[1]` is trusted by `x[0]`.
     - We decrement `deg[x[0]]` to indicate that person `x[0]` is trusting someone, so they cannot be the judge.
   - This allows us to track the "trust degree" for each person — the net trust value (number of people who trust them minus the number of people they trust).

```cpp
        for(int i = 1; i <= n; i++)
            if(deg[i] == n - 1) return i;  // If a person has trust degree of n-1, they are the judge
```

3. **Identifying the Judge**:
   - After processing all trust relationships, we loop through the `deg` array from `1` to `n`.
   - If a person has a trust degree of `n-1` (i.e., they are trusted by everyone except themselves), we return that person as the judge.
   - The condition `deg[i] == n - 1` ensures that the person is trusted by everyone else, and `deg[i]` is `0` for the person because they trust no one.

```cpp
        return -1;  // If no judge is found, return -1
    }
};
```

4. **Return the Result**:
   - If we have gone through all the people and found no one who satisfies the conditions of being a judge, we return `-1`.

### Complexity

- **Time Complexity**: The time complexity of this solution is **O(T + n)**, where `T` is the number of trust relationships and `n` is the number of people. This is because:
  - We iterate through the `trust` list once, which takes `O(T)` time to update the `deg` array.
  - We then iterate through the `deg` array, which takes `O(n)` time to check for the judge.
  
- **Space Complexity**: The space complexity is **O(n)**, which comes from the `deg` array of size `n + 1` used to track the trust degrees of each person.

### Conclusion

The solution efficiently solves the problem by leveraging a degree-based approach to track the trust relationships between people. By updating the "trust degree" for each person as we process the `trust` array, we can quickly identify the judge (if one exists) by checking for a person with a trust degree of `n-1` and a self-trust degree of `0`. The algorithm has an optimal time complexity of `O(T + n)` and a space complexity of `O(n)`, making it well-suited to handle large input sizes. 

This approach avoids the need for complex graph traversal or nested loops, providing a simple and effective solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-town-judge/description/)

---
{{< youtube xR2Qg9ENtKQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
