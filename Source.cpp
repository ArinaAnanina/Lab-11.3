#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<char> MakeSTL(int size)
{
	stack<char> res;
	char tmp;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите элемент " << i + 1 << ": ";
		cin >> tmp;
		res.push(tmp);
	}
	return res;
}

void PrintSTL(stack<char> st)
{
	if (st.empty())
	{
		cout << "Стек пустой" << endl;
		return;
	}

	stack<char> t;
	while (!st.empty())
	{
		t.push(st.top());
		st.pop();
	}
	while (!t.empty())
	{
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
		
}
stack<char> ReplaceSTL(stack<char> st)
{
	int n = st.size();
	stack<char> per, upend;
	char* ar = new char[n];
	char tmp;
	while (!st.empty())
	{
		upend.push(st.top());
		st.pop();
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			cout << "Введите " << i+1 << " элемент: " << endl;
			cin >> tmp;
			ar[i] = tmp;
			upend.pop();
		}
		else
		{
			ar[i] = upend.top();
			upend.pop();
		}
	}
	for (int j = 0; j < n; j++)
	{
		per.push(ar[j]);
	}
	return per;
}

struct Stack
{
	char data;
	Stack* prev;
};

void push(Stack** last, char element)
{
	Stack* newElement = new Stack;
	newElement->data = element;
	newElement->prev = *last;
	(*last) = newElement;
}

char pop(Stack** last)
{
	char el = (*last)->data;
	Stack* rem = *last;
	*last = (*last)->prev;
	delete rem;
	return el;
}

Stack* make_stack(int size)
{
	Stack* res = 0;
	char tmp;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите элемент " << i + 1 << ": ";
		cin >> tmp;
		push(&res, tmp);
	}
	return res;
}

void print(Stack* &last)
{	
	if (!last) {
		cout << "Стек пустой" << endl;
		return;
	}
	vector<char> copy = vector<char>();
	while (last)
	{
		copy.push_back(pop(&last));
	}
	for (int i = copy.size() - 1; i >= 0; i--) {
		cout << copy[i] << " ";
		push(&last, copy[i]);
	}
	cout << endl;
}

void replace(Stack* &top)
{
	if (!top)
	{
		cout << "Стек пустой" << endl;
		return;
	}
	vector<char> ar = vector<char>();
	while (top)
	{
		ar.insert(ar.begin(), 1, pop(&top));
	}
	for (int j = 0; j < ar.size(); j++) {
		if (j % 2 == 0) {
			cout << "Введите " << j + 1 << " элемент стека: ";
			cin >> ar[j];
		}
		push(&top, ar[j]);
	}
	cout << endl;
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "RUS");
	cout << "Стек через STL библиотеку." << endl;
	int size;
	do
	{
		cout << "Введите кол-во элементов стека: ";
		cin >> size;
	} while (size <= 0);
	stack<char> st1 = MakeSTL(size);
	PrintSTL(st1);
	stack<char> st2= ReplaceSTL(st1);
	PrintSTL(st2);

	cout << "Стек через структуру." << endl;
	int size2;
	do
	{
		cout << "Введите кол-во элементов стека: ";
		cin >> size2;
	} while (size2 <= 0);
	Stack* st3 = make_stack(size2);
	print(st3);
	replace(st3);
	print(st3);

	return 0;
}