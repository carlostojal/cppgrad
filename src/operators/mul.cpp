#include "operators/mul.h"

using namespace cppgrad::operators;
using namespace cppgrad::linalg;

template <typename ValueT>
mul<ValueT>::mul(bool with_grad) noexcept : op<ValueT>(with_grad)
{

}

template <typename ValueT>
void mul<ValueT>::forward(const tensor<ValueT>& op1, const tensor<ValueT>& op2, tensor<ValueT>& out) noexcept
{
	// TODO
}

template <typename ValueT>
void mul<ValueT>::grad(tensor<ValueT>& out) noexcept
{
	// TODO
}
