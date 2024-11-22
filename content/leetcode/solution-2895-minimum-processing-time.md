
+++
authors = ["grid47"]
title = "Leetcode 2895: Minimum Processing Time"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2895: Minimum Processing Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ju6ArOqNhxM"
youtube_upload_date="2023-10-08"
youtube_thumbnail="https://i.ytimg.com/vi/Ju6ArOqNhxM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minProcessingTime(vector<int>& t, vector<int>& v) {
        int n=v.size();
        sort(t.begin(),t.end());
        sort(v.begin(),v.end());
        int j=n-1;
        int m=t.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int c=0;
            while(c<4)
            {
                ans=max(ans,t[i]+v[j]);
                c++;
                j--;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to calculate the minimum processing time of tasks given two arrays of task times: one array (`t`) representing the task times for different operations and another array (`v`) representing the available processing capacities. 

The goal is to match the operations to the processing capacities in such a way that the maximum processing time is minimized. Specifically, we need to match the maximum task times with the maximum available processing capacities. The task is to return the minimum possible maximum processing time when all tasks have been assigned to a processor.

### Approach

We can approach this problem by using a greedy strategy, where we attempt to match the largest available task time with the largest available processor capacity. By sorting both arrays in ascending order, we can easily match the largest remaining task with the largest remaining processor. Here is a step-by-step breakdown of the approach:

1. **Sort the Task Times and Processor Capacities**:
   - First, we sort both the task times (`t`) and the processor capacities (`v`) in ascending order.
   - Sorting the task times allows us to match the smallest task time with the smallest processor capacity and progressively use larger task times for larger processor capacities.

2. **Greedy Assignment**:
   - We start from the largest task time (`t[n-1]` where `n` is the size of `t`) and assign it to the largest processor capacity (`v[n-1]`).
   - The second largest task time is then assigned to the second largest processor capacity, and so on.

3. **Computing the Result**:
   - For each assignment, the processing time for that task is the sum of the task time and the processor capacity.
   - We keep track of the maximum processing time seen across all assignments.
   - The final result will be this maximum processing time.

4. **Loop to Compute the Result**:
   - We iterate over the task times and assign them to the processor times.
   - The loop runs for each task time, and in each iteration, the task is assigned to the processor, and we update the maximum processing time.

### Code Breakdown (Step by Step)

Let's break down the code into smaller parts to understand how the solution works:

#### 1. Sorting the Input Arrays

```cpp
sort(t.begin(), t.end());
sort(v.begin(), v.end());
```

- **Sorting `t` and `v`**: 
  - We start by sorting both arrays `t` (task times) and `v` (processor capacities) in ascending order. Sorting is essential because, by matching the largest task times with the largest processor capacities, we can minimize the maximum processing time.
  - After sorting, we will attempt to assign the largest available task time to the largest processor capacity.

#### 2. Initializing Variables

```cpp
int n = v.size();
int j = n - 1;
int m = t.size();
int ans = 0;
```

- **`n`**: The size of the processor capacities array `v`.
- **`j`**: An index to keep track of the current processor being assigned (starting from the last index, `n - 1`, the largest processor).
- **`m`**: The size of the task time array `t`.
- **`ans`**: A variable to store the maximum processing time encountered during the assignments.

#### 3. Iterating Over the Tasks and Assigning Them to Processors

```cpp
for(int i = 0; i < m; i++) {
    int c = 0;
    while(c < 4) {
        ans = max(ans, t[i] + v[j]);
        c++;
        j--;
    }
}
```

- **Iterating over the tasks (`t`)**: We loop over all tasks in the array `t` (from `0` to `m-1`).
- **While loop to assign processors**: For each task, we assign it to the processor. We use a `while` loop to make sure the processors are assigned correctly.
  - **`ans = max(ans, t[i] + v[j])`**: For each task, we calculate the processing time by adding the task time `t[i]` and the processor capacity `v[j]`, and update `ans` to be the maximum of the current value of `ans` and the current processing time.
  - **`c++` and `j--`**: After each assignment, we increment the counter `c` and decrement the index `j` to move to the next processor.

#### 4. Return the Final Result

```cpp
return ans;
```

- **Returning `ans`**: After completing the loop and assigning all the tasks, the final result stored in `ans` will be the minimum possible maximum processing time.

### Example Walkthrough

Let's walk through an example to clarify how the code works.

#### Example 1: 
- Task times (`t`): `[5, 3, 8, 6]`
- Processor capacities (`v`): `[4, 7, 6, 9]`

#### Step-by-step Execution:

1. **Sort `t` and `v`**:
   - After sorting, `t = [3, 5, 6, 8]` and `v = [4, 6, 7, 9]`.

2. **Loop over the tasks**:
   - **For `t[0] = 3`** and `v[3] = 9`, the processing time is `3 + 9 = 12`, so `ans = 12`.
   - **For `t[1] = 5`** and `v[2] = 7`, the processing time is `5 + 7 = 12`, so `ans = 12`.
   - **For `t[2] = 6`** and `v[1] = 6`, the processing time is `6 + 6 = 12`, so `ans = 12`.
   - **For `t[3] = 8`** and `v[0] = 4`, the processing time is `8 + 4 = 12`, so `ans = 12`.

3. **Final result**: The maximum processing time encountered is `12`.

**Output**:
```cpp
12
```

### Time Complexity

- **Sorting**: Sorting both the task times and processor capacities arrays takes `O(m log m)` and `O(n log n)` time respectively, where `m` is the size of the task times array and `n` is the size of the processor capacities array.
- **Loop**: The loop runs for `m` iterations (the number of task times), and each iteration involves constant time operations.
- The overall time complexity is dominated by the sorting step, so it is **O(m log m + n log n)**.

### Space Complexity

- **Space Complexity**: The space complexity is **O(1)** because we are only using a few extra variables (`ans`, `m`, `n`, etc.) and the input arrays are modified in-place (i.e., no extra space is used apart from the input).

### Conclusion

This solution efficiently calculates the minimum maximum processing time by leveraging a greedy strategy. By sorting both task times and processor capacities, we can make optimal assignments in linear time after sorting. The time complexity of the solution is dominated by the sorting step, making it efficient even for larger inputs. The space complexity is constant, making this solution optimal in terms of memory usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-processing-time/description/)

---
{{< youtube Ju6ArOqNhxM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
