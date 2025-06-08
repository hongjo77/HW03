#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;

protected:
    void resize(int newCapacity);

public:
    SimpleVector();
    SimpleVector(int capacity);
    SimpleVector(const SimpleVector& other);
    ~SimpleVector();

    void push_back(const T& value);
    void pop_back();
    int size();
    int capacity();
    void sortData();

    T& operator[](int index) {
        return data[index];
    }
    const T& operator[](int index) const {
        return data[index];
    }

};

template<typename T>
SimpleVector<T>::SimpleVector() : data(new T[10]), currentSize(0), currentCapacity(10) {}

template<typename T>
SimpleVector<T>::SimpleVector(int capacity)
    : data(new T[capacity]), currentSize(0), currentCapacity(capacity) {
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other) : data(new T[other.currentCapacity]), currentSize(other.currentSize), currentCapacity(other.currentCapacity)
{
    for (int i = 0; i < currentSize; i++)
    {
        data[i] = other.data[i];
    }
}

template<typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template<typename T>
void SimpleVector<T>::resize(int newCapacity) {
    if (newCapacity > currentCapacity)
    {
        T* newdata = new T[newCapacity];
        for (int i = 0; i < currentSize; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        currentCapacity = newCapacity;
    }
}

template<typename T>
void SimpleVector<T>::push_back(const T& value) {
    if (currentSize == currentCapacity)
    {
        resize(currentCapacity + 5);
    }
    data[currentSize++] = value;
}

template<typename T>
void SimpleVector<T>::pop_back() {
    if (currentSize > 0)
    {
        currentSize--;
    }
}

template<typename T>
int SimpleVector<T>::size() {
    return currentSize;
}

template<typename T>
int SimpleVector<T>::capacity() {
    return currentCapacity;
}

template<typename T>
void SimpleVector<T>::sortData() {
    std::sort(data, data + currentSize);
}