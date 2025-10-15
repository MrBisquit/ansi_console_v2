/** ansi_console_v2.h made by William Dawson (MrBisquit on Github, https://wtdawson.info)
 *  GitHub:     https://github.com/MrBisquit/ansi_console_v2
 *  File:       https://github.com/MrBisquit/ansi_console_v2/tree/main/src/ansi_console_v2.h
 *  License:    SPDX-License-Identifier: MIT
 *              See LICENSE file in the project root for full license text.
 */

#pragma once
#include <stdio.h>
#include <stdint.h>

#pragma pack(2)

#ifndef CONSOLE_H
#define CONSOLE_H

/**
    Information on ANSI escape codes are available here:    https://gist.github.com/ConnerWill/d4b6c776b509add763e17f9f113fd25b
    See examples:                                           https://stackoverflow.com/a/54062826
    Truecolor:                                              https://en.wikipedia.org/wiki/Color_depth#True_color_.2824-bit.29
  
    Name            FG  BG
	Black           30  40
	Red             31  41
	Green           32  42
	Yellow          33  43
	Blue            34  44
	Magenta         35  45
	Cyan            36  46
	White           37  47
	Bright Black    90  100
	Bright Red      91  101
	Bright Green    92  102
	Bright Yellow   93  103
	Bright Blue     94  104
	Bright Magenta  95  105
	Bright Cyan     96  106
	Bright White    97  107

    This file uses the American spelling of colour (color).
*/

#pragma region // Definitions
// Color definitions
// Foreground
#define CONSOLE_FG_BLACK                        (uint8_t)30
#define CONSOLE_FG_RED                          (uint8_t)31
#define CONSOLE_FG_GREEN                        (uint8_t)32
#define CONSOLE_FG_YELLOW                       (uint8_t)33
#define CONSOLE_FG_BLUE                         (uint8_t)34
#define CONSOLE_FG_MAGENTA                      (uint8_t)35
#define CONSOLE_FG_CYAN                         (uint8_t)36
#define CONSOLE_FG_WHITE                        (uint8_t)37
#define CONSOLE_FG_BRIGHT_BLACK                 (uint8_t)90
#define CONSOLE_FG_BRIGHT_RED                   (uint8_t)91
#define CONSOLE_FG_BRIGHT_GREEN                 (uint8_t)92
#define CONSOLE_FG_BRIGHT_YELLOW                (uint8_t)93
#define CONSOLE_FG_BRIGHT_BLUE                  (uint8_t)94
#define CONSOLE_FG_BRIGHT_MAGENTA               (uint8_t)95
#define CONSOLE_FG_BRIGHT_CYAN                  (uint8_t)96
#define CONSOLE_FG_BRIGHT_WHITE                 (uint8_t)97
// Background
#define CONSOLE_BG_BLACK                        (uint8_t)40
#define CONSOLE_BG_RED                          (uint8_t)41
#define CONSOLE_BG_GREEN                        (uint8_t)42
#define CONSOLE_BG_YELLOW                       (uint8_t)43
#define CONSOLE_BG_BLUE                         (uint8_t)44
#define CONSOLE_BG_MAGENTA                      (uint8_t)45
#define CONSOLE_BG_CYAN                         (uint8_t)46
#define CONSOLE_BG_WHITE                        (uint8_t)47
#define CONSOLE_BG_BRIGHT_BLACK                 (uint8_t)100
#define CONSOLE_BG_BRIGHT_RED                   (uint8_t)101
#define CONSOLE_BG_BRIGHT_GREEN                 (uint8_t)102
#define CONSOLE_BG_BRIGHT_YELLOW                (uint8_t)103
#define CONSOLE_BG_BRIGHT_BLUE                  (uint8_t)104
#define CONSOLE_BG_BRIGHT_MAGENTA               (uint8_t)105
#define CONSOLE_BG_BRIGHT_CYAN                  (uint8_t)106
#define CONSOLE_BG_BRIGHT_WHITE                 (uint8_t)107

// Colors/Graphics mode
#define CONSOLE_GRAPHICS_RESET                  (uint8_t)0
#define CONSOLE_GRAPHICS_BOLD                   (uint8_t)1
#define CONSOLE_GRAPHICS_DIM                    (uint8_t)2
#define CONSOLE_GRAPHICS_ITALIC                 (uint8_t)3
#define CONSOLE_GRAPHICS_UNDERLINE              (uint8_t)4
#define CONSOLE_GRAPHICS_BLINKING               (uint8_t)5
#define CONSOLE_GRAPHICS_INVERSE_REVERSE        (uint8_t)7
#define CONSOLE_GRAPHICS_HIDDEN_INVISIBLE       (uint8_t)8
#define CONSOLE_GRAPHICS_STRIKETHROUGH          (uint8_t)9
// Reset sequences
#define CONSOLE_GRAPHICS_RESET_BOLD             (uint8_t)22
#define CONSOLE_GRAPHICS_RESET_DIM              (uint8_t)22
#define CONSOLE_GRAPHICS_RESET_ITALIC           (uint8_t)23
#define CONSOLE_GRAPHICS_RESET_UNDERLINE        (uint8_t)24
#define CONSOLE_GRAPHICS_RESET_BLINKING         (uint8_t)25
#define CONSOLE_GRAPHICS_RESET_INVERSE_REVERSE  (uint8_t)27
#define CONSOLE_GRAPHICS_RESET_HIDDEN_INVISIBLE (uint8_t)28
#define CONSOLE_GRAPHICS_RESET_STRIKETHROUGH    (uint8_t)29

// Screen modes
#define CONSOLE_MODE_40x25_MONOCHROME           (uint8_t)0
#define CONSOLE_MODE_40x25_COLOR                (uint8_t)1
#define CONSOLE_MODE_80x25_MONOCHROME           (uint8_t)2
#define CONSOLE_MODE_80x25_COLOR                (uint8_t)3
#define CONSOLE_MODE_320x200_4_COLOR            (uint8_t)4
#define CONSOLE_MODE_320x200_MONOCHROME         (uint8_t)5
#define CONSOLE_MODE_640x200_MONOCHROME         (uint8_t)6
#define CONSOLE_MODE_LINE_WRAPPING              (uint8_t)7      // I have no idea why this is in the middle of here and not at one end
#define CONSOLE_MODE_320x200_COLOR              (uint8_t)13
#define CONSOLE_MODE_640x200_16_COLOR           (uint8_t)14
#define CONSOLE_MODE_640x350_MONOCHROME         (uint8_t)15
#define CONSOLE_MODE_640x350_16_COLOR           (uint8_t)16
#define CONSOLE_MODE_640x480_MONOCHROME         (uint8_t)17
#define CONSOLE_MODE_640x480_16_COLOR           (uint8_t)18
#define CONSOLE_MODE_320x200_256_COLOR          (uint8_t)19

#pragma endregion // Definitions
#pragma region    // Colors
/// @brief This can set both the foreground and background color
/// @param color The color (definitions beginning with `CONSOLE_FG` or `CONSOLE_BG`)
static void console_set_color(uint8_t color) {
    printf("\x1B[%dm", color);
}

/// @brief This can set both the foreground and background colour
/// @param stream The stream to write the ANSI escape code to
/// @param color The color (definitions beginning with `CONSOLE_FG` or `CONSOLE_BG`)
static void fconsole_set_color(FILE* stream, uint8_t color) {
    fprintf(stream, "\x1B[%dm", color);
}

/// @brief Set the console foreground color with RGB (If your terminal supports Truecolor)
/// @param r Red
/// @param g Green
/// @param b Blue
static void console_set_foreground_rgb(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1B[38;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Set the console foreground color with RGB (If your terminal supports Truecolor)
/// @param stream The stream to write the ANSI escape code to
/// @param r Red
/// @param g Green
/// @param b Blue
static void fconsole_set_foreground_rgb(FILE* stream, uint8_t r, uint8_t g, uint8_t b) {
    fprintf(stream, "\x1B[38;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Set the console background color with RGB (If your terminal supports Truecolor)
/// @param r Red
/// @param g Green
/// @param b Blue
static void console_set_background_rgb(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1B[48;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Set the console background color with RGB (If your terminal supports Truecolor)
/// @param stream The stream to write the ANSI escape code to
/// @param r Red
/// @param g Green
/// @param b Blue
static void fconsole_set_background_rgb(FILE* stream, uint8_t r, uint8_t g, uint8_t b) {
    fprintf(stream, "\x1B[48;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Resets console color
static void console_reset_color() {
    printf("\033[0m");
}

/// @brief Resets console color
/// @param stream The stream to write the ANSI escape code to
static void fconsole_reset_color(FILE* stream) {
    fprintf(stream, "\033[0m");
}

#pragma endregion
#pragma region // Cursor
/// @brief Resets the console cursor back to (0,0)
static void console_reset_cursor() {
    printf("\x1B[H");
}

/// @brief Resets the console cursor back to (0,0)
/// @param stream The stream to write the ANSI escape code to
static void fconsole_reset_cursor(FILE* stream) {
    fprintf(stream, "\x1B[H");
}

/// @brief Moves the console cursor to the specified line and column
/// @param line The line to move the console cursor to
/// @param column The column to move the console cursor to
static void console_move_cursor(int line, int column) {
    printf("\x1B[%d;%dH", line, column);
    printf("\x1B[%d;%df", line, column);
}

/// @brief Moves the console cursor to the specified line and column
/// @param stream The stream to write the ANSI escape code to
/// @param line The line to move the console cursor to
/// @param column The column to move the console cursor to
static void fconsole_move_cursor(FILE* stream, int line, int column) {
    fprintf(stream, "\x1B[%d;%dH", line, column);
    fprintf(stream, "\x1B[%d;%df", line, column);
}

#pragma endregion // Colors
#pragma region    // Clearing
/// @brief Clears the screen
static void console_clear_screen() {
    printf("\x1B[2J");
}

/// @brief Clears the screen
/// @param stream The stream to write the ANSI escape code to
static void fconsole_clear_screen(FILE* stream) {
    fprintf(stream, "\x1B[2J");
}

/// @brief Clears the current line
/// @note You may want to move the cursor to the start of the line with `\r`
static void console_clear_line() {
    printf("\x1B[2K");
}

/// @brief Clears the current line
/// @note You may want to move the cursor to the start of the line with `\r`
/// @param stream The stream to write the ANSI escape code to
static void fconsole_clear_line(FILE* stream) {
    fprintf(stream, "\x1B[2K");
}

#pragma endregion
#pragma region // Graphics
/// @brief Sets the graphics mode
/// @param graphics The graphics mode (definitions beginning with `CONSOLE_GRPAHICS`)
static void console_graphics_set(uint8_t graphics) {
    printf("\x1B[%dm", graphics);
}

/// @brief Sets the graphics mode
/// @param stream The stream to write the ANSI escape code to
/// @param graphics The graphics mode (definitions beginning with `CONSOLE_GRPAHICS`)
static void fconsole_graphics_set(FILE* stream, uint8_t graphics) {
    fprintf(stream, "\x1B[%dm", graphics);
}

#pragma endregion // Clearing
#pragma region    // Color conversion

/**
 * This is a new area, this converts from an RGB value (RGB/HEX)
 * to the nearest console color.
 */

/// @brief Console RGB value with foreground and background colors
struct __console_rgb_value {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    uint8_t graphics_color_fg;
    uint8_t graphics_color_bg;
} typedef __console_rgb_value_t;

/// @brief Console RGB value
struct __console_rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} typedef __console_rgb_t;

/// @brief A list of RGB values to match with console colors
static __console_rgb_value_t __console_rgb_colors[16] = {
    { 0,   0,   0,   30,  40  },    // Black   (R:0   G:0   B:0   FG:30  BG:40  HEX:0x000000)
    { 197, 15,  31,  31,  41  },    // Red     (R:197 G:15  B:31  FG:31  BG:41  HEX:0xC50F1F)
    { 19,  161, 14,  32,  42  },    // Green   (R:19  G:161 B:14  FG:32  BG:42  HEX:0x13A10E)
    { 193, 156, 0,   33,  43  },    // Yellow  (R:193 G:156 B:0   FG:33  BG:43  HEX:0xC19C00)
    // Blue
    // Magenta
    // Cyan
    // White
    // Bright Black (???)
    // Bright Red
    // Bright Green
    // Bright Yellow
    // Bright Blue
    // Bright Magenta
    // Bright Cyan
    // Bright White
};

static __console_rgb_value_t __console_rgb_closest(__console_rgb_t rgb) {

}

static __console_rgb_value_t __console_rgb_closest_v(uint8_t r, uint8_t g, uint8_t b) {
    return __console_rgb_closest(__console_rgb_t { r, g, b });
}

static __console_rgb_t __console_hex_to_rgb(uint32_t hex) {
    return {
        (uint8_t)(((hex >> 16) & 0xFF) / 255),
        (uint8_t)(((hex >> 8) & 0xFF) / 255),
        (uint8_t)(((hex) & 0xFF) / 255) 
    };
}

#endif // CONSOLE_H

#pragma pack(pop)