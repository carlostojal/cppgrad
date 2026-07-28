#ifndef __OPERATOR_H__
#define __OPERATOR_H__

#include "node.h"
#include "linalg/tensor.h"

namespace cppgrad::operators
{
	/**
	 * @class op
	 * @brief Abstract operator.
	 */
	class op : public node
	{
	public:
		/**
		 * @brief Operator computation.
		 * @param op1 Left-hand operand.
		 * @param op2 Right-hand operand.
		 * @param out Result value.
		 */
		virtual void forward(const linalg::tensor& op1, const linalg::tensor& op2, linalg::tensor& out) noexcept = 0;

		/**
		 * @brief Operator gradient.
		 * @param out Gradient value.
		 */
		virtual linalg::tensor grad(linalg::tensor& out) noexcept = 0;
	};
}

#endif // __OPERATOR_H__
