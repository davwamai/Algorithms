// Copyright 2022 CSCE 240
//

#include <hw3/inc/find_sum.h>
// collection of helper functions

// each function accepts same params as FindSum EXCEPT for sums_found, instead
//   I used four ints:
// (1) index of starting row
// (2) index of starting column
// (3) address of index of ending row
// (4) address of index of ending col
//
// Return true if found

// search row
// search column
// search diag dsc
// search diag asc

const size_t** FindSum(const int** matrix,
                       const size_t* matrix_size,
                       int search_sum,
                       size_t* sums_found) {
  *sums_found = 0;  // init sums found to 0
  size_t summations_size = 2;  // start assuming no more than 2 summations
  // build structure to hold all found summations
  size_t** summations = new size_t*[summations_size];
  size_t **indices_found = nullptr;
  size_t ind_found_size = 0;
  size_t *indices = nullptr;
  for(size_t row = 0; row < matrix_size[kMatrix_size_rows_idx]; row++){
    for(size_t col = 0; col < matrix_size[kMatrix_size_cols_idx]; col++){
      if(search_sum == matrix[row][col]){
        if(!indices){
          indices = Allocate(row, col);
        }
        indices[kIndices_end_row_idx] = row;
        indices[kIndices_end_col_idx] = col;
        
        if(*sums_found == ind_found_size){
          indices_found = IncMatrix(indices_found, &ind_found_size);
        }
        indices_found[*sums_found] = indices;
        (*sums_found)++;
        indices = nullptr;

        continue;
      }
      FunctionType funcs [] = {Ascending, Descending, Column, Row};
      for(FunctionType func : funcs){
        if(!indices){
          indices = Allocate(row, col);
        }
        if((*func)(search_sum, matrix, matrix_size, indices)){
          if(*sums_found == ind_found_size){
            indices_found = IncMatrix(indices_found, &ind_found_size);
          }
          indices_found[*sums_found] = indices;
          (*sums_found)++;
        } else {
          delete [] indices;
        }
        indices = nullptr;
      }
    }
  }
    return const_cast<const size_t**>(indices_found);
  }

  bool Ascending(int search_sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
    for(size_t row = sum_indices[kMatrix_size_rows_idx], column = sum_indices[kMatrix_size_cols_idx];
    row < matrix_size[kMatrix_size_rows_idx] && column < matrix_size[kMatrix_size_cols_idx]; row--, column++){
      search_sum -= matrix[row][column];
      if(search_sum == 0){
        sum_indices[kIndices_end_row_idx] = row;
        sum_indices[kIndices_end_col_idx] = column;
        return true;
      }
    }
    return false; 
  }
  
  bool Descending(int search_sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
    for(size_t row = sum_indices[kMatrix_size_rows_idx], column = sum_indices[kMatrix_size_cols_idx];
    row < matrix_size[kMatrix_size_rows_idx] && column < matrix_size[kMatrix_size_cols_idx]; row++, column++){
      search_sum -= matrix[row][column];
      if(search_sum == 0){
        sum_indices[kIndices_end_row_idx] = row;
        sum_indices[kIndices_end_col_idx] = column;
        return true;
      }
    }
    return false; 
  }

  bool Column(int search_sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
    for(size_t row = sum_indices[kMatrix_size_rows_idx]; row < matrix_size[kMatrix_size_rows_idx]; row++){
      search_sum -= matrix[row][sum_indices[kMatrix_size_cols_idx]];
      if(search_sum==0){
        sum_indices[kIndices_end_col_idx] = sum_indices[kMatrix_size_cols_idx];
        sum_indices[kIndices_end_row_idx] = row;
        return true;
      }
    }
    return false;
  }

  bool Row(int search_sum, const int** matrix, const size_t* matrix_size, size_t* sum_indices){
    for(size_t column = sum_indices[kMatrix_size_cols_idx]; column < matrix_size[kMatrix_size_cols_idx]; column++){
      search_sum -= matrix[sum_indices[kMatrix_size_rows_idx]][column];
      if(search_sum==0){
        sum_indices[kIndices_end_row_idx] = sum_indices[kMatrix_size_rows_idx];
        sum_indices[kIndices_end_col_idx] = column;
        return true;
      }
    }
    return false;
  }

  size_t * Allocate(size_t row, size_t column){
    size_t *i = new size_t[kIndices_size];
    i[kIndices_start_row_idx] = row;
    i[kIndices_start_col_idx] = column;
    return i; 
  }

  size_t ** IncMatrix(size_t** a, size_t* size){
    const size_t start_size = 2;
    size_t new_size;
    if(*size == 0){
      new_size = start_size;
    } else {
      new_size = *size<<1;
    }
    size_t **temp = new size_t *[new_size];
    for(size_t i = 0; i < *size; i++){
      temp[i] = a[i];
    }
    delete [] a;
    *size = new_size;
    return temp;

  }    



                       
