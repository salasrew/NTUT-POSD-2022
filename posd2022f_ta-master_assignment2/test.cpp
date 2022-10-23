#include <iostream>
#include <list>

using namespace std;


int main()
{
//    std::list<int> list1 = {5,2,4,6,2};
//    std::list<int> list2 = {7,6,1,9};

    
// 	for(auto& elmL: list1)
//         std::cout << elmL << " ";
//     std::cout << std::endl;
//     for(auto& elm: list2)
//         std::cout << elm << " ";
//     std::cout << std::endl ;

//     // system("pause");
//      return 0;
    
    list<int> list1 = {5,2,4,6,2};
    list<int> list2 = {7,6,1,9};

    // sort 
    list1.sort();
    list2.sort();

    // merge
    // list1.merge(list2);

    // unique 去重複
    list1.unique();

    // splice 拼接在後面
    // list1.splice(list1.begin(),list2);

	for(auto& elmL: list1)
        cout << elmL << " ";
    cout << endl;
    // for(auto& elm: list2)
    //     cout << elm << " ";
    // cout << endl ;

    // system("pause");
    return 0;
}
