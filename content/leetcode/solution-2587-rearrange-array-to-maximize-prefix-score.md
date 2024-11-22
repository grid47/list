
+++
authors = ["grid47"]
title = "Leetcode 2587: Rearrange Array to Maximize Prefix Score"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2587: Rearrange Array to Maximize Prefix Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N3qkc7zT_a0"
youtube_upload_date="2023-03-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/N3qkc7zT_a0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        
        if(n == 1) return nums[0] > 0;
        int cnt = 0;
        
        long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum > 0) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to maximize the score by selecting elements from a given list of integers. The score is determined by summing the selected numbers until the sum becomes non-positive. We are tasked with returning the number of elements selected from the list such that the sum is positive.

### Approach

To solve this problem, the strategy is to greedily select the largest numbers first. This allows us to ensure that we maximize the sum while minimizing the number of elements selected. The key observation here is that if we sum the elements from the largest to smallest, we maximize the score until we hit a non-positive sum. The approach can be broken down into the following steps:

1. **Sorting the List in Descending Order**: By sorting the list in descending order, we ensure that we are adding the largest numbers first, which will give us the maximum possible sum.
  
2. **Iterate and Sum the Elements**: Start iterating over the sorted list and keep a running sum. If the running sum becomes positive, increment the count of selected elements.

3. **Stop When Sum Becomes Non-Positive**: If at any point, the running sum becomes zero or negative, stop adding more numbers, as further numbers would only reduce the total score.

4. **Return the Count of Selected Elements**: Once the iteration is complete, the count of elements that contributed to a positive sum is the final answer.

### Code Breakdown (Step by Step)

#### 1. **Sorting the List**:
```cpp
sort(nums.begin(), nums.end(), greater<int>());
```
- **Explanation**: The `sort` function is used to sort the `nums` vector in descending order using the `greater<int>()` comparison function. This ensures that the largest elements come first in the list, allowing us to maximize the sum as we iterate through the array.
  
#### 2. **Edge Case - Single Element**:
```cpp
if (n == 1) return nums[0] > 0;
```
- **Explanation**: If the list contains only one element, we simply check if that element is greater than 0. If it is, we return 1 (since we would select that element), otherwise, we return 0 (as a non-positive element can't contribute to the score).
- **Why this is needed**: This handles the corner case where there is only one number in the list and ensures that the solution works for small input sizes.

#### 3. **Iterating and Summing the Elements**:
```cpp
long sum = 0;
for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (sum > 0) cnt++;
}
```
- **Explanation**: 
  - We initialize a variable `sum` to keep track of the running sum as we iterate through the sorted array.
  - For each number `nums[i]`, we add it to the sum.
  - If the sum is positive after adding `nums[i]`, we increment the `cnt` variable, which keeps track of how many elements contribute to a positive score.

#### 4. **Returning the Result**:
```cpp
return cnt;
```
- **Explanation**: After iterating over all the elements, `cnt` will contain the number of elements that were added to the sum such that the sum remained positive. This value is returned as the result.

### Time Complexity

The time complexity of the solution can be broken down as follows:
1. **Sorting**: Sorting the `nums` array takes \(O(n \log n)\), where \(n\) is the number of elements in the array.
2. **Iteration**: The iteration through the sorted list takes \(O(n)\), as we loop through each element exactly once.

Therefore, the overall time complexity of this solution is dominated by the sorting step, and the total time complexity is:

\[
O(n \log n)
\]

### Space Complexity

The space complexity is \(O(1)\), assuming the sort operation is done in-place and no additional data structures (other than the input array) are used. The only extra space used is for a few variables (`cnt` and `sum`), which takes constant space.

### Example Walkthrough

#### Input:
```cpp
vector<int> nums = {-1, 2, 3, -4, 5};
```

1. **Step 1 - Sort the Array**: 
   - The sorted array in descending order would be `[5, 3, 2, -1, -4]`.

2. **Step 2 - Initialize Variables**: 
   - `sum = 0`
   - `cnt = 0`

3. **Step 3 - Start Iterating**:
   - **First iteration** (i = 0): 
     - Add `5` to the sum: `sum = 5`
     - Since `sum > 0`, increment `cnt`: `cnt = 1`
   
   - **Second iteration** (i = 1): 
     - Add `3` to the sum: `sum = 8`
     - Since `sum > 0`, increment `cnt`: `cnt = 2`
   
   - **Third iteration** (i = 2): 
     - Add `2` to the sum: `sum = 10`
     - Since `sum > 0`, increment `cnt`: `cnt = 3`
   
   - **Fourth iteration** (i = 3): 
     - Add `-1` to the sum: `sum = 9`
     - Since `sum > 0`, increment `cnt`: `cnt = 4`
   
   - **Fifth iteration** (i = 4): 
     - Add `-4` to the sum: `sum = 5`
     - Since `sum > 0`, increment `cnt`: `cnt = 5`
   
4. **Step 4 - Return Result**:
   - After iterating through all the elements, the count of elements contributing to a positive sum is `5`.

#### Output:
```cpp
5
```

### Conclusion

The problem is solved efficiently by sorting the list in descending order and then greedily selecting elements as long as the running sum remains positive. The solution ensures that we maximize the number of elements selected by starting with the largest elements. With a time complexity of \(O(n \log n)\), this approach works well within typical input constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/)

---
{{< youtube N3qkc7zT_a0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
