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
struct Node
{
	int key;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};
void removeTail(List& l);
void removeHead(List& l);
void addTail(List& l, int data);
void addHead(List& l, int data);
List createlist(Node* node);
Node* createNode(int data);
void removeAll(List& l);
void printList(List l);
void removeBefore(List& l, int val);
void removeAfter(List& l, int val);
void addPos(List& l, int data, int pos);
int countElements(List l);
void removePos(List& l, int pos);
void addBefore(List& l, int data, int val);
void addAfter(List& l, int data, int val);
List reverseList(List l);
void removeDuplicate(List& l);
void removeNode(List& l, Node* pNode);
bool removeElement(List& l, int key);
struct DNode {
	int key;
	DNode* next;
	DNode* prev;
};
struct DList {
	DNode* head;
	DNode* tail;
};
DNode* createDNode(int data);
DList createDList(DNode* node);
void addDHead(DList& l, int data);
void printDList(DList l);
void addDTail(DList& l, int data);
void removeDHead(DList& l);
void removeDTail(DList& l);
void removeDAll(DList& l);
void removeDBefore(DList& l, int val);
void removeDAfter(DList& l, int val);