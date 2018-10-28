#include <iostream>
#include <vector>
/*
�ǽ�������
ʱ�临�Ӷ�:o(nlgn)
�ռ临�Ӷ�:o(nlgn)
����:o(n)
ά����:o(lgn)
���ȶ�
*/
using namespace std;

void swap(int &a,int &b){int c = a;a = b;b = c;}

int Max(const vector<int> &a,int n,int i){
    if(2*i + 2 > n) return i;//�ýڵ����Ӳ�����
    if(2*i + 3 > n) {
        //�ýڵ��Һ��Ӳ�����
        if(a[i] >= a[2*i + 1]) return i;
        else return 2*i + 1;
    }
    if(a[i] >= a[2*i + 1] && a[i] >= a[2*i + 2]) return i;
    if(a[2*i + 1] >= a[i] && a[2*i + 1] >= a[2*i + 2]) return 2*i + 1;
    return 2*i + 2;
}

void heapify(vector<int>&a,int n,int i)//lgn,���Ѹ߶�
{
    //����
    //n Ϊ�Ѵ�С
    //i ��ָ�±�
    int cur = i;
    while(true){
        int tmp = Max(a,n,cur);
        if(tmp == cur) break;
        swap(a[cur],a[tmp]);
        cur = tmp;
    }
}

//���ѹ���
void buildHeap(vector<int> &a) //n
{
    for(int i = a.size()/2 - 1;i >= 0;i --){
        heapify(a,a.size(),i);
    }
}

//���������
void heapSort(vector<int> &a)
{
    buildHeap(a);
    for(auto c : a) cout << c << " ";
    cout << endl;
    for(int i = a.size() - 1;i > 0;i --){
        swap(a[i],a[0]);
        heapify(a,i,0);
        for(auto c : a) cout << c << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> a = {4,1,3,2,16,9,10,14,8,7};
    heapSort(a);
    for(auto c : a) cout << c << " ";
    return 0;
}