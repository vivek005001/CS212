#include <iostream>
using namespace std;

int main(){

    const int rows = 15;
    const int cols = 20;

    int arr[rows][cols];

    int value = 1;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            arr[row][col] = value++;
        }
    }
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            cout << arr[row][col] << "\t";
        }
        cout << endl;
    }
    // int arr[15][20];
    int x;
    cin>>x;

    int row=0;
    int col=19;
    while(row <15 && col>=0){
        if(x==arr[row][col]){
            cout<<row<<col;
            return 0;
        }
        else if(arr[row][col]>x){
            col--;
        }
        else{
            row++;
        }
    }
    cout<<"nil"<<endl;
    return 0;
}