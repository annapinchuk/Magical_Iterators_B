#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), iterator(new size_t(*other.iterator)) {}
MagicalContainer::AscendingIterator::~AscendingIterator() { delete iterator; }
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    AscendingIterator begin = AscendingIterator(*this);
    if (this->container->items.size() == 0)
    {
        return begin;
    }
    begin.iterator = new size_t(0);
    return begin;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator end = AscendingIterator(*this);
    if (this->container->items.size() == 0)
    {
        return end;
    }
    end.iterator = new size_t(this->container->items.size());
    return end;
}
// override the * operator to pull the elemnt from the vector
int &MagicalContainer::AscendingIterator::operator*() const
{
    return this->container->items[*iterator];
}
// override the ++ operator to move the iterator to the next element
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if (*iterator >= this->container->items.size())
    {
        std::__throw_runtime_error("The iterator is at the end");
    }
    (*iterator)++;
    return *this;
}
// override the == operator to check if the iterators are equal
bool MagicalContainer::AscendingIterator::operator==(const  MagicalContainer::AscendingIterator &other) const
{
    return *iterator == *other.iterator;
}
// override the != operator to check if the iterators are not equal
bool MagicalContainer::AscendingIterator::operator!=(const  MagicalContainer::AscendingIterator &other) const
{
    return *iterator != *other.iterator;
}

// override the = operator to make an assignment between iterators
void MagicalContainer::AscendingIterator::operator=(const  MagicalContainer::AscendingIterator &other)
{
    // throws when iterators are pointing at different containers
    if (this->container != other.container)
    {
        std::__throw_runtime_error("Iterators are pointing at different containers");
    }
    *iterator = *other.iterator;
}
// override the < operator to check if the iterator is smaller than the other iterator
bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const
{
    return *iterator < *other.iterator;
}
// override the > operator to check if the iterator is bigger than the other iterator
bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const
{
    return *iterator > *other.iterator;
}

