#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
template<class ForwardIterator>
void disp(ForwardIterator start, ForwardIterator last)
{
    while(start!=last)
       {
           cout<<*(start++)<<" ";
            start++;
       }
}
int main()
{
    vector<int> x;
    for(int i=1;i<=10;i++)
       {
        x.push_back(i);
       }
    disp(x.begin(),x.end());
    return 0;
}