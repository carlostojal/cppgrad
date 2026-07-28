#ifndef __TENSOR_H__
#define __TENSOR_H__

#include "common.h"

#include <vector>
#include <cstdlib>

namespace cppgrad::linalg
{
	/**
	 * @class tensor
	 * @brief Tensor.
	 * @tparam ScalarT Underlying scalar type.
	 */
	template <typename ScalarT>
	class tensor
	{
	public:
		/**
		 * @brief Constructor.
		 * @param dims Tensor dimensions.
		 */
		tensor(const std::vector<std::size_t>& dims) noexcept;

		/**
		 * @brief Destructor.
		 */
		~tensor(void) noexcept;
		
		/**
		 * @brief Get an element of the tensor.
		 * @param idx Index.
		 * @param out Value at index.
		 * @return Status code.
		 */
		status_e get_elem(const std::vector<std::size_t>& idx, ScalarT& out) const noexcept;

		/**
		 * @brief Set an element of the tensor.
		 * @param idx Index.
		 * @param out Value at index.
		 * @return Status code.
		 */
		status_e set_elem(const std::vector<std::size_t>& idx, ScalarT value) noexcept;

	private:

		/**
		 * @brief Get the flatenned tensor index for a given n-dimensional index.
		 * @param idx n-dimensional index.
		 * @param flat_idx Flatenned index.
		 * @return Status code.
		 */
		status_e get_flat_idx(const std::vector<std::size_t>& idx, std::size_t& flat_idx) const noexcept;

		/// Tensor dimensions.
		std::vector<std::size_t> dims_;

		/// Tensor values.
		ScalarT* values_ = nullptr;
	};
}

#endif // __TENSOR_H__
