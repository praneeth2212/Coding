// link https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& a){
        int n=a.size();
        int i=0,j=1;
        while(j<n){
            if(a[i]==a[j]){
                j++;
            }
            else{
                swap(a[i+1],a[j]);
                i++;
                j++;
            }
        }
        return (i+1);
    }
};