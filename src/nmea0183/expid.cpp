/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  NMEA0183 Support Classes
 * Author:   Samuel R. Blackburn, David S. Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by Samuel R. Blackburn, David S Register           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 *
 *   S Blackburn's original source license:                                *
 *         "You can use it any way you like."                              *
 *   More recent (2010) license statement:                                 *
 *         "It is BSD license, do with it what you will"                   *
 */


#include "nmea0183.h"

/*
** Author: Samuel R. Blackburn
** CI$: 76300,326
** Internet: sammy@sed.csc.com
**
** You can use it any way you like.
*/

wxString& expand_talker_id( const wxString &identifier )
{
   static wxString expanded_identifier;

   char first_character  = 0x00;
   char second_character = 0x00;

   first_character  = identifier[ 0 ];
   second_character = identifier[ 1 ];

   /*
   ** Set up our default return value
   */

   expanded_identifier = wxT("Unknown - ");
   expanded_identifier += identifier;

   switch( first_character )
   {
      case 'A': // AG, AP

         switch( second_character )
         {
            case 'G': // AG

                expanded_identifier = wxT("Autopilot - General");
               break;

            case 'P': // AP

                expanded_identifier = wxT("Autopilot - Magnetic");
               break;
         }

         break;

      case 'C': // CD, CS, CT, CV, CX and CC,CM

         switch( second_character )
         {
            case 'C': // CC

                expanded_identifier = wxT("Commputer - Programmed Calculator (outdated)");
               break;

            case 'D': // CD

                expanded_identifier = wxT("Communications - Digital Selective Calling (DSC)");
               break;

            case 'M': // CM

                expanded_identifier = wxT("Computer - Memory Data (outdated)");
               break;

            case 'S': // CS

                expanded_identifier = wxT("Communications - Satellite");
               break;

            case 'T': // CT

                expanded_identifier = wxT("Communications - Radio-Telephone (MF/HF)");
               break;

            case 'V': // CV

                expanded_identifier = wxT("Communications - Radio-Telephone (VHF)");
               break;

            case 'X': // CX

                expanded_identifier = wxT("Communications - Scanning Receiver");
               break;
         }

         break;

      case 'D': // DE, DF

         switch( second_character )
         {
            case 'E': // DE

                expanded_identifier = wxT("DECCA Navigation");
               break;

            case 'F': // DF

                expanded_identifier = wxT("Direction Finder");
               break;
         }

         break;

      case 'E': // EC, EP, ER

         switch( second_character )
         {
            case 'C': // EC

                expanded_identifier = wxT("Electronic Chart Display & Information System (ECDIS)");
               break;

            case 'P': // EP

                expanded_identifier = wxT("Emergency Position Indicating Beacon (EPIRB)");
               break;

            case 'R': // ER

                expanded_identifier = wxT("Engine Room Monitoring Systems");
               break;
         }

         break;

      case 'G': // GP

         switch( second_character )
         {
            case 'P': // GP

                expanded_identifier = wxT("Global Positioning System (GPS)");
               break;
         }

         break;

      case 'H': // HC, HE, HN

         switch( second_character )
         {
            case 'C': // HC

                expanded_identifier = wxT("Heading - Magnetic Compass");
               break;

            case 'E': // HE

                expanded_identifier = wxT("Heading - North Seeking Gyro");
               break;

            case 'N': // HN

                expanded_identifier = wxT("Heading - Non North Seeking Gyro");
               break;
         }

         break;

      case 'I': // II, IN

         switch( second_character )
         {
            case 'I': // II

                expanded_identifier = wxT("Integrated Instrumentation");
               break;

            case 'N': // IN

                expanded_identifier = wxT("Integrated Navigation");
               break;
         }

         break;

      case 'L': // LA, LC

         switch( second_character )
         {
            case 'A': // LA

                expanded_identifier = wxT("Loran A");
               break;

            case 'C': // LC

                expanded_identifier = wxT("Loran C");
               break;
         }

         break;

      case 'M': // MP

         switch( second_character )
         {
            case 'P': // MP

                expanded_identifier = wxT("Microwave Positioning System (outdated)");
               break;
         }

         break;

      case 'O': // OM, OS

         switch( second_character )
         {
            case 'M': // OM

                expanded_identifier = wxT("OMEGA Navigation System");
               break;

            case 'S': // OS

                expanded_identifier = wxT("Distress Alarm System (outdated)");
               break;
         }

         break;

      case 'P': // P

         break;

      case 'R': // RA

         switch( second_character )
         {
            case 'A': // RA

                expanded_identifier = wxT("RADAR and/or ARPA");
               break;
         }

         break;

      case 'S': // SD, SN, SS

         switch( second_character )
         {
            case 'D': // SD

                expanded_identifier = wxT("Sounder, Depth");
               break;

            case 'N': // SN

                expanded_identifier = wxT("Electronic Positioning System, other/general");
               break;

            case 'S': // SS

                expanded_identifier = wxT("Sounder, Scanning");
               break;
         }

         break;

      case 'T': // TI, TR

         switch( second_character )
         {
            case 'I': // TI

                expanded_identifier = wxT("Turn Rate Indicator");
               break;

            case 'R': // TR

                expanded_identifier = wxT("TRANSIT Navigation System");
               break;
         }

         break;

      case 'V': // VD, VM, VW

         switch( second_character )
         {
            case 'D': // VD

                expanded_identifier = wxT("Velocity Sensor, Doppler, other/general");
               break;

            case 'M': // VM

                expanded_identifier = wxT("Velocity Sensor, Speed Log, Water, Magnetic");
               break;

            case 'W': // VW

                expanded_identifier = wxT("Velocity Sensor, Speed Log, Water, Mechanical");
               break;
         }

         break;


      case 'W': // WI

         switch( second_character )
         {
            case 'I': // WI

                expanded_identifier = wxT("Weather Instruments");
               break;
         }

         break;

      case 'Y': // YC, YD, YF, YL, YP, YR, YT, YV, YX

         switch( second_character )
         {
            case 'C': // YC

                expanded_identifier = wxT("Transducer - Temperature (outdated)");
               break;

            case 'D': // YD

                expanded_identifier = wxT("Transducer - Displacement, Angular or Linear (outdated)");
               break;

            case 'F': // YF

                expanded_identifier = wxT("Transducer - Frequency (outdated)");
               break;

            case 'L': // YL

                expanded_identifier = wxT("Transducer - Level (outdated)");
               break;

            case 'P': // YP

                expanded_identifier = wxT("Transducer - Pressure (outdated)");
               break;

            case 'R': // YR

                expanded_identifier = wxT("Transducer - Flow Rate (outdated)");
               break;

            case 'T': // YT

                expanded_identifier = wxT("Transducer - Tachometer (outdated)");
               break;

            case 'V': // YV

                expanded_identifier = wxT("Transducer - Volume (outdated)");
               break;

            case 'X': // YX

                expanded_identifier = wxT("Transducer");
               break;

         }

         break;

      case 'Z': // ZA, ZC, ZQ, ZV

         switch( second_character )
         {
            case 'A': // ZA

                expanded_identifier = wxT("Timekeeper - Atomic Clock");
               break;

            case 'C': // ZC

                expanded_identifier = wxT("Timekeeper - Chronometer");
               break;

            case 'Q': // ZQ

                expanded_identifier = wxT("Timekeeper - Quartz");
               break;

            case 'V': // ZV

                expanded_identifier = wxT("Timekeeper - Radio Update, WWV or WWVH");
               break;
         }

         break;
   }

   return( expanded_identifier );
}
