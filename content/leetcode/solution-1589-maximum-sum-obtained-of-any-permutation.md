
+++
authors = ["grid47"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1589: Maximum Sum Obtained of Any Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TyZ_FFGIZgs"
youtube_upload_date="2020-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/TyZ_FFGIZgs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        long long res = 0;
        vector<long long> cnt(n, 0);
        for(auto& r: req) {
            cnt[r[0]]++;
            if(r[1] + 1 < n)
                cnt[r[1] +1]--;
    }
        
        for(int i = 1; i < n; i++)
            cnt[i] += cnt[i -1];
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++)
            res +=  ((long long) nums[i] * cnt[i]);
        
        return res % 1000000007;
        }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires us to calculate the maximum sum of values from a given array based on specified range queries. Each query indicates a range of indices within the array, and our goal is to find an optimal arrangement of contributions from these values in a way that maximizes the total sum.

### Approach

To achieve this, we will take the following steps:

1. **Count Contributions**: For each query, we will determine how many times each index in the `nums` array is included in the specified ranges.

2. **Cumulative Count**: Using a technique similar to a prefix sum array, we will derive the total contributions for each index from the range queries.

3. **Sorting**: To maximize the sum, we will sort both the `nums` array and the cumulative contribution counts in descending order.

4. **Calculate Maximum Sum**: By multiplying the values from the sorted `nums` array with the sorted contribution counts, we can find the maximum possible sum from the ranges.

5. **Modulo Operation**: Since the result could be large, we will return it modulo \(10^9 + 7\).

### Code Breakdown (Step by Step)

Let’s go through the code and explain its functionality in detail:

```cpp
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size(); // Get the size of the nums array
        long long res = 0; // Initialize the result variable to store the maximum sum
        vector<long long> cnt(n, 0); // Create a count array initialized to zero
```

- **Initialization**: We begin by initializing the result variable `res` to store the cumulative sum. The `cnt` array will track how many times each index of `nums` contributes to the total sum as determined by the queries.

```cpp
        for(auto& r: req) { // Loop through each range query
            cnt[r[0]]++; // Increment the start of the range
            if(r[1] + 1 < n) // Check if the end of the range exceeds the array bounds
                cnt[r[1] + 1]--; // Decrement the position after the end of the range
        }
```

- **Counting Contributions**: For each query, we increment the start index and decrement the index just after the end of the range. This marks the beginning and end of the contributions for that query.

```cpp
        for(int i = 1; i < n; i++) // Convert the count array to cumulative counts
            cnt[i] += cnt[i - 1]; // Accumulate counts to get total contributions for each index
```

- **Cumulative Count Calculation**: Here, we transform the `cnt` array into a cumulative count. This means that each index now holds the total number of times it was included across all range queries.

```cpp
        sort(nums.begin(), nums.end()); // Sort the nums array in ascending order
        sort(cnt.begin(), cnt.end()); // Sort the count array in ascending order
```

- **Sorting Arrays**: We sort both the `nums` array and the cumulative count array. Sorting ensures that we can maximize the sum when we multiply the largest contributions with the largest numbers.

```cpp
        for(int i = 0; i < n; i++) // Calculate the maximum sum
            res += ((long long) nums[i] * cnt[i]); // Multiply corresponding elements from nums and cnt
```

- **Calculating the Maximum Sum**: In this loop, we multiply the corresponding elements of the sorted `nums` and `cnt` arrays. The result is accumulated into the `res` variable.

```cpp
        return res % 1000000007; // Return the result modulo 10^9 + 7
    }
};
```

- **Final Return**: Finally, we return the result modulo \(10^9 + 7\) to ensure that we handle large sums correctly.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n + k \log k)\), where \(n\) is the size of the `nums` array and \(k\) is the number of queries. The most time-consuming steps are the sorting operations which each take \(O(k \log k)\).

- **Space Complexity**: The space complexity is \(O(n)\) due to the additional count array used for tracking contributions.

### Conclusion

The provided solution efficiently calculates the maximum sum of contributions from the `nums` array based on the specified range queries. By leveraging cumulative counts and sorting, we ensure that we maximize the sum effectively. 

This approach showcases a clever use of array manipulation and sorting techniques to derive an optimal solution for a problem that could otherwise involve more complex and computationally expensive operations.

In summary, this algorithm effectively addresses the problem by:

- Utilizing a counting technique to handle overlapping ranges.
- Transforming the count into a cumulative format to easily manage contributions.
- Employing sorting to ensure maximum contributions align with the largest values.

This method is robust and can handle various input sizes, making it suitable for competitive programming and applications where performance is crucial.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/)

---
{{< youtube TyZ_FFGIZgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
