
+++
authors = ["grid47"]
title = "Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wcDDdRZH1Q0"
youtube_upload_date="2020-08-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wcDDdRZH1Q0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int hit) {
        map<int, int> mp;
        
        int n = nums.size(), sum = 0, right = -1, cnt = 0;
        
        //partial_sum(nums.begin(), nums.end(), nums.begin());
        
        
        mp[0] = -1;
        
        
        for(int i = 0; i < n;i++){
            //cout<< nums[i] << " ";
            sum += nums[i];
            if(mp.count(sum - hit)) {
                int left = mp[sum - hit];
            //    cout << right << " " << left;
                if (right <= left) {
                    cnt++;
                    right = i;
                  }
                }


            mp[sum] = i;
            // cout<< mp[sum] << endl;
          }
            
            

        
        return cnt;
            
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the maximum number of non-overlapping subarrays in a given array of integers `nums`, such that the sum of elements in each subarray equals a specified value `hit`. The challenge is to efficiently count these subarrays while ensuring that no two counted subarrays overlap.

### Approach

To solve this problem, we will use a hash map to keep track of cumulative sums and their indices as we iterate through the array. The core idea is to use the prefix sum technique, which allows us to compute the sum of any subarray in constant time. Here’s a step-by-step breakdown of the approach:

1. **Prefix Sum Calculation**: As we iterate through the array, we maintain a cumulative sum (`sum`). This sum represents the total of all elements encountered so far.

2. **Hash Map for Indices**: We use a hash map (`mp`) to store the indices of previously seen cumulative sums. The key is the cumulative sum, and the value is the latest index where this sum occurs.

3. **Finding Subarrays**: For each cumulative sum at index `i`, we check if there exists a prior sum that would lead to a subarray summing to `hit`. This is done by checking if `sum - hit` exists in the map. If it does, we retrieve the index of this sum.

4. **Non-Overlapping Condition**: To ensure that the found subarrays are non-overlapping, we compare the index of the last counted subarray (`right`) with the index of the found subarray (`left`). If `right` is less than or equal to `left`, we can count this subarray, update `right`, and increment our count.

5. **Update Hash Map**: Regardless of whether we found a valid subarray, we update the hash map with the current cumulative sum and its index.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int hit) {
        map<int, int> mp; // Step 1: Initialize a hash map to store cumulative sums and their latest indices
        
        int n = nums.size(), sum = 0, right = -1, cnt = 0; // Step 2: Initialize variables
        
        mp[0] = -1; // Step 3: Initialize the map with the base case
        
        for(int i = 0; i < n; i++) { // Step 4: Iterate through the array
            sum += nums[i]; // Update the cumulative sum
            
            if(mp.count(sum - hit)) { // Step 5: Check if a valid subarray sum exists
                int left = mp[sum - hit]; // Get the index of the previously found sum
                
                if (right <= left) { // Step 6: Ensure non-overlapping condition
                    cnt++; // Increment count of valid subarrays
                    right = i; // Update the right boundary
                }
            }

            mp[sum] = i; // Step 7: Update the map with the current cumulative sum
        }
        
        return cnt; // Step 8: Return the total count of non-overlapping subarrays
    }
};
```

#### Step-by-Step Breakdown

1. **Initialize Data Structures**:
   - A hash map `mp` is created to store cumulative sums and their last occurrence.
   - Variables `n`, `sum`, `right`, and `cnt` are initialized to hold the size of the array, current cumulative sum, the rightmost index of the last counted subarray, and the count of valid subarrays, respectively.

2. **Base Case**:
   - The hash map is initialized with the entry `{0: -1}` to handle the case where a valid subarray starts from index `0`.

3. **Iterate through the Array**:
   - For each element in `nums`, we add it to `sum`, which keeps a running total of the array elements.

4. **Check for Subarray Sum**:
   - The code checks if the difference `sum - hit` exists in the hash map. This condition checks if the current cumulative sum minus the target sum `hit` has been seen before.

5. **Non-Overlapping Check**:
   - If `sum - hit` is found in `mp`, we retrieve its index `left`. The non-overlapping condition is checked by comparing `right` and `left`. If the current subarray does not overlap with previously counted subarrays (i.e., `right` is less than or equal to `left`), we can count this subarray.

6. **Increment Count and Update Right Index**:
   - If the conditions are satisfied, we increment `cnt` and update `right` to the current index `i`.

7. **Update Hash Map**:
   - Regardless of whether a valid subarray was found, we update the map with the current cumulative sum `sum` and its corresponding index.

8. **Return Result**:
   - After iterating through the array, the final count of non-overlapping subarrays is returned.

### Complexity

#### Time Complexity
- The algorithm runs in \( O(n) \), where \( n \) is the size of the input array. This is because each element in `nums` is processed once, and operations on the hash map (insert and check for existence) are average \( O(1) \).

#### Space Complexity
- The space complexity is \( O(n) \) in the worst case, due to the storage of cumulative sums in the hash map. However, in practice, it might be less depending on the number of unique cumulative sums.

### Conclusion

The solution effectively counts the maximum number of non-overlapping subarrays that sum to a specified value by utilizing the prefix sum technique and a hash map for quick lookups. 

**Key Takeaways**:
- **Prefix Sum Technique**: This method allows for efficient subarray sum calculations.
- **Non-Overlapping Condition**: Proper handling of indices ensures that counted subarrays do not overlap.
- **Hash Map Utilization**: The use of a hash map provides an efficient way to keep track of previously encountered cumulative sums.

This implementation demonstrates a clean and efficient way to tackle problems involving subarray sums and conditions on overlapping, making it a valuable approach for similar problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/)

---
{{< youtube wcDDdRZH1Q0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
