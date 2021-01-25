
#ifndef PCH_H
#define PCH_H
#define _CRT_SECURE_NO_WARNINGS
#define DefaultSize 255 //дефолтное значение для буффера
#define DEFAULT_PATH "C:\\Users\\Public\\Documents\\TEST.txt"
#define DEFAULT_PATH1 "C:\\TEST.txt"
//#define DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h> 
#include <cassert>


struct RandomData
{
	RandomData(int l, int ri, int ro)	{		Length = l; RangeIn = ri; RangeOut = ro;	}
	int Length = 1;
	int RangeIn = 1;
	int RangeOut = 2;
};

using namespace std;


// TODO: add headers that you want to pre-compile here

#endif //PCH_H
