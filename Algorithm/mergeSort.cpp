#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec,int start,int middle, int end){
  vector<int> tmp;
  int ptr1 = start;
  int ptr2 = middle+1;

  while (ptr1 <= middle || ptr2 <= end){
    if(ptr2 > end){
      while(ptr1 <= middle)
        tmp.push_back(vec[ptr1++]);
    }

    else if(ptr1 > middle){
      while(ptr2 <= end)
        tmp.push_back(vec[ptr2++]);
    }

    else if(vec[ptr1]<vec[ptr2]){
      tmp.push_back(vec[ptr1]);
      ptr1++;
    }

    else{
      tmp.push_back(vec[ptr2]);
      ptr2++;
    }
  }
  
  for(int i=start,j=0;i<=end;i++,j++)
    vec[i] = tmp[j];
}

void mergeSort(vector<int> &vec,int start,int end){
  if(start == end)
    return;

  int middle = (start+end)/2;
  mergeSort(vec,start,middle);
  mergeSort(vec,middle+1,end);

  merge(vec,start,middle,end);
}

int main(){
  vector<int> vec = {9,2,10,0,100,5,3,90,85};
  mergeSort(vec,0,vec.size()-1);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
}