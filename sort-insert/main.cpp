#include <iostream>
#include <vector>

using namespace std;

//典型的分治策略,拆分，解决,合并
void Merge(vector<int> &a,int low,int high){
    vector<int> p1,p2;
    int mid = (low + high)/2;
    for(int i = low;i <= mid;i ++) p1.push_back(a[i]);
    for(int i = mid + 1;i <= high;i ++) p2.push_back(a[i]);
    vector<int>::size_type i = 0,j = 0,cur = low;
    while(cur <= high){
        if(i >= p1.size()) a[cur ++] = p2[j ++];
        else if(j >= p2.size()) a[cur ++] = p1[i ++];
        else if(p1[i] <= p2[j]) a[cur ++] = p1[i ++];
        else a[cur ++] = p2[j ++];
    }
}
void merge_sort(vector<int> &a,int low,int high){
    if(high == low) return;
    //high < low 异常不做处理
    int mid = (low + high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid + 1,high);
    Merge(a,low,high);
    return;
}

int main()
{
    vector<int> a{2,3,4,5,1,9};
    merge_sort(a,0,a.size() - 1);
    for(auto c : a) cout << c << " ";
    cout << endl;
    return 0;
}
