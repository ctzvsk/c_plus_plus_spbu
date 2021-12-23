#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {};
	~Node() {};
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int count;

public:
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	LinkedList(const LinkedList& list)
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	int& operator[](int index)
	{
		if (index < 0)
		{
			push_forward(0);
			return head->data;
		}
		if (index >= count)
		{
			push_back(0);
			return tail->data;
		}
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	bool indexValid(int index)
	{
		return (index >= 0 && index < count);
	}

	bool operator==(LinkedList& list1)
	{
		if (list1.count != count)
		{
			return false;
		}
		while (head->next == nullptr)
		{
			if (head->data != list1.head->data)
			{
				return false;
			}
			head = head->next;
			list1.head = list1.head->next;
		}
		return true;
	}
	bool operator!=(LinkedList& list1)
	{
		if (list1.count != count)
		{
			return true;
		}
		while (head->next == nullptr)
		{
			if (head->data != list1.head->data)
			{
				return true;
			}
			head = head->next;
			list1.head = list1.head->next;
		}
		return false;
	}

	LinkedList& operator=(LinkedList& list)
	{
		clear();
		Node* temp = list.head;
		for (int i = 0; i < list.count; ++i)
		{
			push_back(temp->data);
			temp = temp->next;
		}
		return (*this);
	}

	Node* gethead()
	{
		return head;
	}

	void clear()
	{
		Node* temp = nullptr;
		while (head != nullptr)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		head = nullptr;
		return;
	}

	void push_forward(int data)
	{
		head = new Node(data, head);
		if (tail == nullptr)
		{
			tail = head;
		}
		++count;
	}

	void push_back(int data)
	{
		if (tail == nullptr)
		{
			return push_forward(data);
		}
		tail->next = new Node(data);
		tail = tail->next;
		++count;
	}

	void insert(int data, int index)
	{
		if (index == count)
		{
			return push_back(data);
		}
		if (index == 0)
		{
			return push_forward(data);
		}
		if (indexValid(index))
		{
			Node* temp = head;
			for (int i = 0; i < index - 1; ++i)
			{
				temp = temp->next;
			}
			temp->next = new Node(data, temp->next);
			++count;
		}
	}

	int extractHead()
	{
		if (count == 0)
		{
			return 0;
		}
		Node* temp = head;
		head = head->next;
		int result = head->data; // ?
		delete temp;
		--count;
		if (count == 0)
		{
			tail = nullptr;
		}
		return result;
	}

	int extractTail()
	{
		if (count == 0)
		{
			return 0;
		}
		if (count == 1)
		{
			return extractHead();
		}
		Node* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		int result = temp->data;
		delete temp->next;
		temp->next = nullptr;
		--count;
		return result;
	}

	int extract_index(int index)
	{
		if (!indexValid(index))
		{
			return 0;
		}
		if (index == 0)
		{
			return extractHead();
		}
		if (index == count - 1)
		{
			return extractTail();
		}

		Node* temp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			temp = temp->next;
		}
		int result = temp->next->data;
		Node* todelete = temp->next;
		temp->next = temp->next->next;
		delete todelete;
		--count;
		return result;
	}

	void extract_value(int value)
	{
		if (count <= 0)
		{
			return;
		}

		Node* temp = head;
		for (int i = 0; i < count; ++i)
		{
			if (temp->data == value)
			{
				extract_index(i);
				extract_value(value);

			}
			temp = temp->next;

		}

	}

	static void combine_lists(Node* a, Node* b)
	{
		if (a->next == NULL)
			a->next = b;
		else
			combine_lists(a->next, b);
	}
	friend ostream& operator<<(ostream& stream, const LinkedList& list)
	{
		Node* temp = list.head;
		stream << "[" << list.count << "]:{ ";
		while (temp != nullptr)
		{
			stream << temp->data << " ";
			temp = temp->next;
		}
		stream << "}";
		return stream;
	}
};

int main(int argc, char* argv[])
{
	LinkedList list_one;
	list_one.push_forward(1);
	list_one.push_forward(2);
	list_one.push_forward(3);
	LinkedList list_two = list_one;
	cout << list_one << std::endl;
	cout << list_two << std::endl;

	list_two.insert(4, 2);
	cout << "list_two with number 4 inserted: " << list_two << endl;

	if (list_two != list_one)
	{
		cout << "list_two != list_one" << endl;
	}
	else
	{
		cout << "list_two = list_one" << endl;
	}
	
	list_two.extract_index(0);
	cout << "list_two with zeroth element extracted: " << list_two << endl;

	list_one.extract_value(1);
	cout << "list_one with element '1' extracted: " << list_one << endl;

	list_one.insert(9, 1);
	cout << "list_one with number 9 inserted" << list_one << endl;

	LinkedList::combine_lists(list_one.gethead(), list_two.gethead());
	cout << "list_one combined with list_two" << list_one << endl;

	return EXIT_SUCCESS;
}
