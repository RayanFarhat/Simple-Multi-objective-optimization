#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <iostream>

/*
* object that contain:
* 1.feasible solution vector
* 2.objective vector
* 3.his rank with other objects
* 4.the dimension of feasible solution vector
* 5.the dimension of objective vector
* and their implementation
*/
template <class T>
class Element
{
private:
    /* feasible solution vector */
    T *X;
    /* objective vector */
    T *F;
    /* object rank with other objects */
    int rank;
    /* the dimension of feasible solution vector */
    size_t n;
    /* the dimension of objective vector */
    size_t m;

public:
    /* Constructor */
    Element(T *x, T *f, size_t n1, size_t m1);

    /* Copy Constructor */
    Element(const Element<T> &e);

    /* Destructor */
    ~Element();

    /* get the dimension of feasible solution vector */
    inline int get_n() const
    {
        return n;
    }

    /* set the dimension of feasible solution vector */
    inline void set_n(int n)
    {
        this->n = n;
        ;
    }

    /* get the dimension of objective vector */
    inline int get_m() const
    {
        return m;
    }

    /* set the dimension of objective vector */
    inline void set_m(int m)
    {
        this->m = m;
        ;
    }

    /* get object rank */
    inline int get_rank() const
    {
        return rank;
    }

    /* set object rank */
    inline void set_rank(int rank)
    {
        this->rank = rank;
    }

    /* get feasible solution vector to change it */
    inline T *get_X()
    {
        return X;
    }

    /* get feasible solution vector value */
    inline const T *get_X() const
    {
        return X;
    }

    /* get objective vector to change it */
    inline T *get_F()
    {
        return F;
    }

    /* get objective vector value */
    inline const T *get_F() const
    {
        return F;
    }

    /* check if this object same as the other object*/
    bool operator==(const Element<T> &e);

    /* make this object a copy of the other object */
    Element<T> &operator=(const Element<T> &e);
};

/* include Element class implementation
* (did it in other header to deal with templates)
*/
#include "Element_imp.h"

#endif // ELEMENT_H_INCLUDED
