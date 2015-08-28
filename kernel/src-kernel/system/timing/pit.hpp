/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 *  Ghost, a micro-kernel based operating system for the x86 architecture    *
 *  Copyright (C) 2015, Max Schlüssel <lokoxe@gmail.com>                     *
 *                                                                           *
 *  This program is free software: you can redistribute it and/or modify     *
 *  it under the terms of the GNU General Public License as published by     *
 *  the Free Software Foundation, either version 3 of the License, or        *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SYSTEM_TIMING_PIT
#define SYSTEM_TIMING_PIT

#include "ghost/stdint.h"

#define PIT_FREQUENCY	1193180

#define PIT_CHANNEL_0				0x00	// 00......
/**
 * Programmable interval timer
 */
class g_pit {
public:

	/**
	 * Prepares the PIT to sleep for the specified number of
	 * microseconds when the {performSleep} function is called.
	 *
	 * @param microseconds 	number of microseconds to sleep
	 */
	static void prepareSleep(uint32_t microseconds);

	/**
	 * Performs sleep that was before configured using the {prepareSleep}
	 * function. A sleep can executed as often as wished onced its prepared.
	 */
	static void performSleep();

	/**
	 * Starts the PIT in Channel 0 to fire IRQ 0 at the requested hertz rate.
	 *
	 * @param hz	the clocking in Hz (ticks per second)
	 */
	static void startAsTimer(uint32_t hz);

	/**
	 * Returns the clocking that was set using the {startAsTimer} function.
	 */
	static uint32_t getTimerClocking();

};

#endif
