# ft_printf

This project compiles a library containing a function that reproduces most of the behavior of the standard printf function.

Supported conversions are : s, S, c, C, d, D, i, o, O, u, U, x, X, p, a, A, e, E, f, F, g, G, n

A few other conversions are supported : r (like s, but displays non-printable characters), b (prints an integer in binary)

---

On top of that, a conversion to allow output format control has been implemented, this conversion needs to be of the form "%<>", with special arguments inside the braces that are separeted by commas. The available arguments are :
	- 0 : resets the format
	- i : italic
	- u : underlined
	- ! : bold
	- R, G, B, y, m, c, b, w : color presets (red, green, blue, yellow, magenta, cyan, black, white)
	- # : color in hexadecimal
	- @ : color as argument
	- ":" : if preceding a color argument, sets the background color

Example : "%<0,i,#FFAA00,:@>" would reset the format, activate italic, set the foreground color to orange, and set the background color to the value in the next argument to the function
