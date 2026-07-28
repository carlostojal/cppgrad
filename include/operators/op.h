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
	class op : node
	{
	public:
		/**
		 * @brief Operator computation.
		 * @param op1 Left-hand operand.
		 * @param op2 Right-hand operand.
		 * @return Result value.
		 */
		virtual linalg::tensor forward(linalg::tensor op1, linalg::tensor op2) noexcept = 0;

		/**
		 * @brief Operator gradient.
		 * @return Gradient value.
		 */
		virtual linalg::tensor grad(void) noexcept = 0;
	};
}

#endif // __OPERATOR_H__
