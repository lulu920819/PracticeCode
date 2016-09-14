
#include "Book.h"
using namespace std;

void Book::Print_book(ifstream &input,ofstream &output)
{
	string line,word,tmp;
	while( getline(input,tmp) )
	{
		// first line
		//cout <<line<<endl;
		if(isNewPage)
			print_Page1stLine(output);
		
		// new line 
		string_replace(tmp,"\t","    ");
		line = RemovePreAndLastSpace(tmp);
		//string_replace(tmp,"\t","    ");
		if(line == "")
		{
			if(isNewLine&&!isNewPage)
				print_EmptyLine(output);
			isNewLine = false;
		}
		else
		{
			readLine(output,line);
			isNewLine = true;
		}	
	}

}

void Book::print_EmptyLine(ofstream &output)
{
	output<<endl;
	cur_line++;
	isNewLine = false;
	if(cur_line == line_max)
	{
		isNewPage  = true;
		cur_line = 0;
	}
}

void Book::print_Page1stLine(ofstream &output)
{
	for(int i = 0;i<width_max;i++)
		output<<FirstLineChar;
	output<<endl;

	isNewPage = false;
	isNewLine = false;
	cur_line++;
}

void Book::print_Line(ofstream &output,string s)
{
	if(isNewPage)
	{
		print_Page1stLine(output);
	}
	if(s=="")
		return;
	output<<s<<endl;
		cur_line++;
	if(cur_line == line_max)
	{
		isNewPage  = true;
		isNewLine = false;
		cur_line = 0;
	}
}

void  Book::setPageStyle(string book_format )
{
	if(!book_format .compare("A4") )
	{
		this->line_max = 210/2;
		this->width_max = 297/3;
	}
	else if(!book_format .compare("A3") )
	{
		this->line_max = 297/2;
		this->width_max = 420/3;
	}
	else if(!book_format .compare("TEST") )
	{
		this->line_max = 100;
		this->width_max = 105;
	}
	else  //default A4
	{
		this->line_max = 210/2;
		this->width_max = 297/3;
	}
}

string Book::RemovePreAndLastSpace(string str)
{
	int length = str.size();    
    int i = 0, j = length -1;    
 
    while(i < length && isspace(str[i] ) ){
		i++;
	}    
    
    while(j >= 0 && isspace(str[j])){
		j--;
	}    
    
    if(j<i) 
		return "";   

    return str.substr(i,j-i+1);  

}


int Book::find_split(string str)
{
	int length = str.size();    
    int j = length -1;    

    while(j >= 0&&!isspace(str[j])){
		j--;
	}   

	return j;
}

void Book::string_replace(string&s1,const string&s2,const string&s3)
{
	string::size_type pos=0;
	string::size_type a=s2.size();
	string::size_type b=s3.size();
	while((pos=s1.find(s2,pos))!=string::npos)
	{
		s1.replace(pos,a,s3);
		pos+=b;
	}
}

void Book::readLine(ofstream &output,string line)
{
	string str = RemovePreAndLastSpace(line);
	string newline1,newline2;

	if(str == "")
		return ;

	if(str.length()<=width_max)
		print_Line(output,str);
	else
	{
		if( isspace(str[width_max]) ) // new is space no worry
		{
			newline1 = str.substr(0,width_max);
			readLine(output,newline1);
			newline2 = str.substr(width_max);
			readLine(output,newline2);
		}
		else
		{
			string tmp = str.substr(0,width_max);
			int pos = find_split(tmp);

			newline1 = str.substr(0,pos);
			readLine(output,newline1);

			newline2 = str.substr(pos);
			readLine(output,newline2);
		}
	}
}

