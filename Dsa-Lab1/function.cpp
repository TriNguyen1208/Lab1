#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<sstream>
#include"function.h"
using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int sum(int* a, int* b)
{
	int* sum = new int;
	*sum = *a + *b;
	return *sum;
}
void inputArray(int*& a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int* findMax(int* arr, int n)
{
	int* max = new int;
	*max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= *max)
		{
			*max = arr[i];
		}
	}
	return max;
}
int* findLongestAscendingSubarray(int* a, int n, int& length)
{
	int maxLength = 0;
	int idx = 0, idy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			bool KT = true;
			for (int k = i; k <= j - 1; k++)
			{
				if (a[k] >= a[k + 1])
				{
					KT = false;
				}
			}
			if (KT == true)
			{
				if (j - i + 1 >= maxLength)
				{
					maxLength = j - i + 1;
					idx = i;
					idy = j;
				}
			}
			else
			{
				break;
			}
		}
	}
	int* b = new int[maxLength];
	for (int i = idx; i <= idy; i++)
	{
		b[i - idx] = a[i];
	}
	length = maxLength;
	return b;
}
void swapArrays(int*& a, int*& b, int& na, int& nb)
{
	int* tmpArr = a;
	a = b;
	b = tmpArr;
	int tmp = na;
	na = nb;
	nb = tmp;
}
int* concatenate2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	nc = na + nb;
	int* result = new int[nc];
	for (int i = 0; i < na; i++)
	{
		result[i] = a[i];
	}
	for (int i = 0; i < nb; i++)
	{
		result[i + na] = b[i];
	}
	return result;
}
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	nc = na + nb;
	int* result = new int[nc];
	int cntA = 0, cntB = 0, cntC = 0;
	while (cntA != na && cntB != nb)
	{
		if (a[cntA] < b[cntB])
		{
			result[cntC] = a[cntA];
			cntC++, cntA++;
		}
		else
		{
			result[cntC] = b[cntB];
			cntC++, cntB++;
		}
	}
	while (cntA != na)
	{
		result[cntC] = a[cntA];
		cntC++, cntA++;
	}
	while (cntB != nb)
	{
		result[cntC] = b[cntB];
		cntC++, cntB++;
	}
	return result;
}
void generateMatrix1(int**& a, int& length, int& width)
{
	cin >> length >> width;
	a = new int* [length];
	for (int i = 0; i < length; i++)
	{
		a[i] = new int[width];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> a[i][j];
		}
	}
}
int** generateMatrix2(int* a, int* b, int na, int nb, int& crow, int &ccol)
{
	int** c = new int* [na];
	for (int i = 0; i < na; i++)
	{
		c[i] = new int[nb];
	}
	for (int i = 0; i < na; i++)
	{
		for (int j = 0; j < nb; j++)
		{
			c[i][j] = a[i] * b[j];
		}
	}
	crow = na, ccol = nb;
	return c;
}
void printMatrix(int** a, int length, int width)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void swapRows(int** a, int length, int width, int ir1, int ir2)
{
	for (int i = 0; i < width; i++)
	{
		swap(&a[ir1][i], &a[ir2][i]);
	}
}
void swapColumns(int** a, int length, int width, int ic1, int ic2)
{
	for (int i = 0; i < length; i++)
	{
		swap(&a[i][ic1], &a[i][ic2]);
	}
}
int** transposeMatrix(int** a, int length, int width)
{
	int** b = new int*[width];
	for (int i = 0; i < width; i++)
	{
		b[i] = new int[length];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			b[j][i] = a[i][j];
		}
	}
	return b;
}
int** concatenate2MatricesH(int** a, int** b, int length, int width, int& lres, int& wres)
{
	lres = length, wres = width + width;
	int** c = new int*[lres];
	for (int i = 0; i < lres; i++)
	{
		c[i] = new int[wres];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j + width] = b[i][j];
		}
	}
	return c;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width, int& lres, int& wres)
{
	lres = length + length, wres = width;
	int** c = new int* [lres];
	for (int i = 0; i < lres; i++)
	{
		c[i] = new int[wres];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c[i + length][j] = b[i][j];
		}
	}
	return c;
}
bool multiple2Matrices(int**& res, int** a, int** b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb)
{
	if (widtha != lengthb)
	{
		return false;
	}
	lengthr = lengtha, widthr = widthb;
	res = new int* [lengthr];
	for (int i = 0; i < lengthr; i++)
	{
		res[i] = new int[widthr];
	}
	for(int i = 0;i < lengthr;i++)
	{ 
		for (int j = 0; j < widthr; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < widtha; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return true;
}
int** findSubmatrix(int** a, int length, int width, int& lres, int& wres)
{
	cin >> lres >> wres;
	int max = INT_MIN;
	int idx1, idx2, idy1, idy2;
	for (int i = 0; i <= length - lres; i++)
	{
		for (int j = 0; j <= width - wres; j++)
		{
			for (int k = i; k < i + lres; k++)
			{
				for (int l = j; l < j + wres; l++)
				{
					int sum = 0;
					for (int m = i; m <= k; m++)
					{
						for (int n = j; n <= l; n++)
						{
							sum = sum + a[m][n];
						}
					}
					if (sum >= max)
					{
						max = sum;
						idx1 = i, idx2 = k, idy1 = j, idy2 = l;
					}
				}
			}

		}
	}
	int** res = new int* [lres];
	for (int i = 0; i < lres; i++)
	{
		res[i] = new int[wres];
	}
	for (int i = idx1; i <= idx2; i++)
	{
		for (int j = idy1; j <= idy2; j++)
		{
			res[i - idx1][j - idy1] = a[i][j];
		}
	}
	return res;
}
int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int SentinelLinearSearch(int* a, int n, int key)
{
	int last = a[n - 1];
	a[n - 1] = key;
	int i = 0;
	while (a[i] != key)
	{
		i++;
	}
	a[n - 1] = last;
	if ((i < n - 1) || a[n - 1] == key)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int BinarySearch(int* a, int n, int key)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] < key)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}
int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	int mid = (left + right) / 2;
	if (a[mid] == key)
	{
		return mid;
	}
	else if (left > right)
	{
		return -1;
	}
	else if (a[mid] < key)
	{
		return RecursiveBinarySearch(a, mid + 1, right, key);
	}
	else
	{
		return RecursiveBinarySearch(a, left, mid - 1, key);
	}
}
int RecursiveSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n + RecursiveSum(n - 1);
}
int RecursiveFactorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * RecursiveFactorial(n - 1);
}
int BinaryPow(int x, int n)
{
	if (n == 1)
	{
		return x;
	}
	int res = BinaryPow(x, n / 2);
	if (n % 2 == 0)
	{
		return res * res;
	}
	else
	{
		return res * res * x;
	}
}
int countDigit(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return 1 + countDigit(n / 10);
}
bool IsEven(int n)
{
	if (n == 0)
	{
		return true;
	}
	if (n % 2 == 1)
	{
		return false;
	}
	return IsEven(n / 10);
}

int GreatestCommonDivisor(int x, int y)
{
	if (y % x == 0)
	{
		return x;
	}
	return GreatestCommonDivisor(y, x % y);

}
int LeastCommonDivisor(int x, int y)
{
	return (x * y) / GreatestCommonDivisor(x, y);
}
int ReverseValue(int x, int sum = 0)
{
	if (x == 0)
	{
		return sum;
	}
	return ReverseValue(x / 10, sum * 10 + x % 10);
}
int fibo(int x)
{
	if (x <= 1)
	{
		return x;
	}
	return fibo(x - 1) + fibo(x - 2);
}
void swap(char& x, char& y)
{
	char tmp = x;
	x = y;
	y = tmp;
}
void permutationsCharacter(string s, int left, int right)
{
	if (left == right)
	{
		cout << s << endl;
		return;
	}
	for (int i = left; i <= right; i++)
	{
		swap(s[i], s[left]);
		permutationsCharacter(s, left + 1, right);
		swap(s[i], s[left]);
	}
}
Examinee readExaminee(string line_info)
{
	ifstream fin;
	fin.open("data.txt", ios::in);
	if (!fin.is_open())
	{
		Examinee trash;
		return trash;
	}
	string tmp;
	getline(fin, tmp, ',');
	while (getline(fin, tmp))
	{
		if (tmp == line_info)
		{
			break;
		}
	}
	Examinee res;
	stringstream ss(tmp);
	getline(ss, res.id, ',');
	getline(ss, tmp, ',');
	string tmpValue[13];
	for (int i = 0; i < 13; i++)
	{
		getline(ss, tmpValue[i], ',');
	}
	if (tmpValue[0] != "") res.maths = stof(tmpValue[0]);
	else res.maths = 0;
	if (tmpValue[1] != "") res.literature = stof(tmpValue[1]);
	else res.literature = 0;
	if (tmpValue[2] != "") res.physics = stof(tmpValue[2]);
	else res.physics = 0;
	if (tmpValue[3] != "") res.chemistry = stof(tmpValue[3]);
	else res.chemistry = 0;
	if (tmpValue[4] != "") res.biology = stof(tmpValue[4]);
	else res.biology = 0;
	if (tmpValue[5] != "") res.history = stof(tmpValue[5]);
	else res.history = 0;
	if (tmpValue[6] != "") res.geography = stof(tmpValue[6]);
	else res.geography = 0;
	if (tmpValue[7] != "") res.civic_education = stof(tmpValue[7]);
	else res.civic_education = 0;
	if (tmpValue[10] != "") res.foreign_language = stof(tmpValue[10]);
	else res.foreign_language = 0;
	res.natural_science = res.physics + res.chemistry + res.biology;
	res.social_science = res.history + res.geography + res.civic_education;
	fin.close();
	return res;
}
vector<Examinee> readExamineeList(string file_name)
{
	vector<Examinee>value;
	ifstream fin;
	fin.open(file_name.c_str(), ios::in);
	if (!fin.is_open())
	{
		return value;
	}
	string tmp;
	getline(fin, tmp);
	while (getline(fin, tmp))
	{
		Examinee res;
		stringstream ss(tmp);
		getline(ss, res.id, ',');
		getline(ss, tmp, ',');
		string tmpValue[13];
		for (int i = 0; i < 13; i++)
		{
			getline(ss, tmpValue[i], ',');
		}
		if (tmpValue[0] != "") res.maths = stof(tmpValue[0]);
		else res.maths = 0;
		if (tmpValue[1] != "") res.literature = stof(tmpValue[1]);
		else res.literature = 0;
		if (tmpValue[2] != "") res.physics = stof(tmpValue[2]);
		else res.physics = 0;
		if (tmpValue[3] != "") res.chemistry = stof(tmpValue[3]);
		else res.chemistry = 0;
		if (tmpValue[4] != "") res.biology = stof(tmpValue[4]);
		else res.biology = 0;
		if (tmpValue[5] != "") res.history = stof(tmpValue[5]);
		else res.history = 0;
		if (tmpValue[6] != "") res.geography = stof(tmpValue[6]);
		else res.geography = 0;
		if (tmpValue[7] != "") res.civic_education = stof(tmpValue[7]);
		else res.civic_education = 0;
		if (tmpValue[10] != "") res.foreign_language = stof(tmpValue[10]);
		else res.foreign_language = 0;
		res.natural_science = res.physics + res.chemistry + res.biology;
		res.social_science = res.history + res.geography + res.civic_education;
		value.push_back(res);
	}
	fin.close();
	return value;
}
void writeScores(vector<Examinee> examinee_list, string out_file_name)
{
	ofstream os;
	os.open(out_file_name.c_str());
	if (!os.is_open())
	{
		return;
	}
	os << "SBD BB KHTN KHXH" << endl;
	for (int i = 0; i < examinee_list.size(); i++)
	{
		float compulsory = examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foreign_language;
		os << examinee_list[i].id << " " << compulsory << " " << examinee_list[i].natural_science << " " << examinee_list[i].social_science << endl;
	}
	os.close();
}
Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->key = data;
	newNode->next = NULL;
	return newNode;
}
List createlist(Node* node)
{
	List l;
	l.head = node;
	l.tail = node;
	return l;
}
void addHead(List& l, int data)
{
	Node* newNode = createNode(data);
	if (l.head == NULL)
	{
		l.head = newNode;
		l.tail = newNode;
		return;
	}
	newNode->next = l.head;
	l.head = newNode;
}
void addTail(List& l, int data)
{
	Node* newNode = createNode(data);
	if (l.head == NULL)
	{
		l.head = newNode;
		l.tail = newNode;
		return;
	}
	l.tail->next = newNode;
	l.tail = newNode;
}
void removeHead(List& l)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.head->next == NULL)
	{
		delete l.head;
		l.head = NULL;
		l.tail = NULL;
		return;
	}
	Node* tmp = l.head;
	l.head = l.head->next;
	delete tmp;
}
void removeTail(List& l)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.head->next == NULL)
	{
		delete l.head;
		l.head = NULL;
		l.tail = NULL;
		return;
	}
	Node* pCurr = l.head;
	while (pCurr->next->next != NULL)
	{
		pCurr = pCurr->next;
	}
	delete l.tail;
	l.tail = pCurr;
	l.tail->next = NULL;
}
void removeAll(List& l)
{
	while (l.head != NULL)
	{
		removeHead(l);
	}
}
void printList(List l)
{
	for (Node* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->key << " ";
	}
}
void removeBefore(List& l, int val)
{
	if (l.head == NULL || l.head->next == NULL || l.head->key == val)// only one element
	{
		return;
	}
	if (l.head->next->key == val)
	{
		removeHead(l);
		return;
	}
	Node* pCurr = l.head;
	Node* pPrev = NULL;
	while (pCurr->next->key != val && pCurr != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
	if (pCurr == NULL)
	{
		return;
	}
	pPrev->next = pCurr->next;
	delete pCurr;
}
void removeAfter(List& l, int val)
{
	if (l.head == NULL || l.tail->key == val || l.head->next == NULL)
	{
		return;
	}
	Node* pCurr = l.head->next;
	Node* pPrev = l.head;
	while (pPrev->key != val && pCurr->next != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
	if (pPrev->next == l.tail)
	{
		removeTail(l);
		return;
	}
	pPrev->next = pCurr->next;
	delete pCurr;
}
int countElements(List l)
{
	int count = 0;
	for (Node* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		count++;
	}
	return count;
}
int countCommonDivisor(int x, int y, int count = 0, int start = 1)
{
	if (start == x || start == y)
	{
		if (x % y == 0 || y % x == 0)
		{
			return count + 1;
		}
		return count;
	}
	if (x % start == 0 && y % start == 0)
	{
		return countCommonDivisor(x, y, count + 1, start + 1);
	}
	return countCommonDivisor(x, y, count, start + 1);
}
void addPos(List& l, int data, int pos)
{
	Node* newNode = createNode(data);
	int count = countElements(l);
	if (pos < 0 || pos > count)
	{
		return;
	}
	if (pos == 0)
	{
		addHead(l, data);
		return;
	}
	if (pos == count)
	{
		addTail(l, data);
		return;
	}
	Node* pPrev = l.head;
	Node* pCurr = l.head->next;
	for (int i = 1; i < count; i++)
	{
		if (i == pos)
		{
			pPrev->next = newNode;
			newNode->next = pCurr;
			return;
		}
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
}
void removePos(List& l, int pos)
{
	int count = countElements(l);
	if (pos < 0 || pos >= count)
	{
		return;
	}
	if (pos == 0)
	{
		removeHead(l);
		return;
	}
	if (pos == count - 1)
	{
		removeTail(l);
		return;
	}
	Node* pPrev = l.head;
	Node* pCurr = l.head->next;
	for (int i = 1; i < count; i++)
	{
		if (i == pos)
		{
			pPrev->next = pCurr->next;
			delete pCurr;
			return;
		}
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
}
void addBefore(List& l, int data, int val)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.head->key == val)
	{
		addHead(l, data);
		return;
	}
	Node* pPrev = NULL;
	Node* pCurr = l.head;
	while (pCurr->key != val && pCurr != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
	if (pCurr == NULL)
	{
		return;
	}
	Node* newNode = createNode(data);
	pPrev->next = newNode;
	newNode->next = pCurr;
}
void addAfter(List& l, int data, int val)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.tail->key == val)
	{
		addTail(l, data);
		return;
	}
	Node* pCurr = l.head->next;
	Node* pPrev = l.head;
	while (pPrev->key != val && pPrev->next != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
	if (pPrev->next == NULL)
	{
		return;
	}
	Node* newNode = createNode(data);
	pPrev->next = newNode;
	newNode->next = pCurr;
}
List reverseList(List l)
{
	List res = createlist(NULL);
	if (l.head == NULL)
	{
		return res;
	}
	for (Node* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		addHead(res, pCurr->key);
	}
	return res;
}
void removeNode(List& l, Node* pNode)
{
	if (pNode == l.head)
	{
		removeHead(l);
		return;
	}
	Node* pPrev = l.head;
	Node* pCurr = l.head->next;
	while (pCurr != pNode && pCurr != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->next;
	}
	if (pCurr->next == NULL)
	{
		removeTail(l);
		return;
	}
	pPrev->next = pCurr->next;
	delete pCurr;
}
void removeDuplicate(List& l)
{
	for (Node* pCurr1 = l.head; pCurr1 != NULL; pCurr1 = pCurr1->next)
	{
		for (Node* pCurr2 = pCurr1->next; pCurr2 != NULL;)
		{
			if (pCurr1->key == pCurr2->key)
			{
				Node* tmp = pCurr2->next;
				removeNode(l, pCurr2);
				pCurr2 = tmp;
			}
			else
			{
				pCurr2 = pCurr2->next;
			}
		}
	}
}
bool removeElement(List& l, int key)
{
	bool check = false;
	for (Node* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		if (pCurr->key == key)
		{
			check = true;
		}
	}
	if (check == false)
	{
		return false;
	}
	for (Node* pCurr = l.head; pCurr != NULL; )
	{
		if (pCurr->key == key)
		{
			Node* tmp = pCurr->next;
			removeNode(l, pCurr);
			pCurr = tmp;
		}
		else
		{
			pCurr = pCurr->next;
		}
	}
	return true;
}

DNode* createDNode(int data)
{
	DNode* newNode = new DNode;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->key = data;
	return newNode;
}
DList createDList(DNode* node)
{
	DList l;
	l.head = node;
	l.tail = node;
	return l;
}
void addDHead(DList& l, int data)
{
	DNode* newNode = createDNode(data);
	if (l.head == NULL)
	{
		l.head = newNode;
		l.tail = newNode;
		return;
	}
	newNode->next = l.head;
	l.head->prev = newNode;
	l.head = newNode;
}
void printDList(DList l)
{
	for (DNode* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->key << " ";
	}
}
void addDTail(DList& l, int data)
{
	DNode* newNode = createDNode(data);
	if (l.head == NULL)
	{
		l.head = newNode;
		l.tail = newNode;
		return;
	}
	l.tail->next = newNode;
	newNode->prev = l.tail;
	l.tail = newNode;
}
void removeDHead(DList& l)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.head->next == NULL)
	{
		delete l.head;
		l.head = NULL;
		l.tail = NULL;
		return;
	}
	DNode* pTmp = l.head;
	l.head = l.head->next;
	l.head->prev = NULL;
	delete pTmp;
}
void removeDTail(DList& l)
{
	if (l.head == NULL)
	{
		return;
	}
	if (l.head->next == NULL)
	{
		delete l.head;
		l.head = NULL;
		l.tail = NULL;
		return;
	}
	DNode* pCurr = l.head;
	while (pCurr->next != NULL)
	{
		pCurr = pCurr->next;
	}
	l.tail = pCurr->prev;
	l.tail->next = NULL;
	delete pCurr;
}
void removeDAll(DList& l)
{
	while (l.head != NULL)
	{
		removeDHead(l);
	}
}
void removeDBefore(DList& l, int val)
{
	if (l.head == NULL || l.head == l.tail)
	{
		return;//the value is in the head or the list don't have any value
	}
	if (l.head->next->key == val)
	{
		removeDHead(l);// the value is in the next of the head
		return;
	}
	DNode* pCurr = l.head;
	while (pCurr->key != val && pCurr != NULL)
	{
		pCurr = pCurr->next;
	}
	if (pCurr == NULL) //Don't have value in the list
	{
		return;
	}
	DNode* tmp = pCurr->prev;
	pCurr->prev = tmp->prev;
	(tmp->prev)->next = pCurr;
	delete tmp;
}
void removeDAfter(DList& l, int val)
{
	if (l.head == NULL || l.head == l.tail || l.tail->key == val) //the value is in the head or the list don't have any value
	{
		return; 
	}
	if (l.tail->prev->key == val)
	{
		removeDTail(l);
		return;
	}
	DNode* pCurr = l.head;
	while (pCurr->key != val && pCurr != NULL)
	{
		pCurr = pCurr->next;
	}
	if (pCurr == NULL)
	{
		return;
	}
	DNode* tmp = pCurr->next;
	pCurr->next = tmp->next;
	(tmp->next)->prev = pCurr;
	delete tmp;
}
int countDElement(DList l)
{
	int count = 0;
	for (DNode* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		count++;
	}
	return count;
}
void addDPos(DList& l, int data, int pos)
{
	int countElement = countDElement(l);
	if (pos == 0)
	{
		addDHead(l, data);
		return;
	}
	if (pos == countElement)
	{
		addDTail(l, data);
		return;
	}
	if (pos < 0 || pos > countElement)
	{
		return;
	}
	int cnt = 0;
	DNode* pCurr = l.head;
	for (int i = 0; i < pos; i++)
	{
		pCurr = pCurr->next;
	}
	DNode* newNode = createDNode(data);
	pCurr->prev->next = newNode;
	newNode->prev = pCurr->prev;
	newNode->next = pCurr;
	pCurr->prev = newNode;
}
void removeDPos(DList& l, int pos)
{
	int countElement = countDElement(l);
	if (pos < 0 || pos > countElement - 1)
	{
		return;
	}
	if (pos == 0)
	{
		removeDHead(l);
		return;
	}
	if (pos == countElement - 1)
	{
		removeDTail(l);
		return;
	}
	DNode* pCurr = l.head;
	for (int i = 0; i < pos; i++)
	{
		pCurr = pCurr->next;
	}
	DNode* tmp = pCurr;
	pCurr->prev->next = tmp->next;
	tmp->next->prev = pCurr->prev;
	delete tmp;
}
bool checkIsVal(DList l, int data)
{
	for (DNode* pCurr = l.head; pCurr != NULL; pCurr = pCurr->next)
	{
		if (pCurr->key == data)
		{
			return true;
		}
	}
	return false;
}
void addDBefore(DList& l, int data, int val)
{
	if (checkIsVal(l, val) == false)
	{
		return;
	}
	if (l.head->key == val)
	{
		addDHead(l, data);
		return;
	}
	DNode* pCurr = l.head;
	while (pCurr->key != val)
	{
		pCurr = pCurr->next;
	}
	DNode* newNode = createDNode(data);
	pCurr->prev->next = newNode;
	newNode->prev = pCurr->prev;
	newNode->next = pCurr;
	pCurr->prev = newNode;
}
void addDAfter(DList& l, int data, int val)
{
	if (checkIsVal(l, val) == false)
	{
		return;
	}
	if (l.tail->key == val)
	{
		addDTail(l, data);
		return;
	}
	DNode* pCurr = l.head;
	while (pCurr->key != val)
	{
		pCurr = pCurr->next;
	}
	DNode* newNode = createDNode(data);
	DNode* tmp = pCurr->next;
	pCurr->next = newNode;
	newNode->prev = pCurr;
	newNode->next = tmp;
	tmp->prev = newNode;
}
DList reverseDList(DList l)
{
	if (l.head == NULL)
	{
		DList rubbish = createDList(NULL);
		return rubbish;
	}
	DList newList = createDList(NULL);
	DNode* pCurr = l.head;
	while (pCurr != NULL)
	{
		addDHead(newList, pCurr->key);
		pCurr = pCurr->next;
	}
	return newList;
}
void removeDNode(DList& l, DNode* node)
{
	if (node == l.head)
	{
		removeDHead(l);
		return;
	}
	if (node == l.tail)
	{
		removeDTail(l);
		return;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}
void removeDDuplicate(DList& l)
{
	for (DNode* pCurr1 = l.head; pCurr1 != NULL; pCurr1 = pCurr1->next)
	{
		for (DNode* pCurr2 = pCurr1->next; pCurr2 != NULL;)
		{
			if (pCurr2->key == pCurr1->key)
			{
				DNode* tmp = pCurr2->next;
				removeDNode(l, pCurr2);
				pCurr2 = tmp;
			}
			else
			{
				pCurr2 = pCurr2->next;
			}
		}
	}
}
void removeDElement(DList& l, int key)
{
	if (checkIsVal(l, key) == false)
	{
		return;
	}
	for (DNode* pCurr = l.head; pCurr != NULL;)
	{
		if (pCurr->key == key)
		{
			DNode* tmp = pCurr->next;
			removeDNode(l, pCurr);
			pCurr = tmp;
		}
		else
		{
			pCurr = pCurr->next;
		}
	}
}
stack initStack(int data)
{
	stack s;
	s.pTop = new Node;
	s.pTop->key = data;
	s.pTop->next = NULL;
	return s;
}
bool isEmptyStack(stack s)
{
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}
void Push(stack& s, int key)
{
	Node* newNode = createNode(key);
	if (s.pTop == NULL)
	{
		s.pTop = newNode;
		return;
	}
	newNode->next = s.pTop;
	s.pTop = newNode;
}
void PrintStack(stack s)
{
	for (Node* pCurr = s.pTop; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->key << " ";
	}
}
void Pop(stack& s)
{
	if (s.pTop == NULL)
	{
		return;
	}
	if (s.pTop->next == NULL)
	{
		delete s.pTop;
		s.pTop = NULL;
		return;
	}
	Node* tmp = s.pTop;
	s.pTop = s.pTop->next;
	delete tmp;
}
int CountStack(stack s)
{
	int count = 0;
	for (Node* pCurr = s.pTop; pCurr != NULL; pCurr = pCurr->next)
	{
		count++;
	}
	return count;
}
queue initQueue(int data)
{
	queue q;
	q.front = q.rear = new Node;
	q.front->key = q.rear->key = data;
	q.front->next = q.rear->next = NULL;
	return q;
}
void Enqueue(queue& q, int data)
{
	Node* newNode = createNode(data);
	if (q.front == NULL)
	{
		q.front = q.rear = newNode;
		return;
	}
	q.rear->next = newNode;
	q.rear = newNode;
}
void Dequeue(queue& q)
{
	if (q.front == NULL)
	{
		return;
	}
	if (q.front == q.rear)
	{
		delete q.front;
		q.front = q.rear = NULL;
		return;
	}
	Node* tmp = q.front;
	q.front = q.front->next;
	delete tmp;
}
int countQueue(queue q)
{
	int count = 0;
	for (Node* pCurr = q.front; pCurr != NULL; pCurr = pCurr->next)
	{
		count++;
	}
	return count;
}
bool isEmptyQueue(queue q)
{
	if (q.front == NULL)
	{
		return true;
	}
	return false;
}
void printQueue(queue q)
{
	for (Node* pCurr = q.front; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->key << " ";
	}
}
void backtrack(string arr, int n, int count, int start)
{
	if (count == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
		}
		cout << " ";
		return;
	}
	for (int i = start; i <= 9; i++)
	{
		arr += i + '0';
		backtrack(arr, n, count + 1, i + 1);
		arr.pop_back();
	}
}
DNodeFile* createDNodeFile(Examinee data)
{
	DNodeFile* newNode = new DNodeFile;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void addDTailFile(DListFile& lst, Examinee data)
{
	DNodeFile* newNode = createDNodeFile(data);
	if (lst.head == NULL)
	{
		lst.head = newNode;
		lst.tail = newNode;
		return;
	}
	lst.tail->next = newNode;
	newNode->prev = lst.tail;
	lst.tail = newNode;
}
void readFileDLinkedList(DListFile& lst, string fileName)
{
	ifstream fin(fileName.c_str());
	if (!fin.is_open())
	{
		return;
	}
	string tmp;
	getline(fin, tmp);
	while (getline(fin, tmp))
	{
		Examinee examinee;
		stringstream ss(tmp);
		getline(ss, tmp, ',');
		examinee.id = tmp;
		getline(ss, tmp, ',');
		getline(ss, tmp, ',');
		if (tmp == "") examinee.maths = 0;
		else examinee.maths = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.literature = 0;
		else examinee.literature = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.physics = 0;
		else examinee.physics = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.chemistry = 0;
		else examinee.chemistry = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.biology = 0;
		else examinee.biology = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.history = 0;
		else examinee.history = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.geography = 0;
		else examinee.geography = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.civic_education = 0;
		else examinee.civic_education = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.natural_science = 0;
		else examinee.natural_science = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.social_science = 0;
		else examinee.social_science = stof(tmp);
		getline(ss, tmp, ',');
		if (tmp == "") examinee.foreign_language = 0;
		else examinee.foreign_language = stof(tmp);
		addDTailFile(lst, examinee);
	}
}
DNodePokemon* createNode(Pokemon data)
{
	DNodePokemon* newNode = new DNodePokemon;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void addTail(DListPokemon& lst, Pokemon data)
{
	DNodePokemon* newNode = createNode(data);
	if (lst.head == NULL)
	{
		lst.head = newNode;
		lst.tail = newNode;
		return;
	}
	lst.tail->next = newNode;
	newNode->prev = lst.tail;
	lst.tail = newNode;
}
void removeDauNgoacVuongAndDauNgoacKep(string& s)
{
	if (s[0] == '\"' && s[s.length() - 1] == '\"')
	{
		s.erase(0, 1);
		s.erase(s.length() - 1, 1);
	}
	if (s[0] == '[' && s[s.length() - 1] == ']')
	{
		s.erase(0, 1);
		s.erase(s.length() - 1, 1);
		if (s.empty())
		{
			return;
		}
	}
}
void removeSpePunctuation(string& s)
{
	if (s[0] == ' ')
	{
		s.erase(0, 1);
	}
	if (s[0] == '\'' && s[s.length() - 1] == '\'')
	{
		s.erase(0, 1);
		s.erase(s.length() - 1);
	}
	if (s[0] == '\"' && s[s.length() - 1] == '\"')
	{
		s.erase(0, 2);
		s.erase(s.length() - 2);
	}
}
vector<string>Push_Back_Object(string s)
{
	vector<string>results;
	removeDauNgoacVuongAndDauNgoacKep(s);
	if (s.empty())
	{
		return { " " };
	}
	stringstream ss_one_object(s);
	string one_object;
	while (getline(ss_one_object, one_object, ';'))
	{
		removeSpePunctuation(one_object);
		results.push_back(one_object);
	}
	return results;
}
void readFilePokemon(string fileName, DListPokemon& lst)
{
	ifstream fin(fileName.c_str());
	if (!fin.is_open())
	{
		return;
	}
	string rubbish;
	getline(fin, rubbish);
	string one_line;
	Pokemon pokemon;
	while (getline(fin, one_line))
	{
		stringstream ss_one_line(one_line);
		string tmp_name;
		string tmp_type;
		string tmp_abilities;
		string tmp_tier;
		string tmp_hp;
		string tmp_attack;
		string tmp_defense;
		string tmp_speAttack;
		string tmp_speDefense;
		string tmp_speed;
		string tmp_next_evoluation;
		string tmp_move;

		getline(ss_one_line, tmp_name, ',');
		getline(ss_one_line, tmp_type, ',');
		getline(ss_one_line, tmp_abilities, ',');
		getline(ss_one_line, tmp_tier, ',');
		getline(ss_one_line, tmp_hp, ',');
		getline(ss_one_line, tmp_attack, ',');
		getline(ss_one_line, tmp_defense, ',');
		getline(ss_one_line, tmp_speAttack, ',');
		getline(ss_one_line, tmp_speDefense, ',');
		getline(ss_one_line, tmp_speed, ',');
		getline(ss_one_line, tmp_next_evoluation, ',');
		getline(ss_one_line, tmp_move, '\n');

		pokemon.name = tmp_name;
		vector<string>type = Push_Back_Object(tmp_type);
		pokemon.type1 = type[0];
		if (type.size() == 2) pokemon.type2 = type[1];
		pokemon.abilities = Push_Back_Object(tmp_abilities);
		pokemon.tier = tmp_tier;
		pokemon.hp = stoi(tmp_hp);
		pokemon.attack = stoi(tmp_attack);
		pokemon.defense = stoi(tmp_defense);
		pokemon.speAttack = stoi(tmp_speAttack);
		pokemon.speDefense = stoi(tmp_speDefense);
		pokemon.speed = stoi(tmp_speed);
		pokemon.next_evoluation = Push_Back_Object(tmp_next_evoluation);
		pokemon.move = Push_Back_Object(tmp_move);
		addTail(lst, pokemon);

		//Reset
		pokemon.type1 = "";
		pokemon.type2 = "";
		type.clear();
		pokemon.move.clear();
		pokemon.next_evoluation.clear();
		pokemon.abilities.clear();
	}
	fin.close();
}
void printPokemon(DListPokemon lst)
{
	for (DNodePokemon* pCurr = lst.head; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->data.name << " ";
		cout << pCurr->data.type1 << " " << pCurr->data.type2 << " ";
		for (int i = 0; i < pCurr->data.abilities.size(); i++)
		{
			cout << pCurr->data.abilities[i] << "=";
		}
		cout << pCurr->data.tier << " ";
		cout << pCurr->data.hp << " ";
		cout << pCurr->data.attack << " ";
		cout << pCurr->data.defense << " ";
		cout << pCurr->data.speAttack << " ";
		cout << pCurr->data.speDefense << " ";
		cout << pCurr->data.speed << " ";
		for (int i = 0; i < pCurr->data.next_evoluation.size(); i++)
		{
			cout << pCurr->data.next_evoluation[i] << "=";
		}
		for (int i = 0; i < pCurr->data.move.size(); i++)
		{
			cout << pCurr->data.move[i] << "=";
		}
		cout << endl << endl;
	}
}
int countNumsPokemon(string fileName)
{
	ifstream fin(fileName.c_str());
	if (!fin.is_open())
	{
		return 0;
	}
	string rubbish;
	getline(fin, rubbish);
	string tmp;
	int cnt = 0;
	while (getline(fin, tmp))
	{
		cnt++;
	}
	fin.close();
	return cnt;
}
Pokemon*** readFilePokemonPointer(string fileName, int p, int m, int n)
{
	if (p * m * n > countNumsPokemon(fileName))
	{
		return NULL;
	}
	Pokemon*** pokemon = new Pokemon * *[p];
	for (int i = 0; i < p; i++)
	{
		pokemon[i] = new Pokemon* [m];
		for (int j = 0; j < m; j++)
		{
			pokemon[i][j] = new Pokemon[n];
		}
	}
	ifstream fin(fileName.c_str());
	if (!fin.is_open())
	{
		return NULL;
	}
	string rubbish;
	getline(fin, rubbish);
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				string one_line;
				getline(fin, one_line);
				string tmp_name;
				string tmp_type;
				string tmp_abilities;
				string tmp_tier;
				string tmp_hp;
				string tmp_attack;
				string tmp_defense;
				string tmp_speAttack;
				string tmp_speDefense;
				string tmp_speed;
				string tmp_next_evoluation;
				string tmp_move;

				stringstream ss_one_line(one_line);
				getline(ss_one_line, tmp_name, ',');
				getline(ss_one_line, tmp_type, ',');
				getline(ss_one_line, tmp_abilities, ',');
				getline(ss_one_line, tmp_tier, ',');
				getline(ss_one_line, tmp_hp, ',');
				getline(ss_one_line, tmp_attack, ',');
				getline(ss_one_line, tmp_defense, ',');
				getline(ss_one_line, tmp_speAttack, ',');
				getline(ss_one_line, tmp_speDefense, ',');
				getline(ss_one_line, tmp_speed, ',');
				getline(ss_one_line, tmp_next_evoluation, ',');
				getline(ss_one_line, tmp_move, ',');

				pokemon[i][j][k].name = tmp_name;
				vector<string>type = Push_Back_Object(tmp_type);
				pokemon[i][j][k].type1 = type[0];
				if(type.size() == 2) pokemon[i][j][k].type2 = type[1];
				pokemon[i][j][k].abilities = Push_Back_Object(tmp_abilities);
				pokemon[i][j][k].tier = tmp_tier;
				pokemon[i][j][k].hp = stoi(tmp_hp);
				pokemon[i][j][k].attack = stoi(tmp_attack);
				pokemon[i][j][k].defense = stoi(tmp_defense);
				pokemon[i][j][k].speAttack = stoi(tmp_speAttack);
				pokemon[i][j][k].speDefense = stoi(tmp_speDefense);
				pokemon[i][j][k].speed = stoi(tmp_speed);
				pokemon[i][j][k].next_evoluation = Push_Back_Object(tmp_next_evoluation);
				pokemon[i][j][k].move = Push_Back_Object(tmp_move);

			}
		}
	}
	fin.close();
	return pokemon;
}
void printPokemonPointer(Pokemon***& pokemon, int p, int m, int n)
{
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << pokemon[i][j][k].name << " ";
				cout << pokemon[i][j][k].type1 << " " << pokemon[i][j][k].type2 << " ";
				for (int l = 0; l < pokemon[i][j][k].abilities.size(); l++)
				{
					cout << pokemon[i][j][k].abilities[l] << "=";
				}
				cout << pokemon[i][j][k].tier << " ";
				cout << pokemon[i][j][k].hp << " ";
				cout << pokemon[i][j][k].attack << " ";
				cout << pokemon[i][j][k].defense << " ";
				cout << pokemon[i][j][k].speAttack << " ";
				cout << pokemon[i][j][k].speDefense << " ";
				cout << pokemon[i][j][k].speed << " ";
				for (int l = 0; l < pokemon[i][j][k].next_evoluation.size(); l++)
				{
					cout << pokemon[i][j][k].next_evoluation[l] << "=";
				}
				for (int l = 0; l < pokemon[i][j][k].move.size(); l++)
				{
					cout << pokemon[i][j][k].move[l] << "=";
				}
				cout << endl << endl;
			}
		}
	}
}