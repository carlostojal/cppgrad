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
	template <typename ScalarT>
	class op : public node
	{
	public:

		/**
		 * @brief Constructor.
		 * @param with_grad Will compute gradients?
		 */
		op(bool with_grad = true) noexcept;

		/**
		 * @brief Operator computation.
		 * @param op1 Left-hand operand.
		 * @param op2 Right-hand operand.
		 * @param out Result value.
		 */
		virtual void forward(const linalg::tensor<ScalarT>& op1, const linalg::tensor<ScalarT>& op2, linalg::tensor<ScalarT>& out) noexcept = 0;

		/**
		 * @brief Operator gradient.
		 * @param out Gradient value.
		 */
		virtual void grad(linalg::tensor<ScalarT>& out) noexcept = 0;

	protected:
		/// Compute gradients?
		bool with_grad_ = true;
	};
}

#endif // __OPERATOR_H__
