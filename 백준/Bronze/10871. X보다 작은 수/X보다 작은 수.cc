#include <iostream>

using namespace std;

int main(){
    int N, X;

    cin >> N >> X;

    int space[N];
    for(int i = 0; i < N; i++){    
        cin >> space[i];
    }

    for(int i = 0; i < N; i++){
        if(space[i] < X){
            cout << space[i] << ' ';
        }
    }
}