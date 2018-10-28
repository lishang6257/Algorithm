#include <iostream>
#include <vector>
using namespace std;

void SimpleInsertSort(vector<int>&a)
{
    if(a.size() <= 1) return ;
    for(int i = 1;i < a.size();i ++){
        int m = a[i],j;
        for(j = i - 1;j >= 0 && a[j] > m;j --){
            swap(a[j],a[j+1]);
        }
//        for(auto c : a) cout << c << " ";
//        cout << endl;
        a[j + 1] = m;
    }
}

int main()
{
    vector<int> a = {1,0,8,3,7,5,10,4,100};
    SimpleInsertSort(a);
    for(auto c : a) cout << c << " ";
    return 0;
}
