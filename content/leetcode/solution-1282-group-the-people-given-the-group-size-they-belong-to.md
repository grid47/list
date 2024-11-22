
+++
authors = ["grid47"]
title = "Leetcode 1282: Group the People Given the Group Size They Belong To"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1282: Group the People Given the Group Size They Belong To in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RrnhHjJmzj8"
youtube_upload_date="2023-09-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RrnhHjJmzj8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gz) {
        vector<vector<int>> res, gzs(gz.size() + 1);
        for(auto i = 0; i < gz.size(); i++) {
            gzs[gz[i]].push_back(i);
            if(gzs[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), gzs[gz[i]]);
            }
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires grouping people based on their group sizes. You are given an array `gz` where each element `gz[i]` represents the size of the group that the `i-th` person belongs to. The goal is to form groups where each group contains exactly the number of people specified by their corresponding sizes in the array.

For example, if `gz = [3, 3, 3, 3, 3, 1, 3]`, this indicates that there are five people who want to be in groups of size 3 and one person who wants to be in a group of size 1. The output should then be groups of the correct sizes, like `[[0, 1, 2], [3, 4], [5]]`.

### Approach
To solve this problem efficiently, we can utilize a hashmap (or an array of vectors in this case) to keep track of the indices of people that belong to each group size. The idea is to iterate through the `gz` array, and for each person, we add their index to the corresponding group size in our helper structure. Once we have a complete group (i.e., the number of people in the list equals the group size), we can transfer this list to our results and reset the group for potential future groups of the same size.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gz) {
```
- **Line 1-2**: We define the class `Solution` and start the method `groupThePeople`, which takes a reference to a vector `gz` (group sizes) as input and returns a vector of vectors containing grouped people.

```cpp
        vector<vector<int>> res, gzs(gz.size() + 1);
```
- **Line 3**: We initialize two vectors:
  - `res`: This will store the final result containing the groups.
  - `gzs`: This is a vector of vectors that will temporarily hold the indices of people based on their group sizes. The size is `gz.size() + 1` to accommodate all possible group sizes, including `0`.

```cpp
        for(auto i = 0; i < gz.size(); i++) {
            gzs[gz[i]].push_back(i);
```
- **Line 4-5**: We iterate through each person's index `i` in `gz`. For each person, we push their index `i` into the corresponding vector in `gzs` based on their group size `gz[i]`.

```cpp
            if(gzs[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), gzs[gz[i]]);
            }
```
- **Line 6-9**: After adding the index to the group, we check if the size of that group has reached the required size (`gz[i]`). If it has, we:
  - Add a new empty vector to `res`.
  - Use `swap` to move the contents of `gzs[gz[i]]` (the group of indices) into the newly created group in `res`. This effectively transfers the group to the results and resets `gzs[gz[i]]` for further use.

```cpp
        }
        return res;
    }
};
```
- **Line 10-12**: We complete the loop and return the result `res`, which now contains all the groups of people formed according to their specified sizes.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of people in the input array `gz`. This is because we iterate through the `gz` array exactly once, performing constant-time operations for each person.

2. **Space Complexity**:
   - The space complexity is also \(O(n)\). In the worst case, all people could belong to the same group size, leading to a scenario where we store all indices in `gzs`. The output `res` also takes up space proportional to \(n\) in the worst case, where every person forms a group by themselves.

### Conclusion
The `groupThePeople` function efficiently groups people based on their specified group sizes using a straightforward approach that utilizes a vector of vectors to organize indices. By iterating through the input array and maintaining a temporary structure for groups, we can ensure that each group is formed exactly as specified. The overall time and space efficiency make this solution suitable for larger inputs, maintaining a linear complexity.

This explanation serves to clarify the functionality and efficiency of the code, providing insights into how group formation can be handled programmatically using basic data structures in C++. Readers will benefit from understanding both the specific implementation details and the broader context of the problem, enhancing their programming skills in algorithms and data structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/)

---
{{< youtube RrnhHjJmzj8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
