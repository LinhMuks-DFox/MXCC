#pragma once
#ifndef MXC_ARRAY_LIST
#define MXC_ARRAY_LIST
#include "IList.hpp"
namespace MXC::Container {

	template <class T>
	class [[deprecated("Unimplemented yet")]] ArrayList : public object
	{
	private:
		T* _arr = nullptr;
		uint64 size = 0;
		bool _read_only = true;

	public:
	};
}


#endif // MXC_ARRAY_LIST