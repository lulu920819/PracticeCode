#include <iostream>
#include <fstream>
#include <string>
#include<sstream> 

using namespace std;

class Book
{
public:
	Book(string format)
	{
		this->book_format = format;
		setPageStyle(book_format);
		this->FirstLineChar = '=';
		this->cur_line  = 0;
		this->isNewPage=this->isNewLine = true;
	};

	~Book(){};
	void Print_book(ifstream &input,ofstream &output);

private:
	string book_format;
	int line_max;
	int width_max;
	int cur_line;
	char FirstLineChar;
	bool isNewPage;
	bool isNewLine;


	//output page first line
	void print_Page1stLine(ofstream &output);
	//output empty line
	void print_EmptyLine(ofstream &output);
	// set page style A4 A3
	void setPageStyle(string book_format );

	void readLine(ofstream &output,string line);
	void print_Line(ofstream &output,string s);
	string RemovePreAndLastSpace(string str);
	void string_replace(string&s1,const string&s2,const string&s3);
	int Book::find_split(string str);
};
