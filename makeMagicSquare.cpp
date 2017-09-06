#include <iostream>
using namespace std;
int main()
{	
	int dim = 0;
	cout << "Please enter the dimension of the magic square: " << endl;
	cin >> dim;
	
	int **magicSquare = new int *[dim];
    for ( int i = 0; i < dim; ++i ) {
        magicSquare[i] = new int[dim]();
    }

    int num = 1;
    magicSquare[0][dim/2] = num++;

    int row = dim-1, col = dim/2+1;

    for ( int cnt = 1; cnt < dim*dim; ++cnt ) {

    	magicSquare[row][col] = num++;

    	int tempRow = row--, tempCol = col++;

    	if ( row < 0 )
    		row = dim-1;
    	if ( col >= dim )
    		col = 0;

    	if ( magicSquare[row][col] != 0 ) {
    		row = tempRow;
    		col = tempCol;
    		++row;
    	}

    }

    for ( int i = 0; i < dim; ++i ) {
    	for ( int j = 0; j < dim; ++j ) {
    		cout << magicSquare[i][j] << " ";
    	}
    	cout << endl;
    }

    for ( int i = 0; i < dim; ++i )
        delete [] magicSquare[i];
    delete [] magicSquare;
}