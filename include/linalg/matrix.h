
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstddef>

#include "common.h"

namespace cppgrad::linalg
{
	/**
	 * @class matrix
	 * @brief Represents a matrix.
	 * @tparam ScalarT Underlying scalar type.
	 * @tparam N_rows Number of matrix rows.
	 * @tparam N_cols Number of matrix columns.
	 */
	template <typename ScalarT, std::size_t N_rows, std::size_t N_cols>
	class matrix
	{
	public:
		/// Constructor.
		matrix(void) noexcept;

		/**
		 * @brief Get an element of the matrix.
		 * @param out Value output.
		 * @param row_idx Row index.
		 * @param col_idx Column index.
		 */
		status_e get_elem(ScalarT &out, std::size_t row_idx, std::size_t col_idx) const noexcept;

		/**
		 * @brief Set an element of the matrix.
		 * @param value Value to set.
		 * @param row_idx Row index.
		 * @param col_idx Column index.
		 */
		status_e set_elem(ScalarT value, std::size_t row_idx, std::size_t col_idx) noexcept;

		/**
		 * @brief Multiply this matrix with another.
		 * @param m Matrix to multiply with.
		 * @return Result matrix.
		 */
		matrix operator*(const matrix &m) const noexcept;

		/**
		 * @brief Sum this matrix with another.
		 * @param m Matrix to sum with.
		 * @return Result matrix.
		 */
		matrix operator+(const matrix &m) const noexcept;

		/**
		 * @brief Subtract this matrix with another.
		 * @param m Matrix to subtract with.
		 * @return Result matrix.
		 */
		matrix operator-(const matrix &m) const noexcept;

		/**
		 * @brief Assignment operator.
		 * @param m Matrix values to assign to this.
		 */
		void operator=(const matrix &m) noexcept;

	private:
		/// Underlying data. Row-major.
		ScalarT data_[N_rows * N_cols];
	};

	/// 3x3 float matrix specialization.
	using matrix3f = matrix<float,3,3>;

	/// 3x3 double matrix specialization.
	using matrix3d = matrix<double,3,3>;
}

#endif // __MATRIX_H__
