#include "linalg/tensor.h"

using namespace cppgrad;
using namespace cppgrad::linalg;

template <typename ScalarT>
tensor<ScalarT>::tensor(const std::vector<std::size_t>& dims) noexcept
{
	std::size_t tensor_size = 1;
	for(std::size_t i = 0; i < dims.size(); i++)
	{
		tensor_size *= dims[i];
	}

	this->dims_ = dims;
	this->values_ = malloc(tensor_size * sizeof(ScalarT));
}

template <typename ScalarT>
tensor<ScalarT>::~tensor(void) noexcept
{
	if(this->values_ != nullptr)
	{
		free(this->values_);
	}
}

template <typename ScalarT>
status_e tensor<ScalarT>::get_flat_idx(const std::vector<std::size_t>& idx, std::size_t& flat_idx) const noexcept
{
	status_e err = status_e::ok;

	if(idx.size() == this->dims_.size())
	{
		// TODO: extract index
	}
	else
	{
		// requested dimensions do not match tensor dimensions
		err = status_e::linalg_err;
	}

	return err;
}

template <typename ScalarT>
status_e tensor<ScalarT>::get_elem(const std::vector<std::size_t>& idx, ScalarT& out) const noexcept
{
	status_e err = status_e::ok;

	if(this->values_ != nullptr)
	{
		std::size_t flat_idx;
		err = this->get_flat_idx(idx, flat_idx);
	}
	else
	{
		// values were not allocated
		err = status_e::memory_fault;
	}

	return err;
}
