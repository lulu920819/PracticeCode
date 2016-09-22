#include<map>
#include <vector>
#include <string>
#include <utility>
#include "SnapShotTime.h"
#define _TEST

using namespace std;

typedef pair<int ,int > Coordinate;
typedef map<string,Coordinate> StatusInfo;

class SnapShot
{
private:
	StatusInfo LatestStatus;  // AnimalName, X, Y
	string id;
	string curAnimalName;
	Coordinate curCordinate;
	int LineMode;
	SnapShotTime LatestTime; 

private:
	// Error
	string InvalidErr();
	string ConflictErr(string id);

public:	
	// validate check
	bool isIDLegal(string IDLine);
	bool isTimeLegal(string TimeLine);
	bool isTimeConflict(string TimeLine);
	bool isXYLegal(string XYLine,vector<int> &xy_cor);
	bool isXYConflict(vector<int>& xy_cor);
	bool splitXY(string XYLine, vector<string> & result);

	// set and get attribute
	void setID(string _id);
	string getID();

	void setLatestTime(SnapShotTime _LatestTime);
	SnapShotTime getLastestTime();

	void setAnimalName(string _AnimalName);
	string getAnimalName();

	void setcurCordinate(int x, int y);
	void updatecurCordinate(Coordinate &preStatus,int x, int y);
	Coordinate getCordinate();

	void setLineMode(int _LineMode);
	int getLineMode();

	void updateLatestStatus(StatusInfo::iterator  it);
	void addLatestStatus();
	string getLatestStatusString();
	StatusInfo& getLatestStatus();


	string GetSnapShot(string historyData, string id);

	SnapShot();
	~SnapShot();
};