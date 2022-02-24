#include <vector>
#include <algorithm>
#include <iostream>
typedef std::vector<int>::iterator iter;
inline std::ostream& operator << (std::ostream& psort, const std::vector<int> &arr) {
    for(auto i : arr){
        psort << i << ' ';
    }
    return psort << std::endl;
}

void Merge(std::vector<int> &arr, std::vector<int> &tmparr, iter left, iter mid, iter right) {
    int num_elements = right - left;
    iter left_pos = left;
    iter right_pos = mid;
    int tmp_pos = 0;
    while(left_pos!=mid && right_pos!=right) {
        if(*left_pos <= *right_pos){
            tmparr[tmp_pos] = *left_pos++;
        }else{
            tmparr[tmp_pos] = *right_pos++;
        }
        tmp_pos++;
    }
    while(left_pos != mid) {
        tmparr[tmp_pos++] = *left_pos++;
    }

    while(right_pos != right) {
        tmparr[tmp_pos++] = *right_pos++;
    }
    
    for(int i=0; i<num_elements; ++i) {
        *left++ = tmparr[i];
    }
    
    //use <algorithm> copy
    //std::copy(tmparr.begin(), tmparr.begin()+num_elements, left);
    return;
}

void MergeSort(std::vector<int> &arr, std::vector<int> &tmparr, iter left, iter right){
    if(right-left==1)
        return;
    iter mid = left + ((right - left) >> 1);
    MergeSort(arr, tmparr, left, mid);
    MergeSort(arr, tmparr, mid, right);
    //use <algorithm> merge
    /*
    iter tmpleft = tmparr.begin() + (left - arr.begin());
    iter tmpright = tmpleft + (right - left);
    std::merge(left, mid, mid, right, tmpleft);
    std::copy(tmpleft, tmpright, left);
    */

    //use Merge
    Merge(arr, tmparr, left, mid, right);
}


int main(){
    std::vector<int> arr{4,6,5,9,1,2,7,3,0,8};
    std::cout << arr; 
    std::vector<int> tmparr(arr.size(),0);
    MergeSort(arr, tmparr, arr.begin(), arr.end());
    std::cout << arr;
}
