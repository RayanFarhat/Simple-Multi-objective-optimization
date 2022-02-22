#include <iostream>
#include <fstream>
#include "part2.h"

using namespace std;

/*
 in first line in input file :
* first number is the number of objects
* second number is the dimension of feasible solution vector
* third number is the dimension of objective vector
* forth number is how many times to generate new objects
*/

/* the rest of lines contain feasible solution vectors for objects */

/* the output file must be empty */

/*example of input file content :*/

//10 6 3 5000
//0.5 0.5 0.5 0.5 0.5 0.5
//0.1 0.1 0.2 0.5 0.5 0.5
//0.0 0.0 0.0 0.0 0.0 0.1
//0.1 0.0 0.2 0.5 0.5 1.0
//1.0 0.0 0.0 0.0 0.0 0.0
//0.0 1.0 0.0 0.0 0.0 0.0
//0.0 0.0 1.0 0.0 0.0 0.0
//0.0 0.0 0.0 1.0 0.0 0.0
//0.0 0.0 0.0 0.0 1.0 0.0
//0.0 0.0 0.0 0.0 0.0 1.0

/*example of output file content after running :*/

//23.36 5.76 0.16
//24.47 6.27 0.07
//23.77 5.97 0.17
//24.47 6.27 0.07
//24.18 6.18 0.18
//24.47 6.27 0.07
//24.2 6.2 0.2
//21.41 4.81 0.21
//25.7 6.9 0.1
//24.22 6.22 0.22

int main(int argc, char **argv)
{
    /* number of objects */
    int Element_num;
    /* the dimension of feasible solution vector */
    int vect_dim;
    /* the dimension of objective vector */
    int funcs_dim;
    /* how many generations of new objects with random increasment */
    int rounds;
    /* file read the input file */
    fstream input_file;
    try
    {
        if (argc != 3)
        {
            throw 0;
        }
        //open file
        input_file.open(argv[1]);
        if (!input_file.is_open())
        {
            throw 0;
        }
    }
    catch (...)
    {
        cerr << "ERROR: " << argv[1] << " does not exist or cannot be opened\n";
        return 0;
    }

    try
    {
        //get first line information, if failed throw error
        get_first_line(input_file, Element_num, vect_dim, funcs_dim, rounds);

        if (vect_dim < funcs_dim)
        {
            throw 0;
        }
    }
    catch (...)
    {
        cerr << "ERROR: simulation definition in " << argv[1] << " is invalid\n";
        return 0;
    }

    //create container of objects
    vector<Element<double> *> Elements;

    try
    {
        //read objects info from file and insert it to the container,if failed throw error
        create_elements(input_file, Elements, Element_num, vect_dim, funcs_dim);
    }
    catch (int line_counter)
    {
        cerr << "ERROR: population definition in " << argv[1] << " at line " << line_counter << " is invalid\n";
        return 0;
    }

    //sort objects in container
    sorting(Elements);

    //get the optimal solution
    generate_solution(rounds, Element_num, Elements);

    //open the output file and print the  Pareto front to it the file
    ofstream output_file(argv[2]);
    print_to_output(output_file, Element_num, funcs_dim, Elements);

    //delete the elements from memory
    clear_memory(Elements, Element_num);

    //close files
    input_file.close();
    output_file.close();
    return 0;
}
