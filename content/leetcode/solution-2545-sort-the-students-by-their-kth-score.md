
+++
authors = ["grid47"]
title = "Leetcode 2545: Sort the Students by Their Kth Score"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2545: Sort the Students by Their Kth Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YwAAwSzIavU"
youtube_upload_date="2023-01-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YwAAwSzIavU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int k;
    int partition(vector<vector<int>>& score, int low, int high) {

      // select the rightmost element as pivot
      vector<int> pivot = score[high];

      // pointer for greater element
      int i = (low - 1);

      // traverse each element of the array
      // compare them with the pivot
      for (int j = low; j < high; j++) {
        if (score[j][k] > pivot[k]) {

          // if element smaller than pivot is found
          // swap it with the greater element pointed by i
          i++;

          // swap element at i with element at j
          swap(score[i], score[j]);
        }
      }

      // swap pivot with the greater element at i
      swap(score[i + 1], score[high]);

      // return the partition point
      return (i + 1);
    }
    void quickSort(vector<vector<int>>& score, int low, int high) {
        if (low < high) {
            int pi = partition(score, low, high);
            quickSort(score, low, pi - 1);
            quickSort(score, pi + 1, high);
        }
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        this->k = k;
        quickSort(score, 0, score.size() - 1);
        return score;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2545.md" >}}
---
{{< youtube YwAAwSzIavU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2546: Apply Bitwise Operations to Make Strings Equal](https://grid47.xyz/leetcode/solution-2546-apply-bitwise-operations-to-make-strings-equal/) |
| --- |
