#include<iostream>
#include<string>
using namespace std;

class ArrayList
{
private:
    int count;
    int capacity;
    int* data;

    void expand(int expandRate = 0)
    {
        if (expandRate == 0)
        {
            expandRate = capacity;
        }
        int* newData = new int[capacity + expandRate];
        for (int i = 0; i < count; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity += expandRate;
    }

    void ArrayListAssign(const ArrayList& list)
    {
        this->capacity = list.capacity;
        this->count = list.count;
        this->data = new int[list.count];
        for (int i = 0; i < list.count; ++i)
        {
            this->data[i] = list.data[i];
        }
    }
public:
    ArrayList(int capacity = 0) : count(0), capacity(capacity), data(new int[capacity]) {}
    ArrayList(const ArrayList& list)
    {
        ArrayListAssign(list);
    }
    ~ArrayList()
    {
        delete[] this->data;
    }

    ArrayList& operator=(ArrayList& list)
    {
        delete[] this->data;
        ArrayListAssign(list);
        return *this;
    }

    bool operator==(ArrayList& list)
    {
        if (list.count != count)
        {
            return false;
        }
        for (int i = 0; i < count; ++i)
        {
            if (list.data[i] != data[i])
            {
                return false;
            }
        }
        return true;
    }

    ArrayList& operator+= (ArrayList& list)
    {
        combine_arraylist(list);
        return (*this);
    }

    friend ostream& operator<< (ostream& stream, const ArrayList& list)
    {
        stream << "[" << list.count << "/" << list.capacity << "] { ";
        for (int i = 0; i < list.count; ++i)
        {
            cout << list.data[i] << " ";
        }
        stream << "}" << endl;
        return stream;
    }

    void push_back(int val)
    {
        if (count == capacity)
        {
            expand();
        }
        data[count] = val;
        ++count;
    }

    void push_forward(int val)
    {
        if (count == capacity)
        {
            expand();
        }
        for (int i = count; i > 0; --i)
        {
            data[i] = data[i - 1];
        }
        ++count;
        data[0] = val;
    }

    void extract_index(int val)
    {
        for (int i = 0; i < count - 1; ++i)
        {
            if (i >= val)
            {
                data[i] = data[i + 1];
            }
        }
        --count;
    }

    void extract_value(int val)
    {
        if (count <= 0)
        {
            return;
        }
        for (int t = 0; t < count; t++)
        {
            if (data[t] == val)
            {
                extract_index(t);
                extract_value(val);
            }
        }
    }

    void insert_index(int val, int index)
    {
        count++;
        for (int i = count; i >= index; --i)
        {
            data[i] = data[i-1];
        }
        data[index] = val;
    }

    ArrayList combine_arraylist(ArrayList& list)
    {
        int length = list.count;
        if (count + length > capacity)
        {
            expand(length);
        }

        for (int i = 0; i < length; ++i)
        {
            push_back(list.data[i]);
        }

        return (*this);
    }
};

int main(int argc, char* argv[])
{
    ArrayList a1(10);
    ArrayList a2(8);

    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    a1.push_back(4);
    cout << "Array 1: " << a1 << endl;
        
    a2.push_back(5);
    a2.push_back(6);
    a2.push_back(7);
    a2.push_back(8);
    a2.push_back(9);
    cout << "Array 2: " << a2 << endl;

    a1.extract_value(2);
    cout << "Array 1 without element '2': " << a1 << endl;

    a2.extract_index(3);
    cout << "Array 2 without third element: " << a2 << endl;
    
    a1.insert_index(2, 0);
    cout << "Array 1 with element '2' at position '0': " << a1 << endl;

    a1.combine_arraylist(a2);
    cout << "Array 1 and 2 combined: " << a1 << endl;

    a1 += a1;
    cout << "Array 1 + Array 1: " << a1 << endl;

    return EXIT_SUCCESS;
}
