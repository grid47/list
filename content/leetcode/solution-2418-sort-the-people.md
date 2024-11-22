
+++
authors = ["grid47"]
title = "Leetcode 2418: Sort the People"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2418: Sort the People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Zv_gXqqslbw"
youtube_upload_date="2024-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/Zv_gXqqslbw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> A;
        int N = names.size();
        for(int i = 0; i < N; i++) {
            A.push_back({heights[i], names[i]});
        }

        sort(A.rbegin(), A.rend());

        vector<string> ans;
        for(int i = 0; i < N; i++) {
            ans.push_back(A[i].second);
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to sort a list of people by their heights in descending order, where each person is represented by a name and a corresponding height. The task is to return the names of the people, sorted by their heights from tallest to shortest.

### Approach

The problem can be solved by pairing each name with its corresponding height and then sorting the list of pairs based on the heights in descending order. After sorting, we can extract the names from the sorted list and return them.

To implement this solution, we will:
1. Create a vector of pairs, where each pair contains a person's height and name.
2. Sort the pairs in descending order based on the height.
3. Extract and return the names from the sorted pairs.

### Code Breakdown (Step by Step)

#### 1. Initializing Data Structures

```cpp
vector<pair<int, string>> A;
int N = names.size();
```
- We first declare a vector of pairs `A`, where each pair will store a height and a name. This allows us to associate each person’s name with their height.
- `N` is the size of the `names` vector, which represents the number of people.

#### 2. Pairing Heights with Names

```cpp
for(int i = 0; i < N; i++) {
    A.push_back({heights[i], names[i]});
}
```
- We loop through the `names` vector (and simultaneously the `heights` vector), creating pairs of the form `{height, name}` and pushing them into the vector `A`.
- The first element of each pair is the height, and the second element is the name.

#### 3. Sorting the Pairs

```cpp
sort(A.rbegin(), A.rend());
```
- We now sort the vector `A` in descending order of heights. The `sort` function is used with `rbegin()` and `rend()` iterators, which allow sorting in reverse order (from tallest to shortest).
- Sorting in descending order is achieved because we want the tallest person first in the list.

#### 4. Extracting the Sorted Names

```cpp
vector<string> ans;
for(int i = 0; i < N; i++) {
    ans.push_back(A[i].second);
}
```
- After sorting, we extract the names from the sorted pairs. We loop through the sorted vector `A`, and for each pair, we push the second element (the name) into the `ans` vector.

#### 5. Returning the Result

```cpp
return ans;
```
- Finally, after extracting all the names, we return the `ans` vector containing the names sorted by height.

### Complexity

#### Time Complexity:
- **O(N log N)**: The time complexity of the solution is dominated by the sorting step, where `N` is the number of people (or the size of the input arrays). Sorting the `N` pairs takes \(O(N \log N)\) time.
- The rest of the operations (pairing names with heights and extracting the names) take linear time, i.e., O(N).

#### Space Complexity:
- **O(N)**: The space complexity is also \(O(N)\) because we are storing `N` pairs in the vector `A` and `N` names in the vector `ans`.

### Conclusion

This solution efficiently solves the problem of sorting people by height. By pairing the heights with the names and using a sorting algorithm, the solution guarantees that we get the names in descending order of height. The algorithm has optimal time complexity, making it suitable for handling large inputs. The use of a pair data structure simplifies the problem by directly associating names and heights, and sorting them becomes a straightforward task.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-the-people/description/)

---
{{< youtube Zv_gXqqslbw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
