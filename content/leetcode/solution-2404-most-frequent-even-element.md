
+++
authors = ["grid47"]
title = "Leetcode 2404: Most Frequent Even Element"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2404: Most Frequent Even Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JykfDvn2o0M"
youtube_upload_date="2022-09-11"
youtube_thumbnail="https://i.ytimg.com/vi/JykfDvn2o0M/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto n: nums) mp[n]++;
        int ans = -1, mx = -1;
        for(auto m: mp){
            if(m.first%2 == 0 && m.second > mx){
                mx = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array `nums` of integers, the goal is to return the most frequent even number in the array. If there are multiple even numbers with the same highest frequency, return the smallest one. If there are no even numbers, return `-1`.

### Approach

The solution involves two key steps:

1. **Counting the Frequency of Each Number**: We need to first determine the frequency of each number in the array.
2. **Identifying the Most Frequent Even Number**: After counting the frequencies, we then need to identify which even number appears the most frequently, and if there is a tie, return the smallest such number.

#### Key Concepts:
- **Map (HashMap)**: A map (or hash map) allows us to store the frequency of each number efficiently. By iterating over the input list and updating the map, we can track how many times each number appears in the array.
- **Even Numbers**: We are only interested in even numbers, so we filter out odd numbers during our frequency comparison.
- **Comparison Logic**: We need to determine the most frequent even number, and if multiple numbers have the same frequency, we return the smallest one.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Map to Count Frequencies

```cpp
map<int, int> mp;
for(auto n: nums) mp[n]++;
```

- **map<int, int> mp**: We use a `map` to store the frequency of each number in the array. The key is the number from the array, and the value is the frequency (count of occurrences of that number).
  
- **for(auto n: nums)**: This loop iterates over every number `n` in the array `nums`. For each number, we update the map `mp[n]` by incrementing its frequency count (`mp[n]++`).

#### Step 2: Initialize Variables for Tracking the Result

```cpp
int ans = -1, mx = -1;
```

- **ans**: This variable will store the result, i.e., the most frequent even number. We initialize it to `-1`, which represents the case where no even number is found.
  
- **mx**: This variable keeps track of the maximum frequency encountered so far. Initially, it is set to `-1`, since we haven't encountered any numbers yet.

#### Step 3: Find the Most Frequent Even Number

```cpp
for(auto m: mp){
    if(m.first % 2 == 0 && m.second > mx){
        mx = m.second;
        ans = m.first;
    }
}
```

- **for(auto m: mp)**: This loop iterates over each entry in the map `mp`, where `m.first` is the number and `m.second` is its frequency.
  
- **if(m.first % 2 == 0 && m.second > mx)**: We only care about even numbers, so we check if the number (`m.first`) is even using the condition `m.first % 2 == 0`. Additionally, we check if the frequency of the current number (`m.second`) is greater than the current maximum frequency `mx`. If both conditions are satisfied:
  - We update `mx` to the new higher frequency (`m.second`).
  - We update `ans` to the current number (`m.first`), since it has the highest frequency.

#### Step 4: Return the Result

```cpp
return ans;
```

- Once the loop finishes, we return the value of `ans`, which contains the most frequent even number. If no even numbers were found, `ans` will remain `-1`.

### Complexity

#### Time Complexity:
- **Counting Frequencies**: We iterate over each element in the `nums` array once. This takes **O(n)** time, where `n` is the length of the array.
  
- **Iterating Over the Map**: After constructing the map, we iterate over the entries in the map. In the worst case, the map will have as many entries as the number of unique numbers in the input array. This step takes **O(k)** time, where `k` is the number of unique numbers in the array.

Thus, the overall time complexity of the algorithm is **O(n + k)**, where:
- `n` is the size of the input array (`nums`),
- `k` is the number of unique numbers in `nums`.

#### Space Complexity:
- **Map Storage**: The map stores the frequency of each number in the array. In the worst case, the map could store every number as a unique key, which requires **O(k)** space, where `k` is the number of unique numbers in the array.
  
Thus, the space complexity is **O(k)**.

### Conclusion

This solution efficiently finds the most frequent even number in an array using a map to store frequency counts and a linear scan to identify the most frequent even number. The approach ensures that we:
- Handle arrays of any size,
- Correctly identify even numbers and return the smallest one in case of ties,
- Handle edge cases such as arrays with no even numbers.

Key Takeaways:
- Using a map to track frequency is an efficient way to solve problems involving frequency counts.
- We efficiently filter out odd numbers by checking the condition `m.first % 2 == 0`.
- The solution's time and space complexities are optimal for the problem, ensuring that it scales well with the input size.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-even-element/description/)

---
{{< youtube JykfDvn2o0M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
