#include "pch.h"
#include "CCore.h"

/*!
\brief  онструктор по умолчанию

	—уществует
*/
CCore::CCore()
{
}
/*!
\brief setMassive
\param[in] Value - массив строк

ѕерегруженна€ функци€ - принимает в себ€ вектор строк, конвентирует в int и сохран€ет данные в приватный вектор int
*/
void CCore::setMassive(vector<string> Value)
{
	vector<int> Return;
	for(string str : Value)
	{
		int i = 0;
		char Buffer[DefaultSize];
		while (i < str.length())
		{
			Buffer[i] += str[i];
			i++;
			if (str[i] == ' ' || i >= str.length())
			{
				Return.push_back(atoi(Buffer));
				memset(Buffer, 0, sizeof(Buffer));
				i++;
			}
			
		}
	}
	
	setRandMassive(Return);
	cout << "From File: ";
	PrintMassive(Return);
	sortByType(2);
	
}

/*!
\brief Bubblesort
\param[in] Value - вектор целочисленных
\param[out] Value - отсортированный вектор целочисленных

	ѕринимает в себ€ вектор целочисленных, сортирует методом пузырька
*/
vector<int> CCore::Bubblesort(vector<int> input)
{
	vector<int> result = input;
	clock_t start = clock();
	for (int i = 0; i < result.size(); i++)
	{
		int temp = 0;
		for (int j = i + 1; j < result.size(); j++)
		{
			if (result[i] > result[j])
			{
				temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
		}
	}
	clock_t end = clock();
	PrintMassive(result);
	setMassive(result);
	cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
	return result;
}
vector<int> heapify(vector<int> arr, int n, int i)
{
	int largest = i;
	// »нициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // ≈сли левый дочерний элемент больше корн€
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// ≈сли правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// ≈сли самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// –екурсивно преобразуем в двоичную кучу затронутое поддерево
		arr = heapify(arr, n, largest);
	}
	return arr;
}
/*!
\brief Pyramidsort
\param[in] Value - вектор целочисленных
\param[out] Value - отсортированный вектор целочисленных

	ѕринимает в себ€ вектор целочисленных, сортирует методом пирамиды
*/
vector<int> CCore::Pyramidsort(vector<int> arr)
{
	setMassive(arr);
	int n = arr.size();
	clock_t start = clock();
	// ѕостроение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		arr = heapify(arr, n, i);

	// ќдин за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// ѕеремещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		arr = heapify(arr, i, 0);
	}
	clock_t end = clock();
	PrintMassive(arr);
	cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
	setMassive(arr);
	return arr;
}

/*!
\brief sortByType
\param[in] Value - “ип сортировки

	—ортировка по типу
	0 - сортировка методом пузырька
	1 - сортировка методом пирамиды
	2 - сортировка пузырька и пирамиды
	default - сортировка пузырька и пирамиды
*/
void CCore::sortByType(int type)
{
	switch (type)
	{
	case 0:
	{
		cout << "Bubble sort: ";
		setMassive(Bubblesort(Random));
	}
	case 1:
	{
		cout << "Pyramid sort: ";
		setMassive(Pyramidsort(Random));
	}
	case 2:
	{
		cout << "Bubble sort: ";
		setMassive(Bubblesort(Random));
		cout << "Pyramid sort: ";
		setMassive(Pyramidsort(Random));

	}
	}
}

/*!
\brief createRandomMassive
\param[in] Data - данные рандомизации (размер вектора, диапозон цифр (начало, конец))
\param[in] Type - тип сортировки

	—ортировка по типу
	0 - сортировка методом пузырька
	1 - сортировка методом пирамиды
	2 - сортировка пузырька и пирамиды
	default - сортировка пузырька и пирамиды
*/
void CCore::createRandomMassive(RandomData Data, int Type)
{
	if (Data.Length > 0)
	{
		vector<int> Return;
		for (int i = 0; i < Data.Length; i++)
			Return.push_back(Data.RangeIn + (std::rand() % (Data.RangeOut - Data.RangeIn + 1)));
		setRandMassive(Return);
		cout << "\n\nCreated: ";
		PrintMassive(Random);
		sortByType(Type);
	}
}
/*!
\brief StringToVector
\param[in] input - строка
\param[out] Result -вектор строк

	разбиение строки на массив строк через пробел
*/
vector<string> CCore::StringToVector(string input)
{
	vector<string> Result;
	string buffer;
	for (int i = 0; i < input.length(); i++)
	{
		
		if (input[i] == ' ' || i + 1 >= input.length())
		{
			Result.push_back(buffer);
			buffer = "";
			i++;
		}
		buffer += input[i];
	}
	return Result;
}
/*!
\brief ~CCore
ƒеструктор - существует.
*/
CCore::~CCore()
{
}
