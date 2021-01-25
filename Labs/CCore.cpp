#include "pch.h"
#include "CCore.h"

/*!
\brief ����2
	����2
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
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

 // ���� ����� �������� ������� ������ �����
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// ���������� ����������� � �������� ���� ���������� ���������
		arr = heapify(arr, n, largest);
	}
	return arr;
}
vector<int> CCore::Pyramidsort(vector<int> arr)
{
	setMassive(arr);
	int n = arr.size();
	clock_t start = clock();
	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		arr = heapify(arr, n, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);

		// �������� ��������� heapify �� ����������� ����
		arr = heapify(arr, i, 0);
	}
	clock_t end = clock();
	PrintMassive(arr);
	cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
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
	}
}


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
