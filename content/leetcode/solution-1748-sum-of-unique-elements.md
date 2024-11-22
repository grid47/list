
+++
authors = ["grid47"]
title = "Leetcode 1748: Sum of Unique Elements"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1748: Sum of Unique Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MXQyGU493vE"
youtube_upload_date="2021-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MXQyGU493vE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum= 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]] <= 1)
                sum+= nums[i];
        }
        return sum;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to calculate the sum of unique elements in an array `nums`. A unique element is one that appears exactly once in the array. If an element appears multiple times, it should not contribute to the sum.

### Approach

This solution utilizes a hash map to count the occurrences of each element in the array. By counting frequencies, we can identify which elements appear only once. Once we know the frequency of each element, we calculate the sum by adding up only those elements that have a frequency of one in the hash map.

### Code Breakdown (Step by Step)

Let’s go through the code in detail to understand each step.

1. **Frequency Counting Using Hash Map**:
   - Initialize an empty hash map `mpp` to store frequencies of each element in `nums`.
   - Loop through each element in `nums` and update its count in the map.
  
   ```cpp
   unordered_map<int, int> mpp;
   for(int i = 0; i < nums.size(); i++) {
       mpp[nums[i]]++;
   }
   ```
   
   After this loop, `mpp` will hold the count of occurrences for each number in `nums`.

2. **Summing Unique Elements**:
   - Initialize `sum` to zero to store the sum of unique elements.
   - Loop through the elements in `nums` again, and for each element, check if it has a count of 1 in `mpp`.
   - If so, add it to `sum` since it is unique.

   ```cpp
   int sum = 0;
   for(int i = 0; i < nums.size(); i++) {
       if(mpp[nums[i]] == 1) {
           sum += nums[i];
       }
   }
   ```

   This step ensures that only unique elements contribute to the final sum.

3. **Returning the Result**:
   - Finally, return the calculated sum.

   ```cpp
   return sum;
   ```

### Complexity

- **Time Complexity**: \(O(N)\), where \(N\) is the number of elements in `nums`. The code iterates through `nums` twice: once to fill the hash map and once to calculate the sum, making the overall complexity \(O(N)\).
  
- **Space Complexity**: \(O(N)\) for the hash map `mpp`, as it stores the frequency of each unique element in `nums`.

### Conclusion

This solution efficiently calculates the sum of unique elements in an array using a hash map to count occurrences. By isolating elements with a count of 1, we ensure that only unique elements are included in the sum. This approach provides a straightforward and optimal solution to the problem of summing unique elements.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-unique-elements/description/)

---
{{< youtube MXQyGU493vE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
