#include <iostream>

template<typename T>
class DynamicArray {
protected:
    T *m_array;
    int m_size;

public:
    // Конструктор с заполнением одинаковыми элементами
    DynamicArray(int size, T value) {
        m_size = size;
        m_array = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_array[i] = value;
        }
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray &other) {
        m_size = other.m_size;
        m_array = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_array[i] = other.m_array[i];
        }
    }

    // Деструктор
    ~DynamicArray() {
        delete[] m_array;
        m_array = nullptr;
        std::cout << "Destructor" << std::endl;
    }

    // Оператор присваивания
    DynamicArray &operator=(const DynamicArray &other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_array = new T[m_size];
            for (int i = 0; i < m_size; i++) {
                m_array[i] = other.m_array[i];
            }
        }
        return *this;
    }

    // Метод для увеличения размера массива
    void increaseSize(int newSize, T value) {
        if (newSize <= m_size) {
            std::cout << "Error: New size <= current size" << std::endl;
            return;
        }
        T *newArray = new T[newSize];
        for (int i = 0; i < m_size; i++) {
            newArray[i] = m_array[i];
        }
        for (int i = m_size; i < newSize; i++) {
            newArray[i] = value;
        }
        delete[] m_array;
        m_array = newArray;
        m_size = newSize;
    }

    // Метод для уменьшения размера массива
    void decreaseSize(int newSize) {
        if (newSize >= m_size) {
            std::cout << "Error: New size >= current size" << std::endl;
            return;
        }
        T *newArray = new T[newSize];
        for (int i = 0; i < newSize; i++) {
            newArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = newArray;
        m_size = newSize;
    }

    // Вывод массива
    void printArray() {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_array[i] << ' ';
        }
        std::cout << std::endl;
    }
};

template<typename T>
class DynamicStack : public DynamicArray<T> {
    int s_size;
    T *s_arr;
public:

    // Конструктор с указанием размера стека
    DynamicStack(int size, T value) : DynamicArray<T>(size, value) {
        s_size = size;
        s_arr = new T[s_size];
        for (int i = 0; i < s_size; i++) {
            s_arr[i] = value;
        }
    }

// Конструктор копирования наследованного класса
    DynamicStack(const DynamicStack &other) : DynamicArray<T>(other) {
        s_size = other.s_size;
        s_arr = new T[s_size];
        for (int i = 0; i < s_size; i++) {
            s_arr[i] = other.s_arr[i];
        }
    }

// Деструктор наследованного класса
    ~DynamicStack() {
        delete[] s_arr;
        s_arr = nullptr;
        std::cout << "Destructor for stack" << std::endl;
    }

// Оператор присваивания наследованного класса
    DynamicStack &operator=(const DynamicStack &other) {
        if (this != &other) {
            delete[] s_arr;
            s_size = other.m_size;
            s_arr = new T[s_size];
            for (int i = 0; i < s_size; i++) {
                s_arr[i] = other.s_arr[i];
            }
        }
        return *this;
    }
    
    // Вывод наследованного класа
    void printStack() {
        for (int i = 0; i < s_size; i++) {
            std::cout << s_arr[i] << ' ';
        }
        std::cout << std::endl;
    }

    // Добавление элемента на вершину стека
    void push(T value) {
        this->increaseSize(this->m_size + 1, value);
    }

    // Удаление элемента с вершины стека
    void pop() {
        if (this->m_size > 0) {
            this->decreaseSize(this->m_size - 1);
        } else {
            std::cout << "Error: Stack is empty" << std::endl;
        }
    }
};


int main() {

    //добовление элемента
    DynamicStack<double> Stack(10, 0.1);
    std::cout << std::endl;
    Stack.printStack();
    /*
    NewStack.push(999);
    NewStack.push(999);
    NewStack.printArray();
    NewStack.pop();NewStack.pop();NewStack.pop();NewStack.pop();NewStack.pop();NewStack.pop();
    NewStack.printArray();
    */
    DynamicStack<double> NewStack = Stack;
    NewStack.printStack();
    DynamicStack<double> DoubStack(4, 999.999);
    DoubStack.printStack();
    DoubStack = NewStack;
    DoubStack.printStack();

    /*
    //2 Вида массивов
    DynamicArray<int> intArray(5, 10);
    intArray.printArray();
    intArray.increaseSize(8, 5);
    intArray.printArray();
    intArray.decreaseSize(6);
    intArray.printArray();

    DynamicArray<double> doubleArray(5, 3.14);
    doubleArray.printArray();
    doubleArray.increaseSize(8, 2.72);
    doubleArray.printArray();
    doubleArray.decreaseSize(6);
    doubleArray.printArray();


    //2 конструктора копирования
    DynamicArray<int> NewArrayInt = intArray;
    NewArrayInt.printArray();

    DynamicArray<double> NewArrayDouble(doubleArray);
    NewArrayDouble.printArray();


    //2 оператора присваивания
    DynamicArray<int> IntArray(3, 7);
    IntArray.printArray();
    IntArray = intArray;
    IntArray.printArray();

    DynamicArray<double> DoubleArray(10, 0.0001);
    DoubleArray.printArray();
    DoubleArray = doubleArray;
    DoubleArray.printArray();
*/

    return 0;
}
