#include <iostream>
#define PrintVal(Param) (cout << "{" #Param "}: " << (Param) << endl)// маккрос

using namespace std;

template <class MyType> // макет функций для замены векторов друг с другом
void MySwap(MyType& element1, MyType& element2) {
	MyType element3 = element1;
	element1 = element2;
	element2 = element3;
}


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
		ChangeCapacity(length + 1);
		*(dataPointer + length) = newElement;
		length++;
	}

	void Reverse() {
		TypeOfElement* temporary = new TypeOfElement[length];
		for (int i = (length - 1); i > 0; i--) {
			temporary[length - i] = dataPointer[i];
		}
		delete[] dataPointer;
		dataPointer = temporary;
	}

	void print() {
		for (int i = 0; i < length; i++) {
			cout << dataPointer[i] << " ";
		}
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
		ChangeCapacity(newLength);
		length = newLength;
	}

private:
	int length;
	int capacity;
	TypeOfElement* dataPointer;

	void ChangeCapacity(int newCapacity) {
		if (newCapacity > capacity) {
			TypeOfElement* X = new TypeOfElement[newCapacity];
			for (int i = 0; i < length; i++) {
				X[i] = *(dataPointer + i);
			}
			delete[] dataPointer;
			this->dataPointer = X;
			capacity = newCapacity;
		}
		else {
			capacity = newCapacity;
			TypeOfElement* X = new TypeOfElement[newCapacity];
			for (int i = 0; i < capacity; i++) {
				X[i] = *(dataPointer + i);
			}
			delete[] dataPointer;
			dataPointer = X;
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
