# Top 10 Tweet

*My school course project from 2017 :)*

**Includes:**
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

wordNode: Keep structure of linked list nodes keep word , word count and link.
struct wordNode
{
	wordNode *link;
	int countOfWord = 0;
	string word;
};
hash[100]: Keep sentences in file.
string hash[100];
hash array index is determined by hashTable function get order of line and calculate mode operation with 100;
int top10Tweet::hashTable(int index)
{
	return index % 100;
}

Linked list: Keep words and counts in file.
wordNode *first, *last;

Arrays: Keep  ten most frequently using words and words counts.
int wordCounts[10];
string words[10];


**FUNCTIONS:**

void top10Tweet::project(string projectfileName, string projectfileFormat)
{
	read(projectfileName, projectfileFormat);
	cleanerForPunctuationMarks();
	readFromHash();
	addTopTenSortList();
	printTopTen();
}

project(string projectfileName, string projectfileFormat) function is my main function which make this search and sort operations with functions which is called in project() function.

Called Functions in Project() Function:
1- read(projectfileName, projectfileFormat);
2- cleanerForPunctuationMarks();
3- readFromHash();
4- addTopTenSortList();
5- printTopTen();

1- read(projectfileName, projectfileFormat);

read() function create an object (ifstream readF;) , readF object open the file with open() function (readF.open(fileName + "." + fileFormat, ios::in);) and then readF object read with getline(readF, currentString); function but jump first fourth string and then save to hash[100] string array fifth string sentence which is called “tweet” with put(counterOfLine, currentString); function and then increase hash array index with counterOfLine++; statement in each return on loop.

2- cleanerForPunctuationMarks();

cleanerForPunctuationMarks() function travel in hash array with visit any index. Function crate a string test = hash[i]; and keep hash array elements then delete  punctuation marks with switch-case structure. Finally save to hash array again.
/*
switch (test[i])
{
			.
			.
			.
	case 'Punctuation Marks':
		test[i] = '';
		break;
			.
			.
			.
	default:
		break;
}
*/


3- readFromHash();

readFromHash(); function create a string variable and keep hash array elements(sentences) and split by words then call addOneTimesAndCount(word); .On the other hand, this function delete any stopping words in stopping words array.
	
addOneTimesAndCount(word);

Keep words and change their upper char to lower char. Then save to linked list which is keeping by wordNode *first, *last; pointers. If word already keeping in linked list increase word count in node.

4- addTopTenSortList();

Travel on linked list(*first , *last) and find most frequently using words then save to                      int wordCounts[10]; and string words[10]; arrays simultaneously.  

5- printTopTen();

Print int wordCounts[10]; and string words[10]; arrays simultaneously.
	OUTPUT
		<wordCounts[i]>  <words[i]>
