#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a)
{
    if(a.size() <= 1) return ;
    for(int i = 0;i < a.size() - 1;i ++){
        for(int j = 0;j < a.size() - i;j ++){
            if(a[j] > a[j + 1]) swap(a[j],a[j+1]);
        }
    }
}

int main()
{
    vector<int> a = {2,4,1,9,4,5,0};
    bubbleSort(a);
    for(auto c : a) cout << c << " ";
    return 0;
}
