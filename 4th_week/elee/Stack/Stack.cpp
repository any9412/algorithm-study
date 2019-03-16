#include "Stack.h"
#include <malloc.h>

CStack::CStack()
{
	iSize = 0;
	Top = nullptr;
}

CStack::~CStack()
{
}

void CStack::push(int iValue)
{
	struct ListNode* newTop = (ListNode*)malloc(sizeof(ListNode));

	newTop->value = iValue;
	if (iSize != 0)		
		newTop->next = Top;
	Top = newTop;
	
	iSize++;
}

int CStack::pop()
{
	int iValue = Top->value;
	Top = Top->next;

	iSize--;

	return iValue;
}

int CStack::top()
{
	return Top->value;
}

int CStack::size()
{
	return iSize;
}

bool CStack::isEmptyStack()
{
	return Top == nullptr;
}