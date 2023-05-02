#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// 1
// apart from the solution, one thing here is to note that a member function of a class can access the non member 
// function of the class.

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void func(stack<int> &st, int ele){
    
    if(st.empty()){
        st.push(ele);
        return;
    }
    
    if(st.top() <= ele){
        st.push(ele);
        return;
    }
    
    int a = st.top();
    st.pop();
    
    func(st, ele);
    st.push(a);
    
}
void SortedStack :: sort()
{
    if(s.empty()) return;
    
    int ele = s.top();
    s.pop();    
    sort();    
    func(s,ele);
}