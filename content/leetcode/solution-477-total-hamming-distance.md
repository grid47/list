
+++
authors = ["grid47"]
title = "Leetcode 477: Total Hamming Distance"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 477: Total Hamming Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/477.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/477.webp" 
    alt="A sequence of binary strings where the total Hamming distance is calculated, with each distance step gently highlighted"
    caption="Solution to LeetCode 477: Total Hamming Distance Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int bitCnt = 0;
            for(int j = 0; j < nums.size(); j++)
                bitCnt += (nums[j] >> i) & 1;
            
            total += bitCnt * (n - bitCnt);
        }
        return total;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to calculate the **total Hamming distance** between all pairs of integers in a given list of integers. The Hamming distance between two numbers is the number of positions at which the corresponding bits are different. For a list of integers, we need to find the sum of Hamming distances between all possible pairs of numbers.

For example, given the input array `nums = [4, 14, 2]`, the goal is to compute the total Hamming distance for all pairs of integers from the list. The output would be the sum of individual Hamming distances between each pair of integers.

### Approach

To solve this problem efficiently, we can break down the task as follows:

1. **Understanding the Hamming Distance**:
   - The Hamming distance between two numbers is the count of bit positions where the two numbers differ. For example:
     - The binary representation of `4` is `100`.
     - The binary representation of `14` is `1110`.
     - The Hamming distance between `4` and `14` is 3 because their binary forms differ at 3 positions.

2. **Efficiently Calculating Hamming Distance for All Pairs**:
   - Instead of calculating the Hamming distance between every possible pair of numbers in the list (which could be computationally expensive), we can optimize the process by considering each bit position (0 through 31 for a 32-bit integer).
   - For each bit position `i`, count how many numbers have a `1` at that bit position, and how many have a `0`. The total number of differing pairs for that bit position will be the product of the count of `1`s and the count of `0`s.
   - This is because each `1` in a particular bit position will form a differing pair with each `0` in the same bit position.

3. **Summing Up the Hamming Distances**:
   - For each of the 32 bit positions (assuming 32-bit integers), we count how many numbers have `1` in that position and how many have `0`. The number of differing pairs for that position is given by multiplying these counts. The total Hamming distance is the sum of such products over all bit positions.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int total = 0, n = nums.size();
```

- `total`: This will store the cumulative total Hamming distance.
- `n`: This stores the number of integers in the `nums` array.

#### Step 2: Iterate Over Each Bit Position

```cpp
for (int i = 0; i < 32; i++) {
    int bitCnt = 0;
    for (int j = 0; j < nums.size(); j++)
        bitCnt += (nums[j] >> i) & 1;
```

- We loop over each bit position `i` from 0 to 31 (since we are assuming a 32-bit integer).
- `bitCnt`: This variable counts how many numbers in the list have a `1` in the `i`th bit position.
- The expression `(nums[j] >> i) & 1` shifts the `j`th number right by `i` bits and checks if the least significant bit is 1 (i.e., checks if the `i`th bit is 1). If it is, we increment `bitCnt`.

#### Step 3: Calculate Contribution of the Current Bit Position

```cpp
total += bitCnt * (n - bitCnt);
```

- For each bit position `i`, the number of differing pairs is the product of the count of `1`s (`bitCnt`) and the count of `0`s (`n - bitCnt`). This is because each `1` in that bit position forms a differing pair with each `0` at that position.
- We add this contribution to the `total`.

#### Step 4: Return the Result

```cpp
return total;
```

- After processing all 32 bit positions, the `total` will contain the sum of Hamming distances for all pairs of integers in the list.
- We return the `total` as the result.

### Complexity

#### Time Complexity:

- **Outer Loop**: The outer loop runs for each of the 32 bit positions, so it iterates 32 times.
- **Inner Loop**: The inner loop iterates over all `n` numbers in the `nums` array to count the number of `1`s in each bit position.
- **Overall Time Complexity**: The total time complexity is `O(32 * n)`, which simplifies to `O(n)`, since the constant factor 32 is ignored in Big O notation.

#### Space Complexity:

- The space complexity is `O(1)` because the algorithm uses only a constant amount of extra space for variables like `total`, `bitCnt`, and `n`. No additional data structures are used that depend on the input size.

### Conclusion

This solution efficiently calculates the total Hamming distance between all pairs of integers in the list by leveraging bitwise operations and the observation that the total number of differing pairs for each bit position is the product of the count of `1`s and the count of `0`s at that position. The approach significantly reduces the time complexity compared to a naive solution, making it feasible for larger input sizes. The time complexity of `O(n)` and space complexity of `O(1)` ensure that the solution is both time-efficient and space-efficient, which is ideal for handling large datasets.

[`Link to LeetCode Lab`](https://leetcode.com/problems/total-hamming-distance/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
