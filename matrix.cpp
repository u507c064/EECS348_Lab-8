#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    matrix = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
}

//Constructor that initilizes the matrix with the values passed in from the parameter.
//The parameter is the vector of integers called "nums".
Matrix::Matrix(std::vector<std::vector<int>> nums) : matrix(std::move(nums)) {}

// e.g. for a member function:

//The addition operator called "operator+" that takes in a Matrix object called "rhs".
Matrix Matrix::operator+(const Matrix &rhs) const {
    //Variable called "N" and is set to the matrix's size.
    std::size_t N = matrix.size();
    //Matrix object "result" with size N to store the result of the operation.
    Matrix result(N);

    //Iterate through the matrix to enable the addition of all elements.
    //First go through the rows.
    for (std::size_t i = 0; i < N; i++)
    {
        //Then iterate through the columns.
        for (std::size_t j = 0; j < N; j++)
        {
            //Access the matrix of result and set it to the addition of the matrix and the matrix passed in.
            //This is done by first accessing the individual rows and columns ([i][j]).
            //Then storing the elements with the operator (=).
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }

    //Return the result Matrix object.
    return result;
}

//The multiplication operator called "operator*" that takes in a Matrix object called "rhs".
Matrix Matrix::operator*(const Matrix &rhs) const {
    //Variable called "N" and is set to the matrix's size.
    std::size_t N = matrix.size();
    //Matrix object "result" with size N to store the result of the operation.
    Matrix result(N);

    //Iterate through the matrix to enable the multiplication of all elements.
    //First go through the rows.
    for (std::size_t i = 0; i < N; i++)
    {
        //Then iterate through the columns.
        for (std::size_t j = 0; j < N; j++)
        {
            //Then iterate through the row of the first matrix and the column of the matrix passed in.
            //This is to perform the dot operation between the elements.
            for(std::size_t k = 0; k < N; k++)
            {
                //Access the matrix of result and set it to the multiplication of the matrix and the matrix passed in.
                //This is done by first accessing the individual rows and columns ([i][j]).
                //Then storing the elements with the operator (=).
                result.matrix[i][j] = matrix[i][j] * rhs.matrix[i][j];
            }
        }
    }

    //Return the result Matrix object.
    return result;
}

//Function called "set_value" which takes in the parameters "i", "j", and an integer variable called "n".
//Sets the value of an individual element in the matrix to the value n.
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    //Access an individual matrix element with [i][j] and set it to n.
    matrix[i][j] = n;
}

//Function called "get_value" which returns the value at given element in the matrix.
int Matrix::get_value(std::size_t i, std::size_t j) const {
    //Access the individual matrix element and return it.
    return matrix[i][j];
}

//Function called "get_size" which returns the size of the matrix.
int Matrix::get_size() const {
    //Return the size of the matrix using size function (size function given from vector properties).
    return matrix.size();
}

//Function called "sum_diagonal_major" which sums up the diagonal elements in the matrix.
int Matrix::sum_diagonal_major() const {
    //Integer variable called "sum" and set to 0.
    int sum = 0;

    //Iterate through the matrix.
    for(std::size_t i = 0; i < matrix.size(); i++) {
        //sum is adding all the elements of the diagonal.
        //To access the diagonal, the sum is set to the addition of the matrix element [i][i].
        //The row index is set to the column index, which accesses the diagonal elements.
        sum += matrix[i][i];
    }

    //Return sum.
    return sum;
}

//Function called "sum_diagonal_minor" which sums up the second diagonal of the matrix.
int Matrix::sum_diagonal_minor() const {
    //Integer variable called "sum" and set to 0.
    int sum = 0;
    //Variable called "N" and set to the matrix's size.
    std::size_t N = matrix.size();

    //Iterate through the matrix.
    for(std::size_t i = 0; i < matrix.size(); i++) {
        //sum is adding all the elements of the second diagonal.
        //To access the second diagonal, the element for the column would be the size - 1 and - the row index.
        sum += matrix[i][N - 1 - i];
    }

    //Return the sum.
    return sum;
}

//Function called "swap_rows" which swaps to rows in the matrix.
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    //First check if r1 and r2 are less than the matrix's size.
    //This is to enable the swap to happen (If they do no pass the check, then the rows are out of bound).
    if (r1 < matrix.size() && r2 < matrix.size()) {
        //Use the swap function to swap the to rows.
        //Arguments are matrix[r1] and matrix[r2].
        //Matrix[r1] and Matrix[r2] accesses all the row elements.
        std::swap(matrix[r1], matrix[r2]);
    }
}

//Function called "swap_cols" which swaps to columns in the matrix.
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    //First check if c1 and c2 are less than the matrix's size.
    //This is to enable the swap to happen (If they do no pass the check, then the rows are out of bound).
    if (c1 < matrix.size() && c2 < matrix.size()) {
        for (std::size_t i = 0; i < matrix.size(); i++) {
            //Use the swap function to swap the columns.
            //To access the columns, the row must be identified for each column.
            //This is represented in the arguments of the swap function (matrix[i][c1]).
            //After the row has been identified, then the swap can occur.
            std::swap(matrixp[i][c1], matrix[i][c2]);
        }
    }
}

void Matrix::print_matrix() const {
    // print out the matrix

    for (const auto &row : matrix) {
        for (int val : row) {
            std::cout << std::setw(4) << val << " ";
        }
        std::cout << std::endl;
    }
}

//Function called "read_matrices" that reads in matrices from a file.
//Parameters: String variable called "filename" and two Matrix objects called "mat1" and "mat2".
void Matrix::read_matrices(const std::string &filename, Matrix &mat1, Matrix &mat2) {
    //First open the file with ifstream function with the filename passed in.
    std::ifstream file(filename);
    //If there is an error with opening the file, then throw an error.
    if (!file) {
        //Display "Error opening file: " with the filename.
        std::cerr << "Error opening file: " << filename << std::endl;
        //Exits the program. 
        return;
    }
    
    //Variable called "N" to read in the first value from the file.
    std::size_t N;
    //Reads the first value.
    file >> N;
    //Initialize the first two matrices with NxN matrices filled with zeros.
    std::vector<std::vector<int>> data1(N, std::vector<int>(N));
    std::vector<std::vector<int>> data2(N, std::vector<int>(N));
    
    //For loop that passes in the data from the file and stores it in the first matrix (data1).
    for (std::size_t i = 0; i < N; ++i) //Iterate through the rows.
        for (std::size_t j = 0; j < N; ++j) //Iterate through the columns.
            file >> data1[i][j]; //Read in the data from the file and store the data in their respective element.
    
    //For loop that passes in the data from the file and stores it in the second matrix (data2).
    for (std::size_t i = 0; i < N; ++i) //Iterate through the rows.
        for (std::size_t j = 0; j < N; ++j) //Iterate through the columns.
            file >> data2[i][j]; //Read in the data from the file and store the data in their respective element.
    
    //Sets matrix 1 (mat1) to the object Matrix(data1) (Which is the matrix now filled with data). 
    mat1 = Matrix(data1);
    //Sets matrix 2 (mat2) to the object Matrix(data2) (Which is the matrix now filled with data).
    mat2 = Matrix(data2);
}
