#include<iostream>
#include<fstream>
#include"function.h"
#include <string>
using namespace std;

void backtrack(string arr, int n, int count = 0, int start = 0)
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
int main()
{
	DList lst = createDList(NULL);
	addDTail(lst, 7);
	addDTail(lst, 6);
	addDTail(lst, 5);
	addDTail(lst, 4);
	removeDAfter(lst, 4);
	printDList(lst);
}