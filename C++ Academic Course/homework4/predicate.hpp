#include <iterator>
#include <iostream>

#ifndef IS_2020_PROG_2_SEM_PREDICATE_HPP
#define IS_2020_PROG_2_SEM_PREDICATE_HPP


template<class TIterator, class Tpredicate>
bool allOf(TIterator begin, TIterator end, Tpredicate func) {

    for (; begin != end; begin++) {

        if (!func(*begin))
            return false;

    }

    return true;

}


template<class TIterator, class Tpredicate>
bool anyOf(TIterator begin, TIterator end, Tpredicate func) {

    for (; begin != end; begin++) {

        if (func(*begin))
            return true;
    }

    return false;

}


template<class TIterator, class Tpredicate>
bool noneOf(TIterator begin, TIterator end, Tpredicate func) {

    for (; begin != end; begin++) {

        if (func(*begin))
            return false;

    }

    return true;

}


template<class TIterator, class Tpredicate>
bool oneOf(TIterator begin, TIterator end, Tpredicate func) {

    bool first_time = true;

    for (; begin != end; begin++) {

        if (func(*begin)) {

            if (first_time)
                first_time = false;

            else
                return false;

        }

    }

    if (!first_time)
        return true;

    return false;

}

//fixed use default template argument with std::less
template<class TIterator, class Tpredicate=std::less<>>
bool isSorted(TIterator begin, TIterator end, Tpredicate func = Tpredicate()) {

    for (; begin != end - 1; begin++) {

        if (!func(*begin, *(begin + 1)))
            return false;

    }

    return true;

}

template<class TIterator, class TPredicate>
bool isPartitioned(TIterator begin, TIterator end, TPredicate func) {

    bool curr_result = func(*begin);
    bool elem_exists = false;

    for (; begin != end; begin++) {

        if (func(*begin) != curr_result) {

            if (!elem_exists) {

                elem_exists = true;
                curr_result = func(*begin);

            } else
                return false;

        }
    }
    return true;

}


template<class TIterator, class TCollection>
TIterator findNot(TIterator begin, TIterator end, TCollection value) {

    for (; begin != end; begin++) {

        if (*begin != value)
            return begin;
    }

    return end;

}

template<class TIterator, class TCollection>
TIterator findBackward(TIterator begin, TIterator end, TCollection value) {

    TIterator result = end;

    for (; begin != end; begin++) {

        if (*begin == value)
            result = begin;

    }

    return result;

}

template<class TIterator, class TPredicate>
bool isPalindrome(TIterator begin, TIterator end, TPredicate func) {

    int counter = 1;

    for (; begin != end; begin++) {

        if (!func(*begin, *(std::prev(end, counter))))
            return false;

        counter++;

    }

    return true;

}

#endif //IS_2020_PROG_2_SEM_PREDICATE_HPP
