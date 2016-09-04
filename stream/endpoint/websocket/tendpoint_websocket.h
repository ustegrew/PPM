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


#ifndef TENDPOINT_WEBSOCKET_H
#define TENDPOINT_WEBSOCKET_H

/**
 * An endpoint for i/o via web socket (e.g. to send metering values to a web browser)
 *
 * @brief The TEndpoint_DirectIO class
 */
class TEndpoint_WebSocket : public VEndpoint
{
    public:
        TEndpoint_WebSocket();
};

#endif // TENDPOINT_WEBSOCKET_H
