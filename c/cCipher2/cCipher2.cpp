
#include <iostream>
#include <string>

using namespace std;

int main(int arcg, char *argv[]) {

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ";

    cout << "Hello" << endl;

    int n = alphabet.find("Å");

    printf("%i\n", n);

    return 0;
}
