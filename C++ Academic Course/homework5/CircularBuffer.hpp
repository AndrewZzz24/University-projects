#include <iostream>
#include <sstream>

#ifndef IS_2020_PROG_2_SEM_CIRCULARBUFFER_HPP
#define IS_2020_PROG_2_SEM_CIRCULARBUFFER_HPP

template<typename T>
class CircularBuffer {

private:

    T *data;
    int capacity;
    int first_el;
    int last_el;
    bool empty;
    int count_of_active_el;

public:

    explicit CircularBuffer(int size_) {

        if (size_ < 0)
            throw std::out_of_range("impossible size");

        capacity = size_ + 1;
        data = new T[capacity];

        first_el = 0;
        last_el = 0;
        count_of_active_el = 0;
        empty = true;

        for (int i = 0; i < capacity; i++)
            data[i] = 0;

    }

    ~CircularBuffer() {
        //fixed delete[]
        delete[] data;

    }

    //fixed O(1)
    void addFirst(int value) {

        if (count_of_active_el < capacity - 1)
            count_of_active_el++;

        if (empty) {

            data[first_el] = value;
            empty = false;
            return;

        }

        if (first_el - 1 < 0 && !empty) {

            if (last_el == capacity - 1) {

                first_el = last_el;
                last_el--;
                data[first_el] = value;
                return;

            }

            first_el = capacity - 1;
            data[first_el] = value;
            return;

        }

        if (!empty) {

            first_el--;

            if (first_el == last_el + 1) {

                if (last_el - 1 < 0)
                    last_el = capacity - 1;

                else
                    last_el--;

            }

        }

        data[first_el] = value;

    }

    void addLast(int value) {

        count_of_active_el++;

        if (empty) {

            data[first_el] = value;
            empty = false;
            return;

        }

        if (last_el + 1 == capacity) {

            if (first_el == 0) {

                last_el = first_el;
                first_el++;
                data[last_el] = value;
                return;
            }

            last_el = 0;
            data[last_el] = value;

        }

        last_el++;
        data[last_el] = value;

    }

    void delFirst() {

        count_of_active_el--;

        if (first_el == last_el) {

            empty = true;
            return;

        }

        if (first_el + 1 == capacity)
            first_el = 0;

        else
            first_el++;

    }

    void delLast() {
        count_of_active_el--;
        if (first_el == last_el) {

            empty = true;
            return;

        }

        if (last_el - 1 < 0)
            last_el = capacity - 1;
        else
            last_el--;

    }

    void changeCapacity(int new_capacity) {

        new_capacity++;
        T *tmp = new T[new_capacity];

        int counter = 0;

        for (int i = first_el; true; i++) {

            i = i % (capacity);
            tmp[counter] = data[i];

            if (i == last_el)
                break;

            counter++;

        }

        first_el = 0;
        last_el = capacity - 2;

        for (int i = capacity; i < new_capacity; i++)
            tmp[i] = 0;

        capacity = new_capacity;

        data = tmp;

    }

    T first() {

        return data[first_el];

    }

    T last() {

        return data[last_el];

    }

    T &operator[](int value) {

        if (value >= 0 && value < capacity - 1 && !empty) {
            return data[(first_el + value) % (capacity - 1)];
        }

        //fixed more information
        if (empty)
            throw std::out_of_range("Impossible to get the element: the buffer is empty");

        std::stringstream ss;
        ss << "Number " << value << " is out of buffer's range\n";
        ss << "Available elemets are from 0 to " << count_of_active_el;
        throw std::out_of_range(ss.str());

    }

    T operator[](int value) const {

        if (value >= 0 && value < capacity - 1 && !empty) {
            return data[(first_el + value) % (capacity - 1)];
        }

        //fixed more information
        if (empty)
            throw std::out_of_range("Impossible to get the element: the buffer is empty");

        std::stringstream ss;
        ss << "Number " << value << " is out of buffer's range\n";
        ss << "Available elemets are from 0 to " << count_of_active_el;
        throw std::out_of_range(ss.str());

    }

    void print_buf() {

        if (!empty) {

            std::cout << "first " << first_el << " last " << last_el << std::endl;

            for (int i = first_el; true; i++) {
                i = i % (capacity);
                std::cout << data[i] << ' ';
                if (i == last_el)
                    break;
            }

            std::cout << std::endl;

        }

    }

    class CBIterator {
    private:

        T *ptr;
        T *ptr_to_beggining;
        T *ptr_to_end;
        T *end;

    public:

        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;

        explicit CBIterator(T *ptr_, T *ptr_2, T *ptr_3, T *end_) {

            ptr = ptr_;
            ptr_to_end = ptr_3;
            ptr_to_beggining = ptr_2;
            end = end_;

        }

        ~CBIterator() = default;

        bool operator!=(CBIterator const &other) const {

            return other.ptr != ptr;

        }

        bool operator==(CBIterator const &other) const {

            return other.ptr == ptr;

        }

        bool operator<(CBIterator const &other) const {

            if (this->ptr > end && other.ptr > end)
                return this->ptr < other.ptr;

            if (this->ptr < end && other.ptr < end)
                return this->ptr < other.ptr;

            if (this->ptr > end)
                return true;

            else
                return false;

        }

        bool operator>(CBIterator const &other) const {

            if (this->ptr > end && other.ptr > end)
                return this->ptr > other.ptr;

            if (this->ptr < end && other.ptr < end)
                return this->ptr > other.ptr;

            if (this->ptr > end)
                return false;

            else
                return true;

        }

        CBIterator &operator++() {

            if (ptr + 1 == ptr_to_end)
                ptr = ptr_to_beggining;
            else
                ptr++;

            return *this;

        }

        CBIterator &operator--() {

            if (ptr - 1 == ptr_to_beggining - 1)
                ptr = ptr_to_end - 1;

            else
                ptr--;

            return *this;

        }

        CBIterator operator++(int) {

            CBIterator tmp(ptr, ptr_to_beggining, ptr_to_end, end);

            if (ptr + 1 == ptr_to_end)
                ptr = ptr_to_beggining;

            else
                ptr++;

            return tmp;

        }

        CBIterator operator--(int) {

            CBIterator tmp(ptr, ptr_to_beggining, ptr_to_end, end);

            if (ptr - 1 == ptr_to_beggining - 1)
                ptr = ptr_to_end - 1;

            else
                ptr--;

            return tmp;

        }

        CBIterator operator-(int n) {

            CBIterator tmp(ptr, ptr_to_beggining, ptr_to_end, end);

            if (tmp.ptr - n < ptr_to_beggining) {

                n = n - (tmp.ptr - ptr_to_beggining) - 1;
                tmp.ptr = ptr_to_end - 1 - n;

            } else {

                tmp.ptr -= n;

                if (tmp.ptr <= end && this->ptr > end)
                    tmp.ptr--;

            }

            return tmp;

        }

        CBIterator operator+(int n) {

            CBIterator tmp(ptr, ptr_to_beggining, ptr_to_end, end);

            if (tmp.ptr + n >= ptr_to_end) {

                n = n - (ptr_to_end - tmp.ptr);
                tmp.ptr = ptr_to_beggining + n;

                if (tmp.ptr >= end && this->ptr < end)
                    tmp.ptr++;

            } else
                tmp.ptr += n;

            return tmp;

        }

        int operator-(CBIterator &other) {

            int res = this->ptr - other.ptr;

            if (res < 0) res += ptr_to_end - ptr_to_beggining;

            return res;

        }

        T &operator*() const {

            return *ptr;

        }

    };


    CBIterator begin() const {

        return CBIterator(data + first_el, data, data + capacity, data + last_el + 1);

    };

    CBIterator end() const {

        return CBIterator(data + last_el + 1, data, data + capacity, data + last_el + 1);

    };

};


#endif //IS_2020_PROG_2_SEM_CIRCULARBUFFER_HPP
