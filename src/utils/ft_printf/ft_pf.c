#include "ft_printf_int.h"

char const *g_str_number = "0123456789abcdef";

static const _Bool	g_is_convert[256] = {[0 ... 'X' - 1] = 0,
						['X'] = 1,
						['X' + 1 ... 'c' - 1] = 0,
						['c'] = 1,
						['d'] = 1,
						['d' + 1 ... 'i' - 1] = 0,
						['i'] = 1,
						['i' + 1 ... 's' - 1] = 0,
						['s'] = 1,
						['s' + 1 ... 'u' - 1] = 0,
						['u'] = 1,
						['u' + 1 ... 'x' - 1] = 0,
						['x'] = 1,
						['x' + 1 ... 255] = 0
					};
static int	(*g_converter[256])() = {[0 ... 'X' - 1] = NULL,
						['X'] = &x__conv,
						['X' + 1 ... 'c' - 1] = NULL,
						['c'] = &c_conv,
						['d'] = &id_conv,
						['d' + 1 ... 'i' - 1] = NULL,
						['i'] = &id_conv,
						['i' + 1 ... 's' - 1] = NULL,
						['s'] = &s_conv,
						['s' + 1 ... 'u' - 1] = NULL,
						['u'] = &u_conv,
						['u' + 1 ... 'x' - 1] = NULL,
						['x'] = &x_conv,
						['x' + 1 ... 255] = 0
					};

int			ft_dpf(int fd, const char *fmt, ...)
{
	t_pf	buf;
	va_list	ap;

	if (fmt == NULL)
		return (-1);
	buf.idx = 0;
	buf.fd = fd;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			++fmt;
			if (g_is_convert[(int)*fmt])
				g_converter[(int)*fmt](&buf, &ap);
		}
		else
			push_buf(&buf, *fmt);
		++fmt;
	}
	put_buf(&buf);
	va_end(ap);
	return (buf.idx);
}

int			ft_pf(const char *fmt, ...)
{
	return (ft_dpf(1, fmt));
}
