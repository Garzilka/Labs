/**


*/

#include "pch.h"
#include "CCore.h"
ifstream ff;
/*!
	\brief Макрос открытия файла
	\version 1.0.0
	\warning варианты неудачи - файл не найден, не введен путь или он короче 5 символов
	\param[in] argv - Путь
	Задача OpenFile - Открытие файла по указанному пути, в случае неудачи вывод информации в консоль
*/
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
/*!
	\brief Вывод справки
	\version 1.0.0

	Help: -h
	Help: -help
	Fast Sort: -FF (FROMFILE) + Path + type (Example: -FF C:TestFolderTest.txt 1)
	Fast Sort: -RND (RANDOM MASSIVE) + Length + RangeIn + RangeOut (Example: -RND 50 10 200)

*/
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
/*!
	\brief Vector from file
	\version 1.0.0
	\param[in] path - путь к файлу

	Vector from file - разбиение строки на массив строк через пробел

*/
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



/*!
	\brief checkParams
	\version 1.0.0
	\param[in] Params - вектор параметров
	\warning - минимальное колличество параметров - 3, если параметры описаны неправильно выведится ошибка "Uncorrect! Parameters are incorrect or not entered"
	checkParams - обработка входящих параметров

*/
void checkParams(vector<string> Params)
{

	for (string str : Params)
	{
		if ((str == "-h"))
		{
			getHelp();
			return;
		}
		if ((str == "-help"))
		{
			getHelp();
			return;
		}
		if (str == "-FF" && Params.size() > 0)
		{
			Core->setMassive(VectorFromFile(Params[1]));
			return;
		}
		if (str == "-RND")
		{
			if (Params.size() > 4)
			{
				Core->createRandomMassive(RandomData(atoi(Params[1].c_str()), atoi(Params[2].c_str()), atoi(Params[3].c_str())), atoi(Params[4].c_str()));
				return;
			}
			else if (Params.size() >= 4)
			{
				cout << "No input type. Use default " << Params.size() << " \n";
				Core->createRandomMassive(RandomData(atoi(Params[1].c_str()), atoi(Params[2].c_str()), atoi(Params[3].c_str())));
				return;
				
			}
			else
				cout << "Uncorrect! Minimum params 3, your count params: " << Params.size() << " \n";
		}
	}
	cout << "Uncorrect! Parameters are incorrect or not entered \n";
}
/*!
	\brief Testing
	\version 1.0.0

	Testing - Unit тесты
	В программе реализованы две проверки, только на сортировки. 
	Работают только при включенной директиве DEBUG

*/
void Testing()
{
#ifdef DEBUG
	Core->createRandomMassive(RandomData(15, 5, 10), 0);
	//Проверка корректности сортировки пузырьком
	assert(Core->isMassiveSorted() == true);
	Core->createRandomMassive(RandomData(15, 5, 10), 1);
	//Проверка корректности сортировки пирамидой
	assert(Core->isMassiveSorted() == true);
	cout << "Test completed!\n";
#endif // DEBUG
}

/*!
	\brief it's Main
	\version 1.0.0
	\param[in] argc - количество входящих параметров
	\param[in] argv - параметры

	Задача main - вывод справки, обработка запросов пользователя

*/
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

