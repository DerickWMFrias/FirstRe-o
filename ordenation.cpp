#include<iostream>
#include<array>
using namespace std;

template<typename genericArg>
void merge(int a, int b, int c, genericArg arr[]);

template<typename genericArg>
void mergesort(int a, int b, genericArg arr[]);

template<typename genericArg>
void teste(genericArg arr[]);

template<typename genericArg>
void teste(genericArg arr[]){
    arr[0] = 999;
}

template<typename genericArg>
void mergesort(int a, int b, genericArg arr[]){
    if(a < b){
        int c = (a+b)/2;
        mergesort <genericArg> (a,c, arr);
        mergesort <genericArg> (c+1, b, arr);
        merge <genericArg> (a, b, c, arr);
    }
}
template<typename genericArg>
void merge(int a, int b, int c, genericArg arr[]){
    int n1 = a;
    int n2 = c+1;
    int at = 0;
    genericArg* auxarray;

    auxarray = new genericArg[b-a];

    while(n1 <= c && n2 <= b){
        if(arr[n1] >= arr[n2]){
            auxarray[at] = arr[n1];
            n1++;
            at++;
        }
        else{
            auxarray[at] = arr[n2];
            n2++;
            at++;
        }

        if(n1 > c){
            while(n2<=b){
                auxarray[at] = arr[n2];
                n2++;
                at++;
            }
        }
        else if(n2 > b){
            while(n1<=c){
                auxarray[at] = arr[n1];
                n1++;
                at++;
            }
        }
    }

    for(int i = a; i <=b; i++) arr[i] = auxarray[i-a];
    delete auxarray;
}



int main(){
    int v[10] = {40, 70, 10, 20, 50, 90, 30, 60, 80, 100};

    for(int i = 0; i < 10; i++) cout << v[i] << " ";
    cout << endl;

    mergesort <int> (0, 10-1, v);

    for(int i = 0; i < 10; i++) cout << v[i] << " ";
    cout << endl;

    teste <int> (v);

    for(int i = 0; i < 10; i++) cout << v[i] << " ";
    cout << endl;
    
    return 0;
}