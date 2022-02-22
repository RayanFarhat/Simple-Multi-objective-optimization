
/////////////////////////////////////////////////////////////////////////
template <class T>
Element<T>::Element(T *x, T *f, size_t n1, size_t m1)
{
    //copy feasible solution vector info
    X = new T[n1];
    for (int i = 0; i < n1; i++)
    {
        X[i] = x[i];
    }
    //copy objective vector info
    F = new T[m1];
    for (int i = 0; i < m1; i++)
    {
        F[i] = f[i];
    }
    //copy other info
    rank = 0;
    n = n1;
    m = m1;
}

/////////////////////////////////////////////////////////////////////////
template <class T>
Element<T>::Element(const Element<T> &e)
{
    X = 0;     // enabling deletion
    F = 0;     // enabling deletion
    *this = e; // uses overloaded operator=
}

/////////////////////////////////////////////////////////////////////////
template <class T>
Element<T>::~Element()
{
    delete[] X; // deleting
    delete[] F; // deleting
}

/////////////////////////////////////////////////////////////////////////
template <class T>
bool Element<T>::operator==(const Element<T> &e)
{
    if (this->rank != e.get_rank())
        return false;

    if (this->n != e.get_n())
        return false;

    if (this->m != e.get_m())
        return false;

    for (int i = 0; i < n; i++)
    {
        if (this.X[i] != e.get_X()[i])
            return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (this.F[j] != e.get_F()[j])
            return false;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////
template <class T>
Element<T> &Element<T>::operator=(const Element<T> &e)
{
    if (&e == this) // uses overloaded operator==
        return *this;

    delete[] X; // deleting
    n = e.get_n();

    //copy feasible solution vector info
    X = new T[n];
    for (int i = 0; i < n; i++)
        X[i] = e.get_X()[i];

    delete[] F; // deleting
    m = e.get_m();

    //copy objective vector info
    F = new T[m];
    for (int j = 0; j < m; j++)
        F[j] = e.get_F()[j];

    this->rank = e.get_rank();

    return *this;
}

/////////////////////////////////////////////////////////////////////////