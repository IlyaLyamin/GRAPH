#include <iostream>
#define PrintVal(Param) (cout << "{" #Param "}: " << (Param) << endl)// маккрос

using namespace std;

template <class MyType> // макет функций для замены векторов друг с другом
void MySwap(MyType& element1, MyType& element2) {
	MyType element3 = element1;
	element1 = element2;
	element2 = element3;
}

class MyIntVector {

public:
	MyIntVector() : length(0), capacity(1), dataPointer(new int[1]) {}// инициализация без аргумента

	MyIntVector(const MyIntVector& rhs) {// инициализация с аргументом
		length = rhs.Length();
		capacity = rhs.Capacity();
		dataPointer = new int[capacity];
		for (int i = 0; i < length; i++) {
			dataPointer[i] = rhs[i];
		}
	}

	~MyIntVector() {// деструктор
		delete[] dataPointer;
	}

	void PushBack(int newElement) {
		length == capacity ? UpCapacity(capacity + 1) : UpCapacity(capacity);// увелечение вместительности при необходимости
		dataPointer[length] = newElement;
		length++;
	}

	int& operator[] (int index) {// оператор получения элемента по индексу(не константных элементов)
		return *(dataPointer + index);
	}

	int& operator[](int index) const {// оператор получения элемента по индексу(константных)
		return *(dataPointer + index);
	}

	MyIntVector& operator= (const MyIntVector& rhs) {// оператор присвоения 
		delete[] dataPointer;
		length = rhs.Length();
		capacity = rhs.Capacity();
		dataPointer = new int[capacity];
		for (int i = 0; i < length; i++) {
			dataPointer[i] = rhs[i];
		}
		return *this;
	}

	bool IsEmpty() const {
		return this->length == 0;
	}
	int Length() const {
		return this->length;
	}
	int Capacity() const {
		return this->capacity;
	}
	void SetSize(int newLength) {// то что требовалось по заднию
		UpCapacity(newLength);
		length = newLength;
	}

private:

	int length;
	int capacity;
	int* dataPointer;

	void UpCapacity(int newCapacity) {// увелечение вместительности
		if (newCapacity > capacity) {
			int* X = new int[newCapacity];
			for (int i = 0; i < length; i++) {
				X[i] = *(dataPointer + i);
			}
			delete[] dataPointer;
			dataPointer = X;
			capacity = newCapacity;
		}
	}
};

template <class TypeOfElement>
class MyVector {
public:
	MyVector() : length(0), capacity(1), dataPointer(new TypeOfElement[1]) {
	};

	MyVector(const MyVector& vec) {
		length = vec.Length();
		capacity = vec.Capacity();
		dataPointer = new TypeOfElement[capacity];
		for (int i = 0; i < length; i++) {
			*(dataPointer + i) = vec[i];
		}
	}

	~MyVector() {
		delete[] dataPointer;
	};

	void PushBack(TypeOfElement newElement) {
		UpCapacity(length + 1);
		*(dataPointer + length) = newElement;
		length++;
	}

	TypeOfElement& operator[](int index) {
		return *(dataPointer + index);
	}

	TypeOfElement& operator[](int index) const {
		return *(dataPointer + index);
	}

	MyVector& operator= (const MyVector& vec) {
		delete[] dataPointer;
		length = vec.Length();
		capacity = vec.Capacity();
		dataPointer = new TypeOfElement[capacity];
		for (int i = 0; i < length; i++) {
			*(dataPointer + i) = vec[i];
		}
		return *this;
	}

	bool IsEmpty() const {
		return(length == 0);
	}
	int Length() const {
		return length;
	}
	int Capacity() const {
		return capacity;
	}

	void SetSize(int newLength) {
		UpCapacity(newLength);
		length = newLength;
		TypeOfElement* X = new TypeOfElement[length];
		delete[] dataPointer;
		dataPointer = X;
	}

private:
	int length;
	int capacity;
	TypeOfElement* dataPointer;

	void UpCapacity(int newCapacity) {
		if (newCapacity > capacity) {
			TypeOfElement* X = new TypeOfElement[newCapacity];
			for (int i = 0; i < length; i++) {
				X[i] = *(dataPointer + i);
			}
			delete[] dataPointer;
			dataPointer = X;
			capacity = newCapacity;
		}
	}

};


template<class Type>
void InputMyVector(MyVector<Type>& inVector, int n) {
	for (int i = 0; i < n; i++) {
		Type vector_element;
		cout << i + 1 << "-ый элемент массива: ";
		cin >> vector_element;
		inVector.PushBack(vector_element);
	}
}

template<class Type>
void OutputMyVector(MyVector<Type>& outVector) {
	cout << endl << "Vector :" << endl;
	for (int i = 0; i < outVector.Length(); i++) {
		cout << outVector[i] << " ";
	}
	cout << endl;
}
