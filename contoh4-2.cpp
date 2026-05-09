#include <iostream>
using namespace std;

int myStack[5];  // array untuk stack
int top = -1;    // posisi atas stack

int main(){

    // PUSH
    top++;
    myStack[top] = 5;
    
    top++;
    myStack[top] = 10;
    
    cout << "Isi stack setelah push:" << endl;
    for(int i = top; i >= 0; i--){
        cout << myStack[i] << endl;
    }
    
    // POP
    cout << "\nData yang keluar: " << myStack[top] << endl;
    top--;
    
    cout << "\nIsi stack setelah pop:" << endl;
    for(int i = top; i >= 0; i--){
        cout << myStack[i] << endl;
    }
    
    return 0;
}