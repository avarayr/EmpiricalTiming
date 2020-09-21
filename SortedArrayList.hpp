#include <memory>
#include <functional>
#include <algorithm>

using namespace std;

#ifndef EMPIRICALTIMING_SORTEDARRAYLIST_HPP
#define EMPIRICALTIMING_SORTEDARRAYLIST_HPP


#define ORIGINAL_CAPACITY 10

template<typename T>
class SortedArrayList {
private:
    T *data = new T[ORIGINAL_CAPACITY];
    int _capacity = ORIGINAL_CAPACITY;
    int _size = 0;

    void resize(int newCapacity);

    void insertAt(int index, T item);


public:
    SortedArrayList();

    /**
     * Constructor for SortedArrayList with initial capacity
     * @param capacity Initial capacity
     */
    explicit SortedArrayList(int capacity);

    /**
     * Adds an item to the sorted array
     * @param item
     * @return true if successful
     */
    bool add(T item);

    /**
     * Current Capacity of the sorted array list
     * @return
     */
    int capacity();

    /**
     * Clears the sorted array list
     */
    void clear();

    /**
     * Gets an item at index
     * @param index
     * @return The item
     */
    T get(int index);

    /*
     * Returns whether the sorted array list is empty
     */
    bool isEmpty();

    /**
     * Removes an item at index
     * @param index
     * @return the item removed
     */
    T remove(int index);

    /**
     * Returns the physical size of the array list
     * @return
     */
    int size();

    virtual ~SortedArrayList();

};

template<typename T>
SortedArrayList<T>::SortedArrayList() = default;

template<typename T>
SortedArrayList<T>::SortedArrayList(int capacity):_capacity(capacity) {}

template<typename T>
bool SortedArrayList<T>::add(T item) {
    if (_size + 1 >= _capacity) {
        resize(_capacity * 2);
    }


    // Check if empty, skip the loop
    if (_size == 0) {
        data[0] = item;
        _size++;
        return true;
    }

    // Check if bigger than the last element, skip the loop
    if (data[_size - 1] < item) {
        data[_size] = item;
        _size++;
        return true;
    }

    // Check if item is in the middle
    for (int i = 0; i < _size; i++) {
        if (item < data[i]) {
            insertAt(i, item);
            return true;
        }
    }

}

template<typename T>
int SortedArrayList<T>::capacity() {
    return _capacity;
}

template<typename T>
void SortedArrayList<T>::clear() {
    delete[] data;
    T *newData = new T[_capacity];
    data = newData;
    _size = 0;
}

template<typename T>
T SortedArrayList<T>::get(int index) {
    assert(index < _size);
    return data[index];
}

template<typename T>
bool SortedArrayList<T>::isEmpty() {
    return _size == 0;
}

template<typename T>
T SortedArrayList<T>::remove(int index) {
    assert(index >= 0 && index < _size);

    T item = data[index];
    for (int i = index; i < _size - 1; i++) {
        data[i] = data[i + 1];
    }
    _size--;

    if (_size > 0
        && _capacity > ORIGINAL_CAPACITY
        && _capacity % _size == 0 // capacity is evenly divisible by actual size
        && _capacity / _size >= 2  // capacity is exactly 2 (or more) times the actual size
            ) {
        resize(_size);
    }
    return item;
}

template<typename T>
int SortedArrayList<T>::size() {
    return _size;
}

template<typename T>
void SortedArrayList<T>::resize(int newCapacity) {
    T *newData = new T[newCapacity];
    std::copy(data, data + std::min(_capacity, newCapacity), newData);
    delete[] data;
    data = newData;
    _capacity = newCapacity;
}

template<typename T>
void SortedArrayList<T>::insertAt(int index, T item) {
    // This function assumes there is already enough capacity
    assert(_capacity > _size + 1);

    for (int j = _size; j > index; j--) {
        data[j] = data[j - 1];
    }

    data[index] = item;
    _size++;
}

template<typename T>
SortedArrayList<T>::~SortedArrayList() {
    delete[] data;
}

#endif //EMPIRICALTIMING_SORTEDARRAYLIST_HPP
