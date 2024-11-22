
+++
authors = ["grid47"]
title = "Leetcode 2610: Convert an Array Into a 2D Array With Conditions"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2610: Convert an Array Into a 2D Array With Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9pl1QiaGgmI"
youtube_upload_date="2024-01-02"
youtube_thumbnail="https://i.ytimg.com/vi/9pl1QiaGgmI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int mx = 0;
        for(int x: nums) {
            mp[x]++;
            mx = max(mp[x], mx);
        }
        vector<vector<int>> grid(mx);
        for(auto it: mp) {
            for(int i = 0; i < it.second; i++) {
                grid[i].push_back(it.first);
            }
        }
        return grid;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to organize a list of integers into a matrix, where each row contains one or more numbers from the original list, and the number of rows in the matrix should be as small as possible. Additionally, each number in the matrix should appear the same number of times across all rows, if possible. Specifically, the matrix should have the following properties:
1. Each row contains a number of integers.
2. The integers in each row are taken from the original list.
3. The number of rows should be minimized.
4. Each integer should appear the same number of times in each row as much as possible.

### Approach

To solve this problem, we need to:
1. **Count the frequency of each number**: First, we count how many times each number appears in the list.
2. **Determine the number of rows required**: The number of rows required will be equal to the highest frequency of any number.
3. **Distribute the numbers into rows**: Distribute the numbers into rows so that each row contains the numbers in the original order, while ensuring that the number of rows matches the maximum frequency of any number. We will aim to have each number appear the same number of times across rows as much as possible.
4. **Return the matrix**: Finally, return the matrix where each row is a list of numbers, and the number of rows corresponds to the maximum frequency of the numbers.

### Code Breakdown (Step by Step)

1. **Counting Occurrences of Each Number**:
   
```cpp
map<int, int> mp;
int mx = 0;
for(int x: nums) {
    mp[x]++;
    mx = max(mp[x], mx);
}
```

- **Explanation**: 
  - We first declare a map `mp` to store the frequency of each number in `nums`. The key is the number, and the value is its frequency.
  - We then iterate over each number in the `nums` list and increment its count in the map.
  - While iterating, we also track the maximum frequency of any number in `mx` to determine the number of rows required for the matrix.

2. **Initialize the Matrix**:
   
```cpp
vector<vector<int>> grid(mx);
```

- **Explanation**:
  - We initialize a 2D vector `grid` with `mx` rows. Each row will correspond to a list of numbers, and the number of rows will be equal to the maximum frequency found in the previous step.

3. **Distribute the Numbers into Rows**:
   
```cpp
for(auto it: mp) {
    for(int i = 0; i < it.second; i++) {
        grid[i].push_back(it.first);
    }
}
```

- **Explanation**:
  - We iterate over the map `mp` where each entry contains a number and its frequency.
  - For each number, we add it to the rows in the `grid`. Specifically, we add `it.second` (the frequency of the number) copies of `it.first` (the number itself) into the appropriate rows.
  - We loop from `i = 0` to `i < it.second` to add the current number to the appropriate row in the grid, ensuring that the matrix is filled with each number the correct number of times.

4. **Return the Matrix**:
   
```cpp
return grid;
```

- **Explanation**: 
  - After distributing the numbers into rows, we return the matrix `grid` as the result.

### Time and Space Complexity

#### Time Complexity:
1. **Counting the Occurrences**: We loop through the input list `nums`, which has `n` elements. Therefore, counting the occurrences takes \(O(n)\).
2. **Filling the Matrix**: We iterate over the map `mp` to distribute the numbers into rows. The total number of operations is proportional to the sum of the frequencies of all the numbers in `nums`, which is also \(O(n)\) since the total frequency counts across all numbers will sum to `n`.
3. **Overall Time Complexity**: The total time complexity is \(O(n)\), where \(n\) is the size of the input list `nums`.

#### Space Complexity:
1. **Space for the Map**: The map `mp` stores the frequency of each unique number, which requires \(O(k)\) space, where \(k\) is the number of distinct elements in `nums`.
2. **Space for the Matrix**: The matrix `grid` stores all the elements in `nums` distributed into rows. Therefore, the space required for the matrix is \(O(n)\).
3. **Overall Space Complexity**: The total space complexity is \(O(n)\), considering both the space required for the map and the matrix.

### Conclusion

This solution efficiently creates a matrix with a minimal number of rows where the numbers from the original list are distributed as evenly as possible across the rows. The algorithm runs in linear time \(O(n)\), making it suitable for large input sizes. By counting the frequency of each number and organizing the numbers into rows based on their frequency, we ensure that each number appears the correct number of times in each row while minimizing the number of rows. The space complexity is also linear, as we only need to store the input list and the resulting matrix.

[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/)

---
{{< youtube 9pl1QiaGgmI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
