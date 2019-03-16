#pragma once
#include "struct.h"

class CStack
{
private:
	struct ListNode* Top;
	int iSize = 0;
public:
	CStack();
	~CStack();
public:
	void push(int iValue);
	int pop();

	int top();
	int size();
	bool isEmptyStack();
};

