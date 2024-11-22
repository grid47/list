
+++
authors = ["grid47"]
title = "Leetcode 1338: Reduce Array Size to The Half"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1338: Reduce Array Size to The Half in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int c: arr) ++mp[c];

        vector<int> frq;
        for(auto [_, fq] : mp) frq.push_back(fq);

        sort(frq.begin(), frq.end());

        int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
        while(rm < half) {
            rm += frq[i--];
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires finding the minimum size of a set of integers such that removing all occurrences of the integers in this set from the input array results in at least half of the original elements being removed. This can be visualized as selecting a subset of elements that has the greatest frequency, allowing for the largest reduction in the size of the array when removed.

### Approach
To solve this problem, we can follow these steps:

1. **Count Frequency**: First, count the frequency of each integer in the array. This can be achieved using a hash map.

2. **Store Frequencies**: Store the frequencies in a vector for easy access and sorting.

3. **Sort Frequencies**: Sort the frequency vector in descending order. This allows us to prioritize removing the most frequent elements first.

4. **Accumulate Removal**: Iteratively sum the frequencies from the sorted list until at least half of the original array's size is removed, counting the number of elements we need to include in our removal set.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
```
- We define a class `Solution` with a public method `minSetSize`, which takes a vector of integers, `arr`, as an input.

```cpp
        unordered_map<int, int> mp;
        for(int c: arr) ++mp[c];
```
- We create an unordered map `mp` to store the frequency of each element in the array. We iterate over each element in `arr`, incrementing its count in the map. This gives us a count of how many times each integer appears in the array.

```cpp
        vector<int> frq;
        for(auto [_, fq] : mp) frq.push_back(fq);
```
- We initialize a vector `frq` to hold the frequencies. We loop through each entry in the frequency map and push the frequency value (`fq`) into the `frq` vector.

```cpp
        sort(frq.begin(), frq.end());
```
- We sort the `frq` vector in ascending order. This step is crucial because we will be interested in the most frequent elements to remove first, so sorting will help us easily access the largest frequencies later.

```cpp
        int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
```
- We initialize several variables:
  - `ans`: to count the minimum number of elements in the set we need.
  - `i`: to traverse the sorted frequency vector from the end (where the largest frequencies are).
  - `half`: to determine half the size of the original array, which we need to achieve in terms of removal.
  - `rm`: to keep track of the total number of elements removed.

```cpp
        while(rm < half) {
            rm += frq[i--];
            ans++;
        }
```
- We enter a loop that continues until the total number of removed elements (`rm`) is less than half of the original array size (`half`). Inside the loop:
  - We add the current frequency (`frq[i]`) to `rm`, which represents the total number of elements removed.
  - We decrement `i` to move to the next largest frequency in the next iteration.
  - We increment `ans` by 1 to reflect that we've added another integer to our removal set.

```cpp
        return ans;
    }
};
```
- Finally, we return `ans`, which contains the minimum size of the set needed to remove at least half of the elements from the original array.

### Complexity Analysis
- **Time Complexity**: The time complexity of the solution is \(O(n + m \log m)\), where \(n\) is the number of elements in the input array and \(m\) is the number of unique elements in the array. The \(O(n)\) part comes from counting the frequencies, and \(O(m \log m)\) comes from sorting the frequency vector.

- **Space Complexity**: The space complexity is \(O(m)\), where \(m\) is the number of unique elements in the array, as we store the frequencies in a separate vector.

### Conclusion
The provided code efficiently calculates the minimum size of a set of integers that can remove at least half of the elements from the input array. It leverages a hash map for frequency counting, followed by sorting to prioritize the most frequently occurring elements for removal.

This approach is optimal and straightforward, making it suitable for similar problems in competitive programming and algorithmic challenges. Understanding this solution reinforces the concepts of frequency counting, sorting, and greedy algorithms, which are fundamental in solving optimization problems.

The methodology can be applied in various scenarios, such as data analysis, where determining the most common elements is essential for decision-making processes.

This explanation comprehensively covers the problem, the approach taken, a step-by-step breakdown of the code, complexity analysis, and a concluding discussion about its applications.


[`Link to LeetCode Lab`](https://leetcode.com/problems/reduce-array-size-to-the-half/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
