#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>

namespace cppgrad
{

	/// Return codes.
	enum class status_e : std::uint8_t
	{
		ok = 0,			///< Success.
		numerical_err,	///< Numerical error.
		linalg_err,		///< Linear algebra error.
		out_of_bounds	///< Out of bounds error.
	};
}

#endif // __COMMON_H__
