#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct Pokemon
{
	string name;
	vector<string>type;
	vector<string>abilities;
	string tier;
	int hp; int attack; int defense; int specialAttack; int specialDefense; int speed;
	string nextEvoluation;
	vector<string>move;
};
struct DNode
{
	Pokemon data;
	DNode* next;
	DNode* prev;
};
struct DList
{
	DNode* head;
	DNode* tail;
};
DNode* createNode(Pokemon data)
{
	DNode* newNode = new DNode;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void addTail(DList& lst, Pokemon data)
{
	DNode* newNode = createNode(data);
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
void RemoveSemicolon(string& s)
{
	if (s[s.size() - 1] == ';')
	{
		s.pop_back();
	}
}
void RemoveWhiteSpace(string& s)
{
	if (s[0] == ' ')
	{
		for (int i = 1; i < s.size(); i++)
		{
			s[i - 1] = s[i];
		}
		s.pop_back();
	}
}
void RemoveSpecialPunctuation(string& s)
{
	RemoveSemicolon(s);
	RemoveWhiteSpace(s);
	s.pop_back();
	//Delete '
	for (int i = 1; i < s.size(); i++)
	{
		s[i - 1] = s[i];
	}
	s.pop_back();
}
void readFile(DList& lst, string fileName)
{
	ifstream fin(fileName.c_str());
	if (!fin.is_open()) {
		return;
	}
	string tmp;
	getline(fin, tmp);
	Pokemon pokemon;
	while (getline(fin, tmp))
	{
		string s;
		string contain;
		stringstream ss(tmp);

		//Name pokemon
		getline(ss, pokemon.name, ',');
		ss.ignore();

		//Type
		getline(ss, s, ']');
		stringstream ss1(s);
		while (getline(ss1, contain, ';'))
		{
			RemoveSpecialPunctuation(contain);
			pokemon.type.push_back(contain);
		}
		ss.ignore(2);
		//Abilities
		getline(ss, s, ']');
		stringstream ss2(s);
		while (getline(ss2, contain, ';'))
		{
			RemoveSpecialPunctuation(contain);
			pokemon.abilities.push_back(contain);
		}
		ss.ignore();

		getline(ss, pokemon.tier, ',');

		getline(ss, s, ',');
		pokemon.hp = stoi(s);

		getline(ss, s, ',');
		pokemon.attack = stoi(s);

		getline(ss, s, ',');
		pokemon.defense = stoi(s);

		getline(ss, s, ',');
		pokemon.specialAttack = stoi(s);

		getline(ss, s, ',');
		pokemon.specialDefense = stoi(s);

		getline(ss, s, ',');
		pokemon.speed = stoi(s);

		ss.ignore();
		getline(ss, pokemon.nextEvoluation, ']');
		
		ss.ignore(3);

		/*getline(ss, s, ']');
		stringstream ss3(s);
		while (getline(ss3, contain, ';'))
		{
			RemoveSpecialPunctuation(contain);
			pokemon.move.push_back(contain);
		}*/
		getline(ss, s);
		addTail(lst, pokemon);
		pokemon.abilities.clear();
		pokemon.type.clear();
		pokemon.move.clear();
	}
}
void printPokemon(DList lst)
{
	for (DNode* pCurr = lst.head; pCurr != NULL; pCurr = pCurr->next)
	{
		cout << pCurr->data.name << endl;
	}
}
int main()
{
	DList lst;
	lst.head = NULL;
	lst.tail = NULL;
	readFile(lst, "pokemon_temp.csv");
	printPokemon(lst);
}