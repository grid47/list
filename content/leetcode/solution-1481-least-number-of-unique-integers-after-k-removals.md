
+++
authors = ["grid47"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1481: Least Number of Unique Integers after K Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Nsp_ta7SlEk"
youtube_upload_date="2024-02-16"
youtube_thumbnail="https://i.ytimg.com/vi/Nsp_ta7SlEk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto m : arr) mp[m]++;

        sort(begin(arr), end(arr), [&](int x, int y) {
            return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
        });

        unordered_set<int> st;
        for(int i = k; i < arr.size(); i++) st.insert(arr[i]);

        return st.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine the least number of unique integers in an array after performing at most `k` removals. Given an array of integers, you need to remove up to `k` elements to minimize the number of distinct integers remaining in the array. The goal is to efficiently compute the minimum number of unique integers left after the removal process.

### Approach

To solve the problem, we can follow these steps:

1. **Count Frequencies**: Use a hash map to count the frequency of each integer in the input array. This helps in determining which integers can be removed most efficiently.

2. **Sort Based on Frequency**: We need to sort the integers based on their frequencies in ascending order. If two integers have the same frequency, we can sort them based on their values. This allows us to prioritize removing the least frequent integers first.

3. **Remove Integers**: Use a set to keep track of the unique integers that remain after removing up to `k` integers from the array. By iterating through the sorted array of frequencies and removing integers as we go, we can determine how many unique integers are left.

4. **Return the Result**: Finally, return the size of the set, which represents the number of unique integers remaining in the array.

This approach ensures that we effectively minimize the number of unique integers by removing the most frequent integers first, leading to an optimal solution.

### Code Breakdown (Step by Step)

Here’s a detailed explanation of the code implementation:

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto m : arr) mp[m]++;
```
- **Class Definition**: The `Solution` class encapsulates the method for solving the problem.
- **Method Declaration**: The method `findLeastNumOfUniqueInts` takes a reference to a vector of integers `arr` and an integer `k` as its parameters.
- **Frequency Counting**: An unordered map `mp` is declared to store the frequency of each integer in the array. A for-each loop iterates over each element `m` in `arr`, updating the count in `mp`.

```cpp
        sort(begin(arr), end(arr), [&](int x, int y) {
            return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
        });
```
- **Sorting**: The array `arr` is sorted using a custom comparator. The `sort` function rearranges the elements in ascending order based on their frequency in `mp`. If two elements have the same frequency, they are sorted by their value. This ensures that we can efficiently identify and remove the least frequent integers.

```cpp
        unordered_set<int> st;
        for(int i = k; i < arr.size(); i++) st.insert(arr[i]);
```
- **Unique Integer Tracking**: An unordered set `st` is initialized to keep track of the unique integers that remain after removing elements. The loop starts from index `k`, effectively ignoring the first `k` elements (the least frequent ones) since they are removed.

```cpp
        return st.size();
    }
};
```
- **Returning the Result**: The method returns the size of the set `st`, which contains the unique integers left after `k` removals.

### Complexity

- **Time Complexity**:
  - The time complexity of this algorithm is \(O(n \log n)\), where \(n\) is the number of elements in the input array. The main contributors to this complexity are the frequency counting, sorting the array, and the final pass through the array to build the set of unique integers.

- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the storage of the frequency map and the set. In the worst case, all integers could be unique, leading to storage proportional to the input size.

### Conclusion

The `findLeastNumOfUniqueInts` method efficiently calculates the minimum number of unique integers remaining after removing up to `k` integers from an array. By utilizing a hash map for frequency counting and sorting, this solution optimizes the removal process and guarantees that we focus on removing the least frequent integers first.

Key takeaways from this implementation include:

1. **Efficiency**: The approach effectively reduces the number of unique integers by prioritizing the removal of the least frequent ones. This results in an optimal solution while maintaining a reasonable time complexity.

2. **Data Structures**: The use of an unordered map for counting frequencies and an unordered set for tracking unique integers demonstrates a practical application of these data structures in solving real-world problems.

3. **Adaptability**: This method can be adapted to similar problems involving arrays, frequency counting, and the minimization or maximization of unique elements. It serves as a useful template for tackling a variety of algorithmic challenges.

In summary, this implementation provides a clear and effective solution to the problem of minimizing the number of unique integers in an array after a series of removals, making it a valuable addition to the toolbox of techniques for array manipulation and optimization.

[`Link to LeetCode Lab`](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/)

---
{{< youtube Nsp_ta7SlEk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
