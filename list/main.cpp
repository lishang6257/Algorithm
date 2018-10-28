#include <iostream>
using namespace std;

template <typename T>
struct Node{
    Node(){
        next = NULL;
    }
    T info;
    Node<T>* next;
};

template <typename T>
class List{
public:
    List();
    List(const T *a,int n);
    ~List();
    int Lsize(){return lsize;}
    void Lreverse();
    T Linsert(T info,int pos);
    T Ldelete(int pos);
    /* -----------for test---------- */
    void Lprint();
private:
    Node<T>* sentinel;
    int lsize;
};

template <typename T>
List<T>::~List()
{
    Node<T>* tmp = sentinel;
    while(tmp->next){
        Node<T>* dNode = tmp;
        tmp = tmp->next;
        delete dNode;
    }
}

template <typename T>
List<T>::List()
{
    sentinel = new Node<T>;
    lsize = 0;
}

template <typename T>
List<T>::List(const T *a,int n)
{
    sentinel = new Node<T>;
    Node<T>* t = sentinel;
    for(int i = 0;i < n;i ++){
        t->next = new Node<T>;
        t->next->info = a[i];
        t = t->next;
    }
    lsize = n;
}

template <typename T>
void List<T>::Lprint()
{
    Node<T>* tmp = sentinel;
    while(tmp->next){
        tmp = tmp->next;
        cout << tmp->info << " ";
    }
    cout << endl;
}

template <typename T>
T List<T>::Linsert(T info,int pos)
{
    if(pos > lsize || pos < 0) return NULL;
    Node<T>* tmp = sentinel;int cur = 0;
    while(tmp->next){
        if(cur == pos){
            Node<T>* iNode = new Node<T>;
            iNode->info = info;
            iNode->next = tmp->next;
            tmp->next = iNode;
            lsize ++;
            return info;
        }
        tmp = tmp->next;
        cur ++;
        if(cur == lsize){
            Node<T>* iNode = new Node<T>;
            iNode->info = info;
            tmp->next = iNode;
            lsize ++;
            return info;
        }
    }
}

template <typename T>
T List<T>::Ldelete(int pos)
{
    if(pos >= lsize || pos < 0) return NULL;
    Node<T>* tmp = sentinel;int cur = 0;
    while(tmp->next){
        if(cur == pos){
            Node<T>* dNode = tmp->next;
            tmp->next = tmp->next->next;
            T dinfo = dNode->info;
            delete dNode;
            lsize --;
            return dinfo;
        }
        tmp = tmp->next;
        cur ++;
    }
}

template <typename T>
void List<T>::Lreverse()
{
    if(lsize < 2) return;
    Node<T>* tmp = sentinel->next;
    while(tmp->next){
        Node<T>* mNode = tmp->next;
        //remove current node from the list
        tmp->next = mNode->next;
        //add the removed node behind the sentinel node
        mNode->next = sentinel->next;
        sentinel->next = mNode;
        //roll up
//        tmp = tmp->next;
    }
}

int main()
{
    List<int>l;
    int a[5] = {1,3,2,4,5};
    l.Lprint();
    List<int>l2(a,5);
    l2.Lprint();
    l2.Ldelete(4);
    l2.Linsert(6,4);
    l2.Lreverse();
    l2.Lprint();
    l2.Lsize();
    return 0;
}
