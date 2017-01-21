//SAMPLE
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include "SortedVector.h"
#include "SortedList.h"
#include "SortedVector.cpp"
#include "SortedList.cpp"

using namespace std;
using namespace std::chrono;

void test() throw (string);
long elapsed_time(void f(SortedVector& sv, int size), SortedVector& sv, int size);
long elapsed_time(void f(SortedList& sl, int size), SortedList& sl, int size);

void vector_prepends(SortedVector& sv, int size);
void list_prepends(SortedList& sl, int size);

void vector_appends(SortedVector& sv, int size);
void list_appends(SortedList& sl, int size);

void vector_gets(SortedVector& sv, int size) throw (string);
void list_gets(SortedList& sl, int size) throw (string);

void vector_searches(SortedVector& sv, int size);
void list_searches(SortedList& sl, int size);

void vector_removes(SortedVector& sv, int size);
void list_removes(SortedList& sl, int size);

int main()
{
    srand(time(NULL));

    try
    {
        test();
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
        return -1;
    }

    cout << endl << "Done!" << endl;
    return 0;
}

void test() throw (string)
{
    cout << "         |---Prepend---|   |-----Gets----|   |----Search---|   |----Remove---|   |----Append---|" << endl;
    cout << "  Size   Vector     List   Vector     List   Vector     List   Vector     List   Vector     List" << endl;

    //const int SIZES[] = {5000, 10000, 15000, 20000, 50000, 100000, 150000, 200000};
    for (int size = 5000; size<=200000;size=size+5000)
    {
        SortedVector sv;
        SortedList sl;
        long etv, etl;

        cout << setw(6) << size;

        etv = elapsed_time(vector_prepends, sv, size);
        cout << setw(6) << etv << " ms";
        etl = elapsed_time(list_prepends, sl, size);
        cout << setw(6) << etl << " ms";

        if (!sv.check()) throw "Prepend: Vector sort error!";
        if (!sl.check()) throw "Prepend: List sort error!";

        etv = elapsed_time(vector_gets, sv, size);
        cout << setw(6) << etv << " ms";
        etl = elapsed_time(list_gets, sl, size);
        cout << setw(6) << etl << " ms";

        etv = elapsed_time(vector_searches, sv, size);
        cout << setw(6) << etv << " ms";
        etl = elapsed_time(list_searches, sl, size);
        cout << setw(6) << etl << " ms";

        etv = elapsed_time(vector_removes, sv, size);
        cout << setw(6) << etv << " ms";
        etl = elapsed_time(list_removes, sl, size);
        cout << setw(6) << etl << " ms";

        etv = elapsed_time(vector_appends, sv, size);
        cout << setw(6) << etv << " ms";
        etl = elapsed_time(list_appends, sl, size);
        cout << setw(6) << etl << " ms";

        if (!sv.check()) throw "Append: Vector sort error!";
        if (!sl.check()) throw "Append: List sort error!";

        cout << endl;
    }
}

long elapsed_time(void f(SortedVector& sv, int size), SortedVector& sv, int size)
{
    steady_clock::time_point start_time = steady_clock::now();
    f(sv, size);
    steady_clock::time_point end_time = steady_clock::now();
    return duration_cast<milliseconds>(end_time - start_time).count();
}

long elapsed_time(void f(SortedList& sl, int size), SortedList& sl, int size)
{
    steady_clock::time_point start_time = steady_clock::now();
    f(sl, size);
    steady_clock::time_point end_time = steady_clock::now();
    return duration_cast<milliseconds>(end_time - start_time).count();
}

void vector_prepends(SortedVector& sv, int size)
{
    for (int i = size-1; i >= 0; i--) sv.prepend(i);
}

void list_prepends(SortedList& sl, int size)
{
    for (int i = size-1; i >= 0; i--) sl.prepend(i);
}

void vector_appends(SortedVector& sv, int size)
{
    for (int i = 0; i < size; i++) sv.append(i);
}

void list_appends(SortedList& sl, int size)
{
    for (int i = 0; i < size; i++) sl.append(i);
}

void vector_gets(SortedVector& sv, int size) throw (string)
{
    for (int i = 0; i < 1000; i++)
    {
        int j = rand()%size;
        int value = sv.get_value(j);
        if (j != value) throw "Get: Vector data mismatch!";
    }
}

void list_gets(SortedList& sl, int size) throw (string)
{
    for (int i = 0; i < 1000; i++)
    {
        int j = rand()%size;
        int value = sl.get_value(j);
        if (j != value) throw "Get: List data mismatch!";
    }
}

void vector_searches(SortedVector& sv, int size)
{
    for (int i = 0; i < 1000; i++)
    {
        int value = rand()%size;
        sv.find(value);
    }
}

void list_searches(SortedList& sl, int size)
{
    for (int i = 0; i < 1000; i++)
    {
        int value = rand()%size;
        sl.find(value);
    }
}

void vector_removes(SortedVector& sv, int size)
{
    sv.clear();
}

void list_removes(SortedList& sl, int size)
{
    sl.clear();
}