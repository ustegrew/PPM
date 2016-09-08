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

#include "types.h"
#include "gui/twndmain.h"
#include "jackd/tjackdadapter.h"
#include "router/trouter.h"
#include <QApplication>
#include <QMessageBox>

/* Please note that JackD must be running before starting this application */
int main(int argc, char *argv[])
{
    /* Create objects on the stack, system should call dTors when main() gets out of scope. */
    QApplication        a(argc, argv);
    TWndMain            w;
    QMessageBox         msgBox;
    TJackDAdapter       audioSys    ("ppm", "l", "r");
    TRouter             router;
    bool                success;

    audioSys.RegisterWith (router);

    /* Connect to JackD. */
    success = audioSys.Open ();

    if (! success)
    {   // Crude error reporting - will refine this later.
        audioSys.Close (); // Not strictly necessary... will be done in cTor, but for good taste, included here ...
        msgBox.setText ("Failed to connect to JackD server. Is JackD running? Check stderr for further details.");
    }

    w.show();

    return a.exec();
}
