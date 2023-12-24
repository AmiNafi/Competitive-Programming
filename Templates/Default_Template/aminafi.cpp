
#include <map>
#include <iostream>
// using namespace std;
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K,V> m_map;
public:
    void printmap() {
        std::cout << " begin = ";
        m_valBegin.print();
        std::cout << "\n";
        // m_valBegin.print();
        for (auto it = m_map.begin(); it != m_map.end(); it++) {
            K key = it->first;
            V val = it->second;
            key.print();
            val.print();
            std::cout << "\n";
        }
    }
    // constructor associates whole range of K with val
    interval_map(V const& val)
    : m_valBegin(val)
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ){
        if (!(keyBegin < keyEnd)) {
            return;
        }
        // map empty
        if (m_map.empty()) {
            if (!(val == m_valBegin)) {
                m_map.insert(m_map.end(), std::make_pair(keyBegin, val));
                m_map.insert(m_map.end(), std::make_pair(keyEnd, m_valBegin));
            }
            return;
        }
        V prevBeginVal = m_valBegin, prevEndVal = m_valBegin;
        // whole interval is in last
        auto it = m_map.lower_bound(keyBegin);

        // if (it == m_map.end() || keyBegin < it->first) {
        if (it == m_map.begin()) prevBeginVal = m_valBegin;
        else {
            it--;
            prevBeginVal = it->second;
            it++;
        }
        prevEndVal = prevBeginVal;
        // m_map.insert_or_assign(it, std::make_pair(keyBegin, val));
        while (it != m_map.end()) {
            if (keyEnd < it->first) break;
            prevEndVal = it->second;
            auto nit = it;
            it++;
            m_map.erase(nit);
        }
        if (prevBeginVal == val && prevEndVal == val) return;
        else if (prevBeginVal == val) m_map.insert_or_assign(it, keyEnd, prevEndVal);
        else if (prevEndVal == val) m_map.insert_or_assign(it, keyBegin, val);
        else {
            m_map.insert_or_assign(it, keyBegin, val);
            m_map.insert_or_assign(it, keyEnd, prevEndVal);
        }

    }


    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        auto it=m_map.upper_bound(key);
        if(it==m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

#include <iostream>
struct K
{
    int c;
    bool operator< (const K& x) const {
        return c < x.c;
    }
    K* operator=(const K& x) {
        c = x.c;
        return this;
    }
    void print() {
        std::cout << " key = " << c;
    }

};
struct V {
    char c;
    bool operator< (const V& x) const {
        return c < x.c;
    }
    V* operator=(const V& x) {
        c = x.c;
        return this;
    }
    bool operator== (const V& x) const {
        return c == x.c;
    }
    void print() {
        std::cout << " value = " << c;
    }
};


int main () {   
    int x, y;
    char c;
    V v;
    v.c = 'A';
    interval_map <K, V> mp(v);
    while (std::cin >> x >> y >> c) {
        v.c = c;
        K k1, k2;
        k1.c = x;
        k2.c = y;
        mp.assign(k1, k2, v);
        mp.printmap();
    }
    return 0;
}