// link https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/
vector<int> Solution::solve(vector<int> &a) {
    int n=a.size();
    int i=0,j=0;
    while(j<n){
        if(a[j]==0 && i==j){
            j++;
            i++;
        }
        else if(a[j]==0 && i!=j){
            swap(a[i],a[j]);
            i++;
            j++;
        }
        else if(a[j]==1){
            j++;
        }
    }
    return a;
}
