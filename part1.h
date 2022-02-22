#ifndef PART1_H_INCLUDED
#define PART1_H_INCLUDED
#include "Element.h"
#include <vector>

/*
* Algorithm that get array of objective vectors 'f' and there sizes
* and other array 'ranks' that will save the rank of every objective vector object in the same order.
*/
template <class T>
int *ParetoRanking(int *ranks, T **f, int vsize, int m)
{

    for (int i = 0; i < vsize; i++)
        ranks[i] = 0;
    int is_dominant = 0;

    for (int i = 0; i < vsize; i++)
    {
        for (int j = 0; j < vsize; j++)
        {
            is_dominant = 0;
            for (int k = 0; k < m; k++)
            {
                if (f[i][k] > f[j][k])
                    is_dominant = 1;
            }
            if (is_dominant == 1)
                ranks[i]++;
        }
    }
    return ranks;
}

/* Algorithm that get array of objects 'Elements' and sort it with regard to their ranks. */
template <class T>
void ElementsReordering(std::vector<Element<T> *> &Elements)
{
    for (int i = 0; i < (int)Elements.size(); i++)
    {
        for (int j = i + 1; j < Elements.size(); j++)
        {
            if (Elements[i]->get_rank() > Elements[j]->get_rank())
            {
                //swap objects places in array
                Element<T> temp = *Elements[i];
                *Elements[i] = *Elements[j];
                *Elements[j] = temp;
            }
        }
    }
}

/*
* Algorithm that get array of objects 'Elements'
* and implement the two functions 'ParetoRanking' and 'ElementsReordering'
* to sort the objects with regard to their Pareto (dominate), start from most dominated object to least  dominated object.
* that is, In mathematical terms, an object x1 is said to (Pareto) dominate another object x2 if :
* 1. x1.F[i] <= x2.F[i] for all indexes i.
* 2. x1.F[i] < x2.F[i] for at least one index i.
*/
template <class T>
void ParetoSorting(std::vector<Element<T> *> &Elements)
{
    //insert objects objective vectors to the array
    T *funcs_arr[Elements.size()];
    for (int i = 0; i < (int)Elements.size(); i++)
    {
        funcs_arr[i] = Elements[i]->get_F();
    }

    //calculate their ranks
    int *ranks = new int[Elements.size()];
    ranks = ParetoRanking(ranks, funcs_arr, Elements.size(), Elements[0]->get_m());

    for (int j = 0; j < (int)Elements.size(); j++)
    {
        Elements[j]->set_rank(ranks[j]);
    }
    delete[] ranks;

    //sort objects
    ElementsReordering(Elements);
}

//Note: made it in one header to deal with templates

#endif // PART1_H_INCLUDED
