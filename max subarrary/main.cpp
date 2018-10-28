//最大连续子序列问题

#include <iostream>
#include <vector>

using namespace std;

class result{
public:
    result(){
        low = high = sum = 0;
    }
    result(int a,int b,int c):low(a),high(b),sum(c){};
    bool operator>=(const result &b){
        if(sum >= b.sum) return true;
        return false;
    }
    int low,high,sum;
};

template<typename T>
T Max(T a,T b,T c){
    if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    return c;
}

result find_cross_max(vector<int>&a,int low,int high){
    int mid = (high + low)/2;
    int sumR = -1000,sumL = -1000;//-INF,这里假设是1000
    int R = 0,L = 0;
    int sum = 0;
    for(int i = mid;i >= low;i --){
        sum += a[i];
        if(sum > sumL){
            sumL = sum;L = i;
        }
    }
    sum = 0;
    for(int i = mid + 1;i <= high;i ++){
        sum += a[i];
        if(sum > sumR){
            sumR = sum;R = i;
        }
    }
    return result(L,R,sumR+sumL);
}

result resolve1(vector<int>&a ,int low,int high)
{
    if(low == high) return result(low,high,a[low]);
    //分治
    int mid = (high + low)/2;
    result r1 = resolve1(a,low,mid);
    result r2 = resolve1(a,mid+1,high);
    //跨越两者的数据
    result M = find_cross_max(a,low,high);
    return Max(r1,r2,M);
}

result resolve2(vector<int>&a ,int low,int high)
{
    int maxS = - 10000;
    result res = result();
    for(int i = 0;i < a.size();i ++){
        int sum = a[i],j,max2 = - 10000;
        result res2 = result();//**这里要注意
        for(j = i + 1;j < a.size();j ++){
            //if(sum > sum + a[j]) break;
            sum += a[j];
            if(sum > max2){
                max2 = sum;
                res2 = result(i,j,sum);
            }
        }
        if(max2 >= maxS) {
            res = res2;maxS = max2;
        }
    }
    return res;
}

result resolve3(vector<int>&a,int low,int high)
{
    int sum = 0,l = 0,h = 0,maxS = - 10000;
    for(int i = 0;i < a.size();i ++){
        sum += a[i];
        if(sum < 0){
            l = i + 1;sum = 0;
        }
        if(sum > maxS){
            maxS = sum;
            h = i;
        }
    }
    return result(l,h,maxS);
}

int main()
{
    vector<int> a{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    result r  = resolve1(a,0,a.size() - 1);
//    r = resolve3(a,0,a.size() - 1);
    cout << r.low << " " << r.high << " " << r.sum << endl;
    return 0;
}
