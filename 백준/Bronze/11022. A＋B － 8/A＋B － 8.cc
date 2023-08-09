#include <iostream>

using namespace std;

int main(){
    int T; //number of test cases
    cin >> T;

    int holder[T][2];

    for(int i = 0; i < T; i++){
        cin >> holder[i][0] >> holder[i][1];
    }

    for(int i=0; i < T; i++){
        cout << "Case #"<< i+1 <<": " << holder[i][0] << " + " << holder[i][1] << " = " << holder[i][0] + holder[i][1];
        if(i<T-1)
            cout << endl;
    }
}