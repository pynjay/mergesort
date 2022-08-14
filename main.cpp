
#include <iostream>
using namespace std;

void merge3(int *arr, int l, int m1, int m2, int r){
    int i, j, o, k;
    int nl = m1 - l + 1;
    int nr = r - m2;
    int nm = m2 - m1;
    cout << nl << ' ' << nr << ' ' << nm << ' ' << endl;
    int arr1[nl], arr2[nr], arr3[nm];
    for(i = 0; i<nl; i++){
      arr1[i] = arr[l+i];
    }
    for(j = 0; j<nr; j++){
      arr2[j] = arr[m2+1+j];
    }
    for(o = 0; o<nm; o++){
      arr3[o] = arr[m1+1+o];
    }
    i = 0;
    j = 0;
    o = 0;
    k = l;
    while(i < nl && j<nr && o < nm) {
      if(arr1[i] < arr2[j]) {
         if(arr1[i] < arr3[o]){
            arr[k] = arr1[i];
            i++;
         } else {
            arr[k] = arr3[o];
            o++;
         }
      }else{
         if(arr2[j] < arr3[o]){
            arr[k] = arr2[j];
            j++;
         } else {
            arr[k] = arr3[o];
            o++;
         }
      }
      k++;
   }

   while(i < nl && j<nr) {
      if(arr1[i] <= arr2[j]) {
         arr[k] = arr1[i];
         i++;
      }else{
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }

   while(i < nl && o < nm) {
      if(arr1[i] <= arr3[o]) {
         arr[k] = arr1[i];
         i++;
      }else{
         arr[k] = arr3[o];
         o++;
      }
      k++;
   }

   while(o < nm && j<nr) {
      if(arr3[o] <= arr2[j]) {
         arr[k] = arr3[o];
         o++;
      }else{
         arr[k] = arr2[j];
         j++;
      }
      k++;
   }


   while(i<nl) {       
      arr[k] = arr1[i];
      i++; k++;
   }
   while(o<nm) {    
      arr[k] = arr3[o];
      o++; k++;
   }
   while(j<nr) {    
      arr[k] = arr2[j];
      j++; k++;
   }

    cout << endl << arr[k-1] << endl;
}

void mergeSort3(int *arr, int l, int r){
    int m1, m2;
    if((r-l) >= 2) {
        m1 = l+(r-l+1)/3-1;
        m2 = l+2*((r-l+1)/3)-1;
        mergeSort3(arr, l, m1);
        mergeSort3(arr, m1+1, m2);
        mergeSort3(arr, m2+1, r);
        merge3(arr, l, m1, m2, r);
    } else if((r-l) == 1){
      merge3(arr, l, l, l, r);
    }
}


int main(){

   srand( (unsigned)time(NULL));

   const int max = 20;

   int d[max];

   int no1;

   for(int s = 0; s < max; s++){
        no1 = rand() % 100;
        d[s] = no1;
   }


   for(int i = 0; i<max; i++){
      cout << d[i] << " ";
   }
   cout << endl;

   mergeSort3(d, 0, max-1);     //(n-1) for last index

   cout << "Array after Sorting: ";

  for(int i = 0; i<max; i++){
      cout << d[i] << " ";
   }
   cout << endl;
}