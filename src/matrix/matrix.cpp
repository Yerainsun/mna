#include "matrix/matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;


void print(int nv, double Yn[MAX_NOS+1][MAX_NOS+2]){
    /* Opcional: Mostra o sistema apos a montagem da estampa */
    for (int k=1; k<=nv; k++) {
        for (int j=1; j<=nv+1; j++)
            if (Yn[k][j]!=0){
                cout << setprecision(1) << fixed << setw(3) << showpos;
                cout << Yn[k][j] << " ";
            }
            else cout << " ... ";
        cout << endl;
    }
    cout << endl;
}


int solve( int nv, double Yn[MAX_NOS+1][MAX_NOS+2] ){
    int i, j, l, a;
    double t, p;

    for( i = 1; i <= nv; i++ ){
        t = 0.0;
        a = i;
        for( l = i; l <= nv; l++ ){
            if( fabs( Yn[l][i] ) > fabs( t ) ){
                a = l;
                t = Yn[l][i];
            }
        }
        if( i != a){
            for( l = 1; l <= nv + 1; l++ ){
                p = Yn[i][l];
                Yn[i][l] = Yn[a][l];
                Yn[a][l] = p;
            }
        }
        if( fabs( t ) < TOLG ){
            printf("Sistema singular\n");
            return 1;
        }
        for( j = nv + 1; j > 0; j-- ){  /* Basta j>i em vez de j>0 */
            Yn[i][j] /= t;
            p = Yn[i][j];
            for( l = 1; l <= nv; l++ ){
                if( l != i )
                    Yn[l][j] -= Yn[l][i] * p;
            }
        }
    }
    return 0;
}
