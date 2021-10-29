#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vector;
    int user_input;
    while(true){
        cout<<"Enter the your number: ";
        cin>>user_input;
        if(user_input>=0){
            break;
        }
        vector.push_back(user_input);
    }
    if(vector.empty()) {
        cout << "Vector is empty, abort!";
        return 0;
    }
    float sum = 0;
    for (int i: vector) {
        sum += float(i);
    }
    cout << "\nThe average of all number you entered in the vector is " << sum / float(vector.size());
    return 0;
};
