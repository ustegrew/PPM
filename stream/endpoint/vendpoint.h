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

#ifndef VENDPOINT_H
#define VENDPOINT_H

#include <string>
#include "../conduit/tconduit.h"

/**
 * Base class for all end points.
 *
 * @brief The VEndpoint class
 */
class VEndpoint
{
    public:
                                                VEndpoint               (std::string id);
                                               ~VEndpoint               ();

        std::string                             GetID                   ();

    protected:
        TConduit*                               fConduit;
        std::string                             fID;
};

#endif // VENDPOINT_H
