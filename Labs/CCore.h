#pragma once
#include "pch.h"
#define Iterations 10
class CCore
{
public:
	CCore();
	
	void setMassive(vector<string> Value);
	void Sorting(RandomData Data, int Type = 2);
	void createRandomMassive();
	vector<string> StringToVector(string input);
	void sortByType(int type);

#ifdef DEBUG
	vector<int> getMassive() { return Massive; }
	bool isMassiveSorted()
	{
		for (int i = 0; i < Massive.size() - 1; i++)
			if (Massive[i + 1] < Massive[i])
				return false;
		return true;
	}
#endif // DEBUG
	~CCore();
protected:
	vector<int> Bubblesort(vector<int> input);
	vector<int> Pyramidsort(vector<int> input);
	void setMassive(vector<int> Value)	{		Massive = Value;	}
	void setRandMassive(vector<int> Value) { Random = Value; }
private:

	void PrintMassive(vector<int> massive) 
	{
		for (int value : massive)
			cout << value << " ";
		cout << "\n";
	}
	vector<int> Massive;
	vector<int> Random;
	RandomData CurRandomData = RandomData(0,0,0);
};

extern CCore* Core;

