#include "pch.h"
#include "CCore.h"

/*!
\brief Тест2
	Тест2
	Test2
*/
CCore::CCore()
{
}

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
vector<int> CCore::Bubblesort(vector<int> input)
{
	vector<int> result = input;
	float allTime = 0.0f;
	float CurTime = 0.0f;
	clock_t start;
	clock_t end;
	for (int i = 0; i < Iterations; i++)
	{
		start = clock();
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
		end = clock();
		CurTime = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Iteration time: " << CurTime << "\t Step - " << i << "\n";
		allTime += CurTime;

	}
	cout << "Full time: " << allTime << "\n";
	cout << "Average time: " << allTime / Iterations << "\n";
	if (input.size() < 201)
		PrintMassive(result);
	else
		cout << "Massive is very long\n";
	setMassive(result);
	return result;
}
vector<int> heapify(vector<int> arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		arr = heapify(arr, n, largest);
	}
	return arr;
}
vector<int> CCore::Pyramidsort(vector<int> arr)
{
	setMassive(arr);
	float allTime = 0.0f;
	float CurTime = 0.0f;
	for (int i = 0; i < Iterations; i++)
	{
		createRandomMassive(); // Пересоздание массива
		int n = arr.size();
		clock_t start = clock(); // Старт отчета
		// Построение кучи (перегруппируем массив)
		for (int i = n / 2 - 1; i >= 0; i--)
			arr = heapify(arr, n, i);

		// Один за другим извлекаем элементы из кучи
		for (int i = n - 1; i >= 0; i--)
		{
			// Перемещаем текущий корень в конец
			swap(arr[0], arr[i]);

			// вызываем процедуру heapify на уменьшенной куче
			arr = heapify(arr, i, 0);
		}
		clock_t end = clock(); // Конец отчета
		CurTime = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Iteration time: " << CurTime << "\t Step - " << i << "\n";
		allTime += CurTime;
		
	}
	cout << "Full time: " << allTime << "\n";
	cout << "Average time: " << allTime / Iterations << "\n";
	if (arr.size() < 201)
		PrintMassive(arr);
	else
		cout << "Massive is very long\n";	
	setMassive(arr);
	return arr;
}


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
	default:
	{
		cout << "Bubble sort: ";
		setMassive(Bubblesort(Random));
		cout << "Pyramid sort: ";
		setMassive(Pyramidsort(Random));

	}
	}
}
void CCore::Sorting(RandomData Data, int Type)
{
	CurRandomData = Data;
	createRandomMassive();
	PrintMassive(Random);
	sortByType(Type);
}

void CCore::createRandomMassive()
{
	if (CurRandomData.Length > 0)
	{
		vector<int> Return;
		for (int i = 0; i < CurRandomData.Length; i++)
			Return.push_back(CurRandomData.RangeIn + (std::rand() % (CurRandomData.RangeOut - CurRandomData.RangeIn + 1)));
		setRandMassive(Return);
	}
}
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
CCore::~CCore()
{
}
