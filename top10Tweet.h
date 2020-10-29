#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


struct wordNode
{
	wordNode *link;
	int countOfWord = 0;
	string word;
};
class top10Tweet
{
private:
	string hash[100];//HASH TABLE STRING ARRAY
	wordNode *first, *last;
	int wordCounts[10];
	string words[10];
	//STOPPING WORDS ARRAY
	const string a[58] = { "a","abroad","according","accordingly","across","actually","adj","after","afterwards","again","against","ago","ahead","ain't","all","allow","allows","almost","alone","along","alongside","already","also","although","always","am","amid","amidst","among","amongst","an","and","another","any","anybody","anyhow","anyone","anything","anyway","anyways","anywhere","apart","appear","appreciate","appropriate","are","aren't","around","as","a's","aside","ask","asking","associated","at","available","away","awfully" };
	const string b[28] = { "b","back","backward","backwards","be","became","because","become","becomes","becoming","been","before","beforehand","begin","behind","being","believe","below","beside","besides","best","better","between","beyond","both","brief","but","by" };
	const string c[32] = { "c","came","can","cannot","cant","can't","caption","cause","causes","certain","certainly","changes","clearly","c'mon","co","co.","com","come","comes","concerning","consequently","consider","considering","contain","containing","contains","corresponding","could","couldn't","course","c's","currently" };
	const string d[19] = { "d","dare","daren't","definitely","described","despite","did","didn't","different","directly","do","does","doesn't","doing","done","don't","down","downwards","during" };
	const string e[28] = { "e","each","edu","eg","eight","eighty","either","else","elsewhere","end","ending","enough","entirely","especially","et","etc","even","ever","evermore","every","everybody","everyone","everything","everywhere","ex","exactly","example","except" };
	const string f[23] = { "f","fairly","far","farther","few","fewer","fifth","first","five","followed","following","follows","for","forever","former","formerly","forth","forward","found","four","from","further","furthermore" };
	const string g[13] = { "g","get","gets","getting","given","gives","go","goes","going","gone","got","gotten","greetings" };
	const string h[37] = { "h","had","hadn't","half","happens","hardly","has","hasn't","have","haven't","having","he","he'd","he'll","hello","help","hence","her","here","hereafter","hereby","herein","here's","hereupon","hers","herself","he's","hi","him","himself","his","hither","hopefully","how","howbeit","however","hundred" };
	const string istp[31] = { "i","i'd","ie","if","ignored","i'll","i'm","immediate","in","inasmuch","inc","inc.","indeed","indicate","indicated","indicates","inner","inside","insofar","instead","into","inward","is","isn't","it","it'd","it'll","its","it's","itself","i've" };
	const string j[2] = { "j","just" };
	const string k[7] = { "k","keep","keeps","kept","know","known","knows" };
	const string l[23] = { "l","ll","last","lately","later","latter","latterly","least","less","lest","let","let's","like","liked","likely","likewise","little","look","looking","looks","low","lower","ltd" };
	const string m[30] = { "m","made","mainly","make","makes","many","may","maybe","mayn't","me","mean","meantime","meanwhile","merely","might","mightn't","mine","minus","miss","more","moreover","most","mostly","mr","mrs","much","must","mustn't","my","myself" };
	const string n[34] = { "n","name","namely","nd","near","nearly","necessary","need","needn't","needs","neither","never","neverf","neverless","nevertheless","new","next","nine","ninety","no","nobody","non","none","nonetheless","noone","no-one","nor","normally","not","nothing","notwithstanding","novel","now","nowhere" };
	const string o[31] = { "o","obviously","of","off","often","oh","ok","okay","old","on","once","one","ones","one's","only","onto","opposite","or","other","others","otherwise","ought","oughtn't","our","ours","ourselves","out","outside","over","overall","own" };
	const string p[14] = { "p","particular","particularly","past","per","perhaps","placed","please","plus","possible","presumably","probably","provided","provides" };
	const string q[4] = { "q","que","quite","qv" };
	const string r[15] = { "r","rather","rd","re","really","reasonably","recent","recently","regarding","regardless","regards","relatively","respectively","right","round" };
	const string s[55] = { "s","said","same","saw","say","saying","says","second","secondly","see","seeing","seem","seemed","seeming","seems","seen","self","selves","sensible","sent","serious","seriously","seven","several","shall","shan't","she","she'd","she'll","she's","should","shouldn't","since","six","so","some","somebody","someday","somehow","someone","something","sometime","sometimes","somewhat","somewhere","soon","sorry","specified","specify","specifying","still","sub","such","sup","sure" };
	const string t[71] = { "t","take","taken","taking","tell","tends","th","than","thank","thanks","thanx","that","that'll","thats","that's","that've","the","their","theirs","them","themselves","then","thence","there","thereafter","thereby","there'd","therefore","therein","there'll","there're","theres","there's","thereupon","there've","these","they","they'd","they'll","they're","they've","thing","things","think","third","thirty","this","thorough","thoroughly","those","though","three","through","throughout","thru","thus","till","to","together","too","took","toward","towards","tried","tries","truly","try","trying","t's","twice","two" };
	const string u[21] = { "u","un","under","underneath","undoing","unfortunately","unless","unlike","unlikely","until","unto","up","upon","upwards","us","use","used","useful","uses","using","usually" };
	const string v[9] = { "v","value","various","versus","very","via","viz","vs","ve" };
	const string w[58] = { "w","want","wants","was","wasn't","way","we","we'd","welcome","well","we'll","went","were","we're","weren't","we've","what","whatever","what'll","what's","what've","when","whence","whenever","where","whereafter","whereas","whereby","wherein","where's","whereupon","wherever","whether","which","whichever","while","whilst","whither","who","who'd","whoever","whole","who'll","whom","whomever","who's","whose","why","will","willing","wish","with","within","without","wonder","won't","would","wouldn't" };
	const string x[1] = { "x" };
	const string y[12] = { "y","yes","yet","you","you'd","you'll","your","you're","yours","yourself","yourselves","you've" };
	const string z[2] = { "z","zero" };
public:
	//CONSTRUCTOR
	top10Tweet();
	//PROJECT
	void project(string, string);
	//READING FUNCTION [get tweets from file]
	void read(string, string);
	//HASH TABLE FUNCTIONS
	int hashTable(int);//prepare to array index..
	string get(int);//return value in keyValue index else return null
	string put(int, string);//return new value in keyValue index else return null
	void printValueHashTable();
	void cleanerForPunctuationMarks();
	//***********************************************************
	//***********************************************************
	//GET WORD FROM HASH(100) ARRAY TO WORDS LINKED LIST
	void readFromHash();//read and add only one times but with counting
	void addOneTimesAndCount(string currentWord);
	bool isEmpty();
	void initializeList(string);
	bool isInList(string);
	bool stopWord(string);
	bool searchInLinkedList(string currentWord);
	void deleteForMaxWord(string currentWord);
	void print();
	//***********************************************************
	//***********************************************************
	//FOR FIND TOP 10 WORDS
	void initializeTopTenList();
	bool isEmptyTopTen();
	void addTopTenSortList();
	bool isFullTopTen();
	void printTopTen();
};
