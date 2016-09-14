#include "Book.h"
using namespace std;

int main()
{

	string infileName = "9.in";
	string outfileName = "9.out";


	ifstream infile;
	ofstream outfile;
	infile.open(infileName.c_str());
	if(!infile)
	{
		cerr<<"can't open file"<<infileName<<endl;
		return -1;
	}
	outfile.open(outfileName.c_str());
	if(!outfile)
	{
		cerr<<"can't open file"<<outfile<<endl;
		return -1;
	}

	Book book1 = Book("TEST");
	book1.Print_book(infile,outfile);

	infile.close();
	outfile.close();


	return 0;
}