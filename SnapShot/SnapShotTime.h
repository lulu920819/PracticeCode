#include <string>

using namespace std;

#define DELIME '\n'
#define SPACE " "

class SnapShotTime
{
private:
	string SSDate;
	string SSTime;

public:
	SnapShotTime(string str);
	SnapShotTime();
	~SnapShotTime();

	string getDate();
	void setDate(string _SSDate);
	string getTime();
	void setTime(string _SSTime);
	bool  operator > ( SnapShotTime cur);
	 void operator = (SnapShotTime cur);
private:
	bool bigger(SnapShotTime n1, SnapShotTime n2);
};
