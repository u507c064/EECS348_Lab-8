#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <vector>

//Function called "read_matrices" that reads in matrices from a file.
//Parameters: String variable called "filename" and two Matrix objects called "mat1" and "mat2".
void read_matrices(const std::string &filename, Matrix &mat1, Matrix &mat2) {
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

int main(int argc, char *argv[]) {
    //String variable called "filename".
    std::string filename;
    //Displays "Enter the file name: ".
    std::cout << "Enter the filename: ";
    //Stores the information from the keyboard into filename.
    std::cin >> filename;
    
    //Creates two matrix object called "mat1" and "mat2" with 0 passed in to initialize both matrices with zeros.
    Matrix mat1(0), mat2(0);
    //Calls on read_matrices function with filename, mat1 and mat2 as arguments.
    read_matrices(filename, mat1, mat2);
    
    //Displays "Matrix 1: ".
    std::cout << "Matrix 1:" << std::endl;
    //Uses the print_matrix property of mat1 to display matrix 1.
    mat1.print_matrix();
    
    //Displays "Matrix 2: ".
    std::cout << "Matrix 2:" << std::endl;
    //Uses the print_matrix property of mat2 to display matrix 2.
    mat2.print_matrix();

    //Matrix addition problem.
    //First a check to see if the matrices are the same size.
    //This is done by accessing both matrice's get_size property.
    //If they are the same size, then perform addition.
    if (mat1.get_size() == mat2.get_size()) {
        //Displays "Matrix Addition Result: ".
        std::cout << "Matrix Addition Result:" << std::endl;
        //Creates a Matrix object called "sum" to store the result of the addition between mat1 and mat2.
        Matrix sum = mat1 + mat2;
        //Uses the print_matrix property of sum to display the summed matrix.
        sum.print_matrix();
    } else { //Else, display "Error Matrices must be the same size for addition."
        std::cerr << "Error: Matrices must be the same size for addition." << std::endl;
    }
    
    //Matrix multiplication problem.
    //First a check to see if the matrices are the same size.
    //This is done by accessing both matrice's get_size property.
    //If they are the same size, then perform multiplication.
    if (mat1.get_size() == mat2.get_size()) {
        //Displays "Matrix Multiplication Result: ".
        std::cout << "Matrix Multiplication Result:" << std::endl;
        //Creates a Matrix object called "product" to store the result of the multiplication between mat1 and mat2.
        Matrix product = mat1 * mat2;
        //Uses the print_matrix property of product to display the resulting matrix.
        product.print_matrix();
    } else { //Else, display "Error Matrices must be the same size for multiplication."
        std::cerr << "Error: Matrices must be compatible for multiplication." << std::endl;
    }
    
    //Diagonal sums problem to display the sum of the main and secondary diagonal elements of the matrices.
    //Displays "Main diagonal sum of Matrix 1: " with a call to mat1's sum_diagonal_major property. (Main diagonal).
    std::cout << "Main diagonal sum of Matrix 1: " << mat1.sum_diagonal_major() << std::endl;
    //Displays "Secondary diagonal sum of Matrix 1: " with a call to mat1's sum_diagonal_minor property. (Secondary diagonal).
    std::cout << "Secondary diagonal sum of Matrix 1: " << mat1.sum_diagonal_minor() << std::endl;
    
    //Swap rows problem.
    //Variables called "r1" and "r2" for row indices.
    std::size_t r1, r2;
    //Displays "Enter two row indices to swap in Matrix 1: ".
    std::cout << "Enter two row indices to swap in Matrix 1: ";
    if (!(std::cin >> r1 >> r2)) {
        std::cerr << "Invalid input for row indices." << std::endl;
        return 1;
    }
    if (r1 < mat1.get_size() && r2 < mat1.get_size()) {
        mat1.swap_rows(r1, r2);
        std::cout << "Matrix 1 after row swap:" << std::endl;
        mat1.print_matrix();
    } else {
        std::cerr << "Error: Row indices out of bounds." << std::endl;
    }
    
    //Swap columns problem.
    //Variables called "c1" and "c2" for column indices.
    std::size_t c1, c2;
    //Displays "Enter two column indices to swap in Matrix 1: ".
    std::cout << "Enter two column indices to swap in Matrix 1: ";
    if (!(std::cin >> c1 >> c2)) {
        std::cerr << "Invalid input for column indices." << std::endl;
        return 1;
    }
    if (c1 < mat1.get_size() && c2 < mat1.get_size()) {
        mat1.swap_cols(c1, c2);
        std::cout << "Matrix 1 after column swap:" << std::endl;
        mat1.print_matrix();
    } else {
        std::cerr << "Error: Column indices out of bounds." << std::endl;
    }
    
    //Update matrix value problem.
    //Variables called "row" and "col" to enter the row and column to store the element in.
    std::size_t row, col;
    //Integer variable called "new_value" for the value being entered in the matrix.
    int new_value;
    //Displays "Enter row, column, and new value for Matrix1: ".
    std::cout << "Enter row, column, and new value for Matrix 1: ";
    //Stores the information from the keyboard for row, col, and new_value.
    std::cin >> row >> col >> new_value;
    //Uses mat1's set_value property with row, col, and new_value passed in.
    mat1.set_value(row, col, new_value);
    //Displays "Matrix 1 after updating value: ".
    std::cout << "Matrix 1 after updating value:" << std::endl;
    //Uses mat1's print_matrix property to display the matrix.
    mat1.print_matrix();

    return 0;
}
