#include "operators/op.h"

using namespace cppgrad::operators;

template <typename ScalarT>
op<ScalarT>::op(bool with_grad) noexcept
{
	this->with_grad_ = with_grad;
}
