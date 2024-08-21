/*
Author: Guramrit Singh
Description: GDB Activity, Midsem CS-108, Spring 2023-24
*/

#include <iostream>

using namespace std;

int main() {
    int k, n, m, l;

    // input dimensions
    cin >> m >> n;
    cin >> l >> k;

    int matrix1[m][n];
    int matrix2[l][k];

  	// check if provided dimensions are valid
    if(n != l || m <= 0 || k <= 0 || n <= 0) {
        cout << "Invalid dimensions" << endl;
    }
  
    else {
      // input matrix1
    for(unsigned int i = 0; i < m; i++) {
        for(unsigned int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
  
   


    // input matrix2
    for(unsigned int i = 0; i < l; i++) {
        for(unsigned int j = 0; j < k; j++) {
            cin >> matrix2[i][j];
        }
    }

    int product[m][k];   
    // Calculate product using the formula: 
    // product[i][j] = sum(matrix1[i][k] * matrix2[k][j]) for k = 0 to c-1 where c is the number of columns in matrix1
    for(unsigned int i = 0; i < m; i++) {
        for(unsigned int j = 0; j < k; j++) {
            product[i][j] = 0;
            for(unsigned int s = 0; s < n; s++) {
                
                    product[i][j] += matrix1[i][s] * matrix2[s][j];
            }
        }
    }

    // print product
    for(unsigned int i = 0; i < m; i++) {
        for(unsigned int j = 0; j < k; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    }

}
 
