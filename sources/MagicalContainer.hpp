#include <vector>
using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> items;
        vector<int *> p_prime;

    public:
        size_t size();
        MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        bool isprime(int element);
        class AscendingIterator : public iterator<forward_iterator_tag, int> // forward_iterator_tag
        {
        private:
            MagicalContainer *container;
            size_t *iterator;

        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();
            AscendingIterator begin();
            AscendingIterator end();
            MagicalContainer *get_container();
            size_t *get_iterator();
            int &operator*() const;
            AscendingIterator& operator++();
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            void operator=(const AscendingIterator &other);
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
        };
        class SideCrossIterator : public iterator<forward_iterator_tag, int> // forward_iterator_tag
        {
        private:
            MagicalContainer *container;
            size_t *iterator;

        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();
            SideCrossIterator begin();
            SideCrossIterator end();
            MagicalContainer *get_container();
            size_t *get_iterator();
            int &operator*() const;
            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            void operator=(const SideCrossIterator &other);
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
        };
        class PrimeIterator : public iterator<forward_iterator_tag, int> // forward_iterator_tag
        {
        private:
            MagicalContainer *container;
            size_t *iterator; //should point to container->p_prime.at(0)

        public:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
            PrimeIterator begin();
            PrimeIterator end();
            MagicalContainer *get_container();
            size_t *get_iterator();
            int &operator*() const;
            PrimeIterator& operator++();
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            void operator=(const PrimeIterator &other);
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
        };
    };
} // namespace ariel