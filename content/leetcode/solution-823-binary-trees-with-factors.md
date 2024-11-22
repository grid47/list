
+++
authors = ["grid47"]
title = "Leetcode 823: Binary Trees With Factors"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 823: Binary Trees With Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vzjMGYUG7qY"
youtube_upload_date="2021-03-13"
youtube_thumbnail="https://i.ytimg.com/vi/vzjMGYUG7qY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;
        for(int i = 0; i < arr.size(); i++) {
            long count = 1;
            for(auto j : rootWithCount) {
                int root = j.first;
                if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
                    count += rootWithCount[root] * rootWithCount[arr[i]/root];
                }
            }
            rootWithCount[arr[i]] = count;
        }
        int no = 0;
        for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
        return no;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand asks for the number of distinct binary trees that can be formed where each node’s value is an integer from a given list `arr`. The binary tree must be a valid binary tree in the sense that the value of each node must be a factor of its parent node's value.

The goal is to compute the total number of such valid binary trees modulo \(10^9 + 7\). The binary trees must be constructed such that the structure of each tree is valid according to the conditions, and the values at each node must be from the array `arr`.

### Approach

To solve this problem efficiently, we need to utilize dynamic programming and factorization. The steps involved in solving the problem are:

1. **Sorting the Input Array**:
   - Sorting the array ensures that we can work with smaller factors first, which is important because if a number is divisible by another, it will always be placed after it in the sorted array.
   - By processing the numbers in increasing order, we can ensure that when considering a number, we have already counted all possible trees that use smaller factors.

2. **Dynamic Programming with Hash Map**:
   - Use a hash map, `rootWithCount`, where the key is a number from `arr`, and the value is the number of binary trees that can be formed with that number as the root.
   - Initially, every number is considered as a potential root of one tree (itself). So, we start by setting the count of each number in the map to `1`.

3. **Factorization for Tree Formation**:
   - For each number in `arr`, check its divisors from the earlier processed numbers.
   - If the number `arr[i]` is divisible by some `root`, and if the quotient `arr[i] / root` is also in `arr`, then a binary tree can be formed by using `root` as one of the children of `arr[i]`.
   - The number of binary trees that can be formed with `arr[i]` as the root is updated by adding the product of the counts of `root` and `arr[i] / root`.

4. **Modulo Operation**:
   - The answer to the problem may be a large number, so the result is computed modulo \(10^9 + 7\) to prevent overflow and meet problem requirements.

5. **Final Summation**:
   - Once all numbers in `arr` are processed, sum the values in the `rootWithCount` map to get the total number of distinct binary trees.

### Code Breakdown (Step by Step)

1. **Sorting the Array**:
   ```cpp
   sort(arr.begin(), arr.end());
   ```
   - We first sort the array `arr` to ensure that smaller numbers are processed first. This is important because smaller numbers can potentially be used as factors for larger numbers.

2. **Initialize the Hash Map**:
   ```cpp
   unordered_map<int, long> rootWithCount;
   rootWithCount[arr[0]] = 1;
   ```
   - We initialize an unordered map `rootWithCount` to store the number of binary trees that can be rooted at each value. Initially, the first number in `arr` is assigned a count of `1`, because it can form one tree by itself.

3. **Dynamic Programming Loop**:
   ```cpp
   for(int i = 0; i < arr.size(); i++) {
       long count = 1;
       for(auto j : rootWithCount) {
           int root = j.first;
           if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
               count += rootWithCount[root] * rootWithCount[arr[i]/root];
           }
       }
       rootWithCount[arr[i]] = count;
   }
   ```
   - For each number `arr[i]`, we initialize `count` to `1` because the number itself can form a binary tree.
   - We then iterate through all previously processed numbers in `rootWithCount`. For each `root`, we check if `arr[i]` is divisible by `root` and if the quotient `arr[i] / root` is also in `rootWithCount`. If both conditions are met, it means we can form a binary tree by using `root` and `arr[i] / root` as children.
   - The count for `arr[i]` is updated by adding the product of the counts of `root` and `arr[i] / root`, which represents the number of trees formed with `root` and `arr[i] / root` as children.

4. **Final Result Calculation**:
   ```cpp
   int no = 0;
   for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
   return no;
   ```
   - After processing all numbers, the final result is the sum of the values in `rootWithCount`. This sum represents the total number of distinct binary trees that can be formed.
   - The result is taken modulo \(10^9 + 7\) to handle large numbers and to meet the problem's requirements.

### Complexity

- **Time Complexity**: 
  - Sorting the array takes \(O(n \log n)\), where \(n\) is the size of the array.
  - The nested loops for each element in `arr` take \(O(n^2)\) in the worst case because for each number, we may check all the numbers before it.
  - Thus, the overall time complexity is \(O(n^2)\), where \(n\) is the number of elements in `arr`.

- **Space Complexity**:
  - The space complexity is \(O(n)\), as we use an unordered map `rootWithCount` to store counts for each number in `arr`, and the size of this map is proportional to the number of elements in `arr`.

### Conclusion

This solution efficiently calculates the number of distinct binary trees that can be formed by using the numbers in the input array `arr` as nodes. By leveraging dynamic programming and factorization, it avoids redundant calculations and ensures an optimal solution. The algorithm processes each number and its possible divisors, building the solution progressively, which makes it well-suited for handling large inputs. The use of modular arithmetic ensures that the result fits within the required bounds, making the solution both time-efficient and space-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-trees-with-factors/description/)

---
{{< youtube vzjMGYUG7qY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
