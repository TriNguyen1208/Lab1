#include<iostream>
#include<fstream>
#include"function.h"
#include <string>
using namespace std;

int main()
{
	vector<Examinee>value = readExamineeList("data.txt");
	writeScores(value, "out.txt");
}