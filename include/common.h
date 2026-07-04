#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>

namespace cppgrad
{

	enum class status_e : std::uint8_t
	{
		ok = 0,
		numerical_err,
		linalg_err,
		out_of_bounds
	};
}

#endif // __COMMON_H__
