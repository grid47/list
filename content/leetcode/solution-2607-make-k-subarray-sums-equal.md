
+++
authors = ["grid47"]
title = "Leetcode 2607: Make K-Subarray Sums Equal"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2607: Make K-Subarray Sums Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aBMFrPs2I5c"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi/aBMFrPs2I5c/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    long long solve(vector<int> nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int hit = nums[nums.size() / 2];
        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += abs(hit - nums[i]);
        return res;
    }
    
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        set<int> cnt;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            
            int j = i;
            vector<int> nums;
            while(!cnt.count(j)) {
                cnt.insert(j);
                nums.push_back(arr[j]);
                j = (j + k) % n;
            }
            res += solve(nums);
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to modify an array `arr` such that elements at every `k`-th position are equal by performing a series of operations. The operation is to make all elements in each cycle of `k`-th positions equal by minimizing the total cost. The cost is defined as the sum of absolute differences between the elements in the cycle and the median element of that cycle.

### Approach

To solve the problem, we can break the task into the following steps:

1. **Grouping Elements Based on Indices Modulo k**: 
   The first observation is that the elements that need to be made equal are grouped by their indices modulo `k`. This means that we can treat the array as having `k` separate groups. The elements in the group with indices `i, i+k, i+2k, ...` form a cycle and should be adjusted to the same value.

2. **Finding the Minimum Cost to Equalize a Group**: 
   To minimize the cost of equalizing a group, we should convert all elements in the group to the median of the group. The reason for this is that the median minimizes the sum of absolute differences. This is a well-known property of the median in statistics. So, for each cycle, we find the median and compute the cost to convert every element to the median.

3. **Computing the Result**: 
   For each cycle, we compute the total cost of making all elements equal to the median and sum up these costs to get the final result.

### Code Breakdown (Step by Step)

#### 1. **Helper Function to Compute the Cost for a Group**:

```cpp
long long solve(vector<int> nums) {
    if(nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int hit = nums[nums.size() / 2];  // The median of the sorted group
    long long res = 0;
    for(int i = 0; i < nums.size(); i++)
        res += abs(hit - nums[i]);  // Sum of absolute differences
    return res;
}
```

- **Purpose**: This function computes the total cost of making all elements in a given group equal to the median of the group.
- **Steps**:
  - First, we sort the array of elements. This allows us to easily find the median element, which is the middle element in a sorted array.
  - We then calculate the sum of absolute differences between each element and the median.
  - Finally, we return the total cost.

#### 2. **Main Function to Solve the Problem**:

```cpp
long long makeSubKSumEqual(vector<int>& arr, int k) {
    int n = arr.size();
    set<int> cnt;  // Set to track visited elements
    long long res = 0;  // Final result
    
    for(int i = 0; i < n; i++) {
        int j = i;
        vector<int> nums;
        
        // Grouping elements based on their indices modulo k
        while(!cnt.count(j)) {
            cnt.insert(j);  // Mark this element as visited
            nums.push_back(arr[j]);  // Add the element to the current group
            j = (j + k) % n;  // Move to the next index in the cycle
        }
        
        // Calculate the cost for this group
        res += solve(nums);
    }
    
    return res;
}
```

- **Purpose**: This function calculates the minimum cost required to make all elements at each `k`-th position equal.
- **Steps**:
  - **Initialize Variables**:
    - `n` is the size of the array `arr`.
    - `cnt` is a set used to keep track of the elements we've already processed to avoid redundant work.
    - `res` is the variable that accumulates the total cost.
  
  - **Iterating Through the Array**:
    - For each index `i` in the array, we form a cycle of indices by repeatedly adding `k` to `i` and taking the modulo `n` to wrap around the array. This forms the cycle of indices that need to be equalized.
    - `nums` is a vector that stores the elements in the current cycle.
    - We use a `while` loop to keep adding elements to `nums` until we've visited all elements in the current cycle, and mark the indices as visited by adding them to the `cnt` set.
  
  - **Calculate Cost for Each Group**:
    - Once a cycle is formed, we call the `solve` function to compute the cost of making all elements in this group equal to the median.
    - We accumulate this cost in `res`.
  
  - **Return the Final Result**: After processing all cycles, we return the accumulated cost `res`.

### Complexity Analysis

#### Time Complexity:
- **Sorting**: Sorting the elements in each group takes \(O(m \log m)\), where \(m\) is the size of the group. Since there are at most \(k\) different groups, the total sorting cost for all groups is \(O(n \log n)\), where \(n\) is the size of the array.
- **Cycle Construction and Cost Calculation**: For each element in the array, we process it exactly once. Constructing the cycles and calculating the cost for each group both take linear time relative to the size of the array. Hence, this step takes \(O(n)\).
  
- **Overall Time Complexity**: The overall time complexity is dominated by the sorting step, which is \(O(n \log n)\).

#### Space Complexity:
- **Auxiliary Space**: The space used by the `cnt` set and the `nums` vector is proportional to the number of elements in the array, so the space complexity is \(O(n)\).
  
- **Overall Space Complexity**: The overall space complexity is \(O(n)\), as we only need space for storing the elements of the current cycle and tracking the visited elements.

### Conclusion

This solution efficiently calculates the minimum cost required to make elements at each `k`-th index equal by grouping elements based on their indices modulo `k` and minimizing the cost within each group. The algorithm leverages sorting and Kadane's-like logic for calculating the cost in each cycle. The overall time complexity is \(O(n \log n)\), which makes it feasible for large inputs. This approach is optimal in terms of both time and space, providing a solution to the problem in a systematic and efficient manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/make-k-subarray-sums-equal/description/)

---
{{< youtube aBMFrPs2I5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
