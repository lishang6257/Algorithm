#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a,int &b){int c = a;a = b;b = c;}

int partition(vector<int> &a,int low,int high)
{
    //C. A. R. Hoare
    srand(unsigned(time(NULL)));
    int j = low + rand()%(high - low + 1);
    swap(a[high],a[j]);
    j = low;
    for(int i = low;i < high;i ++){
        if(a[i] <= a[high])swap(a[i],a[j++]);
    }
    swap(a[j ],a[high]);
    return j ;
}

int partition2(vector<int>&a,int low,int high)
{
    srand(unsigned(time(NULL)));
    int j = low + rand()%(high - low + 1);
    swap(a[high],a[j]);
    int pivot = a[high];
    while(low < high){
        while(low < high && a[low] <= pivot){low ++;}
        a[high] = a[low];
        while(low < high && a[high] > pivot){high --;}
        a[low] = a[high];
    }
    cout << low << " " << high << ";\n";
    a[low] = pivot;
    return low;
}

void quickSort(vector<int> &a,int low,int high)
{
    if(low >= high) return ;
    int pivot = partition(a,low,high);
    quickSort(a,low,pivot-1);
    quickSort(a,pivot+1,high);
}

int main()
{
    vector<int> a = {1,40,10,4,5,8,9,1};
//    cout << partition2(a,0,a.size()-1) << "|";
    quickSort(a,0,a.size()-1);
    for(auto c : a) cout << c << " ";
    return 0;
}
