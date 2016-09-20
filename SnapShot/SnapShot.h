#include<map>
#include <vector>
#include <string>
#include <utility>
#define _TEST
using namespace std;

typedef pair<int ,int > Coordinate;

class SnapShot
{
private:
	map<string, Coordinate > LatestStatus;  // AnimalName, X, Y
	string id;
	string curAnimalName;
	Coordinate curCordinate;
	int LineMode;
public:	
	// validate check
	bool isIDLegal(string IDLine);
	bool isTimeLegal(string TimeLine);
	bool isXYLegal(string XYLine,vector<int> &xy_cor);
	bool isXYConflict(vector<int>& xy_cor);
	bool splitXY(string XYLine, vector<string> & result);

	// set and get attribute
	void setID(string _id);
	string getID();

	void setAnimalName(string _AnimalName);
	string getAnimalName();

	void setcurCordinate(int x, int y);
	void updatecurCordinate(Coordinate &preStatus,int x, int y);
	Coordinate getCordinate();

	void setLineMode(int _LineMode);
	int getLineMode();

	void updateLatestStatus(map<string, Coordinate>::iterator  it);
	void addLatestStatus();
	string getLatestStatus();

	// Error
	string InvalidErr();
	string ConflictErr(string id);

	string GetSnapShot(string historyData, string id);

	SnapShot();
	~SnapShot();
};