#ifndef PART2_H_INCLUDED
#define PART2_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "part1.h"

//this file deal with double type objects

/* reset object ranks and call ParetoSorting algorithm */
void sorting(std::vector<Element<double> *> &Elements);

/* get vector and increase it by random number between 0 and 1 */
void increase_vector_by_random(double *vect, const int &vect_dim);

/* collect info from first line of input file */
void get_first_line(std::fstream &file, int &Element_num, int &vect_dim, int &funcs_dim, int &rounds);

/* read a line from file and insert the info to feasible solution vector */
void create_vector(std::fstream &file, const int &vect_dim, double *vec);

/* create objective vector from feasible solution vector he got */
void create_funcs(const int &funcs_dim, const int &vect_dim, double *funcs, double *vec);

/* read all objects info lines and make objects and insert it to the container */
void create_elements(std::fstream &file, std::vector<Element<double> *> &Elements, const int &Element_num, const int &vect_dim, const int &funcs_dim);

/* delete last 'Element_num'(the number of objects in input file) objects from container */
void clear_memory(std::vector<Element<double> *> &Elements, const int &Element_num);

/* add the new objects and sort the container then delete second half of container 'rounds' times */
void generate_solution(const int &rounds, const int &Element_num, std::vector<Element<double> *> &Elements);

/* print the Pareto front (set of all Pareto efficient solutions) to output file and the screen  */
void print_to_output(std::ofstream &file, const int &Element_num, const int &funcs_dim, std::vector<Element<double> *> &Elements);

#endif // PART2_H_INCLUDED
