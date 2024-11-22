
+++
authors = ["grid47"]
title = "Leetcode 2965: Find Missing and Repeated Values"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2965: Find Missing and Repeated Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6r-PQyoHHoQ"
youtube_upload_date="2023-12-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6r-PQyoHHoQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int first = 0;
        int sec = 0;
        
        int n = grid.size();
        
        //xor from 1 to n^2
        for(int i=1;i<=n*n;i++){
            first = first ^ i;
        }

        //xor all element from array
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sec = sec ^ grid[i][j];
            }
        }


        int xorboth = first ^ sec;

        int diff_bit_pos = 0;
        //find differentiating bit postion from back
        for(int i=0;i<32;i++){
            if((xorboth & (1<<i))) {
                diff_bit_pos = i;
                break;
            }
        }

        int ans0 = 0;
        int ans1 = 0;

        //differentiate the both according to the diff_bit_pos
        for(int i=1;i<=n*n;i++){
            if(i & (1<<diff_bit_pos)){
                ans0 ^= i;
            }
            else{
                ans1 ^= i;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] & (1<<diff_bit_pos)){
                    ans0 ^= grid[i][j];
                }
                else{
                    ans1 ^= grid[i][j];
                }
            }
        }

        //finding the order of answer
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == ans0)
                    //if ans0 is found then its repeating number
                    return {ans0 , ans1};
            }
        }

        //if ans0 is found then its not a repeating number
        return {ans1 , ans0};
    }
};
{{< /highlight >}}
---

### Problem Statement:
Given a `n x n` grid that contains numbers from `1` to `n^2` (with one number missing and one number repeated), the task is to find the repeated number and the missing number. The grid will have exactly one missing number and one repeated number. You need to return these two numbers: the repeated number first, and the missing number second.

### Approach:
The approach to solve this problem relies on the properties of the XOR operation. The XOR of two equal numbers results in `0`, and the XOR of a number with `0` results in the number itself. By XOR-ing all the numbers from `1` to `n^2` and the elements of the grid, we can isolate the repeated and missing numbers.

The key idea is that the XOR of the complete set of numbers (`1` to `n^2`) will cancel out with the XOR of the numbers present in the grid. This will leave us with the XOR of the repeated number and the missing number. We can then use this result to differentiate between the two and identify which is missing and which is repeated.

### Code Breakdown (Step by Step):

#### Step 1: Initialize Variables
```cpp
int first = 0;
int sec = 0;
```
- `first`: This variable will hold the XOR of all numbers from `1` to `n^2`.
- `sec`: This variable will hold the XOR of all the elements in the grid.

#### Step 2: XOR all numbers from `1` to `n^2`
```cpp
for(int i=1;i<=n*n;i++){
    first = first ^ i;
}
```
- This loop runs from `1` to `n^2`, XOR-ing each number with `first`. After this loop, `first` will contain the XOR of all numbers from `1` to `n^2`.

#### Step 3: XOR all elements in the grid
```cpp
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        sec = sec ^ grid[i][j];
    }
}
```
- This loop iterates through all elements of the `n x n` grid and XORs them with `sec`. After this loop, `sec` will contain the XOR of all the numbers in the grid.

#### Step 4: XOR the results from Step 2 and Step 3
```cpp
int xorboth = first ^ sec;
```
- The XOR of `first` and `sec` will cancel out the numbers that appear exactly once (because they will cancel themselves out). The result, `xorboth`, will be the XOR of the repeated and missing numbers.

#### Step 5: Find the position of the differing bit
```cpp
int diff_bit_pos = 0;
for(int i=0;i<32;i++){
    if((xorboth & (1<<i))) {
        diff_bit_pos = i;
        break;
    }
}
```
- To differentiate between the repeated and missing numbers, we find the position of the first differing bit in `xorboth`. This is done by checking each bit of `xorboth` to find where it differs from `0`. The position of this bit (`diff_bit_pos`) will help us divide the numbers into two groups.

#### Step 6: Separate the numbers into two groups
```cpp
int ans0 = 0;
int ans1 = 0;

for(int i=1;i<=n*n;i++){
    if(i & (1<<diff_bit_pos)){
        ans0 ^= i;
    }
    else{
        ans1 ^= i;
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j] & (1<<diff_bit_pos)){
            ans0 ^= grid[i][j];
        }
        else{
            ans1 ^= grid[i][j];
        }
    }
}
```
- After identifying the position of the differing bit (`diff_bit_pos`), we divide all the numbers from `1` to `n^2` and the grid elements into two groups based on whether they have this bit set or not. 
- The two groups are then XOR-ed separately into `ans0` and `ans1`. At the end of this step, one of `ans0` or `ans1` will contain the repeated number, and the other will contain the missing number.

#### Step 7: Identify the repeated and missing numbers
```cpp
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j] == ans0)
            return {ans0 , ans1};
    }
}
return {ans1 , ans0};
```
- At this point, we check whether `ans0` exists in the grid. If it does, then `ans0` is the repeated number, and `ans1` is the missing number. 
- If `ans0` is not found in the grid, then `ans1` must be the repeated number, and `ans0` is the missing number.

### Complexity Analysis:

#### Time Complexity:
1. **XOR from `1` to `n^2`**: This loop runs `n^2` times, so its time complexity is **O(n^2)**.
2. **XOR grid elements**: This loop also runs `n^2` times (since the grid is `n x n`), so its time complexity is **O(n^2)**.
3. **Finding the differing bit**: This step takes a constant amount of time, **O(1)**, because it loops over a fixed number of bits (32).
4. **Second XOR loop**: This step again runs `n^2` times, so it has a time complexity of **O(n^2)**.
5. **Final check for the repeated number**: The final check involves scanning the entire grid, which has a time complexity of **O(n^2)**.

Overall, the time complexity is **O(n^2)**.

#### Space Complexity:
- The space complexity is constant, **O(1)**, because we are only using a few extra variables (`first`, `sec`, `xorboth`, `diff_bit_pos`, `ans0`, `ans1`) regardless of the input size.

### Conclusion:
The problem of finding the repeated and missing numbers in a grid can be efficiently solved using XOR. By leveraging the properties of XOR, we can identify the two numbers in linear time **O(n^2)** with constant space **O(1)**. This approach avoids the need for extra storage or complex algorithms, providing an optimal solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-missing-and-repeated-values/description/)

---
{{< youtube 6r-PQyoHHoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
