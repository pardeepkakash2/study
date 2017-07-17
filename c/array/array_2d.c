// dynamically allocating memory for matrix (2D array)
int **matrix;
int i, j;
int size = 5; // let's assume matrix is square (size x size)
matrix = (int **)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++)
        matrix[i] = (int *)malloc(size * sizeof(int));
 
matrix[3][1] = 16;
