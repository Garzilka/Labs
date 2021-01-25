/**


*/
/*!
	\brief it's Main
	Это главный файл программы

*/
#include "pch.h"
#include "CCore.h"
ifstream ff;

#define OpenFile(argv)\
{\
	cout << "PreProc Define file start without out";\
	ff = ifstream(argv.c_str());\
	if (argv.size() > 5)\
	{\
std::cout << "\npath = " << argv << "\n"; \
if (!ff.is_open())\
{\
	cout << "\nStop! \nFile not Found! " << "\n"; \
}\
	}\
	else\
	cout << "\nStop! Haven't path! " << "\n"; \
};\

CCore* Core = new CCore();
vector<string> getHelp()
{
	vector<string> Result = { "Help: -h ", "\nHelp: -help", "\nFast Sort: -FF (FROMFILE) + Path + type (Example: -FF C:\TestFolder\Test.txt 1)" };
	vector<string> Result1 = { "\nFast Sort: -RND (RANDOM MASSIVE) + Length + RangeIn + RangeOut (Example: -RND 50 10 200)", "\n" };
	for(string str : Result1)
		Result.push_back(str);
	for (string str : Result)
		cout << str;
	return Result;
}

vector<string> VectorFromFile(string path)
{
	OpenFile(path)
	vector<string> Result;
	string s;
	if (ff.is_open())
		while (getline(ff, s))
			Result = Core->StringToVector(s);

	return Result;
}




void checkParams(vector<string> Params)
{

	for (string str : Params)
	{
		if ((str == "-h"))
			getHelp();
		if ((str == "-help"))
			getHelp();
		if (str == "-FF" && Params.size() > 0)
		{
			Core->setMassive(VectorFromFile(Params[1]));
		}
		if (str == "-RND")
		{
			if (Params.size() > 4)
				Core->Sorting(RandomData(atoi(Params[1].c_str()), atoi(Params[2].c_str()), atoi(Params[3].c_str())), atoi(Params[4].c_str()));
			else if (Params.size() >= 4)
			{
				cout << "No input type. Use default " << Params.size() << " \n";
				Core->Sorting(RandomData(atoi(Params[1].c_str()), atoi(Params[2].c_str()), atoi(Params[3].c_str())));
				
			}
			else
				cout << "Uncorrect! Minimum params 3, your count params: " << Params.size() << " \n";
		}
	}
}

void Testing()
{
#ifdef DEBUG
	//Core->setMassive(VectorFromFile(OpenFile(string(DEFAULT_PATH1))));
	Core->Sorting(RandomData(100, 5000, 5000000), 0);
	assert(Core->isMassiveSorted() == true);
	Core->Sorting(RandomData(15, 5, 10), 1);
	assert(Core->isMassiveSorted() == true);
	cout << "Test completed!\n";
#endif // DEBUG
}
int main(int argc, char* argv[])
{
#ifdef DEBUG
	cout << "Count input params"<<argc << "\n";
	Testing();
	
#endif // DEBUG
	setlocale(LC_ALL, "Russian");	
	vector<string> Params;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			Params.push_back(argv[i]);
		checkParams(Params);
	}
	else
	{
		getHelp();
	}
	cout << "Введите -1 чтобы закончить\n";
	Params.clear();
	string UserInput;
	while (UserInput != "-1")
	{
		UserInput = "";
		char input[200];
		cin.getline(input, sizeof(input));
		UserInput = string(input);
		checkParams(Core->StringToVector(UserInput));
	}
	delete(Core);
	cout << "Close programm\n";

	return 0;
}

