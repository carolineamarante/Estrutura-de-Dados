#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputValue[10]; 
    int i;

    cout << "Insira 10 elementos do tipo texto" << endl;
    
    for( i = 0; i < 10; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        getline(cin, inputValue[i]);
    }

    cout << "Elementos digitados sao: " << endl;
    for(i = 0; i < 10; ++i) {
        cout << inputValue[i] << endl;
    }
}

