#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//вершина бинарного дерева
struct binaryNode
{
public:
	int data;
	//указатели левый узел
	binaryNode* left = nullptr;
	//указатели правый узел
	binaryNode* right = nullptr;

public:
	binaryNode() : data(0) {}
	binaryNode(int data) : data(data) {}
};

//бинарное дерево
class binaryTree
{
private:
	vector<int> treeElements;

	//указатель на корень дерева 
	binaryNode* root;
	//кол-во вершин в дереве
	int count;

private:
	// проверка места элемента в дереве
	int place(int value, binaryNode* node)
	{
		if (value > node->data) return 1;
		else if (value == node->data) return 0;
		else return -1;
	}

	// добавление элемента
	void add(binaryNode* node, int value)
	{
		// если число меньше, чем в корне - создаем левый корень для данного числа 
		if (place(value, node) == -1)
		{
			// если у просматриваемого корня нет продолжения - создаем новую крайнюю ветку
			if (node->left == nullptr)
				node->left = new binaryNode(value);
			// идем глубже по дереву
			else
				add(node->left, value);
		}
		// если число больше, чем в корне - создаем правый корень для данного числа 
		else
		{
			// если у просматриваемого корня нет продолжения - создаем новую крайнюю ветку
			if (node->right == nullptr)
				node->right = new binaryNode(value);
			// идем глубже по дереву
			else
				add(node->right, value);
		}
	}

	// обход дерева
	void goAround(binaryNode* node)
	{
		treeElements.push_back(node->data);

		if (node->left)
			goAround(node->left);

		if (node->right)
			goAround(node->right);
	}

	// сохранение дерева
	void save(binaryNode* node)
	{
		ofstream of("File.txt", ofstream::app);

		if (node == nullptr) return;

		of << node->data << " ";
		of.close();

		save(node->left);
		save(node->right);
	}

	binaryNode* findLeastElement(binaryNode* node)
	{
		binaryNode* currentNode = node;
		for (;;)
		{
			if (currentNode->left != nullptr)
				currentNode = currentNode->left;
			else
				return currentNode;
		}
	}

	// поиск вершины
	binaryNode* getNode(int value, binaryNode*& parent)
	{
		binaryNode* node = root;

		for (;;)
		{
			// дерево пустое или вершина есть лист
			if (node == nullptr) return nullptr;
			// если узел не последний и равен искомому, то возвращаем 
			else if (value == node->data) return node;
			// если узел не последний и меньше искомого, то идем вправо по дереву
			else if (value > node->data)
			{
				parent = node;
				node = node->right;
			}
			// иначе идем влево по дереву
			else
			{
				parent = node;
				node = node->left;
			}
		}
	}

public:
	binaryTree() : root(nullptr), count(0) {}

	// конструтор для создания самих узлов
	binaryTree(int data, binaryNode* left, binaryNode* right)
	{
		root = new binaryNode;
		root->data = data;
		root->left = left;
		root->right = right;
		count = 1;
	}

	binaryNode* buildTree(int value)
	{
		// если дерево пустое - создаем корень с данным значением
		if (root == nullptr)
			root = new binaryNode(value);
		// ищем место для добавления нового элемента
		else
			add(root, value);

		count++;

		return root;
	}

	vector<int> getTree()
	{
		treeElements.clear();
		goAround(root);
		return treeElements;
	}

	void remove(int element)
	{
		binaryNode* elementNodeParent = new binaryNode();
		binaryNode* elementNode = getNode(element, elementNodeParent);

		if (!elementNode) return;

		// Случай 1: удаляем лист
		if (elementNode->right == nullptr && elementNode->left == nullptr)
		{
			if (place(element, elementNodeParent) == 1) elementNodeParent->right = nullptr;
			else if (place(element, elementNodeParent) == -1) elementNodeParent->left = nullptr;
		}
		// Случай 2: имеет 2 дочерние ветви
		else if (elementNode->left && elementNode->right)
		{
			binaryNode* rightTreeNode = elementNode->right;
			binaryNode* leastElement = findLeastElement(rightTreeNode);
			binaryNode* leastElementParent = new binaryNode();
			getNode(leastElement->data, leastElementParent);

			if (rightTreeNode->left == nullptr)
			{
				if (elementNode != root)
				{
					// впараво
					if (place(element, elementNodeParent) == 1) elementNodeParent->right = rightTreeNode;
					// влево
					else if (place(element, elementNodeParent) == -1) elementNodeParent->left = rightTreeNode;

					rightTreeNode->left = elementNode->left;
				}
				else
				{
					leastElement->left = root->left;
					root = leastElement;
				}
			}
			else
			{
				leastElementParent->left = leastElement->right;

				if (elementNode != root)
				{
					if (place(element, elementNodeParent) == 1) elementNodeParent->right = leastElement;
					else if (place(element, elementNodeParent) == -1) elementNodeParent->left = leastElement;

					leastElement->left = elementNode->left;

					if (elementNode != leastElementParent) leastElement->right = elementNode->right;
				}
				else
				{
					leastElement->left = root->left;
					leastElement->right = root->right;
					root = leastElement;
				}
			}
		}
		// Вариант 3: имеет 1 дочернюю ветвь
		else
		{
			binaryNode* newRoot;

			if (elementNode->left != nullptr)
				newRoot = elementNode->left;
			else
				newRoot = elementNode->right;

			if (elementNode != root)
			{
				if (place(element, elementNodeParent) == 1) elementNodeParent->right = newRoot;
				else elementNodeParent->left = newRoot;
			}
			else
				root = newRoot;
		}

		delete elementNode;
	}

	void saveData() { save(root); }
};

void main()
{
	setlocale(LC_ALL, "RUS");

	binaryTree tree;
	vector<int> treeElements = { 35,70,43,89,34,23,78,45,0,12,7 };
	int elementToDelete;

	for (int e : treeElements)
		tree.buildTree(e);

	treeElements = tree.getTree();

	for (int e : treeElements)
		cout << e << " ";

	cout << endl;

	cout << "Введите число, которое нужно удалить: ";
	cin >> elementToDelete;

	tree.remove(elementToDelete);

	treeElements = tree.getTree();

	for (int e : treeElements)
		cout << e << " ";

	tree.saveData();
}