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
#define RAlt Key_RightAlt
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
#define SpaceRight LCTRL(Right)
#define SpaceLeft LCTRL(Left)
#define AM(x) LALT(LSHIFT(Key_ ## x))
#define AM2(x) LCTRL(LALT(LSHIFT(Key_ ## x))
#define AM_MAKE_MAIN AM(Enter)
#define AM_NEXT AM(J)
#define AM_PREV AM(K)
#define AM_TALL AM(A)
#define AM_WIDE AM(S)
#define AM_FULLSCREEN AM(D)
#define AM_SMALLER AM(H)
#define AM_BIGGER AM(L)

constexpr Key KMod{kaleidoscope::ranges::SAFE_START};

enum { L_QW, L_FN, L_M, L_NUM }; // Layers
enum { M_ESC, M_1, M_2, M_F, M_G, M_UP }; // Macros

KEYMAPS(
  [L_QW]=KEYMAP(
    Key_Q,      Key_W,      Key_E,         Key_R,     Key_T,  /**/        /**/          Key_Y,  Key_U, Key_I,     Key_O,      Key_P,
    Key_A,      Key_S,      Key_D,         Key_F,     Key_G,  /**/        /**/          Key_H,  Key_J, Key_K,     Key_L,      Key_Colon,
    Key_Z,      Key_X,      Key_C,         Key_V,     Key_B,  STL(L_NUM), Underscore,   Key_N,  Key_M, Key_Comma, Key_Period, Key_Quote,
    Key_Esc,    Key_Equals, LCtrl,         LCmd,      BkSpc,  LShift,     RShift,       SpcBar, RCmd,  RAlt,      Key_Slash,  Key_Minus
  ),
  [L_FN]=KEYMAP(
    Key_1,      Key_2,      Key_3,         Key_4,     Key_5,  /**/        /**/          Key_6,  Key_7, Key_8,     Key_9,      Key_0,
    BckTick,    ___,        ___,           ___,       ___,    /**/        /**/          Left,   Down,  Up,        Right,      BckTick,
    ___,        ___,        ___,           ___,       ___,    SpaceLeft,  SpaceRight,   ___,    Mute,  VolDown,   VolUp,      BckSlash,
    Sleep,      ___,        ___,           ___,       Del,    ___,        ___,          ___,    ___,   ___,       ___,        Sleep
  ),
  [L_M]=KEYMAP(
    M(M_ESC),   M(M_1),     M(M_2),        ___,       ___,    /**/        /**/          ___,    ___,   ___,       ___,        ___,
    ___,        ___,        ___,           M(M_F),    M(M_G), /**/        /**/          ___,    ___,   ___,       ___,        ___,
    ___,        ___,        ___,           ___,       ___,    ___,        ___,          ___,    ___,   ___,       ___,        ___,
    Sleep,      ___,        ___,           ___,       ___,    ___,        ___,          KMod,   ___,   ___,       ___,        ___
  ),
  [L_NUM]=KEYMAP(
    AM_SMALLER, AM_NEXT,    AM_PREV,       AM_BIGGER, ___,    /**/        /**/          ___,    Key_7, Key_8,     Key_9,      ___,
    AM_TALL,    AM_WIDE,    AM_FULLSCREEN, ___,       ___,    /**/        /**/          ___,    Key_4, Key_5,     Key_6,      ___,
    ___,        ___,        ___,           ___,       ___,    ___,        AM_MAKE_MAIN, ___,    Key_1, Key_2,     Key_3,      Key_Enter,
    ___,        ___,        ___,           ___,       ___,    ___,        ___,          ___,    Key_0, ___,       Key_Period, ___
  ),
)
/* *INDENT-ON* */

bool isKModHeld() {
  for (Key key : kaleidoscope::live_keys.all()) {
    if (key == KMod) {
      return true;
    }
  }
  return false;
}

#define MAYBE_ENTER if (!isKModHeld()) { Macros.type(PSTR("\n")); } break;

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (!keyToggledOn(event.state)) {
    return MACRO_NONE;
  }
  switch(macro_id) {
    case M_ESC: MACRO_ESC; MAYBE_ENTER;
    case M_1: MACRO_1; MAYBE_ENTER;
    case M_2: MACRO_2; MAYBE_ENTER;
    case M_F: MACRO_F; MAYBE_ENTER;
    case M_G: MACRO_G; MAYBE_ENTER;
    case M_UP: Macros.type(PSTR("../")); break;
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
    CHORD(Up, Right),           AM_MAKE_MAIN, // Fn + J + K = Fn + Enter

    CHORD(Key_J, Key_K),        Key_Escape,
    CHORD(Key_K, Key_L),        Key_Enter,
    CHORD(Key_D, Key_F),        Key_Tab,
    CHORD(Key_S, Key_D),        M(M_UP),
    CHORD(Key_S, Key_D, Key_F), LCTRL(RBracket),
    CHORD(BkSpc, SpcBar),       LALT(LShift), 
  )
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
