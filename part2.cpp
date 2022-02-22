
#include "part2.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////
void sorting(vector<Element<double> *> &Elements)
{
    for (int i = 0; i < (int)Elements.size(); i++)
    {
        Elements[i]->set_rank(0);
    }
    ParetoSorting(Elements);
}

/////////////////////////////////////////////////////////////////////////
void increase_vector_by_random(double *vect, const int &vect_dim)
{
    for (int k = 0; k < vect_dim; k++)
    {
        double random_num = ((double)(rand() % 11)) / 10.0;
        vect[k] += random_num;
    }
}

/////////////////////////////////////////////////////////////////////////
void get_first_line(fstream &file, int &Element_num, int &vect_dim, int &funcs_dim, int &rounds)
{
    string word;
    file >> word;
    Element_num = atoi(word.c_str());
    file >> word;
    vect_dim = atoi(word.c_str());
    file >> word;
    funcs_dim = atoi(word.c_str());
    file >> word;
    rounds = atoi(word.c_str());
}

/////////////////////////////////////////////////////////////////////////
void create_vector(fstream &file, const int &vect_dim, double *vec, const int &Element_num, const int &line_counter)
{
    string word;
    int counter = 0;
    char c;
    for (int j = 0; j < vect_dim; j++)
    {
        counter++;
        file >> word;
        vec[j] = atof(word.c_str());
        if (counter == vect_dim)
        {
            file.get(c);
            if ((line_counter - 1) != Element_num)
            {
                if (c != '\n')
                {
                    throw line_counter;
                }
            }
            else
            {
                if (!file.eof())
                {
                    throw line_counter;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////
void create_funcs(const int &funcs_dim, const int &vect_dim, double *funcs, double *vec)
{
    double e = 0.0;
    for (int j = 0; j < funcs_dim; j++)
    {
        double sum = 0.0;
        e++;
        double temp;
        for (int k = 0; k < vect_dim; k++)
        {
            temp = vec[k] - e;
            sum += temp * temp;
        }
        funcs[j] = sum;
    }
}

/////////////////////////////////////////////////////////////////////////
void create_elements(fstream &file, vector<Element<double> *> &Elements, const int &Element_num, const int &vect_dim, const int &funcs_dim)
{
    int line_counter = 1;
    for (int i = 0; i < Element_num; i++)
    {
        line_counter++;

        double *vec = new double[vect_dim];
        create_vector(file, vect_dim, vec, Element_num, line_counter);

        double *funcs = new double[funcs_dim];
        create_funcs(funcs_dim, vect_dim, funcs, vec);

        Element<double> *e = new Element<double>(vec, funcs, vect_dim, funcs_dim);
        Elements.push_back(e);

        delete[] funcs;
        delete[] vec;
    }
}

/////////////////////////////////////////////////////////////////////////
void clear_memory(vector<Element<double> *> &Elements, const int &Element_num)
{
    for (int i = 0; i < Element_num; i++)
    {
        Element<double> *e = Elements.back();
        Elements.pop_back();
        delete e;
    }
}

/////////////////////////////////////////////////////////////////////////
void generate_solution(const int &rounds, const int &Element_num, vector<Element<double> *> &Elements)
{
    srand(time(0));
    for (int i = 0; i < rounds; i++)
    {
        for (int j = 0; j < Element_num; j++)
        {
            double v[] = {0.0, 0.0};
            double f[] = {0.0, 0.0};
            Element<double> *new_copy = new Element<double>(v, f, 2, 2);
            *new_copy = *Elements[j];

            double *vect = new_copy->get_X();
            double *funcs = new_copy->get_F();
            int n = new_copy->get_n();
            int m = new_copy->get_m();

            increase_vector_by_random(vect, n);
            create_funcs(m, n, funcs, vect);
            Elements.push_back(new_copy);
        }
        sorting(Elements);
        clear_memory(Elements, Element_num);
    }
}

/////////////////////////////////////////////////////////////////////////
void print_to_output(ofstream &file, const int &Element_num, const int &funcs_dim, vector<Element<double> *> &Elements)
{
    for (int k = 0; k < Element_num; k++)
    {
        double *funcs = Elements[k]->get_F();
        for (int i = 0; i < funcs_dim; i++)
        {
            file << funcs[i] << ' ';
            cout << funcs[i] << ' ';
        }
        file << '\n';
        cout << '\n';
    }
}
