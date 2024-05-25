/* TubeScreamer - Guitar Overdrive pedal simulation created with faust and JUCE
 * Copyright (C) 2021 Barabas Raffai
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
tone = hslider("tone", 0.5, 0, 1, 0.01) : si.smoo;
volume = hslider("volume", 0.5, 0, 1, 0.01) : si.smoo;

input_filter = fi.highpass(1, 720);

clipping = ef.cubicnl(gain, 0);

post_filter = fi.lowpass(1, 350 + (tone * (4500 - 350)));

volume_control = ba.db2linear((volume - 1) * 40);

process = _,_ :> input_filter : clipping : post_filter * volume_control <: _,_;
