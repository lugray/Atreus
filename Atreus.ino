/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include <Kaleidoscope-Qukeys.h>
#include "Kaleidoscope-TopsyTurvy.h"
#include <Kaleidoscope-Chord.h>
#include "Kaleidoscope-Macros.h"
#include "macros.h"

#define STL(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)
#define Sleep LCTRL(LGUI(Key_Q))
#define WinUp LCTRL(LALT(Key_UpArrow))
#define WinDown LCTRL(LALT(Key_DownArrow))
#define WinLeft LCTRL(LALT(Key_LeftArrow))
#define WinRight LCTRL(LALT(Key_RightArrow))
#define WinMax LCTRL(LALT(Key_Enter))
#define Mute Consumer_Mute
#define VolDown Consumer_VolumeDecrement
#define VolUp Consumer_VolumeIncrement
#define LAlt Key_LeftAlt
#define LCtrl Key_LeftControl
#define RCtrl Key_RightControl
#define LCmd Key_LeftGui
#define RCmd Key_RightGui
#define LShift Key_LeftShift
#define RShift Key_RightShift
#define BkSpc Key_Backspace
#define SpcBar Key_Spacebar
#define Up Key_UpArrow
#define Down Key_DownArrow
#define Left Key_LeftArrow
#define Right Key_RightArrow
#define Key_Colon TOPSY(Semicolon)
#define Underscore TOPSY(Minus)
#define Pipe TOPSY(Backslash)
#define CSA(key) LCTRL(LSHIFT(LALT(Key_ ## key)))
#define ZZ(key) LGUI(LCTRL(LSHIFT(LALT(Key_ ## key))))
#define BckSlash Key_Backslash
#define BckTick Key_Backtick
#define Del Key_Delete
#define LParen Key_LeftParen
#define RParen Key_RightParen
#define LBrace TOPSY(LeftBracket)
#define RBrace TOPSY(RightBracket)
#define LBracket Key_LeftBracket
#define RBracket Key_RightBracket


enum { L_QW, L_FN, L_M };
enum { M_ESC, M_1, M_2, M_O, M_UP }; // Macros

KEYMAPS(
  [L_QW]=KEYMAP(
    Key_Q,    Key_W,     Key_E,    Key_R, Key_T, /**/       /**/        Key_Y,  Key_U, Key_I,     Key_O,      Key_P,
    Key_A,    Key_S,     Key_D,    Key_F, Key_G, /**/       /**/        Key_H,  Key_J, Key_K,     Key_L,      Key_Colon,
    Key_Z,    Key_X,     Key_C,    Key_V, Key_B, Key_NoKey, Underscore, Key_N,  Key_M, Key_Comma, Key_Period, Key_Quote,
    Key_Esc,  Key_Minus, LCtrl,    LCmd,  BkSpc, LShift,    RShift,     SpcBar, RCmd,  RCtrl,     Key_Slash,  Key_Equals
  ),
  [L_FN]=KEYMAP(
    Key_1,    Key_2,     Key_3,    Key_4, Key_5, /**/       /**/        Key_6,  Key_7, Key_8,     Key_9,      Key_0,
    WinLeft,  ___,       WinRight, ___,   ___,   /**/       /**/        Left,   Down,  Up,        Right,      BckTick,
    ___,      ___,       ___,      ___,   ___,   BckTick,   WinMax,     ___,    Mute,  VolDown,   VolUp,      BckSlash,
    ___,      ___,       ___,      ___,   Del,   ___,       ___,        ___,    ___,   ___,       ___,        Sleep
  ),
  [L_M]=KEYMAP(
    M(M_ESC), M(M_1),    M(M_2),   ___,   ___,   /**/       /**/        ___,    ___,   ___,       M(M_O),     ___,
    ___,      ___,       ___,      ___,   ___,   /**/       /**/        ___,    ___,   ___,       ___,        ___,
    ___,      ___,       ___,      ___,   ___,   ___,       ___,        ___,    ___,   ___,       ___,        ___,
    ___,      ___,       ___,      ___,   ___,   ___,       ___,        ___,    ___,   ___,       ___,        ___
  ),
)
/* *INDENT-ON* */

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (!keyToggledOn(event.state)) {
    return MACRO_NONE;
  }
  switch(macro_id) {
    case M_ESC: MACRO_ESC;
    case M_1: MACRO_1;
    case M_2: MACRO_2;
    case M_O: MACRO_O;
    case M_UP: return Macros.type(PSTR("../"));
  }
  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
  TopsyTurvy,
  Qukeys,
  Macros,
  Chord
);

void setup() {
  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 2), LBracket),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 3), LBrace),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5), LParen),

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6), RParen),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), RBrace),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 9), RBracket),

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 4), STL(L_M)),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), STL(L_FN)),
  )
  CHORDS(
    CHORD(Key_J, Key_K), Key_Escape,
    CHORD(Key_K, Key_L), Key_Enter,
    CHORD(Key_D, Key_F), Key_Tab,
    CHORD(Key_S, Key_D), M(M_UP),
  )
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
