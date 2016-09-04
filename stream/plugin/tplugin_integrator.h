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


#ifndef TPLUGIN_INTEGRATOR_H
#define TPLUGIN_INTEGRATOR_H

/**
 * A plugin to integrate a stream of samples so that we get a smooth rise/fall
 * in the values of the outgoing data.
 *
 * @brief The TPlugin_Integrator class
 */
class TPlugin_Integrator : public VPlugin
{
    public:
        TPlugin_Integrator();
};

#endif // TPLUGIN_INTEGRATOR_H
