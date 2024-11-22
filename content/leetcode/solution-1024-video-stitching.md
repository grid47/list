
+++
authors = ["grid47"]
title = "Leetcode 1024: Video Stitching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1024: Video Stitching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4Qho-im90ew"
youtube_upload_date="2020-11-05"
youtube_thumbnail="https://i.ytimg.com/vi/4Qho-im90ew/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int res = 0;
        for(auto i = 0, st = 0, end = 0; st < time; st=end, ++res){
            for(; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if(st == end) return -1;
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The goal of the problem is to cover a specified duration of time using the minimum number of video clips. Each clip has a start time and an end time, and you need to determine how many clips you need to stitch together to cover the entire duration from 0 to the given time. If it is not possible to cover the entire duration, the function should return -1.

For instance, given clips `[[0, 2], [2, 5], [5, 8]]` and `time = 8`, you can stitch together the clips `[0, 2]` and `[2, 5]` to cover up to 5, and then add the clip `[5, 8]` to cover the full duration. Therefore, the output would be 3 clips.

### Approach
To solve the video stitching problem, the following approach is adopted:
1. **Sort the Clips**: First, sort the clips based on their start times. This ensures that we can process them in a sequential manner.
2. **Iterate Over Time**: Use a loop to traverse the time intervals from `0` to `time`.
3. **Track the Maximum End**: For each starting point, find the maximum end time of the clips that start at or before the current starting point.
4. **Count the Clips**: Increment the count of clips each time a new segment is added. If at any point the start time equals the end time (meaning no further clips can extend the coverage), return -1.
5. **Return the Result**: Finally, return the count of clips needed to cover the specified duration.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `videoStitching` is defined within the `Solution` class, taking a reference to a 2D vector of integers `clips` and an integer `time` as its parameters.

2. **Sorting Clips**:
   - The `sort` function is called to sort the `clips` vector in ascending order based on the starting times of the clips. This allows for efficient processing in sequential order.

3. **Initialization**:
   - Variables `res` (to count the number of clips used), `st` (the starting time for the current segment), and `end` (the farthest point that can be reached) are initialized.

4. **Outer Loop**:
   - A `for` loop runs until `st` is less than `time`, where `st` is updated to the value of `end` at the beginning of each iteration. The loop continues to increment `res` each time a new clip is added.

5. **Inner Loop**:
   - A nested `for` loop is used to check which clips can be used starting from the current `st`. This loop continues as long as:
     - `i` is less than the size of the `clips` vector.
     - The start time of the current clip is less than or equal to `st`.
   - Inside this loop, the `end` variable is updated to the maximum of its current value and the end time of the clip being checked (`clips[i][1]`).

6. **End Check**:
   - After processing all applicable clips, the code checks if `st` is equal to `end`. If they are equal, it means no further progress can be made (i.e., no clip can extend the current coverage), and the function returns -1.

7. **Return Statement**:
   - If the loop completes successfully (indicating that the entire time interval has been covered), the function returns the value of `res`, which indicates the minimum number of clips required.

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \(O(n \log n)\), where \(n\) is the number of clips. This complexity arises from the sorting step. The iteration through the clips occurs in linear time, which is \(O(n)\).
- **Space Complexity**: The space complexity is \(O(1)\) for the auxiliary space, as we are using a fixed number of variables for counting and tracking indices. The input clips array is not counted towards space complexity since it is provided as input.

### Conclusion
The `videoStitching` function provides an efficient solution to the problem of determining the minimum number of video clips needed to cover a specific duration of time. By sorting the clips and using a systematic approach to find the maximum coverage possible at each step, the algorithm efficiently calculates the required number of clips.

This solution is practical for real-world scenarios where video segments may need to be stitched together, such as in video editing software, streaming services, and content creation applications. The ability to handle dynamic inputs and provide a quick response on the feasibility of covering a duration is crucial in these contexts.

In summary, the function illustrates the effective use of sorting and greedy algorithms in solving problems related to interval coverage. By focusing on maintaining the maximum reach at each step, the solution ensures that the minimum number of clips is used while effectively handling edge cases where coverage may not be possible.

Overall, this implementation serves as a valuable reference for solving similar problems in competitive programming and software development, showcasing the importance of structured approaches in algorithm design.


[`Link to LeetCode Lab`](https://leetcode.com/problems/video-stitching/description/)

---
{{< youtube 4Qho-im90ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
