#include <iterator>
namespace IPHTC
{
    template <typename T>
    class Enumerate
    {
    public:
        using TIter = decltype(std::begin(std::declval<T>()));
        using TVal = decltype(*std::declval<TIter>());

    public:
        class iterator
        {
        public:
            using value_type = std::pair<const size_t, TVal>;
            using reference=value_type;
        public:
            iterator() = default;
            iterator(size_t size, TIter iter):m_size(size),m_iter(iter){}
            iterator &operator++(){++m_size;++m_iter;return *this;}
            iterator operator++(int){iterator tmp=*this;++*this;return tmp;}
            bool operator!=(const iterator &other) const {return m_iter != other.m_iter;}
            bool operator==(const iterator &other) const {return m_iter == other.m_iter;}
            reference operator* () const{return {m_size,*m_iter};}
        private:
            size_t m_size;
            TIter m_iter;
        };

    public:
        Enumerate(T iterable):m_iterable{iterable}{
            //m_size=std::distance(std::begin(m_iterable),std::end(m_iterable));
        }
        iterator begin() const{return iterator{0,std::begin(m_iterable)};}
        iterator end() const{return iterator{0,std::end(m_iterable)};}
        //iterator begin() const{return iterator{0,std::begin(m_iterable)};}
        //iterator end() const{return iterator{0,std::end(m_iterable)};}
        //const size_t size() const{return m_size;}
    private:
        T m_iterable;
        //size_t m_size;
    };
};

#include <utility>
namespace IPHTC
{
    template <typename T>
    Enumerate<T> enumerate(T &&iterable)
    {
        return {std::forward<T>(iterable)};
    }
};

// You may test your own implementation with this function.
#include <iostream>
#include <string>
#include <vector>
#include <list>
void test()
{
    for (auto [i, x] : IPHTC::enumerate(std::vector<int>{1, 2, 3, 4, 5}))
    {
        std::cout << i << ": " << x << '\n';
    }
    std::string s = "Hello, World!";
    for (auto [i, c] : IPHTC::enumerate(s))
    {
        std::cout << i << ": " << c << '\n';
        c = '3';
    }
    std::list<int> l{1, 2, 3, 4, 5};
    for (auto [i, x] : IPHTC::enumerate(l))
    {
        std::cout << i << ": " << x << '\n';
        x = 3;
    }
}