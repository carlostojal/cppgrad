#ifndef __MUL_H__
#define __MUL_H__

#include "operators/op.h"

namespace cppgrad::operators
{
	/**
	 * @class mul
	 * @brief Multiplication (product) operator.
	 */
	template <typename ValueT>
	class mul : public op<ValueT>
	{
	public:

		/**
		 * @brief Constructor.
		 * @param with_grad Will compute gradients?
		 */
		mul(bool with_grad = true) noexcept;

		/**
		 * @brief Multiplication computation.
		 * @param op1 Left-hand operand.
		 * @param op2 Right-hand operand.
		 * @param out Result value.
		 */
		void forward(const linalg::tensor<ValueT>& op1, const linalg::tensor<ValueT>& op2, linalg::tensor<ValueT>& out) noexcept override;

		/**
		 * @brief Multiplication gradient.
		 * @param out Gradient value.
		 */
		void grad(linalg::tensor<ValueT>& out) noexcept override;
	};
}

#endif // __MUL_H__
