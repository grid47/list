
+++
authors = ["grid47"]
title = "Leetcode 2865: Beautiful Towers I"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2865: Beautiful Towers I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iCJCmaPjP4M"
youtube_upload_date="2023-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/iCJCmaPjP4M/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    #define ll long long
    
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        
       ll int ans=0;
        for(int i=0;i<n;i++){
            ll int sum = a[i];
            int prev=a[i];
            for(int j=i-1;j>=0;j--){
                prev = min(a[j],prev);
                sum += prev;
            }
            prev=a[i];
            for(int j=i+1;j<n;j++){
                prev = min(a[j],prev);
                sum += prev;
            }
            
            if(sum > ans) ans=sum;
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to calculate the maximum sum of heights of a subsequence of a given array, where the sum of heights is defined as the sum of the elements in the subsequence considering the minimum value of each subsequence at any point. More specifically, the task is to iterate through all elements of the array, treat each as the "peak," and compute the maximum possible sum of the heights, considering both elements to the left and right of the peak. Each element contributes its height and the minimum height for each side of the peak is used for summing the heights.

### Approach

To solve the problem, we need to iterate over each element of the array, treating it as the "peak" of a subsequence. For each peak, we calculate the sum of the heights by adding the minimum values to the left and right of the peak. The goal is to find the maximum sum of heights across all such peaks.

Here is a step-by-step breakdown of the approach:

1. **Initial Setup**: 
   - We will use two nested loops to explore each possible peak.
   - We will calculate the sum for each peak and keep track of the maximum sum.

2. **Left and Right Calculation**: 
   - For each element, we will first calculate the sum of the heights for the elements to its left (if any) and to its right (if any). 
   - The sum of heights is calculated by adding the minimum of the previous element (to the left) or the current element.
   - Similarly, we do this for the right side, considering the minimum of the current element and the next one.

3. **Edge Cases**: 
   - We need to handle edge cases such as arrays with a single element or arrays where the height sequence is already in increasing or decreasing order.

### Code Breakdown (Step by Step)

#### Step 1: Define Constants and Initialize Variables

```cpp
#define ll long long
```
- Here we define `ll` as an alias for `long long` to make the code cleaner and more readable.

```cpp
int n = a.size();
ll int ans = 0;
```
- `n` stores the size of the input array `a`.
- `ans` is initialized to `0`, which will store the maximum sum of heights as we process each possible peak in the array.

#### Step 2: Iterate Over Each Element as the Peak

```cpp
for(int i = 0; i < n; i++) {
    ll int sum = a[i]; // The peak element itself
    int prev = a[i];   // The previous minimum height
```
- We start iterating through each element of the array with `i` acting as the index of the peak.
- `sum` is initialized to the value of the current element `a[i]`, representing the initial height sum starting from the peak.
- `prev` holds the previous minimum height encountered while traversing the array.

#### Step 3: Calculate Sum for the Left Side of the Peak

```cpp
for(int j = i - 1; j >= 0; j--) {
    prev = min(a[j], prev); // The minimum height between current element and previous minimum
    sum += prev;             // Add the minimum value to the total sum
}
```
- This loop moves leftward from the peak (`i`) to the beginning of the array (`0`), calculating the minimum height (`prev`) at each step and adding it to `sum`.
- The `min(a[j], prev)` ensures that we always consider the minimum height while traversing from left to right.

#### Step 4: Calculate Sum for the Right Side of the Peak

```cpp
prev = a[i]; // Reset the previous height to the peak element

for(int j = i + 1; j < n; j++) {
    prev = min(a[j], prev); // The minimum height between current element and previous minimum
    sum += prev;             // Add the minimum value to the total sum
}
```
- After processing the left side, we reset the `prev` variable to the peak (`a[i]`).
- Then, we move rightward from the peak to the end of the array, again calculating the minimum height at each step and adding it to `sum`.

#### Step 5: Update the Maximum Sum

```cpp
if(sum > ans) ans = sum; // Keep track of the maximum sum
```
- After calculating the sum of heights for the current peak, we check if it is larger than the previously recorded maximum sum (`ans`). If so, we update `ans` to this new maximum.

#### Step 6: Return the Result

```cpp
return ans; // Return the maximum sum found
```
- After iterating through all possible peaks, we return the maximum sum of heights.

### Example Walkthrough

Let's go through an example to better understand how this solution works.

**Example 1**:
Input: `a = [1, 3, 2, 4]`

- We treat `a[0] = 1` as the peak:
  - Left side: No elements to the left, so sum = `1`.
  - Right side: The minimum value on the right side is `2`, so sum = `1 + 2 + 2 = 5`.
  - The maximum sum so far is 5.
  
- We treat `a[1] = 3` as the peak:
  - Left side: The minimum value on the left side is `1`, so sum = `3 + 1 + 1 = 5`.
  - Right side: The minimum value on the right side is `2`, so sum = `3 + 1 + 2 + 2 = 8`.
  - The maximum sum so far is 8.
  
- We treat `a[2] = 2` as the peak:
  - Left side: The minimum value on the left side is `1`, so sum = `2 + 1 + 1 = 4`.
  - Right side: The minimum value on the right side is `2`, so sum = `2 + 1 + 2 = 5`.
  - The maximum sum so far remains 8.

- We treat `a[3] = 4` as the peak:
  - Left side: The minimum value on the left side is `2`, so sum = `4 + 2 + 2 = 8`.
  - Right side: No elements to the right, so sum = `8`.
  - The maximum sum remains 8.

Final answer: `8`.

### Complexity

#### Time Complexity:
- The outer loop runs `n` times, where `n` is the size of the array.
- For each iteration of the outer loop, two inner loops are used to process the left and right sides of the current peak. Each of these inner loops runs at most `n` times in total across all peaks.
- Therefore, the overall time complexity is **O(n^2)**.

#### Space Complexity:
- The space complexity is **O(1)** since we are only using a constant amount of extra space, regardless of the input size.

### Conclusion

This solution iterates over each element in the array, treating each one as a peak and calculating the sum of the heights by considering both the left and right sides. It keeps track of the maximum sum encountered during the iterations. The time complexity is quadratic, making this solution suitable for small to moderate input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/beautiful-towers-i/description/)

---
{{< youtube iCJCmaPjP4M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
