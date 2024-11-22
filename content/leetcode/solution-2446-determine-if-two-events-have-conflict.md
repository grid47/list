
+++
authors = ["grid47"]
title = "Leetcode 2446: Determine if Two Events Have Conflict"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2446: Determine if Two Events Have Conflict in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mahSMDuJL9A"
youtube_upload_date="2022-10-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mahSMDuJL9A/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine if two events, represented by two pairs of strings, have a time conflict. Each event has a start time and an end time, and the goal is to check if the events overlap or not. 

The two events are given as two string arrays `event1` and `event2`. Each array contains two strings: the start time and the end time of the event. The times are formatted as "HH:MM" (24-hour clock format). We need to return `true` if there is a conflict (i.e., the events overlap in time) and `false` if they do not.

For example:
- **Input**: `event1 = ["01:00", "02:00"], event2 = ["01:30", "02:30"]`
- **Output**: `true`

Explanation: The first event lasts from "01:00" to "02:00", and the second event lasts from "01:30" to "02:30". Since the two events overlap from "01:30" to "02:00", the function should return `true`.

### Approach

To determine if two events overlap, we can break down the problem as follows:

1. **Understanding the Time Intervals**: Each event is defined by two time points: a start time and an end time. We can think of the times as intervals on a number line.
2. **Checking for Overlap**: The two events overlap if:
   - The start time of `event2` is before or equal to the end time of `event1` (`event2[0] <= event1[1]`), and
   - The end time of `event2` is after or equal to the start time of `event1` (`event2[1] >= event1[0]`).
   
   If both of these conditions are satisfied, then the two events overlap, and we return `true`. Otherwise, they don't overlap, and we return `false`.

3. **Time Comparison**: Since the times are given in the "HH:MM" format, string comparison will work directly. Strings in lexicographical order will give the correct chronological order for times in this format, as the hour and minute values will be compared in sequence.

Thus, our task is to compare the start and end times of the two events directly using the above conditions.

### Code Breakdown (Step by Step)

#### Step 1: Checking Overlap Condition

The function `haveConflict` takes two input parameters: `event1` and `event2`, which are both vectors of strings representing the start and end times of the respective events.

```cpp
bool haveConflict(vector<string>& event1, vector<string>& event2) {
    if (event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
    return false;
}
```

1. **Input Parameters**:
   - `event1` is an array containing two strings: `event1[0]` represents the start time and `event1[1]` represents the end time.
   - `event2` is similarly an array containing two strings: `event2[0]` represents the start time and `event2[1]` represents the end time.
   
2. **Overlap Condition**:
   The condition inside the `if` statement checks if the events overlap. Specifically, we check:
   - If the start time of `event2` is before or at the same time as the end time of `event1` (`event2[0] <= event1[1]`), and
   - If the end time of `event2` is after or at the same time as the start time of `event1` (`event2[1] >= event1[0]`).

   If both conditions are true, then the events overlap, and we return `true`. If either condition fails, we return `false` indicating no overlap.

3. **Return Statement**:
   If the events overlap, the function returns `true`; otherwise, it returns `false`.

#### Step 2: Conclusion

This code provides a simple and efficient way to determine if two events overlap by comparing their start and end times using basic string comparisons.

### Complexity

#### Time Complexity

The time complexity of the solution is **O(1)**. The function performs a constant number of string comparisons and logical operations regardless of the size of the input, since it only checks two pairs of times. The comparison operations are performed directly between two time strings, which are fixed in length ("HH:MM" format), making the operation constant time.

Thus, the overall time complexity is **O(1)**.

#### Space Complexity

The space complexity of the solution is **O(1)**, as the function only uses a constant amount of space for storing the input and the result. No additional data structures are used beyond the input arrays, making this solution space-efficient.

### Conclusion

This solution provides a direct and efficient way to determine if two events overlap. By leveraging simple string comparisons on the time values, we can easily check if the events conflict. The solution works in constant time, **O(1)**, and constant space, **O(1)**, making it highly efficient for this problem. 

In summary:
- **Time Complexity**: **O(1)** — Only a few string comparisons and logical operations are performed.
- **Space Complexity**: **O(1)** — No additional space is used apart from the input and output.

This approach is optimal for checking event conflicts and guarantees correctness due to the simplicity of comparing time intervals using lexicographical string comparison.

[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-two-events-have-conflict/description/)

---
{{< youtube mahSMDuJL9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
