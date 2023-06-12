#include "MagicalContainer.hpp"
using namespace ariel;
// constructor for prime iterator 
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {
    iterator = new size_t(0);
}
// copy constructor for prime iterator
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), iterator(new size_t(*other.iterator)) {}
// destructor for prime iterator
MagicalContainer::PrimeIterator::~PrimeIterator() { delete iterator;}
// begin function for prime iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator begin = PrimeIterator(*this);
    if (this->container->p_prime.size() == 0)
    {
        // throw runtime error when the container is empty
        std::__throw_runtime_error("The container is empty");
    }
    begin.iterator = new size_t(0);
    return begin;
}
// end function for prime iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator end = PrimeIterator(*this);
    if (this->container->p_prime.size() == 0)
    {
        return end;
    }
    end.iterator = new size_t(this->container->p_prime.size());
    return end;
}
// override the * operator to pull the elemnt from the vector
int &MagicalContainer::PrimeIterator::operator*() const
{
    // return the prime number
    return *this->container->p_prime.at(*iterator);
}
// override the ++ operator to move the iterator to the next element
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    // throw runtime error when there is no next prime number
    if (this->container->p_prime.size() == 0 || *iterator == this->container->p_prime.size())
    {
        std::__throw_runtime_error("The iterator is at the end");
    }
    // move the iterator to the next prime number
    (*iterator)++;
    return *this;
}
// override the == operator to check if the iterators are equal
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return *iterator == *other.iterator;
}
// override the != operator to check if the iterators are not equal
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return *iterator != *other.iterator;
}

// override the = operator to make an assignment between iterators
void MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    // throws when iterators are pointing at different containers
    if (this->container != other.container)
    {
        std::__throw_runtime_error("Iterators are pointing at different containers");
    }
    *iterator = *other.iterator;
}
// override the < operator to check if the iterator is smaller than the other iterator
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return *iterator < *other.iterator;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return *iterator > *other.iterator;
}