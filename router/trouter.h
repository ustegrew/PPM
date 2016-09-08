/* -----------------------------------------------------------------------------
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
----------------------------------------------------------------------------- */

#ifndef TROUTER_H
#define TROUTER_H

#include <map>
#include <string>
#include <jack/jack.h>
#include "../types.h"
#include "../stream/endpoint/vendpoint.h"

/**
 * Routes streams of data from various sources to various destinations.
 *
 * @brief The TRouter class
 */
class TRouter
{
    public:
                                                TRouter                     ();
                                               ~TRouter                     ();

        void                                    Push                        (sample_t smp);
        void                                    Register                    (VEndpoint* ep);

    private:
        std::map<std::string, VEndpoint*>       fEndpoints;
};

#endif // TROUTER_H
