A Dashboard Plugin for OpenCPN
====================================

    
Watching the numbers jumping on Tactics performance instruments
maybe fun but to unleash their full power you should understand
the theory behind them. Attached tactics_pi.odt or tactics_pi.pdf
are highly recommended reading, written by the original author
of those algorithms.

In short (taken from the manual):

What tactics enhancements can do :
----------------------------------
* Calculate true wind data : TWA, TWD, TWS from true heading (HDT), speed
  through water (STW) and app. Wind speed (AWS), with optional correction by heel-angle.
  Calculation is enabled via a preference setting and disables available true wind data
  from the bus throughout the tactics_pi plugin. 
* Calculate the “leeway”, the boat drift based on heel. A common formula is used for that purpose.
* Calculate the surface sea current and display it as single instruments (current speed/direction)
  as part of the “Bearing compass” or as overlay on the chart (semi transparent). The routines take
  boat heel and leeway into account.
  If you don't have a heel sensor, there is a simply workaround, see manual.
  Current display on the chart can be disabled by a preference setting.
* Calculate and display the boat laylines for the current tack, and the same TWA on the other tack.
  Sea current is taken into account, if available ! Boat laylines may be toggled on/off. 
  Adjustable length and max. width (triangle, with one corner at the boat) of boat laylines.
  The layline width reflects the boat's yawing (COG changes over time).
* You can load a polar file and calculate/display performance data, like actual VMG (velocity made good up-/downwind),
  Target-VMG, Target-TWA  (the opt. TWA up-/downwind) angle and speed, CMG (course made good towards a waypoint), Target-CMG
  (opt. CMG) angle and speed, polar speed (the speed you should be able to sail at current TWA/TWS based on your polar),...
* It can display the actual polar as overlay on the chart, including markers for Target-VMG/CMG angles.
  Just adopt your course and place your heading pointer on one of the markers, and you sail Target-VMG/CMG based on your polar ...
* you can set a (one !) temporary tactics waypoint and display the laylines to the mark, based on a Target-TWA calculation,
  while taking your polar into account.
* it has a “dial instruments” called “Bearing compass”. Boat true heading (HDT)  points “up”, it shows the boat laylines as well,
  the surface current, a pointer to the waypoint (either set manually as the temporary Tactics waypoint or read from a NMEA
  RMB sentence), needles for AWA and TWA and markers for the Target-VMG/CMG angles.
* It has a “Polar compass” instrument, graphically displaying the actual polar ring and markers for Bearing to WP,
  Target-VMG angles and Target-CMG angles.
* It has an “Average Wind” instrument with an adjustable averaging time, which displays graphically the average wind
  and its deviations to port / starboard
* It can create specific NMEA performance records with the purpose to export them to the displays of your instruments.
  You can now e.g. calculate the polar target speed in the plugin and send it to your instrument display outside in the cockpit.
  *** Currently only available for NKE, but may be enhanced in the future ***
* There are various settings, which I grouped in a separate tab. To access the preferences screen, right mouse click
  on the tactics_pi window, then select “Preferences ...”






License
=======
The plugin code is licensed under the terms of the GPL v3 or, at your will, later.
