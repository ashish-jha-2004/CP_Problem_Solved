#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // cout << "Number of equations you have";
    cin >> n;
    // cout << "Write down the coefficient of every term and the constant";

    // matrix to store coefficient 
    vector<vector<long double>> eq(n, vector<long double>(n+1));
    for (int i{0}; i<n; i++){
        for (int j{0}; j<n+1; j++){
            cin >> eq[i][j];
        }
    }

    // Applying gaussian elimination to the matrix
    for (int i{0}; i<n-1; i++){
        for (int j{i+1}; j<n; j++){
            long double temp = eq[j][i];
            long double temp2 = eq[i][i];
            for (int k{i}; k<n+1; k++){
                eq[j][k] = eq[j][k]/temp - eq[i][k]/temp2;
            }
        }
    }

    // pribnting the row reduced form or echelone form
    for (int i{0}; i<n; i++){
        for (int j{0}; j<n+1; j++){
            cout << eq[i][j] << " ";
        }
        cout << endl;
    }
}