// TODO 2D ARRAY 

// 2D Array Representation
// int arr[]=
// {
//     {00,01,02},
//     {10,11,12},
//     {20,21,22},
//     {30,31,32}
// };
// here, row = 4,col = 3;

// 2D array representation as 1D array 
// int arr[]={00,01,02,10,11,12,20,21,22,30,31,32};

// if we have to find the index of a particular element
// then we should have the elment's 
// row_index and col_index, ex;
// find element 12;
// so, row_index = 1, col_index = 2;

// => formula of finding the index of element is 
// index = (row_index * col) + col_index;
//       = (1*3)+2; = 5;
    
// => forumula of finding the row_index if index is given 
// row_index = index/col;
//           = 5/3; = 1;

// => formula of finding the col_index if index is given 
// col_index = index % col;
//           = 5 % 3; = 2;

// => formula of finding the memory address of an element
// lets, take example
// address_of_array = 500;
// size_of_element = size_of_datatype, means size of int:4, char:1,bool:1
// index = (row_index * col) +col_index

// arr[i][j] = address_of_array + (index * size_of_element)
// arr[2][1] = 500 + ((2*3)+1 * 4);
//           = 500 + (7 * 4) = 532;

// => Create an 2D array ;
// arr[2][2]= {00,01,10,11};

// => update an 2D array;
// arr[2][1] = 45;

// => print an 2D array;
// for (int i=0;i<row;i++){
//     for(int j=0;j<col;j++){
//         cout<<arr[i][j]<<endl;
//     }
// }


// TODO 2D VECTOR 

// => Create 2d vector
// vector<vector<int>>matrix;

// => give size to a vector and initialse with default value 
// vector<vector<int>>matrix(row, vector<int>(col,3));

// => find rows and cols of a 2d vector
// int row = matrix.size();
// int col = matrix[0].size();