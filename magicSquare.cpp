#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    cout << "Please enter the dimension of the magic square: " << endl;
    int dim = 0;
    cin >> dim;

    int **magicSquare = new int *[dim];
    for ( int i = 0; i < dim; ++i ) {
        magicSquare[i] = new int[dim];
    }

    while ( 1 ) {
        cout << "Please enter the data of the square: " << endl;
        for ( int i = 0; i < dim; ++i ) {
            for ( int j = 0; j < dim; ++j ) {
                cin >> magicSquare[i][j];
            }
        }

        int tempSum = 0;
        for ( int i = 0; i < dim; ++i ) {
            tempSum += magicSquare[0][i];
        }

        //row
        bool magic = true;
        for ( int i = 1; i < dim; ++i ) {
            int temp = 0;
            for ( int j = 0; j < dim; ++j ) {
                temp += magicSquare[i][j];
            }

            if ( temp != tempSum )
                magic = false;
        }

        if ( !magic ) {
            cout << "This is not a magic square." << endl;
            break;
        }

        //column
        for ( int i = 0; i < dim; ++i ) {
            int temp = 0;
            for ( int j = 0; j < dim; ++j ) {
                temp += magicSquare[j][i];
            }

            if ( temp != tempSum )
                magic = false;
        }

        if ( !magic ) {
            cout << "This is not a magic square." << endl;
            break;
        }

        //diagonal
        int temp = 0;
        for ( int i = 0, j = 0; i < dim; ++i, ++j ) {
            temp += magicSquare[i][j];
        }

        if ( temp != tempSum )
            magic = false;

        if ( !magic ) {
            cout << "This is not a magic square." << endl;
            break;
        }

        temp = 0;
        for ( int i = 0, j = dim - 1; i < dim; ++i, --j ) {
            temp += magicSquare[i][j];
        }

        if ( temp != tempSum )
            magic = false;

        if ( !magic ) {
            cout << "This is not a magic square." << endl;
            break;
        } else {
            cout << "Yes, this is a magic square." << endl;
            break;
        }
    }

    for ( int i = 0; i < dim; ++i )
        delete [] magicSquare[i];
    delete [] magicSquare;

    return  0;
}