#pragma once
#include<vector>
using namespace std;
void swap(int* a, int* b);
int sum(int* a, int* b);
void inputArray(int*& a, int& n);
void printArray(int* a, int n);
int* findMax(int* arr, int n);
int* findLongestAscendingSubarray(int* a, int n, int& length);
void swapArrays(int*& a, int*& b, int& na, int& nb);
int* concatenate2Arrays(int* a, int* b, int na, int nb, int& nc);
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc);
void generateMatrix1(int**& a, int& length, int& width);
int** generateMatrix2(int* a, int* b, int na, int nb, int& crow, int& ccol);
void printMatrix(int** a, int length, int width);
void swapRows(int** a, int length, int width, int ir1, int ir2);
void swapColumns(int** a, int length, int width, int ic1, int ic2);
int** transposeMatrix(int** a, int length, int width);
int** concatenate2MatricesH(int** a, int** b, int length, int width, int& lres, int& wres);
int** concatenate2MatricesV(int** a, int** b, int length, int width, int& lres, int& wres);
bool multiple2Matrices(int**& res, int** a, int** b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb);
int** findSubmatrix(int** a, int length, int width, int& lres, int& wres);
int LinearSearch(int* a, int n, int key);
int SentinelLinearSearch(int* a, int n, int key);
int BinarySearch(int* a, int n, int key);
int RecursiveBinarySearch(int* a, int left, int right, int key);
int RecursiveSum(int n);
int RecursiveFactorial(int n);
int BinaryPow(int x, int n);
int countDigit(int n);
bool IsEven(int n);
int countCommonDivisor(int x, int y);
int GreatestCommonDivisor(int x, int y);
int ReverseValue(int x);
int fibo(int x);
void permutationsCharacter(string s, int left, int right);
struct Examinee
{
	string id;
	float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};
Examinee readExaminee(string line_info);
vector<Examinee>readExamineeList(string file_name);
void writeScores(vector<Examinee> examinee_list, string out_file_name);