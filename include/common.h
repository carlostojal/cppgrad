#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>

namespace cppgrad
{

	enum class status_e
	{
		ok,
		numerical_err,
		linalg_err
	};
}

#endif // __COMMON_H__
