
+++
authors = ["grid47"]
title = "Leetcode 2358: Maximum Number of Groups Entering a Competition"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2358: Maximum Number of Groups Entering a Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r_kn18dmnNo"
youtube_upload_date="2022-07-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/r_kn18dmnNo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int cur_people = 1;
        int cur_grade  = nums[0];
        int tmp_people = 0;
        int tmp_grade = 0;
        int total = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
                tmp_grade += nums[i];
                tmp_people += 1;
            } else {
                total += 1;
                cur_people = tmp_people;
                cur_grade = tmp_grade;
                tmp_people = 1;
                tmp_grade = nums[i];
            }
        }
        return (tmp_people > cur_people && tmp_grade > cur_grade)? total + 1: total;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the maximum number of groups that can be formed from a list of grades such that each subsequent group has:
1. More members than the previous group.
2. A higher sum of grades than the previous group.

Given an array of integers representing grades, the task is to partition this list into groups following these rules and return the maximum number of valid groups.

### Approach

The solution uses a greedy approach, sorting the grades and then iteratively forming groups. By starting with a small group and building up, the solution maintains the two required properties (increasing number of people and increasing sum of grades). Here’s a detailed breakdown of the approach:

1. **Sorting the Grades:**  
   - First, we sort the `nums` array in ascending order. This makes it easier to form groups with increasing grades, as we can simply add elements from left to right to maintain the order.

2. **Tracking Current and Temporary Groups:**  
   - We initialize two sets of variables:
     - `cur_people` and `cur_grade`: Track the number of people and sum of grades in the last completed group.
     - `tmp_people` and `tmp_grade`: Track the number of people and sum of grades in the current group being formed.
   - These variables help ensure that each new group being formed (`tmp_people` and `tmp_grade`) has more people and a higher grade sum than the previous group.

3. **Building Groups:**  
   - As we iterate through `nums`, we add each grade to the current group (`tmp_people` and `tmp_grade`).
   - Once `tmp_people` is greater than `cur_people` and `tmp_grade` is greater than `cur_grade`, we complete the current group.
   - At this point, we:
     - Increment the group count (`total`).
     - Set `cur_people` and `cur_grade` to `tmp_people` and `tmp_grade`, marking the new group as completed.
     - Reset `tmp_people` and `tmp_grade` to start forming the next group.

4. **Final Check:**  
   - After completing the loop, we check if the last group in progress (`tmp_people` and `tmp_grade`) can be counted as a valid group. If `tmp_people` and `tmp_grade` both exceed `cur_people` and `cur_grade`, we increment the group count by 1.

5. **Return Result:**  
   - Finally, we return `total`, the maximum number of valid groups that can be formed.

### Code Breakdown (Step by Step)

#### Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

- Sorting the grades array ensures that we can easily build groups with an increasing order of grades by iterating from left to right.

#### Step 2: Initialize Variables

```cpp
int cur_people = 1;
int cur_grade = nums[0];
int tmp_people = 0;
int tmp_grade = 0;
int total = 1;
int n = nums.size();
```

- We initialize `cur_people` and `cur_grade` with the first grade’s values since the first group will start with this value.
- `tmp_people` and `tmp_grade` are set to 0, as these will hold values for the next group being formed.
- `total` is set to 1, as we start with at least one group (the first grade).

#### Step 3: Iterate Over the Array to Form Groups

```cpp
for(int i = 1; i < n; i++) {
    if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
        tmp_grade += nums[i];
        tmp_people += 1;
    } else {
        total += 1;
        cur_people = tmp_people;
        cur_grade = tmp_grade;
        tmp_people = 1;
        tmp_grade = nums[i];
    }
}
```

- **Inside the Loop:**
  - For each grade, if `tmp_people` is less than or equal to `cur_people` or `tmp_grade` is less than or equal to `cur_grade`, we add the grade to the current group by incrementing `tmp_people` and `tmp_grade`.
  - If both conditions are met, we finalize the group, increment the total group count (`total`), and reset `cur_people` and `cur_grade` to `tmp_people` and `tmp_grade` for the next group.

#### Step 4: Final Check for the Last Group

```cpp
return (tmp_people > cur_people && tmp_grade > cur_grade) ? total + 1 : total;
```

- After the loop, we check if the last group (`tmp_people` and `tmp_grade`) satisfies the conditions for a valid group.
- If it does, we increment `total` by 1; otherwise, `total` remains the same.

### Complexity

#### Time Complexity:
- **Sorting:** Sorting the array takes \(O(n \log n)\), where \(n\) is the length of `nums`.
- **Looping through the array:** We loop through `nums` once to form groups, which is \(O(n)\).
- Thus, the overall time complexity is \(O(n \log n)\).

#### Space Complexity:
- The space complexity is \(O(1)\) for additional variables, as we only use a few integers to track the group properties.

### Conclusion

This solution effectively uses a greedy approach to form the maximum number of valid groups from a sorted list of grades. By maintaining cumulative sums and people counts for each group and ensuring each new group is larger in both size and sum, the solution achieves the required goal in optimal time. Sorting the grades helps ensure that we can efficiently build up groups without needing complex comparisons, resulting in a simple yet efficient algorithm to solve the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/)

---
{{< youtube r_kn18dmnNo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
