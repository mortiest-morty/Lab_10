#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

struct Node
{
	int data;
	Node* Next;
};
typedef Node* TNode;

int HowMuchNumbers();
void Add(int data, TNode& Head);
TNode FindTheEvenNumber(TNode Head);
void Show(TNode Head);
void task_1();

void AddToQueue(int data, TNode& Head, TNode& Tail);
void task_2();

void ShowList(TNode& Head);
void task_3();

void AddAfter4Numbers(int M, TNode Head);
void task_4();

void sortInsert(int* m, int n);
void task_5();
