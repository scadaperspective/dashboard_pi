/***************************************************************************
 * $Id: from_ownship.h
 *
 * Project:  OpenCPN
 * Purpose:  Dashboard Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#ifndef _FROM_OWNSHIP_H_
#define _FROM_OWNSHIP_H_

// For compilers that support pre-compilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "instrument.h"

class DashboardInstrument_FromOwnship : public DashboardInstrument
{
public:
    DashboardInstrument_FromOwnship(wxWindow *pparent, wxWindowID id, wxString title,
#ifdef _TACTICSPI_H_
                                    unsigned long long cap_flag1=OCPN_DBP_STC_PLA,
                                    unsigned long long cap_flag2=OCPN_DBP_STC_PLO,
                                    unsigned long long cap_flag3=OCPN_DBP_STC_LAT,
                                    unsigned long long cap_flag4=OCPN_DBP_STC_LON
#else
                                    int cap_flag1=OCPN_DBP_STC_PLA,
                                    int cap_flag2=OCPN_DBP_STC_PLO,
                                    int cap_flag3=OCPN_DBP_STC_LAT,
                                    int cap_flag4=OCPN_DBP_STC_LON
#endif // _TACTICSPI_H_
        );
    ~DashboardInstrument_FromOwnship(){}

#ifdef _TACTICSPI_H_
    void SetData(unsigned long long st, double data, wxString unit);
#else
    void SetData(int, double, wxString);
#endif // _TACTICSPI_H_
    wxSize GetSize( int orient, wxSize hint );
      
protected:
    wxString           m_data1;
    wxString           m_data2;
    double             c_lat;
    double             c_lon;
    double             s_lat;
    double             s_lon;
#ifdef _TACTICSPI_H_
    unsigned long long m_cap_flag1;
    unsigned long long m_cap_flag2;
    unsigned long long m_cap_flag3;
    unsigned long long m_cap_flag4;
#else
    int                m_cap_flag1;
    int                m_cap_flag2;
    int                m_cap_flag3;
    int                m_cap_flag4;
#endif // _TACTICSPI_H_
    int                m_DataHeight;

    void Draw(wxGCDC* dc);
};

#endif
