#include <iostream>
#include <cassert>

#include "linalg/matrix.h"

using namespace cppgrad::linalg;

void test_get_elem(void)
{
	matrix3f m;
	float val;

	m.set_elem(5.0, 1, 1);
	m.get_elem(val, 1, 1);
	assert(val == 5.0);

	std::cout << "get_elem passed" << std::endl;
}

void test_get_elem_out_of_rows(void)
{

}

void test_get_elem_out_of_cols(void)
{

}

void test_get_elem_out_of_both()
{

}

void test_set_elem(void)
{

}

void test_set_elem_out_of_rows(void)
{

}

void test_set_elem_ouf_of_cols(void)
{

}

void test_set_elem_out_of_both(void)
{

}

int main(int argc, char *argv[])
{

	test_get_elem();

	return 0;
}
