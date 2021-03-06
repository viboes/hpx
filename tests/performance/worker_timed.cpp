//  Copyright (c) 2011-2012 Bryce Adelstein-Lelbach
//  Copyright (c) 2007-2012 Hartmut Kaiser
//  Copyright (c)      2013 Thomas Heller
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "worker_timed.hpp"

HPX_SYMBOL_EXPORT void worker_timed(double delay_sec, volatile int * i)
{
    // Start the timer.
    hpx::util::high_resolution_timer td;

    while (true)
    {
        // Check if we've reached the specified delay.
        if (td.elapsed() > delay_sec)
            break;
        else
            // If we haven't reached the specified time, do some busy work. 
            ++*i;
    }
}
