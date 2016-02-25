#include "stdafx.h"
#include <sstream>
#include <iostream>
#include "TemplateCity.h"
#include "unit.hpp"
#include <vld.h>
TemplateCity::TemplateCity(){
	listInitialized = false;
	treeInitialized = false;
}
TemplateCity::~TemplateCity(){
	if (listInitialized){
		newList->CleanList();
		delete newList;
		newList = nullptr;
	}
	if (treeInitialized){
		newBinaryTree->ClearTree();
		delete newBinaryTree;
		newBinaryTree = nullptr;
	}
}
bool TemplateCity::Initialize(){
	m_running = false;
	if (m_running == false){
		InitializeList();
		InitializeBinaryTree();
	}
	m_running = true;
	return true;
}
void TemplateCity::Update(){
	while (m_running){
			ListManipulation<int>();
			//BinaryTreeManipulation<int>();
		}
}
void TemplateCity::InitializeList()
{
	newList = new TList <int>();
	listInitialized = true;
}
void TemplateCity::InitializeBinaryTree(){
	newBinaryTree = new TBinaryTree<int>();
	treeInitialized = true;
}


