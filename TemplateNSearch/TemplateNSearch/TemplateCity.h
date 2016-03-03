#pragma once

template<class T>
struct TNode{
	TNode*nextNode;
	T value;
};
template<class T>
struct TDuoNode{
	T value;
	TDuoNode*nodeLow;
	TDuoNode*nodeHigh;
};
template<class T>
struct TList
{
	TNode<T>* headNode;
	TNode<T>* tempNode;
	void PushBack(T value)
	{
		if (IsListEmpty(value)){
			std::cout << "Pushbacking with value" << value << "as headnode" << std::endl;
		}
		else
		{
			tempNode = headNode;
			for (tempNode = headNode; tempNode->nextNode; tempNode = tempNode->nextNode);
			tempNode->nextNode = new TNode < T >;
			tempNode->nextNode->value = value;
			tempNode->nextNode->nextNode = nullptr;
			std::cout << "Pushbacking with value" << value << std::endl;
		}
	}
	void UnitTest(){
		CleanList();
		PushBack(5);
		PushFront(10);
		FindValue(5);
		verify(2, Size(), "Veryfying list size is 2");
		PopFront();
		PopBack();
		verify(0, Size(), "Veryfying list size is 0");
		PushFront(2);
		CleanList();
		verify(0, Size(), "veryfying list size is 0");
	}
	void PushFront(T value){
		if (IsListEmpty(value))
		{

		}
		else{
			std::cout << "Pushfront with value" << value << std::endl;
			tempNode = new TNode<T>();
			tempNode->value = value;
			tempNode->nextNode = headNode;
			headNode = tempNode;
		}
	}
	void PopFront(){
		if (!headNode){
			std::cout << "Head node is null, failed to popFront" << std::endl;
		}
		else{
			std::cout << "Poppingfront"<< std::endl;
			TNode<T>* tempNode;
			tempNode = headNode->nextNode;
			delete headNode;
			headNode = nullptr;
			headNode = tempNode;
		}	
	}
	void PopBack(){
		if (!headNode)
			std::cout << "list empty " << std::endl;
		else{
			if (headNode->nextNode){
				tempNode = headNode;
				for (; tempNode->nextNode->nextNode; tempNode = tempNode->nextNode);
				delete tempNode->nextNode;
				tempNode->nextNode = nullptr;
			}
			else{
				delete headNode;
				headNode = nullptr;
			}
			std::cout << "Popback" << std::endl;
		}
		}

	T Size(){
		T sizeValue = 0;
		if (headNode != nullptr){
			TNode<int>* tempNode;
			tempNode = headNode;
			while (tempNode!= nullptr){
				tempNode = tempNode->nextNode;
				sizeValue++;
			}
		}
		std::cout << sizeValue <<" size of list"<<std::endl;
		return sizeValue;
	}
	void CleanList(){
		if (headNode==nullptr){
			std::cout << "List Should Already Be Empty\n<<<<<<<<<<<<<" << std::endl;
		}
		else{
			while (headNode->nextNode){
				PopFront();
			}
			delete headNode;
			headNode = nullptr;
			std::cout << "List is cleaned" << std::endl;
		}
	}
	void FindValue(T value){
		if (!headNode){
			std::cout << "Head node is null, nothing to find in list" << std::endl;
		}
		else{
			TNode<T>* tempNode = headNode;
			while (tempNode->nextNode != nullptr){
				if (CompareValues(value,tempNode->value )){
					std::cout << "found value" << value<<std::endl;
				}
				tempNode = tempNode->nextNode;
			}
		}
		
	}
	bool IsListEmpty(T value){
		if (headNode==nullptr){
			headNode = new TNode < T >;
			headNode->nextNode = nullptr;
			headNode->value = value;
			return true;
		}
		return false;
	}
	bool CompareValues(T value, T value2){
		if (value == value2){
			return true;
		}
		else{
			return false;
		}
	}
};
template<class T>
struct TBinaryTree
{
	TDuoNode<T>* headNode;
	template <class T>
	TDuoNode<T>* CreateNode(T value){
		TDuoNode<T>* newNode=new TDuoNode<T>();
		newNode->nodeHigh = nullptr;
		newNode->nodeLow = nullptr;
		newNode->value = value;
		return newNode;
	}
	void AddNodeLocal(T key, TDuoNode<T> *node){
		if (headNode == nullptr){
			headNode = CreateNode(key);
		}
		else if (key < node->value){
			if (node->nodeLow != nullptr)
			{
				AddNodeLocal(key, node->nodeLow);
			}
			else
			{
				node->nodeLow = CreateNode(key);
			}
		}
		else if (key > node->value)
		{
			if (node->nodeHigh != nullptr)
			{
				AddNodeLocal(key, node->nodeHigh);
			}
			else
			{
				node->nodeHigh = CreateNode(key);
			}
		}
		else
		{
			std::cout << "Key Value of" << key << "is already inserted" << std::endl;
		}
	}
	void AddNode(T key){
		if (headNode == nullptr){
			headNode = CreateNode(key);
			std::cout << "Pushbacking " << key << " into tree, as headnode" << std::endl;
		}
		else{
			AddNodeLocal(key, headNode);
			std::cout << "Pushbacking " << key << " into tree" << std::endl;
		}
	
	}
	void Find(T value){
		if (headNode == nullptr){
			std::cout << "The List is Empty" << std::endl;
		}
		else{
			FindLocal(value, headNode);
		}
	}
	TDuoNode<T>* FindLocal(int key, TDuoNode<T>* node){
		if (node != nullptr)
		{
			if (node->value == key)
			{
				std::cout << "Found the corrsesponding value of " << key << std::endl;;
				return node;
			}
			else
			{
				if (key < node->value){
					return FindLocal(key, node->nodeLow);
				}
				else{
					return FindLocal(key, node->nodeHigh);
				}
			}
		}
		else
		{
			return NULL;
		}
	}
	
	TDuoNode<T>* GetHeadNode(){
		return headNode;
	}
	void TraversePreOrder(){
		TraversePreOrderLocal(headNode);
	}
	template<typename T>
	void TraversePreOrderLocal(TDuoNode<T>* p_headnode){
		if (p_headnode != nullptr){
			std::cout << p_headnode->value << " ";

			if (p_headnode->nodeLow != nullptr){
				TraversePreOrderLocal(p_headnode->nodeLow);
			}
			if (p_headnode->nodeHigh != nullptr){
				TraversePreOrderLocal(p_headnode->nodeHigh);
			}
		}
	}
	void TraversePostOrder(){
		TraversePostOrderLocal(headNode);
	}
	void TraversePostOrderLocal(TDuoNode<T>* node){
		if (node->nodeLow != nullptr){
			TraversePostOrderLocal(node->nodeLow);
		}
		if (headNode != nullptr){
			if (node->nodeHigh != nullptr){
				TraversePostOrderLocal(node->nodeHigh);
			}

			std::cout << node->value << " ";
		}
		else{
			std::cout << "The tree is empty\n" << std::endl;
		}
		
	}
	int Size(){
		int size=0;
		LocalGetSize(headNode,size);
		if (headNode != nullptr){
			return size+1;
		}
		return size;
	}
	void LocalGetSize(TDuoNode<T>*node,int &size){
		if (headNode != nullptr){
			if (node->nodeLow != nullptr){
				LocalGetSize(node->nodeLow,size);
				size++;
			}
			
			if (node->nodeHigh != nullptr){
				LocalGetSize(node->nodeHigh,size);
				size++;
			}
		}
		else{
			std::cout << "The tree is empty\n" << std::endl;
		}

	}
	void TraverseInOrder(){
		TraverseInOrderLocal(headNode);
	}
	void TraverseInOrderLocal(TDuoNode<T>* node){
	
		if (headNode != nullptr){
			if (node->nodeLow != nullptr){
				TraverseInOrderLocal(node->nodeLow);
				
			}
			std::cout << node->value << " ";
			if (node->nodeHigh != nullptr){
				TraverseInOrderLocal(node->nodeHigh);
			}
		}
		else{
			std::cout << "The tree is empty\n" << std::endl;
		}
	}
	template <class T>
	TDuoNode<T>* TraverseLocal(TDuoNode<T>*p_node)
	{
		if (TraverseLocalLow(p_node))
		{
			TraverseLocalLow(p_node->nodeLow);
		}
		else if (TraverseLocalHigh(p_node))
		{
			TraverseLocalHigh(p_node->nodeHigh);
		}
		else if (p_node->nodeLow == nullptr && p_node->nodeHigh == nullptr){
			std::cout << p_node->value;
		}
		return p_node;
	}
	bool IsHeadNodeNullptr(T value){
		if (headNode == nullptr){
			headNode = CreateNode(value);
			return true;
		}
		else{
			return false;
		}
	}

	void ClearTree(){
		RemoveSubtree(headNode);
	}
	void RemoveSubtree(TDuoNode<T>* node){
		if (node != nullptr){
			if (node->nodeLow != nullptr){
				RemoveSubtree(node->nodeLow);
			}
			if (node->nodeHigh != nullptr){
				RemoveSubtree(node->nodeHigh);
			}
			std::cout <<"Deleting the node with value"<< node->value;
			delete node;
			node = nullptr;
		}
	}
};
class TemplateCity{
public:
	TemplateCity();
	~TemplateCity();
	bool Initialize();
	template <class T>
	void ListManipulation(){
		std::cout << "\n 1:PushBack\n 2:PushFront\n 3:PopFront\n 4:PopBack \n 5:Clean\n 6:Close Program\n 7:Find Value\n 8:Size of list\n 9:UnitTest\n ";
		T input = std::cin.get();
		switch (input){
		case '1':
			std::cout << "Pushbacking " << +3 << " into list" << std::endl;
			newList->PushBack(3);
			break;
		case '2':
			std::cout << "PushFront " << +3 << " into list" << std::endl;
			newList->PushFront(3);
			break;
		case '3':
			std::cout << "PopFront of list" << std::endl;
			newList->PopFront();
			break;
		case '4':
			std::cout << "PopBack of list" << std::endl;
			newList->PopBack();
			break;
		case '5':
			newList->CleanList();
			break;
		case '6':
			m_running = false;
			break;
		case '7':
			std::cout << "\nWrite Which Number You are looking for\n";
			newList->FindValue(3);
			break;
		case '8':
			 newList->Size();
			break;
		case '9':
			newList->UnitTest();
			break;
		}
	}
	template <class T>
	void BinaryTreeManipulation(){
		std::cout << "\n 1:AddLeaf/Node(Which node value is in the syntax)\n2:TraverseInOrder\n3:TraversePostOrder\n 4:FindValue(which number is in the syntax :( )\n 5:Size of Tree\n 6: Close program\n 7: Unit Testing\n8:TraversePreOrder\n";
		T input = std::cin.get();
		switch (input){
		case '1':
			newBinaryTree->AddNode(7);
			newBinaryTree->AddNode(1);
			newBinaryTree->AddNode(2);
			newBinaryTree->AddNode(3);
			newBinaryTree->AddNode(4);
			newBinaryTree->AddNode(999);
			newBinaryTree->AddNode(48);
			newBinaryTree->AddNode(99);
			newBinaryTree->AddNode(38);
			newBinaryTree->AddNode(998);
			
			break;
		case '2':
			newBinaryTree->TraverseInOrder();
			break;
		case '3':
			newBinaryTree->TraversePostOrder();
			break;
		case '4':
			std::cout << "Trying to find"<<std::endl;
			newBinaryTree->Find(999);
			break;
		case '5':
			newBinaryTree->Size();
			break;
		case '6':
			m_running = false;
			break;
		case '7':
			newBinaryTree->AddNode(2);
			newBinaryTree->Find(2);
			newBinaryTree->AddNode(5);
			newBinaryTree->Find(5);
			newBinaryTree->AddNode(4);
			verify(3, newBinaryTree->Size(), "Verifying size is 3");
			newBinaryTree->AddNode(8);
			verify(4, newBinaryTree->Size(),"Veryfying size is 4");
			newBinaryTree->AddNode(1);
			newBinaryTree->AddNode(3);
			newBinaryTree->AddNode(3);
			newBinaryTree->Find(3);
			newBinaryTree->AddNode(7);
			verify(7, newBinaryTree->Size(), "Veryfying size is 7, since 3 is already inserted");
			newBinaryTree->TraverseInOrder();
			newBinaryTree->TraversePostOrder();
			break;
		case'8':
			newBinaryTree->TraversePreOrder();
			break;
		}
	}
	void Update();
	void InitializeList();
	void InitializeBinaryTree();
	TList<int>* newList;
	TBinaryTree<int>* newBinaryTree;
	bool treeInitialized;
	bool listInitialized;
private:
	bool m_running;
};

