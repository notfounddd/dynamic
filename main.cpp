#include <iostream>

class DynamicArray {
private:
    int *m_array;
    int m_size;

public:
    // Конструктор с заполнением одинаковыми элементами
    DynamicArray(int size, int value) {
        m_size = size;
        m_array = new int[m_size];
        for (int i = 0; i < m_size; i++) {
            m_array[i] = value;
        }
    }

    // Деструктор
    ~DynamicArray() {
        for (size_t i = 0; i < m_size; i++) {
            m_array[i] = 0;
        }
        delete[] m_array;
        m_array = nullptr;
        std::cout << "Destructor" << std::endl;
    }

    // Метод для увеличения размера массива
    void increaseSize(int newSize, int value) {
        if (newSize <= m_size) {
            std::cout << "Erorr : New size < = current size" << std::endl;
            return;
        }

        int* newArray = new int[newSize];
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
            std::cout << "Erorr : New size > = current size" << std::endl;
            return;
        }

        int *newArray = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            newArray[i] = m_array[i];
        }

        delete[] m_array;
        m_array = newArray;
        m_size = newSize;
    }
    //Вывод массив
    void printArray() {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    DynamicArray myArray(5, 10);
    myArray.printArray();

    myArray.increaseSize(8,5);
    myArray.printArray();

    myArray.decreaseSize(6);
    myArray.printArray();
    
    return 0;
}
