#include<map>
#include <vector>
#include <string>
#include <utility>

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
	bool isResult;
	
	bool isIDLegal(string IDLine);
	bool isTimeLegal(string TimeLine);
	bool isXYLegal(string XYLine);
	bool isXYConflict(vector<int> XY_move);

	void setID(string _id);
	string getID();

	void setAnimalName(string _AnimalName);
	string getAnimalName();

	// Error
	void InvalidErr();
	void ConflictErr();

	string getResult();
public:
	string GetSnapShot(string historyData, string id);

	SnapShot();
	~SnapShot();
};