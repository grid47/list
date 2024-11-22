
+++
authors = ["grid47"]
title = "Leetcode 2857: Count Pairs of Points With Distance k"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2857: Count Pairs of Points With Distance k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z7hDq-nGzUI"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/Z7hDq-nGzUI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> count;
        int res = 0;
        for (auto& c : coordinates) {
            for (int x = 0; x <= k; x++)
                if (count[c[0] ^ x].count(c[1] ^ (k - x)))
                    res += count[c[0] ^ x][c[1] ^ (k - x)];
            count[c[0]][c[1]]++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find how many pairs of coordinates in a given list can be transformed by applying a bitwise XOR operation with a given integer `k`, such that the transformed coordinates form a valid pair. Specifically, for each pair of coordinates `(x1, y1)` and `(x2, y2)` in the list, you need to check if there exists some value of `x` such that:

```
x1 ^ x = x2 ^ (k - x)
```

where `^` represents the bitwise XOR operation, and `k` is a given constant.

The goal is to find the total number of such pairs in the list.

### Approach

This problem requires the use of bitwise operations to check how pairs of coordinates can match after applying the XOR transformation. The XOR operation is a bit-level operation, and the property `a ^ b == c` implies a relationship between `a`, `b`, and `c`. Using this property, we can efficiently track pairs of coordinates that can be transformed by the XOR operation.

#### Key Observations:
1. **Efficient Pair Search with XOR**: 
   - For each coordinate pair `(x, y)` in the `coordinates` list, we want to check if there exists any other coordinate pair `(x', y')` such that after applying the XOR operation, the pairs match.
   
2. **Using Maps for Counting**:
   - A direct approach of checking each pair would lead to an O(n^2) solution, which is inefficient. Instead, we use a hash map to store the frequency of the coordinates we've seen so far, enabling us to check if a valid pair has already been encountered in constant time.

3. **XOR and the Relationship**:
   - The key idea is to use the XOR operation in such a way that we transform the coordinates and check if the transformed coordinate exists in the previously seen coordinates.

#### Steps:
1. **Iterate Over Coordinates**:
   - For each coordinate pair `(x, y)`, iterate through all possible `x` values from `0` to `k`, and compute the transformed pair `(x', y')` using the formula `x' = x ^ x` and `y' = y ^ (k - x)`. 

2. **Check for Valid Pairs**:
   - For each transformed pair, check if it exists in the hash map. If it does, increment the count of valid pairs.

3. **Update the Count Map**:
   - After checking for valid pairs, update the hash map with the current coordinate pair `(x, y)`.

4. **Return the Result**:
   - After processing all coordinates, the result will be the total number of valid pairs found.

### Code Breakdown (Step by Step)

```cpp
unordered_map<int, unordered_map<int, int>> count;
int res = 0;
```
- We initialize a map `count` where the keys are the x and y coordinates, and the values are the count of occurrences of each pair `(x, y)`. 
- We also initialize `res` to keep track of the number of valid pairs.

```cpp
for (auto& c : coordinates) {
    for (int x = 0; x <= k; x++)
        if (count[c[0] ^ x].count(c[1] ^ (k - x)))
            res += count[c[0] ^ x][c[1] ^ (k - x)];
    count[c[0]][c[1]]++;
}
```
- For each coordinate pair `c = (x, y)` in the list of coordinates:
  - We iterate over all values of `x` from `0` to `k`.
  - For each `x`, we compute the transformed coordinate `(x', y')` using the XOR operation. Specifically, `x' = c[0] ^ x` and `y' = c[1] ^ (k - x)`.
  - We check if the transformed coordinate `(x', y')` has already appeared in the `count` map. If it has, we add the count of occurrences of `(x', y')` to `res`.
  - Finally, we update the `count` map with the current coordinate `(x, y)`.

```cpp
return res;
```
- After processing all coordinates, we return the total number of valid pairs stored in `res`.

### Complexity

#### Time Complexity:
- **O(n * k)**: 
  - We iterate over all coordinates in the `coordinates` list, where `n` is the number of coordinates.
  - For each coordinate, we perform `k` iterations (one for each possible `x` from `0` to `k`).
  - Therefore, the time complexity is O(n * k), where `n` is the number of coordinates and `k` is the maximum value used in the XOR operation.

#### Space Complexity:
- **O(n * k)**:
  - We are using a hash map to store the count of each coordinate pair. In the worst case, we may need to store `n * k` entries in the map (since we are considering all possible values of `x` for each coordinate).
  - Therefore, the space complexity is O(n * k).

### Conclusion

This approach efficiently computes the number of valid coordinate pairs that can be transformed using the XOR operation by leveraging hash maps for fast lookup. The use of bitwise operations ensures that the transformations are performed efficiently, and the hash map allows for quick counting of valid pairs. By iterating over the coordinates and transforming them, we avoid the inefficiencies of a brute force O(n^2) solution. The overall time complexity of O(n * k) makes this solution suitable for larger inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/)

---
{{< youtube Z7hDq-nGzUI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
