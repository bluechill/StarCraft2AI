//
//  ThreadHelpers.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__ThreadHelpers__
#define __StarCraft2API__ThreadHelpers__

namespace SC2
{
	namespace Utilities
	{
		void suspend_all_threads();
		void unsuspend_all_threads();
	}
}
#endif /* defined(__StarCraft2API__ThreadHelpers__) */
