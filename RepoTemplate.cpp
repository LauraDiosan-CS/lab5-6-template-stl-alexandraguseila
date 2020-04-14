/*#include "RepoTemplate.h"

template <class T>
Repo<T>::Repo()
{

}


template<class T>
Repo<T>::~Repo()
{
    this->elements.clear();
}

template<class T>
void Repo<T>::clear()
{
    this->elements.clear();
}


template<class T>
void Repo<T>::add_element(T e)
{
    this->elements.push_back(e);
}


template<class T>
void Repo<T>::del_element(T p)
{
    typename vector<T>::iterator it;
		it = find(this->elements.begin(), this->elements.end(), p);
		if (!(it == this->elements.end()))
		{
			this->elements.erase(it);
		}
}


template<class T>
void Repo<T>::update_element(T& old_product, T& new_product)
{
    typename vector <T>::iterator it;
		it = find(this->elements.begin(), this->elements.end(), old_product);
		if (!(it == this->elements.end()))
		{
			*it = new_product;
		}
}


template<class T>
vector<T> Repo<T>::show_elements()
{
    return this->elements;
}

template<class T>
int Repo<T>::get_size()
{
    return this->elements.size();
}

template<class T>
T Repo<T>::get_element(int pos)
{
    return this->elements[pos];
}*/

