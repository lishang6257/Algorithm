#include <iostream>

using namespace std;

template<typename T>
struct Node{
    Node(){
        pre = next = NULL;
    }
    T info;
    Node<T>* pre,* next;
};

template<typename T>
class DList{
public:
    DList();
    DList(const T* a,int n);

    int DLsize();
    T DLinsert(T info,int pos);
    T DLdelete(int pos);
    T DLreverse();
    /*------------for test---------*/
    void DLprint();
private:
    Node<T>* sentinel;
    int dlsize;
};

template<typename T>
DList<T>::DList()
{
    sentinel = new Node<T>;
    sentinel.pre = sentinel;
    sentinel.next = sen
    dlsize = 0;
}
template<typename T>
DList<T>::DList(const T * a,int n)
{
    sentinel = new Node<T>;
    Node<T>*tmp = sentinel;
    for(int i = 0;i < n;i ++){
        tmp->next = new Node<T>;
        tmp->next->info = a[i];
        tmp->next->pre = tmp;
        tmp = tmp->next;
    }
    dlsize = n;
}
template<typename T>
T DList<T>::DLinsert(T info,int pos)
{

}


template<typename T>
void DList<T>::DLprint()
{
    Node<T>* tmp = sentinel;
    while(tmp->next){
        cout << tmp->next->info << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    int a[5] = {1,2,4,5,3};
    DList<int> dl(a,5);
    dl.DLprint();
    return 0;
}
