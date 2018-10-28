#include <iostream>
#include <vector>
//算法导论 page 588
//kmp 匹配
using namespace std;

int simpleMatcher(const string &s1,const string &s2)//s1主串，s2模式串
{
    //时间复杂度：o(n*m)
//    for(int i = 0;i < s1.size();i ++){
//        for(int j = 0;j < s2.size();j ++){
//            if(s1[i+j] != s2[j]) break;
//            if(j == s2.size() - 1) return i;
//        }
//    }
    int i = 0,matchedNum = 0;
    while(i < s1.size()){
        if(s1[i] == s2[matchedNum]){
            i ++;matchedNum ++;
            if(matchedNum == s2.size()) return i - s2.size();
        }else{
            i -= matchedNum;
            matchedNum = 0;
            i ++;
        }
    }
    return -1;
}

vector<int> KMPPrefix(const string &s)
{
    vector<int> pai;
    int matchedNum = 0,i = 1;
    pai.push_back(0);
    if(s.size() < 2) return pai;
    while(i < s.size()){
        if(s[i] == s[matchedNum]){
            pai.push_back(++matchedNum);
            i ++;
        }else{
            if(matchedNum == 0){
                pai.push_back(0);i++;
            }
            else{
                matchedNum = pai[matchedNum - 1];
            }
        }
    }
    return pai;
}

int KMPMatcher(const string &s1,const string &s2)
{
    //时间复杂度：o(m) + o(n)
    vector<int> v = KMPPrefix(s2);

    int matchedNum = 0,i = 0;
    while(i < s1.size()){
        if(s1[i] == s2[matchedNum]){
            matchedNum ++;
            i ++;
            if(matchedNum == s2.size()) return i - s2.size();
        }else{
            if(matchedNum == 0){
                i++;
            }
            else{
                matchedNum = v[matchedNum - 1];
            }
        }
    }
    return -1;
}

int main()
{
    string s1 = "ababababca23",s2 = "ababca";
//    string s1 ="1 2 1 2 3 1 2 3 1 3 2 1 2",s2="ababaca";
    cout << simpleMatcher(s1,s2);
//    vector<int> a = KMPPrefix(s2);
//    cout << KMPMatcher(s1,s2);
//    for(auto c : a) cout << c << " ";
//    cout << "Hello world!" << endl;
    return 0;
}
