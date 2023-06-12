#include "MagicalContainer.hpp"
#include <stdio.h>
using namespace ariel;
MagicalContainer::MagicalContainer() : items(), p_prime() {}
MagicalContainer::~MagicalContainer() {
    // delete all the prime numbers
    for (auto it = p_prime.begin(); it != p_prime.end(); it++)
    {
        delete *it;
    } 
}
size_t MagicalContainer::size() { return items.size(); }
bool MagicalContainer::isprime(int element)
{
    if (element <= 1)
    {
        return false;
    }
    for (int i = 2; i < element ; i++)
    {
        if (element % i == 0)
        {
            return false;
        }
    }
    return true;
}
void MagicalContainer::addElement(int element)
{
   // add elemnts in ascending order by value
    if (items.size() == 0 || element > items.back())
    {
        items.push_back(element);
    }
    else
    {
        auto it = items.begin();
        while (it != items.end())
        {
            if (element < *it)
            {
                items.insert(it, element);
                break;
            }
            it++;
        }
    }
    // add prime numbers in ascending order by value
    if (isprime(element))
    {
        if (p_prime.size() == 0 || element > *p_prime.back())
        {
            p_prime.push_back(new int(element));
        }
        else
        {
            auto it = p_prime.begin();
            while (it != p_prime.end())
            {
                if (element < **it)
                {
                    p_prime.insert(it, new int(element));
                    break;
                }
                it++;
            }
        }
    }
}
void MagicalContainer::removeElement(int element)
{
    // if the container is empty
    if (items.size() == 0)
    {
        std::__throw_runtime_error("The container is empty");
    }
    // if the elemnt is not in the container and the end is not the element
    if (find(items.begin(), items.end(), element) == items.end() && items.back() != element)
    {
        std::__throw_runtime_error("The element is not in the container");
    }
    else
    {
        // if the element is prime
        if (isprime(element))
        {
            // find the element in the prime vector
            auto it = find(p_prime.begin(), p_prime.end(), &element);
            // delete the element
            delete *it;
            // remove the element from the vector
            p_prime.erase(it);
        }
    }
    // find the element in the items vector
    auto it = find(items.begin(), items.end(), element);
    // remove the element from the vector
    items.erase(it);
}
