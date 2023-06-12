#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), iterator(new size_t(*other.iterator)) {}
MagicalContainer::SideCrossIterator::~SideCrossIterator() { delete iterator; }
// begin function for side cross iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    SideCrossIterator begin = SideCrossIterator(*this);
    begin.iterator = new size_t(0);
    return begin;
}
// end function for side cross iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator end = SideCrossIterator(*this);
    end.iterator = new size_t(this->container->items.size());
    return end;
}
// override the * operator to pull the elemnt from the vector
int &MagicalContainer::SideCrossIterator::operator*() const
{
    return this->container->items[*iterator];
}
// override the ++ operator to move the iterator to the next element
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    // Throw a runtime error when the iterator is at the end
    if (*iterator >= this->container->items.size())
    {
        std::__throw_runtime_error("The iterator is at the end");
    }

    // Handle the special case when the iterator is at the middle position
    if (*iterator == this->container->items.size() / 2)
    {
        *iterator = *this->end().iterator; // Set iterator to the end position
    }
    else
    {
        // Move the iterator to the next position based on its current position
        if (*iterator < this->container->items.size() / 2)
        {
            *iterator = this->container->items.size() - *iterator - 1;
        }
        else
        {
            *iterator = this->container->items.size() - *iterator;
        }
    }

    return *this;
}

// override the == operator to check if the iterators are equal
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return *iterator == *other.iterator;
}
// override the != operator to check if the iterators are not equal
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return *iterator != *other.iterator;
}

// override the = operator to make an assignment between iterators
void MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    // throws when iterators are pointing at different containers
    if (this->container != other.container)
    {
        std::__throw_runtime_error("Iterators are pointing at different containers");
    }
    *iterator = *other.iterator;
}
// override the < operator to check if the iterator is smaller than the other iterator
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return *iterator < *other.iterator;
}
// override the > operator to check if the iterator is bigger than the other iterator
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return *iterator > *other.iterator;
}