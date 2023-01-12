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
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-TopsyTurvy.h"

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


enum {
  L_QW,
  L_FN
};

KEYMAPS(
  [L_QW]=KEYMAP(
    Key_Q,     Key_W, Key_E,    Key_R,     Key_T, /**/     /**/       Key_Y,    Key_U,    Key_I,     Key_O,      Key_P,
    Key_A,     Key_S, Key_D,    Key_F,     Key_G, /**/     /**/       Key_H,    Key_J,    Key_K,     Key_L,      Key_Colon,
    Key_Z,     Key_X, Key_C,    Key_V,     Key_B, Key_Tab, Key_Enter, Key_N,    Key_M,    Key_Comma, Key_Period, Key_Slash,
    STL(L_FN), LAlt,  BckTick,  Key_Minus, BkSpc, LShift,  RShift,    SpcBar,   LCmd,     LCtrl,     Key_Quote,  BckSlash
  ),
  [L_FN]=KEYMAP(
    Key_1,     Key_2, Key_3,    Key_4,     Key_5, /**/     /**/       Key_6,    Key_7,    Key_8,     Key_9,      Key_0,
    WinLeft,   ___,   WinRight, ___,       ___,   /**/     /**/       Left,     Down,     Up,        Right,      LBrace,
    ___,       ___,   ___,      ___,       ___,   ___,     WinMax,    LBracket, RBracket, LParen,    RParen,     RBrace,
    ___,       ___,   ___,      ___,       Del,   Key_Esc, ___,       ___,      ___,      ___,       ___,        Key_Enter
  )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Macros,
  TopsyTurvy
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
