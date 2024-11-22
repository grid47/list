
+++
authors = ["grid47"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2798: Number of Employees Who Met the Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2AJL4Oh1snk"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2AJL4Oh1snk/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for(int i = 0; i < hours.size(); i++)
            if(hours[i] >= target) cnt++;
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine the number of employees who met or exceeded a specified work target. You are given a list of integers, where each integer represents the number of hours worked by an employee. Additionally, you are provided with a target number of hours. The goal is to count how many employees worked at least the target number of hours.

### Approach

The solution to this problem involves iterating through the list of employee hours and comparing each value to the target. If the employee's hours meet or exceed the target, we increment a counter. The final count will give the number of employees who have met the target.

#### Key Steps:

1. **Iterate Through the List of Employee Hours**: We loop through the list of hours worked by employees.
2. **Compare Each Employee's Hours to the Target**: For each employee, if their hours are greater than or equal to the target, we increase the count.
3. **Return the Count**: After the loop finishes, the counter will hold the total number of employees who met the target.

### Code Breakdown (Step by Step)

```cpp
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int cnt = 0;  // Initialize the counter to 0, which will hold the number of employees who met the target.
    
    // Step 1: Iterate through the hours list
    for(int i = 0; i < hours.size(); i++) {
        // Step 2: Check if the current employee's hours meet or exceed the target
        if(hours[i] >= target) {
            cnt++;  // If so, increment the counter
        }
    }
    
    // Step 3: Return the final count of employees who met the target
    return cnt;
}
```

1. **Function Declaration**: The function `numberOfEmployeesWhoMetTarget` takes in two parameters: a vector `hours` which contains the hours worked by employees, and an integer `target` which represents the target hours.
2. **Counter Initialization**: A variable `cnt` is initialized to zero. This variable will track the number of employees who met or exceeded the target.
3. **Iterating Over the List**: The loop `for(int i = 0; i < hours.size(); i++)` iterates through each element in the `hours` vector. The index `i` represents each employee.
4. **Comparison**: Inside the loop, `if(hours[i] >= target)` checks if the number of hours worked by the current employee (`hours[i]`) is greater than or equal to the target value. If the condition is true, the counter `cnt` is incremented.
5. **Return the Result**: After finishing the loop, the function returns the value of `cnt`, which represents the number of employees who met or exceeded the target.

### Complexity

#### Time Complexity:
The time complexity of the solution is **O(n)**, where `n` is the number of elements in the `hours` vector. This is because we iterate over the list once, comparing each element with the target.

#### Space Complexity:
The space complexity is **O(1)**, meaning constant space. The function only uses a few additional variables (`cnt` and the loop index `i`) regardless of the size of the input, so the space required does not grow with the size of the input.

### Conclusion

This problem is a simple iteration-based task that counts the number of elements in an array that satisfy a given condition (in this case, employees who worked at least the target number of hours). The time complexity of **O(n)** ensures that the solution is efficient for large inputs, and the space complexity of **O(1)** guarantees minimal memory usage.

The solution uses basic programming constructs such as loops and conditional statements, making it both easy to understand and implement. This approach is optimal for scenarios where you need to quickly count elements that meet a specified criterion within a collection, such as in tracking employee performance against a target or similar tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-employees-who-met-the-target/description/)

---
{{< youtube 2AJL4Oh1snk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
