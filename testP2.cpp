#include <gtest/gtest.h>
#include <iostream>
#include "matrix.h"



TEST(testP2,case1){
    Matrix matrix1 = {{1, 1},{1, 1}};
    Matrix matrix2 = {{1, 1},{1, 1}};

    Matrix matrix3;

    matrix3 = matrixMultiply(matrix1, matrix2);

    Matrix matrixExpected = {{2, 2},{2, 2}};
    EXPECT_EQ(matrixExpected, matrix3);

}



TEST(testP2,case2){
    Matrix matrix1 = {{1, 1},{1, 1}};
    Matrix matrix2 = {{1, 1},{1, 1}};

    Matrix matrix3;

    matrix3 = matrixAdd(matrix1, matrix2);

    Matrix matrixExpected = {{2, 2},{2, 2}};
    EXPECT_EQ(matrixExpected, matrix3);

}

TEST(testP2,case3){
    bool caught_invalid_argument = false;

    Matrix matrix_1 = {{1,2,3,4}, {4,5,6,6},{1,2,3,4}};
    Matrix matrix_2 = {{1,2,3},{1,2,3}};
    Matrix testMatrix11;
    try{
      testMatrix11 = matrixMultiply(matrix_1, matrix_2);
    }
    catch (std::invalid_argument e){
      std::cout << "std::invalid_argument caught" <<  std::endl;
      caught_invalid_argument = true;
    }
    EXPECT_TRUE(caught_invalid_argument);
}

// Add 2x3 Matrices
TEST(testP2,case4){
    Matrix matrix1 = {{1, 2, 3},{4, 5, 6}};
    Matrix matrix2 = {{1, 2, 3},{4, 5, 6}};

    Matrix matrix3;

    matrix3 = matrixAdd(matrix1, matrix2);

    Matrix matrixExpected = {{2, 4, 6},{8, 10, 12}};
    EXPECT_EQ(matrixExpected, matrix3);

}

// Multiply 3x2 with 2x3 Matrices
TEST(testP2,case5){
    Matrix matrix1 = {{1, 2},{3, 4},{5, 6}};
    Matrix matrix2 = {{1, 2, 3},{4, 5, 6}};

    Matrix matrix3;

    matrix3 = matrixMultiply(matrix1, matrix2);

    Matrix matrixExpected = {{9, 12, 15},{19, 26, 33},{29, 40, 51}};
    EXPECT_EQ(matrixExpected, matrix3);

}

// Multiply empty Matrices
TEST(testP2,case6){
    Matrix matrix1 = {};
    Matrix matrix2 = {};

    Matrix matrix3;

    bool caught_invalid_argument = false;

  try{
    matrix3 = matrixMultiply(matrix1, matrix2);
  }
  catch (std::invalid_argument e){
      std::cout << "std::invalid_argument caught" <<  std::endl;
      caught_invalid_argument = true;
    }
  EXPECT_TRUE(caught_invalid_argument);
}

// Add empty Matrices
TEST(testP2,case7){
    Matrix matrix1 = {};
    Matrix matrix2 = {};
    Matrix matrix3;
    bool caught_invalid_argument = false;

  try{
    matrix3 = matrixAdd(matrix1, matrix2);
  }
  catch (std::invalid_argument e){
      std::cout << "std::invalid_argument caught" <<  std::endl;
      caught_invalid_argument = true;
    }
  EXPECT_TRUE(caught_invalid_argument);

}

// Multiply empty Matrices (different rxc)
TEST(testP2,case8){
    Matrix matrix1 = {{}};
    Matrix matrix2 = {{},{},{}};

    Matrix matrix3;

    bool caught_invalid_argument = false;

  try{
    matrix3 = matrixMultiply(matrix1, matrix2);
  }
  catch (std::invalid_argument e){
      std::cout << "std::invalid_argument caught" <<  std::endl;
      caught_invalid_argument = true;
    }
  EXPECT_TRUE(caught_invalid_argument);
}

// Add empty Matrices (different rows x columns)
TEST(testP2,case9){
    Matrix matrix1 = {{}};
    Matrix matrix2 = {{},{},{}};
    Matrix matrix3;
    bool caught_invalid_argument = false;

  try{
    matrix3 = matrixAdd(matrix1, matrix2);
  }
  catch (std::invalid_argument e){
      std::cout << "std::invalid_argument caught" <<  std::endl;
      caught_invalid_argument = true;
    }
  EXPECT_TRUE(caught_invalid_argument);

}