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
    //Matrix object called "result" to store the result of the operation.
    Matrix result(N);

    //Iterating through the matrices to store the correct elements in the result matrix.
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.data[i][j] = 0; 
            for (std::size_t k = 0; k < N; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
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
    //Check to see if the index of the row and column are within the matrix.
    if (i >= matrix.size() || j >= matrix.size()) {
        //If they are not, then throw an error displaying "Error: Index not within bounds".
        throw std::out_of_range("Error: Index not within bounds");
    }
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
            std::swap(matrix[i][c1], matrix[i][c2]);
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