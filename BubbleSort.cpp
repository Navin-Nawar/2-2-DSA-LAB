#include<iostream>
using namespace std;
int main(){
    int n;
     cout<<"number of elements in an array: ";
     cin>> n;

     int arr[100];
     for(int i=0; i<n; i++) cin >> arr[i];
     cout<<"before sorting : " ;
     for(int i=0; i<n; i++) cout<<arr[i] <<" " ;
     cout<<endl;
     for(int i=0; i<n-1; i++){
        bool swaped = false;
        for(int j=0; j<n-i-1; j++ ){
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swaped = true;
            }

        }
       
        cout<<"pass " <<i+1 <<":";
        for(int i=0; i<n; i++) cout<<arr[i] <<" ";
        cout<<endl;
         if(!swaped) break;

     }

     cout<<"sorted array :";
      for(int i=0; i<n; i++) cout<<arr[i] <<" ";
}