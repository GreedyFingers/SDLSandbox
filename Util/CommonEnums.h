#pragma once


#ifdef COMMON_ENUMS_EX
#define COMMON_ENUMS_EX __declspec(dllexport)
#else
#define COMMON_ENUMS_EX __declspec(dllimport)
#endif  

namespace Util
{
	class COMMON_ENUMS_EX CommonEnums
	{
	public:

		enum EventEnums
		{
			NO_EVENT = -1,
			QUIT = 0,
			LEFT_MOUSE_CLICK = 1
		};

		CommonEnums();
		~CommonEnums();
	};
}
