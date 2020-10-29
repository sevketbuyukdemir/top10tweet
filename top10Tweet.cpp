#include "top10Tweet.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


top10Tweet::top10Tweet()
{
	first = NULL;
	last = NULL;

	//initialize hash table array..
	for (int i = 0; i < 100; i++) {
		hash[i] = "";
	}
}
//***********************************************************
//***********************************************************
//PROJECT::
//***********************************************************
//***********************************************************
void top10Tweet::project(string projectfileName, string projectfileFormat)
{
	read(projectfileName, projectfileFormat);
	cleanerForPunctuationMarks();
	readFromHash();
	addTopTenSortList();
	printTopTen();
}
//***********************************************************
//***********************************************************
//cleanerForPunctuationMarks() Function is put space to
//punctuation marks for easy reading..
//***********************************************************
//***********************************************************
void top10Tweet::cleanerForPunctuationMarks()
{
	for (int i = 0; i<100; i++)
	{
		string test = hash[i];
		int len = (int)test.length();
		for (int i = 0; i < len; i++)
		{
			switch (test[i])
			{
			case '"':
				test[i] = ' ';
				break;
			case '.':
				test[i] = ' ';
				break;
			case '?':
				test[i] = ' ';
				break;
			case '*':
				test[i] = ' ';
				break;
			case '@':
				test[i] = ' ';
				break;
			case ',':
				test[i] = ' ';
				break;
			case '\'':
				test[i] = ' ';
				break;
			case ':':
				test[i] = ' ';
				break;
			case ';':
				test[i] = ' ';
				break;
			case '!':
				test[i] = ' ';
				break;
			case '(':
				test[i] = ' ';
				break;
			case ')':
				test[i] = ' ';
				break;
			case '{':
				test[i] = ' ';
				break;
			case '}':
				test[i] = ' ';
				break;
			case '#':
				test[i] = ' ';
				break;
			case '+':
				test[i] = ' ';
				break;
			case '-':
				test[i] = ' ';
				break;
			case '/':
				test[i] = ' ';
				break;
			case '_':
				test[i] = ' ';
				break;
			case '=':
				test[i] = ' ';
				break;
			case '\\':
				test[i] = ' ';
				break;
			case '&':
				test[i] = ' ';
				break;
			case '$':
				test[i] = ' ';
				break;
			case '^':
				test[i] = ' ';
				break;
			case '%':
				test[i] = ' ';
				break;
			case '|':
				test[i] = ' ';
				break;
			case '~':
				test[i] = ' ';
				break;
			case '[':
				test[i] = ' ';
				break;
			case ']':
				test[i] = ' ';
				break;
			default:
				break;
			}

		}
		hash[i] = test;
	}
}
//***********************************************************
//***********************************************************
//READING FUNCTION ::read(string fileName,string fileFormat)
//read file and save to hash[] array the tweet..
void top10Tweet::read(string fileName, string fileFormat)
{
	ifstream readF;//read object..
	readF.open(fileName + "." + fileFormat, ios::in);//only read operation..
	int counterOfLine = 0;//index counter..
	string currentString;//keep string from text file..
	while (!readF.eof())//read until end of file..
	{
		for (int i = 0;i<5;i++)//to reach tweet text this loop turn five times
		{
			getline(readF, currentString, ',');//get line from readF object
											   //and save to currentString
											   //with split by comma ','
		}
		getline(readF, currentString);
		put(counterOfLine, currentString);//Save to hash[100] array..
		counterOfLine++;//increase hash[100] array index..
	}
	readF.close();
}
//***********************************************************
//***********************************************************
//HASH TABLE :: hashTable(int index) , get(int keyValue)
//put(int keyValue , string value) , printValueHashTable()
// functions..
//***********************************************************
//***********************************************************
//prepare to array index..
//index number stay in 0-100 interval
int top10Tweet::hashTable(int index)
{
	return index % 100;
}
//return value in keyValue index else return null
string top10Tweet::get(int keyValue)
{
	return hash[hashTable(keyValue)];
}
//return new value in keyValue index else return null
string top10Tweet::put(int keyValue, string value)
{
	hash[hashTable(keyValue)] = (get(keyValue) + " " + value);
	return hash[hashTable(keyValue)];
}
void top10Tweet::printValueHashTable()
{
	for (int i = 0; i<100; i++)
	{
		cout << hash[i] << endl;
	}
}
//***********************************************************
//***********************************************************
//LINKED LIST FUNCTIONS :: void readFromHash();
//void addOneTimesAndCount(string);void compareWithOthers();
//***********************************************************
//***********************************************************
//GET WORD FROM HASH(100) ARRAY TO WORDS LINKED LIST
void top10Tweet::readFromHash()//read and add only word by word
{
	for (int i = 0; i < 100; i++)
	{
		string sentence = hash[i];
		char Char;
		string word;
		for (int i = 0; i < sentence.length() + 1; i++)
		{
			Char = sentence[i];
			if (Char == ' ')
			{
				if (stopWord(word))
				{
					word = "";
				}
				else
				{
					addOneTimesAndCount(word);
				}
				word = "";
			}
			else if (i == sentence.length())
			{
				if (stopWord(word))
				{
					word = "";
				}
				else
				{
					addOneTimesAndCount(word);
				}
				word = "";
			}
			else
			{
				word += Char;
			}
		}
	}
}
void top10Tweet::addOneTimesAndCount(string current)
{
	string currentWord;
	std::locale CharcurrentWord;
	for (int i1 = 0; i1 < current.length(); i1++)
	{
		currentWord += tolower(current[i1]);
	}
	if (isEmpty())
	{
		initializeList(currentWord);
	}
	else if (isInList(currentWord))
	{
		wordNode *pNode = new wordNode();
		pNode = first;
		while (pNode->link != NULL)
		{
			if (pNode->word == currentWord)
			{
				pNode->countOfWord++;
			}
			pNode = pNode->link;
		}
	}
	else
	{
		wordNode *newWord = new wordNode();
		newWord->link = NULL;
		newWord->word = currentWord;
		newWord->countOfWord++;
		last->link = newWord;
		last = newWord;
	}
}
bool top10Tweet::isEmpty()
{
	if (first == NULL && last == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void top10Tweet::initializeList(string current)
{
	string currentWord;
	std::locale CharcurrentWord;
	for (int i1 = 0; i1 < (current.length()); i1++)
	{
		currentWord += tolower(current[i1]);
	}
	if (isEmpty())
	{

		wordNode *p = new wordNode();
		p->word = currentWord;
		p->countOfWord++;
		p->link = NULL;
		first = p;
		last = p;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}
bool top10Tweet::isInList(string current)
{
	string currentWord;
	std::locale CharcurrentWord;
	for (int i1 = 0; i1 < (current.length()); i1++)
	{
		currentWord += tolower(current[i1]);
	}
	wordNode *pNode = new wordNode();
	pNode = first;
	while (pNode->link != NULL)
	{
		if (pNode->word == currentWord)
		{
			return true;
		}
		else
		{
			pNode = pNode->link;
		}
	}
	return false;
}
bool top10Tweet::stopWord(string currentWord)
{
	if (currentWord.empty())
	{
		return true;
	}
	std::locale CharNewWord;
	string newWord;
	for (int i1 = 0; i1 < (currentWord.length()); i1++)
	{
		newWord += tolower(currentWord[i1]);
	}
	char Char = newWord[0];

	switch (Char)
	{
	case '\0':
		return true;
	case 'a'://const string a[58]
		for (int i = 0; i<58;i++)
		{
			if (a[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'b'://const string b[28]
		for (int i = 0; i<28;i++)
		{
			if (b[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'c'://const string c[32]
		for (int i = 0; i<32;i++)
		{
			if (c[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'd'://const string d[19]
		for (int i = 0; i<19;i++)
		{
			if (d[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'e'://const string e[28]
		for (int i = 0; i<28;i++)
		{
			if (e[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'f'://const string f[23]
		for (int i = 0; i<23;i++)
		{
			if (f[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'g'://const string g[13]
		for (int i = 0; i<13;i++)
		{
			if (g[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'h'://const string h[37]
		for (int i = 0; i<37;i++)
		{
			if (h[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'i'://const string istp[31]
		for (int i = 0; i<31;i++)
		{
			if (istp[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'j'://const string j[2]
		for (int i = 0; i<2;i++)
		{
			if (j[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'k'://const string k[7]
		for (int i = 0; i<7;i++)
		{
			if (k[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'l'://const string l[23]
		for (int i = 0; i<23;i++)
		{
			if (l[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'm'://const string m[30]
		for (int i = 0; i<30;i++)
		{
			if (m[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'n'://const string n[34]
		for (int i = 0; i<34;i++)
		{
			if (n[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'o'://const string o[31]
		for (int i = 0; i<31;i++)
		{
			if (o[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'p'://const string p[14]
		for (int i = 0; i<14;i++)
		{
			if (p[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'q'://const string q[4]
		for (int i = 0; i<4;i++)
		{
			if (q[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'r'://const string r[15]
		for (int i = 0; i<15;i++)
		{
			if (r[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 's'://const string s[55]
		for (int i = 0; i<55;i++)
		{
			if (s[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 't'://const string t[71]
		for (int i = 0; i<71;i++)
		{
			if (t[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'u'://const string u[21]
		for (int i = 0; i<21;i++)
		{
			if (u[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'v'://const string v[9]
		for (int i = 0; i<9;i++)
		{
			if (v[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'w'://const string w[58]
		for (int i = 0; i<58;i++)
		{
			if (w[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'x'://const string x[1]
		for (int i = 0; i<1;i++)
		{
			if (x[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'y'://const string y[12]
		for (int i = 0; i<12;i++)
		{
			if (y[i] == newWord)
			{
				return true;
			}
		}
		return false;
	case 'z'://const string z[2]
		for (int i = 0; i<2;i++)
		{
			if (z[i] == newWord)
			{
				return true;
			}
		}
		return false;
	default:
		return false;
	}
}
bool top10Tweet::searchInLinkedList(string currentWord)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		wordNode *iterator = new wordNode();
		iterator = first;
		while (iterator->link != NULL)
		{
			if (iterator->word == currentWord)
			{
				return true;
			}
			else
			{
				iterator = iterator->link;
			}
		}
		return false;
	}
}
void top10Tweet::deleteForMaxWord(string currentWord)
{
	if (searchInLinkedList(currentWord))
	{
		wordNode *iterator = new wordNode();
		iterator = first;
		if (first->word == currentWord)
		{
			first = first->link;
		}
		else if (last->word == currentWord)
		{
			last = NULL;
			wordNode *p = new wordNode();
			p = first;
			while (p->link != NULL)
			{
				p = p->link;
				if (p->link == NULL)
				{
					last = p;
					break;
				}
			}
		}
		else
		{
			while (iterator->link != NULL)
			{
				if (iterator->word == currentWord)
				{
					iterator = iterator->link->link;
				}
				else
				{
					iterator = iterator->link;
				}
			}
		}
	}
	else
	{
		cout << "Delete is failed.." << endl;
	}
}
void top10Tweet::print()
{
	if (isEmpty())
	{
		cout << "List is empty." << endl;
	}
	else
	{
		string printingData;
		int count = 0;
		int wordCount;
		wordNode *printer = new wordNode;
		printer = first;
		while (printer->link != NULL)
		{
			count++;
			printingData = printer->word;
			wordCount = printer->countOfWord;
			cout << count << " - " << printingData << " -" << wordCount << endl;
			printer = printer->link;
			if (printer->link == NULL)
			{
				break;
			}
		}
	}
}
//***********************************************************
//***********************************************************
//FOR FIND TOP 10 WORDS
void top10Tweet::initializeTopTenList()
{
	for (int i = 0; i < 10;i++)
	{
		words[i] = "";
		wordCounts[i] = 0;
	}
}
void top10Tweet::addTopTenSortList()
{
	initializeTopTenList();
	wordNode *iterator = new wordNode();
	iterator = first;
	while (iterator->link != NULL)
	{
		if ((iterator->countOfWord) < wordCounts[0])
		{
		}
		else if ((iterator->countOfWord) > wordCounts[9])
		{
			int current[9];
			string currentWords[9];
			for (int i = 1; i < 10; i++)
			{
				current[i - 1] = wordCounts[i];
				currentWords[i - 1] = words[i];
			}
			for (int i = 0; i < 9; i++)
			{
				wordCounts[i] = current[i];
				words[i] = currentWords[i];
			}
			wordCounts[9] = iterator->countOfWord;
			words[9] = iterator->word;
		}
		else
		{
			int newCount = iterator->countOfWord;
			string newWord = iterator->word;
			for (int i = 0;i<10;i++)
			{
				if (newCount<wordCounts[i] && newCount>wordCounts[i - 1])
				{
					for (int j = 1;j<i;j++)
					{
						wordCounts[j - 1] = wordCounts[j];
						words[j - 1] = words[j];
					}
					words[i - 1] = newWord;
					wordCounts[i - 1] = newCount;
					break;
				}
			}
		}
		iterator = iterator->link;
	}
}
bool top10Tweet::isEmptyTopTen()
{
	if ((words[0] == "") && (wordCounts[0] == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool top10Tweet::isFullTopTen()
{
	if ((words[9] != "") && (wordCounts[9] != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void top10Tweet::printTopTen()
{
	cout << "TOP 10 WORDS:" << endl;
	int count = 1;
	for (int i = 9; i >= 0; i -= 1)
	{
		cout << count << " -> " << "<" << wordCounts[i] << ">" << " " << "<" << words[i] << ">" << endl;
		count++;
	}
}
//***********************************************************
//***********************************************************