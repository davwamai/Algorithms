// File Processing
//  These functions accept a string file name, open the file, read the
//  contents, and processes the contained data as indicated (excluding the
//  count of doubles).
// 
//  The file format consists of an integer n, followed by n additional positive
//  and negative doubles. The first value is not part of the dataset. The
//  values are all separated by white space and so can be parsed using the
//  insertion operator (>>). You should probably use the fstream object (which
//  accepts a string in its constructor) to read the doubles.
// 
// Functions:
// double Max(const string&):
//   Accepts string parameter as file name, returns double value representing
//   the largest value of the doubles in file
// double Min(const string&):
//   Accepts string parameter as file name, returns double value representing
//   the smallest value of the doubles in file
// double Sum(const string&):
//   Accepts string parameter as file name, returns double value representing
//   the sum of the values of the doubles in file
// double Avg(const string&):
//   Accepts string parameter as file name, returns floating point value
//   representing the sum of the values of the doubles in file
// void Sort(const string&, int[]):
//   Accepts string parameter as file name and an double array parameter to
//   store the values in the file pre and post sort. The double array will be
//   large enough to hold all double values (except count) in the file; this
//   is a precondition. The function stores the sorted values from the file in
//   the double array. Notice that this means you must use an in-place sort to
//   sort the array.  YOU MAY NOT use the algorithm library.  Any student doing
//   so will receive 0/6 for this problem.
// 
// References:
//  fstream: http://cplusplus.com/reference/fstream/
//  string: http://cplusplus.com/reference/string/
// 
// Points:
//  -compilation: 1
//  -style: 1
//  -correctness: 4 (Max: 0.5, Min: 0.5, Sum: 0.5, Avg: 1, Sort: 1.5)
//
#ifndef EXAM1_PROBLEM2_H_
#define EXAM1_PROBLEM2_H_

#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <bits/stdc++.h> //meme

using namespace std::chrono;
using namespace std;


double Max(const std::string& file_name);
double Min(const std::string& file_name);
double Sum(const std::string& file_name);
double Avg(const std::string& file_name);
void Sort(const std::string& filename, double ordered_doubles[]);
bool partyrock(vector<double>& a, int n);
void shufflin(vector<double>& a, int n);
vector<double> redfoo(vector<double>& a, int n);
void printErr();
vector<double> fileSetup(const std::string& filename);


const char kTestVal = 'C';  // used to test correct header construction

#endif  // EXAM1_PROBLEM2_H_
