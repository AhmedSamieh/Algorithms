#include <iostream>
#include <assert.h>
#include <map>
#include <limits>

template<class K, class V>
class interval_map
{
    friend void IntervalMapTest();

private:
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const &val)
    {
        m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const &keyBegin, K const &keyEnd, const V &val)
    {
        // INSERT YOUR SOLUTION HERE
        typename std::map<K, V>::iterator start_iter;
        typename std::map<K, V>::iterator end_iter;
        typename std::map<K, V>::iterator pre_start_iter;
        typename std::map<K, V>::iterator post_end_iter;
        V start_v, end_v;

        if (keyBegin >= keyEnd) {
            return;
        }

        start_iter = m_map.lower_bound(keyBegin);
        pre_start_iter = start_iter;
        pre_start_iter--;
        start_v = pre_start_iter->second;
        post_end_iter = m_map.upper_bound(keyEnd);
        end_iter = post_end_iter;
        end_iter--;
        end_v   = end_iter->second;

        if (std::distance(m_map.begin(), post_end_iter) > std::distance(m_map.begin(), start_iter)) {

            m_map.erase(start_iter, post_end_iter);
        }

        if (val != start_v) {
            m_map.insert(pre_start_iter, std::make_pair(keyBegin, val));
        }

        if (val != end_v) {
            m_map.insert(post_end_iter, std::make_pair(keyEnd, end_v));
        }
    }
    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        return (--m_map.upper_bound(key))->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.
void IntervalMapTest()
{
    interval_map<int, char> test_map('Z');
    struct table_tag {
        unsigned int from;
        unsigned int to;
        char         value;
    } table[] = {{0, 10, 'A'}, {4, 7, 'B'}, {6, 9, 'C'}, {2, 5, 'D'}, {1, 8, 'E'}, {3, 5, 'F'}, {5, 7, 'G'}, {0, 2, 'H'}, {2, 3, 'I'}, {2, 3, 'J'}};

    for (std::map<int, char>::iterator it = test_map.m_map.begin();
         it != test_map.m_map.end();
         it++) {
        std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < sizeof(table) / sizeof(struct table_tag); i++) {
        test_map.assign(table[i].from, table[i].to, table[i].value);

        for (std::map<int, char>::iterator it = test_map.m_map.begin();
             it != test_map.m_map.end();
             it++) {
            std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
        }

        std::cout << std::endl;
    }

    /*test_map.assign(2, 8, 'A');
    for (std::map<int, char>::iterator it = test_map.m_map.begin();
         it != test_map.m_map.end();
         it++)
    {
        std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
    }
    std::cout << std::endl;
    test_map.assign(5, 15, 'C');
    for (std::map<int, char>::iterator it = test_map.m_map.begin();
         it != test_map.m_map.end();
         it++)
    {
        std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
    }
    std::cout << std::endl;
    test_map.assign(22, 40, 'A');
    for (std::map<int, char>::iterator it = test_map.m_map.begin();
         it != test_map.m_map.end();
         it++)
    {
        std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
    }
    std::cout << std::endl;
    test_map.assign(13, 37, 'A');*/
    for (std::map<int, char>::iterator it = test_map.m_map.begin();
         it != test_map.m_map.end();
         it++) {
        std::cout << "output key : " << it->first << " , val : " << it->second << std::endl;
    }

    std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    IntervalMapTest();
    return 0;
}
