#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{1,2,3,4,5,6};
    std::cout << vec.capacity() << std::endl;
    const int f = vec.front();
    std::cout << f << std::endl;
    vec.push_back(f);
    std::cout << f << std::endl;
    std::cout << vec.capacity() << std::endl;
    if(sizeof(std::vector<int>) == 3*sizeof(void*))
        std::cout << "yes" << std::endl;
    for (auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << f << std::endl;
    vec[0]=7;
    for (auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;


}
