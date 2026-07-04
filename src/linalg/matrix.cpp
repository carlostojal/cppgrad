#include "linalg/matrix.h"

using namespace cppgrad::linalg;

template <typename ScalarT, std::size_t N_rows, std::size_t N_cols>
matrix<ScalarT, N_rows, N_cols>::matrix(void) noexcept
{
}

template <typename ScalarT, std::size_t N_rows, std::size_t N_cols>
cppgrad::status_e matrix<ScalarT, N_rows, N_cols>::get_elem(ScalarT &out, std::size_t row_idx, std::size_t col_idx) const noexcept
{
	cppgrad::status_e status = cppgrad::status_e::ok;

	if (row_idx < N_rows && col_idx < N_cols)
	{
		out = this->data_[row_idx * N_cols + col_idx];
	}
	else
	{
		status = cppgrad::status_e::out_of_bounds;
	}

	return status;
}

template <typename ScalarT, std::size_t N_rows, std::size_t N_cols>
cppgrad::status_e matrix<ScalarT, N_rows, N_cols>::set_elem(ScalarT value, std::size_t row_idx, std::size_t col_idx) noexcept
{
	cppgrad::status_e status = cppgrad::status_e::ok;

	if (row_idx < N_rows && col_idx < N_cols)
	{
		this->data_[row_idx * N_cols + col_idx] = value;
	}
	else
	{
		status = cppgrad::status_e::out_of_bounds;
	}

	return status;
}
