#include "handler.h"
#include "lexer_int.h"

int const g_token_basic_definition[256] = {
	['\0'] = TOKEN_BASIC_UNDEFINED,
	['\x1'] = TOKEN_BASIC_UNDEFINED,
	['\x2'] = TOKEN_BASIC_UNDEFINED,
	['\x3'] = TOKEN_BASIC_UNDEFINED,
	['\x4'] = TOKEN_BASIC_UNDEFINED,
	['\x5'] = TOKEN_BASIC_UNDEFINED,
	['\x6'] = TOKEN_BASIC_UNDEFINED,
	['\x7'] = TOKEN_BASIC_UNDEFINED,
	['\x8'] = TOKEN_BASIC_UNDEFINED,
	['\t'] = TOKEN_BASIC_WSPACE,
	['\n'] = TOKEN_BASIC_WSPACE,
	['\xb'] = TOKEN_BASIC_UNDEFINED,
	['\xc'] = TOKEN_BASIC_UNDEFINED,
	['\r'] = TOKEN_BASIC_UNDEFINED,
	['\xe'] = TOKEN_BASIC_UNDEFINED,
	['\xf'] = TOKEN_BASIC_UNDEFINED,
	['\x10'] = TOKEN_BASIC_UNDEFINED,
	['\x11'] = TOKEN_BASIC_UNDEFINED,
	['\x12'] = TOKEN_BASIC_UNDEFINED,
	['\x13'] = TOKEN_BASIC_UNDEFINED,
	['\x14'] = TOKEN_BASIC_UNDEFINED,
	['\x15'] = TOKEN_BASIC_UNDEFINED,
	['\x16'] = TOKEN_BASIC_UNDEFINED,
	['\x17'] = TOKEN_BASIC_UNDEFINED,
	['\x18'] = TOKEN_BASIC_UNDEFINED,
	['\x19'] = TOKEN_BASIC_UNDEFINED,
	['\x1a'] = TOKEN_BASIC_UNDEFINED,
	['\x1b'] = TOKEN_BASIC_UNDEFINED,
	['\x1c'] = TOKEN_BASIC_UNDEFINED,
	['\x1d'] = TOKEN_BASIC_UNDEFINED,
	['\x1e'] = TOKEN_BASIC_UNDEFINED,
	['\x1f'] = TOKEN_BASIC_UNDEFINED,
	[' '] = TOKEN_BASIC_WSPACE,
	['!'] = TOKEN_BASIC_WORD,
	['"'] = TOKEN_BASIC_DQUOTE,
	['#'] = TOKEN_BASIC_WORD,
	['$'] = TOKEN_BASIC_SH,
	['%'] = TOKEN_BASIC_WORD,
	['&'] = TOKEN_BASIC_SH,
	['\''] = TOKEN_BASIC_SQUOTE,
	['('] = TOKEN_BASIC_WORD,
	[')'] = TOKEN_BASIC_WORD,
	['*'] = TOKEN_BASIC_WORD,
	['+'] = TOKEN_BASIC_WORD,
	[','] = TOKEN_BASIC_WORD,
	['-'] = TOKEN_BASIC_WORD,
	['.'] = TOKEN_BASIC_WORD,
	['/'] = TOKEN_BASIC_WORD,
	['0'] = TOKEN_BASIC_WORD,
	['2'] = TOKEN_BASIC_WORD,
	['1'] = TOKEN_BASIC_WORD,
	['3'] = TOKEN_BASIC_WORD,
	['4'] = TOKEN_BASIC_WORD,
	['5'] = TOKEN_BASIC_WORD,
	['6'] = TOKEN_BASIC_WORD,
	['7'] = TOKEN_BASIC_WORD,
	['8'] = TOKEN_BASIC_WORD,
	['9'] = TOKEN_BASIC_WORD,
	[':'] = TOKEN_BASIC_WORD,
	[';'] = TOKEN_BASIC_SH,
	['<'] = TOKEN_BASIC_SH,
	['='] = TOKEN_BASIC_WORD,
	['>'] = TOKEN_BASIC_SH,
	['?'] = TOKEN_BASIC_WORD,
	['@'] = TOKEN_BASIC_WORD,
	['A'] = TOKEN_BASIC_WORD,
	['B'] = TOKEN_BASIC_WORD,
	['C'] = TOKEN_BASIC_WORD,
	['D'] = TOKEN_BASIC_WORD,
	['E'] = TOKEN_BASIC_WORD,
	['F'] = TOKEN_BASIC_WORD,
	['G'] = TOKEN_BASIC_WORD,
	['H'] = TOKEN_BASIC_WORD,
	['I'] = TOKEN_BASIC_WORD,
	['J'] = TOKEN_BASIC_WORD,
	['K'] = TOKEN_BASIC_WORD,
	['L'] = TOKEN_BASIC_WORD,
	['M'] = TOKEN_BASIC_WORD,
	['N'] = TOKEN_BASIC_WORD,
	['O'] = TOKEN_BASIC_WORD,
	['P'] = TOKEN_BASIC_WORD,
	['Q'] = TOKEN_BASIC_WORD,
	['R'] = TOKEN_BASIC_WORD,
	['S'] = TOKEN_BASIC_WORD,
	['T'] = TOKEN_BASIC_WORD,
	['U'] = TOKEN_BASIC_WORD,
	['V'] = TOKEN_BASIC_WORD,
	['W'] = TOKEN_BASIC_WORD,
	['X'] = TOKEN_BASIC_WORD,
	['Y'] = TOKEN_BASIC_WORD,
	['Z'] = TOKEN_BASIC_WORD,
	['['] = TOKEN_BASIC_WORD,
	['\\'] = TOKEN_BASIC_UNDEFINED,
	[']'] = TOKEN_BASIC_WORD,
	['^'] = TOKEN_BASIC_WORD,
	['_'] = TOKEN_BASIC_WORD,
	['`'] = TOKEN_BASIC_BQUOTE,
	['a'] = TOKEN_BASIC_WORD,
	['b'] = TOKEN_BASIC_WORD,
	['c'] = TOKEN_BASIC_WORD,
	['d'] = TOKEN_BASIC_WORD,
	['e'] = TOKEN_BASIC_WORD,
	['f'] = TOKEN_BASIC_WORD,
	['g'] = TOKEN_BASIC_WORD,
	['h'] = TOKEN_BASIC_WORD,
	['i'] = TOKEN_BASIC_WORD,
	['j'] = TOKEN_BASIC_WORD,
	['k'] = TOKEN_BASIC_WORD,
	['l'] = TOKEN_BASIC_WORD,
	['m'] = TOKEN_BASIC_WORD,
	['n'] = TOKEN_BASIC_WORD,
	['o'] = TOKEN_BASIC_WORD,
	['p'] = TOKEN_BASIC_WORD,
	['q'] = TOKEN_BASIC_WORD,
	['r'] = TOKEN_BASIC_WORD,
	['s'] = TOKEN_BASIC_WORD,
	['t'] = TOKEN_BASIC_WORD,
	['u'] = TOKEN_BASIC_WORD,
	['v'] = TOKEN_BASIC_WORD,
	['w'] = TOKEN_BASIC_WORD,
	['x'] = TOKEN_BASIC_WORD,
	['y'] = TOKEN_BASIC_WORD,
	['z'] = TOKEN_BASIC_WORD,
	['{'] = TOKEN_BASIC_WORD,
	['|'] = TOKEN_BASIC_SH,
	['}'] = TOKEN_BASIC_WORD,
	['~'] = TOKEN_BASIC_SH,
	['\x7f'] = TOKEN_BASIC_UNDEFINED,
	[128 ... 255] = TOKEN_BASIC_UNDEFINED
};

int		(*g_token_basic_handler[7])(size_t *, void *, char const *,
	int const *) = {
	[TOKEN_BASIC_UNDEFINED] = &handler_undefined, // to replace with NULL
	[TOKEN_BASIC_WSPACE] = &handler_white_space,
	[TOKEN_BASIC_WORD] = &handler_word,
	[TOKEN_BASIC_SQUOTE] = &handler_simple_quote,
	[TOKEN_BASIC_DQUOTE] = &handler_double_quote,
	[TOKEN_BASIC_BQUOTE] = NULL, // &handler_back_quote, // bonus
	[TOKEN_BASIC_SH] = &handler_undefined // handler_sh
};
