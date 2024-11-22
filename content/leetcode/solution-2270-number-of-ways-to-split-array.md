
+++
authors = ["grid47"]
title = "Leetcode 2270: Number of Ways to Split Array"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2270: Number of Ways to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XdsMrB7WRUw"
youtube_upload_date="2022-05-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XdsMrB7WRUw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int waysToSplitArray(vector<int>& in) {
        
        
        // partial_sum(nums.begin(), nums.end(), nums.begin());
        
        int n = in.size(), res = 0;

        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
        nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[n - 1] - nums[i]) res++;
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
The task is to find how many ways we can split the given array `in` into two non-empty subarrays such that the sum of elements in the left subarray is greater than or equal to the sum of elements in the right subarray. A split point is defined between indices `i` and `i + 1`, where the first subarray contains the elements from index `0` to `i`, and the second subarray contains the elements from index `i + 1` to the end of the array.

### Approach
To solve this problem, we can use a technique that involves **prefix sums**. The idea is to calculate the sum of the array's elements up to each point in the array, which allows us to efficiently check whether the left subarray sum is greater than or equal to the right subarray sum at each possible split point. This can be done in two stages:
1. **Compute the prefix sums** of the array.
2. **Check for each potential split** whether the sum of the left subarray is greater than or equal to the sum of the right subarray.

### Code Breakdown (Step by Step)

#### Step 1: Initialization
```cpp
int n = in.size(), res = 0;
vector<long long> nums(n, 0);
```
- `n`: Stores the size of the input array `in`.
- `res`: This variable will hold the count of valid ways to split the array.
- `nums`: A vector of long long integers initialized to zeros, which will be used to store the prefix sums.

#### Step 2: Calculate Prefix Sums
```cpp
for(int i = 0; i < n; i++)
    nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
```
- This loop computes the prefix sums. The value at `nums[i]` will represent the sum of elements from index `0` to `i` in the input array.
- The first element `nums[0]` is simply the first element of the array `in[0]`.
- For each subsequent index `i`, `nums[i]` is calculated as the sum of the previous prefix sum `nums[i-1]` and the current element `in[i]`.

#### Step 3: Count Valid Splits
```cpp
for(int i = 0; i < n - 1; i++) {
    if(nums[i] >= nums[n - 1] - nums[i]) res++;
}
```
- This loop iterates through each possible split point, which is between the elements `i` and `i + 1`.
- For each split, we check if the sum of the left subarray (i.e., `nums[i]`) is greater than or equal to the sum of the right subarray (i.e., `nums[n - 1] - nums[i]`).
- If this condition holds, we increment the counter `res`, indicating that this split is valid.

#### Step 4: Return Result
```cpp
return res;
```
- Finally, we return the value of `res`, which contains the total number of valid splits where the sum of the left subarray is greater than or equal to the sum of the right subarray.

### Complexity

#### Time Complexity
- **O(n)**: The time complexity is linear, O(n), where `n` is the size of the input array. This is because:
  - The first loop, which calculates the prefix sums, takes O(n) time.
  - The second loop, which checks the split condition for each index, also takes O(n) time.
- Therefore, the overall time complexity of the algorithm is O(n).

#### Space Complexity
- **O(n)**: The space complexity is O(n) due to the use of the `nums` vector to store the prefix sums. This is the only additional space used apart from the input array.

### Conclusion

The algorithm efficiently counts the number of valid ways to split an array using a combination of prefix sums and a simple comparison between subarray sums. By calculating the prefix sums, the solution allows us to check each potential split in constant time, leading to an overall linear time complexity of O(n). This approach ensures that the solution can handle large arrays efficiently.

This solution is highly optimal for problems requiring a comparison of subarray sums and is commonly used in problems involving partitioning or splitting arrays based on specific conditions. By using a prefix sum array, we avoid recalculating sums multiple times, thus reducing the computational overhead and providing a scalable solution for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-split-array/description/)

---
{{< youtube XdsMrB7WRUw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
