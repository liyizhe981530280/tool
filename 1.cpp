#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int Item;

class Stack
{
  private:
	enum
	{
		MAX = 10
	};
	Item items[MAX];
	int top;

  public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
	int length;

  protected:
};

Stack::Stack()
{
	top = 0;
}

bool Stack::pop(Item &item)
{
	if (top == 0)
	{
		return false;
	}
	else
	{
		items[top--] = item;
	}
	return true;
}

bool Stack::push(const Item &item)
{
	if (top == 0)
	{
		return false;
	}
	else
	{
		items[top++] = item;
	}

	return true;
}
bool Stack::isfull() const{
	if(top == 10){
		return true;
	}else {
		return false;
	}
}
bool Stack::isempty() const
{
    if(top == 0){
		return true;
	}else {
		return false;
	}
}
int main()
{
	Stack st;

	st.length = 5;
	st.isempty();
	cout << "iiiiiiii" << endl;

	return 0;
}
