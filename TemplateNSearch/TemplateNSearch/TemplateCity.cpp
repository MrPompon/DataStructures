#include "stdafx.h"
#include <sstream>
#include <iostream>
#include "TemplateCity.h"
#include "unit.hpp"
TemplateCity::TemplateCity(){
	Initialize();
}
TemplateCity::~TemplateCity(){
	newList->CleanList();
	delete newList;
	newList = nullptr;

	newBinaryTree->ClearTree();
	delete newBinaryTree;
	newBinaryTree = nullptr;
}
bool TemplateCity::Initialize(){
	
	m_running = true;
	InitializeList();
	InitializeBinaryTree();
	return true;
}
void TemplateCity::Update(){
	while (m_running){
			//ListManipulation<int>();
			BinaryTreeManipulation<int>();
		}
}
void TemplateCity::InitializeList()
{
	newList = new TList <int>();
}
void TemplateCity::InitializeBinaryTree(){
	newBinaryTree = new TBinaryTree<int>();
}

//popfront- popback tabort, clear remove all, find value i list, size length of list. 

