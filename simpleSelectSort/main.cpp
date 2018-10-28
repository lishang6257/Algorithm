#include <iostream>
#include <vector>
//����������
/*
ʱ�临�Ӷ� : o(n^2)
�ռ临�Ӷ� : o(1)
���ȶ� ʾ����1 1^ 8 -> 8 1^ 1
*/
using namespace std;

void swap(int &a,int &b){int c = a;a = b;b = c;}

void simpleSelectSort(vector<int> &a)
{
    for(int i = 0;i < a.size();i ++){
        int m = i;
        for(int j = i;j < a.size();j ++){
            if(a[j] > a[m]) m = j;
        }
        if(m != i) swap(a[m],a[i]);
    }
}

int main()
{
    vector<int> a = {1,3,-1,-4,6,7};
    simpleSelectSort(a);
    for(auto c : a) cout << c << " ";
    return 0;
}
