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

#ifndef TENDPOINT_IOSTREAM_H
#define TENDPOINT_IOSTREAM_H

#include "../vendpoint.h"

/**
 * An endpoint for i/o via iostream (e.g. to pipe metering values to another process).
 * Recommended to turn the program's verbosity level to quiet when using this endpoint.
 *
 * @brief The TEndpoint_IOStream class
 */
class TEndpoint_IOStream : public VEndpoint
{
    public:
        TEndpoint_IOStream();
};

#endif // TENDPOINT_IOSTREAM_H
