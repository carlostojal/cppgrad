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
	this->grad_ = nullptr;
}

template <typename ScalarT>
tensor<ScalarT>::~tensor(void) noexcept
{
	if(this->values_ != nullptr)
	{
		free(this->values_);
	}

	if(this->grad_ != nullptr)
	{
		free(this->grad_);
	}
}

template <typename ScalarT>
status_e tensor<ScalarT>::get_flat_idx(const std::vector<std::size_t>& idx, std::size_t& flat_idx) const noexcept
{
	status_e err = status_e::ok;

	if(idx.size() == this->dims_.size())
	{
		flat_idx = 0;
		for(std::size_t i = 0; i < idx.size(); i++)
		{
			if(idx[i] < this->dims_[i])
			{
				flat_idx = flat_idx * this->dims_[i] + idx[i];
			}
			else
			{
				// out of bounds for this dimension
				err = status_e::out_of_bounds;
			}
		}
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
		if(err == status_e::ok)
		{
			out = this->values_[flat_idx];
		}
	}
	else
	{
		// values were not allocated
		err = status_e::memory_fault;
	}

	return err;
}

template <typename ScalarT>
status_e tensor<ScalarT>::set_elem(const std::vector<std::size_t>& idx, ScalarT value) noexcept
{
	status_e err = status_e::ok;

	if(this->values_ != nullptr)
	{
		std::size_t flat_idx;
		err = this->get_flat_idx(idx, flat_idx);
		if(err == status_e::ok)
		{
			this->values_[flat_idx] = value;
		}
	}
	else
	{
		// values were not allocated
		err = status_e::memory_fault;
	}

	return err;
}

template <typename ScalarT>
std::size_t tensor<ScalarT>::get_ndims(void) const noexcept
{
	return this->dims_.size();
}

template <typename ScalarT>
ScalarT* tensor<ScalarT>::get_values(void) noexcept
{
	return this->values_;
}

template <typename ScalarT>
ScalarT* tensor<ScalarT>::get_grad(void) noexcept
{
	return this->grad_;
}
