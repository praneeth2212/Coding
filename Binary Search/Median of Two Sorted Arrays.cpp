// link https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n2 < n1)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int s = 0, e = n1;
        while (s <= e)
        {
            int cut1 = s + (e - s) / 2;
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;
            int l1, l2, r1, r2;
            if (cut1 == 0)
            {
                l1 = INT_MIN;
            }
            else
            {
                l1 = nums1[cut1 - 1];
            }
            if (cut2 == 0)
            {
                l2 = INT_MIN;
            }
            else
            {
                l2 = nums2[cut2 - 1];
            }
            if (cut1 == n1)
            {
                r1 = INT_MAX;
            }
            else
            {
                r1 = nums1[cut1];
            }
            if (cut2 == n2)
            {
                r2 = INT_MAX;
            }
            else
            {
                r2 = nums2[cut2];
            }
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                e = cut1 - 1;
            }
            else
            {
                s = cut1 + 1;
            }
        }
        return 0.0;
    }
};