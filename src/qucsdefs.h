/*
 * qucsdefs.h - netlist definitions for the Qucs netlists
 *
 * Copyright (C) 2004, 2005, 2006 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.  
 *
 * $Id: qucsdefs.h,v 1.47 2006-05-03 09:43:56 raimi Exp $
 *
 */

#ifndef __QUCSDEFS_H__
#define __QUCSDEFS_H__

// List of available components.
struct define_t qucs_definition_available[] =
{
  /* resistor */
  { "R", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR, 
    { { "R", PROP_REAL, { 50, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Tc1", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Tc2", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Tnom", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* inductor */
  { "L", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "L", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* capacitor */
  { "C", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "C", PROP_REAL, { 1e-12, PROP_NO_STR }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* two mutual inductors */
  { "MUT", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "L1", PROP_REAL, { 1e-3, PROP_NO_STR },	PROP_POS_RANGEX },
      { "L2", PROP_REAL, { 1e-3, PROP_NO_STR },	PROP_POS_RANGEX },
      { "k", PROP_REAL, { 0.9, PROP_NO_STR }, { '[', 0, 1, '[' } },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* three mutual inductors */
  { "MUT2", 6, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "L1", PROP_REAL, { 1e-3, PROP_NO_STR },	PROP_POS_RANGEX },
      { "L2", PROP_REAL, { 1e-3, PROP_NO_STR },	PROP_POS_RANGEX },
      { "L3", PROP_REAL, { 1e-3, PROP_NO_STR },	PROP_POS_RANGEX },
      { "k12", PROP_REAL, { 0.9, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "k13", PROP_REAL, { 0.9, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "k23", PROP_REAL, { 0.9, PROP_NO_STR }, { '[', 0, 1, '[' } },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* voltage controlled current source */
  { "VCCS", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "G", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "T", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* current controlled current source */
  { "CCCS", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "G", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "T", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* voltage controlled voltage source */
  { "VCVS", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "G", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "T", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* current controlled voltage source */
  { "CCVS", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "G", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "T", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* power source */
  { "Pac", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Z", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGEX },
      { "Num", PROP_INT, { 1, PROP_NO_STR }, { '[', 1, MAX_PORTS, ']' } },
      PROP_NO_PROP },
    { { "P", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* circulator */
  { "Circulator", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "Z1", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      { "Z2", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      { "Z3", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* isolator */
  { "Isolator", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Z1", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      { "Z2", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* attenuator */
  { "Attenuator", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "L", PROP_REAL, { 10, PROP_NO_STR }, PROP_MIN_VAL (1) },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Zref", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* bias tee */
  { "BiasT", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "C", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE },
      { "L", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* DC feed */
  { "DCFeed", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "L", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* DC block */
  { "DCBlock", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "C", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* transformer */
  { "Tr", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "T", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* symmetrical transformer */
  { "sTr", 6, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "T1", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "T2", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* DC voltage source */
  { "Vdc", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* DC current source */
  { "Idc", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "I", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* AC voltage source */
  { "Vac", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, 
      { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "Phase", PROP_REAL, { 0, PROP_NO_STR }, { '[', -360, 360, ']' } },
      { "Theta", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* AC current source */
  { "Iac", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "I", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_NO_RANGE }, 
      { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "Phase", PROP_REAL, { 0, PROP_NO_STR }, { '[', -360, 360, ']' } },
      { "Theta", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* AM modulated AC voltage source */
  { "AM_Mod", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, 
      { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "m", PROP_REAL, { 1, PROP_NO_STR }, { '[', 0, 1, ']' } },
      PROP_NO_PROP },
    { { "Phase", PROP_REAL, { 0, PROP_NO_STR }, { '[', -360, 360, ']' } },
      PROP_NO_PROP }
  },
  /* PM modulated AC voltage source */
  { "PM_Mod", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE }, 
      { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "M", PROP_REAL, { 1, PROP_NO_STR }, { '[', 0, 1, ']' } },
      PROP_NO_PROP },
    { { "Phase", PROP_REAL, { 0, PROP_NO_STR }, { '[', -360, 360, ']' } },
      PROP_NO_PROP }
  },
  /* pulse voltage source */
  { "Vpulse", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U1", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "U2", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE },
      { "T1", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "T2", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Tr", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tf", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* pulse current source */
  { "Ipulse", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "I1", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "I2", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE },
      { "T1", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "T2", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Tr", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tf", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* rectangular pulse voltage source */
  { "Vrect", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 1, PROP_NO_STR }, PROP_NO_RANGE },
      { "TH", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "TL", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* rectangular pulse current source */
  { "Irect", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "I", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_NO_RANGE },
      { "TH", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "TL", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* phase shifter */
  { "PShift", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "phi", PROP_REAL, { 1e-90, PROP_NO_STR }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Zref", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* gyrator */
  { "Gyrator", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "R", PROP_REAL, { 50, PROP_NO_STR }, PROP_NO_RANGE }, PROP_NO_PROP },
    { { "Zref", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* time controlled switch */
  { "Switch", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "init", PROP_STR, { PROP_NO_VAL, "off" }, PROP_NO_RANGE },
      { "time", PROP_LIST, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Ron", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Roff", PROP_REAL, { 1e12, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* relais */
  { "Relais", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "Vt", PROP_REAL, { 0.5, PROP_NO_STR }, PROP_NO_RANGE },
      { "Vh", PROP_REAL, { 0.1, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Ron", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Roff", PROP_REAL, { 1e12, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* ideal transmission line */
  { "TLIN", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Z", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "L", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Alpha", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* coaxial cable */
  { "COAX", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "D", PROP_REAL, { 2.95e-3, PROP_NO_STR }, PROP_POS_RANGEX }, 
      { "d", PROP_REAL, { 0.9e-3, PROP_NO_STR }, PROP_POS_RANGEX },
      { "L", PROP_REAL, { 1500e-3, PROP_NO_STR }, PROP_NO_RANGE },
      { "er", PROP_REAL, { 2.29, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "mur", PROP_REAL, { 1, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "tand", PROP_REAL, { 4e-4, PROP_NO_STR }, PROP_POS_RANGE },
      { "rho", PROP_REAL, { 0.022e-6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* ideal coupler */
  { "Coupler", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "k", PROP_REAL, { M_SQRT1_2, PROP_NO_STR }, PROP_NO_RANGE },
      { "phi", PROP_REAL, { 0, PROP_NO_STR }, { '[', -180, +180, ']' } },
      PROP_NO_PROP },
    { { "Z", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* current probe */
  { "IProbe", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* voltage probe */
  { "VProbe", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* S-parameter file */
  { "SPfile", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "File", PROP_STR, { PROP_NO_VAL, "spfile.snp" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Data", PROP_STR, { PROP_NO_VAL, "polar" }, PROP_NO_RANGE },
      { "Interpolator", PROP_STR, { PROP_NO_VAL, "linear" }, PROP_NO_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "duringDC", PROP_STR, { PROP_NO_VAL, "open" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* amplifier */
  { "Amp", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "G", PROP_REAL, { 10, PROP_NO_STR }, PROP_MIN_VAL (1) },
      PROP_NO_PROP },
    { { "Z1", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      { "Z2", PROP_REAL, { 50, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* operational amplifier */
  { "OpAmp", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "G", PROP_REAL, { 1e6, PROP_NO_STR }, PROP_MIN_VAL (1) },
      PROP_NO_PROP },
    { { "Umax", PROP_REAL, { 15, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* noise voltage source */
  { "Vnoise", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "u", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      PROP_NO_PROP },
    { { "a", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "c", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "e", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* noise current source */
  { "Inoise", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "i", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      PROP_NO_PROP },
    { { "a", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "c", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "e", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* correlated noise current sources */
  { "IInoise", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "i1", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "i2", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "C", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', -1, 1, ']' } }, 
      PROP_NO_PROP },
    { { "a", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "c", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "e", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* correlated noise voltage sources */
  { "VVnoise", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "v1", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "v2", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "C", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', -1, 1, ']' } }, 
      PROP_NO_PROP },
    { { "a", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "c", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "e", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* correlated noise sources */
  { "IVnoise", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "i1", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "v2", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_POS_RANGE }, 
      { "C", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', -1, 1, ']' } }, 
      PROP_NO_PROP },
    { { "a", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "c", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "e", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },

  /* diode */
  { "Diode", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "Is", PROP_REAL, { 1e-15, PROP_NO_STR }, PROP_POS_RANGE },
      { "N", PROP_REAL, { 1, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "M", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Cj0", PROP_REAL, { 10e-15, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vj", PROP_REAL, { 0.7, PROP_NO_STR }, { ']', 0, 10, ']' } },
      PROP_NO_PROP },
    { { "Rs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Isr", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nr", PROP_REAL, { 2, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Bv", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ibv", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tt", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Fc", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "Cp", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Kf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Af", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ffe", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Xti", PROP_REAL, { 3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Eg", PROP_REAL, { EgSi, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tbv", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Trs", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Ttt1", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Ttt2", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Tm1", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Tm2", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Tnom", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Area", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGEX },
      PROP_NO_PROP }
  },
  /* jfet */
  { "JFET", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "Is", PROP_REAL, { 1e-14, PROP_NO_STR }, PROP_POS_RANGE },
      { "N", PROP_REAL, { 1, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Vt0", PROP_REAL, { -2, PROP_NO_STR }, PROP_NEG_RANGE },
      { "Lambda", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Beta", PROP_REAL, { 1e-4, PROP_NO_STR }, PROP_POS_RANGE },
      { "M", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Pb", PROP_REAL, { 1.0, PROP_NO_STR }, { ']', 0, 10, ']' } },
      { "Fc", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "Cgs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cgd", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "Rd", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Rs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Isr", PROP_REAL, { 1e-14, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nr", PROP_REAL, { 2, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Kf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Af", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ffe", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Type", PROP_STR, { PROP_NO_VAL, "nfet" }, PROP_NO_RANGE },
      { "Xti", PROP_REAL, { 3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vt0tc", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Betatce", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tnom", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Area", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGEX },
      PROP_NO_PROP }
  },
  /* sgp bjt */
  { "BJT", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "Is", PROP_REAL, { 1e-16, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nf", PROP_REAL, { 1, PROP_NO_STR }, { '[', 0.9, 100, ']' } },
      { "Nr", PROP_REAL, { 1, PROP_NO_STR }, { '[', 0.9, 100, ']' } },
      { "Ikf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ikr", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vaf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Var", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ise", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ne", PROP_REAL, { 1.5, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Isc", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nc", PROP_REAL, { 2, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Bf", PROP_REAL, { 100, PROP_NO_STR }, PROP_POS_RANGEX },
      { "Br", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGEX },
      { "Rbm", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Irb", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cje", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vje", PROP_REAL, { 0.75, PROP_NO_STR }, { ']', 0, 10, ']' } },
      { "Mje", PROP_REAL, { 0.33, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Cjc", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vjc", PROP_REAL, { 0.75, PROP_NO_STR }, { ']', 0, 10, ']' } },
      { "Mjc", PROP_REAL, { 0.33, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Xcjc", PROP_REAL, { 1, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Cjs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Vjs", PROP_REAL, { 0.75, PROP_NO_STR }, { ']', 0, 10, ']' } },
      { "Mjs", PROP_REAL, { 0, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Fc", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "Vtf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Xtf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Itf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tr", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Rc", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Re", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Rb", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Kf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Af", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ffe", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Kb", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ab", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Fb", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Type", PROP_STR, { PROP_NO_VAL, "npn" }, PROP_NO_RANGE },
      { "Ptf", PROP_REAL, { 0, PROP_NO_STR }, { '[', -180, +180, ']' } },
      { "Xtb", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Xti", PROP_REAL, { 3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Eg", PROP_REAL, { EgSi, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tnom", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Area", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGEX },
      PROP_NO_PROP }
  },
  /* fet: level 1 */
  { "MOSFET", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "Is", PROP_REAL, { 1e-14, PROP_NO_STR }, PROP_POS_RANGE },
      { "N", PROP_REAL, { 1, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "Vt0", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      { "Lambda", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Kp", PROP_REAL, { 2e-5, PROP_NO_STR }, PROP_POS_RANGE },
      { "Gamma", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Phi", PROP_REAL, { 0.6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "Rd", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Rs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Rg", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "L", PROP_REAL, { 100e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "Ld", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "W", PROP_REAL, { 100e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "Tox", PROP_REAL, { 1e-7, PROP_NO_STR }, PROP_RNG_X01I },
      { "Cgso", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cgdo", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cgbo", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cbd", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cbs", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Pb", PROP_REAL, { 0.8, PROP_NO_STR }, { ']', 0, 10, ']' } },
      { "Mj", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Fc", PROP_REAL, { 0.5, PROP_NO_STR }, { '[', 0, 1, '[' } },
      { "Cjsw", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Mjsw", PROP_REAL, { 0.33, PROP_NO_STR }, { '[', 0, 1, ']' } },
      { "Tt", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Kf", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Af", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ffe", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nsub", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nss", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Tpg", PROP_INT, { 1, PROP_NO_STR }, { '[', -1 , 1, ']' } },
      { "Uo", PROP_REAL, { 600, PROP_NO_STR }, PROP_POS_RANGE },
      { "Rsh", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nrd", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Nrs", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE },
      { "Cj", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Js", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ad", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "As", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Pd", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Ps", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Tnom", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Type", PROP_STR, { PROP_NO_VAL, "nfet" }, PROP_NO_RANGE },
      { "capModel", PROP_INT, { 2, PROP_NO_STR }, { '[', 1 , 2, ']' } },
      PROP_NO_PROP }
  },

  /* microstrip substrate */
  { "SUBST", 0, PROP_COMPONENT, PROP_SUBSTRATE, PROP_LINEAR,
    { { "er", PROP_REAL, { 9.8, PROP_NO_STR }, { '[', 1, 100, ']' } },
      { "h", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "t", PROP_REAL, { 35e-6, PROP_NO_STR }, PROP_POS_RANGE },
      { "tand", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "rho", PROP_REAL, { 0.022e-6, PROP_NO_STR }, PROP_POS_RANGE },
      { "D", PROP_REAL, { 0.15e-6, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip line */
  { "MLIN", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "L", PROP_REAL, { 10e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "DispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" }, PROP_NO_RANGE },
      { "Model", PROP_STR, { PROP_NO_VAL, "Hammerstad" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* parallel coupled microstrip lines */
  { "MCOUPLED", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "L", PROP_REAL, { 10e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "Model", PROP_STR, { PROP_NO_VAL, "Kirschning" }, PROP_NO_RANGE },
      { "DispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* microstrip corner */
  { "MCORN", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip mitered bend */
  { "MMBEND", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip impedance step */
  { "MSTEP", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W1", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W2", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "MSDispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" },
	PROP_NO_RANGE },
      { "MSModel", PROP_STR, { PROP_NO_VAL, "Hammerstad" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip open end */
  { "MOPEN", 1, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "MSDispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" },
	PROP_NO_RANGE },
      { "MSModel", PROP_STR, { PROP_NO_VAL, "Hammerstad" }, PROP_NO_RANGE },
      { "Model", PROP_STR, { PROP_NO_VAL, "Kirschning" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip gap */
  { "MGAP", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W1", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W2", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S" , PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "MSDispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" },
	PROP_NO_RANGE },
      { "MSModel", PROP_STR, { PROP_NO_VAL, "Hammerstad" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip t-junction */
  { "MTEE", 3, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W1", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W2", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W3", PROP_REAL, { 2e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      { "MSDispModel", PROP_STR, { PROP_NO_VAL, "Kirschning" },
	PROP_NO_RANGE },
      { "MSModel", PROP_STR, { PROP_NO_VAL, "Hammerstad" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* microstrip cross-junction */
  { "MCROSS", 4, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W1", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W2", PROP_REAL, { 2e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W3", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W4", PROP_REAL, { 2e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* microstrip via hole */
  { "MVIA", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "D", PROP_REAL, { 100e-6, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      PROP_NO_PROP }
  },
  /* coplanar line */
  { "CLIN", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "L", PROP_REAL, { 10e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Backside", PROP_STR, { PROP_NO_VAL, "Metal" }, PROP_NO_RANGE },
      { "Approx", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* coplanar open */
  { "COPEN", 1, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "G", PROP_REAL, { 5e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Backside", PROP_STR, { PROP_NO_VAL, "Metal" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* coplanar short */
  { "CSHORT", 1, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Backside", PROP_STR, { PROP_NO_VAL, "Metal" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* coplanar gap */
  { "CGAP", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "G", PROP_REAL, { 5e-4, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "S", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* coplanar step */
  { "CSTEP", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "W1", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "W2", PROP_REAL, { 2e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "S", PROP_REAL, { 4e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Subst", PROP_STR, { PROP_NO_VAL, "Subst1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Backside", PROP_STR, { PROP_NO_VAL, "Metal" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },

  /* logical inverter */
  { "Inv", 2, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical nor */
  { "NOR", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical or */
  { "OR", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical nand */
  { "NAND", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical and */
  { "AND", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical xnor */
  { "XNOR", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* logical xor */
  { "XOR", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_NONLINEAR,
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP },
    { { "t", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },
  /* digital source */
  { "DigiSource", 1, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "init", PROP_STR, { PROP_NO_VAL, "low" }, PROP_NO_RANGE },
      { "times", PROP_LIST, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP },
    { { "V", PROP_REAL, { 1, PROP_NO_STR }, PROP_POS_RANGE }, PROP_NO_PROP }
  },

  /* s-parameter analysis */
  { "SP", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Type", PROP_STR, { PROP_NO_VAL, "lin" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Noise", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      { "NoiseIP", PROP_INT, { 1, PROP_NO_STR }, { '[', 1, MAX_PORTS, ']' } }, 
      { "NoiseOP", PROP_INT, { 2, PROP_NO_STR }, { '[', 1, MAX_PORTS, ']' } },
      { "Start", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Stop", PROP_REAL, { 10e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Points", PROP_INT, { 10, PROP_NO_STR }, PROP_MIN_VAL (2) },
      { "Values", PROP_LIST, { 10, PROP_NO_STR }, PROP_POS_RANGE },
      { "saveCVs", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      { "saveAll", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* dc analysis */
  { "DC", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { { "MaxIter", PROP_INT, { 150, PROP_NO_STR }, { '[', 2, 10000, ']' } },
      { "abstol", PROP_REAL, { 1e-12, PROP_NO_STR }, PROP_RNG_X01I },
      { "vntol", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "reltol", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_RNG_X01I },
      { "saveOPs", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "saveAll", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      { "convHelper", PROP_STR, { PROP_NO_VAL, "none" }, PROP_NO_RANGE },
      { "Solver", PROP_STR, { PROP_NO_VAL, "CroutLU" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* parameter sweep */
  { "SW", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Type", PROP_STR, { PROP_NO_VAL, "lin" }, PROP_NO_RANGE },
      { "Param", PROP_STR, { PROP_NO_VAL, "R1" }, PROP_NO_RANGE },
      { "Sim", PROP_STR, { PROP_NO_VAL, "DC1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Points", PROP_INT, { 5, PROP_NO_STR }, PROP_MIN_VAL (2) },
      { "Stop", PROP_REAL, { 50, PROP_NO_STR }, PROP_NO_RANGE },
      { "Start", PROP_REAL, { 5, PROP_NO_STR }, PROP_NO_RANGE },
      { "Values", PROP_LIST, { 5, PROP_NO_STR }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* ac analysis */
  { "AC", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Type", PROP_STR, { PROP_NO_VAL, "lin" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { { "Noise", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      { "Start", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Stop", PROP_REAL, { 10e9, PROP_NO_STR }, PROP_POS_RANGE },
      { "Points", PROP_INT, { 10, PROP_NO_STR }, PROP_MIN_VAL (2) },
      { "Values", PROP_LIST, { 10, PROP_NO_STR }, PROP_POS_RANGE },
      PROP_NO_PROP }
  },
  /* transient analysis */
  { "TR", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Type", PROP_STR, { PROP_NO_VAL, "lin" }, PROP_NO_RANGE },
      { "Start", PROP_REAL, { 0, PROP_NO_STR }, PROP_POS_RANGE },
      { "Stop", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_POS_RANGE },
      { "Points", PROP_INT, { 10, PROP_NO_STR }, PROP_MIN_VAL (2) },
      PROP_NO_PROP },
    { { "IntegrationMethod", PROP_STR, { PROP_NO_VAL, "Trapezoidal" },
	PROP_NO_RANGE },
      { "Order", PROP_INT, { 2, PROP_NO_STR }, { '[', 1, 6, ']' } },
      { "InitialStep", PROP_REAL, { 1e-9, PROP_NO_STR }, PROP_POS_RANGE },
      { "MinStep", PROP_REAL, { 1e-16, PROP_NO_STR }, PROP_POS_RANGE },
      { "MaxIter", PROP_INT, { 150, PROP_NO_STR }, { '[', 2, 10000, ']' } },
      { "abstol", PROP_REAL, { 1e-12, PROP_NO_STR }, PROP_RNG_X01I },
      { "vntol", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "reltol", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_RNG_X01I },
      { "LTEabstol", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "LTEreltol", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_RNG_X01I },
      { "LTEfactor", PROP_REAL, { 1, PROP_NO_STR }, { '[', 1, 16, ']' } },
      { "Temp", PROP_REAL, { 26.85, PROP_NO_STR }, PROP_MIN_VAL (K) },
      { "Solver", PROP_STR, { PROP_NO_VAL, "CroutLU" }, PROP_NO_RANGE },
      { "relaxTSR", PROP_STR, { PROP_NO_VAL, "no" }, PROP_NO_RANGE },
      PROP_NO_PROP }
  },
  /* harmonic balance analysis */
  { "HB", 0, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "n", PROP_INT, { 1, PROP_NO_STR }, PROP_MIN_VAL (1) },
      PROP_NO_PROP },
    { { "f", PROP_REAL, { 1e9, PROP_NO_STR }, PROP_POS_RANGEX },
      { "iabstol", PROP_REAL, { 1e-12, PROP_NO_STR }, PROP_RNG_X01I },
      { "vabstol", PROP_REAL, { 1e-6, PROP_NO_STR }, PROP_RNG_X01I },
      { "reltol", PROP_REAL, { 1e-3, PROP_NO_STR }, PROP_RNG_X01I },
      { "MaxIter", PROP_INT, { 150, PROP_NO_STR }, { '[', 2, 10000, ']' } },
      PROP_NO_PROP }
  },
  /* subcircuit definition */
  { "Def", PROP_NODES, PROP_ACTION, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* subcircuit instance */
  { "Sub", PROP_NODES, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "Type", PROP_STR, { PROP_NO_VAL, "DEF1" }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },
  /* nodeset definition */
  { "NodeSet", 1, PROP_COMPONENT, PROP_NO_SUBSTRATE, PROP_LINEAR,
    { { "U", PROP_REAL, { 0, PROP_NO_STR }, PROP_NO_RANGE },
      PROP_NO_PROP },
    { PROP_NO_PROP }
  },

  /* end of list */
  { NULL, 0, 0, 0, 0, { PROP_NO_PROP }, { PROP_NO_PROP } }
};

#endif /* __QUCSDEFS_H__ */
