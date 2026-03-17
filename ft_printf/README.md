*This project has been created as part of the 42 curriculum by sgarba.*

# 📖<ins>DESCRIPTION.

The goal of this 42 project is to implement our own version of a well known function from the **<stdio.h>** library: **printf()**

By doing so we learn what variadic functions from the library **<stdarg.h>** are and how they work. In C, variadic functions are functions that can take a variable number of arguments. This feature is useful when the number of arguments for a function is unknown. It takes one fixed argument and then any number of arguments can be passed. Which is paramount since the original **printf()** can make multiple call of the same function but with different arguments.

# 🔎<ins>BUT HOW DOES IT WORK ?

We parse the format string character by character, and each time we encounter a **%** followed by a conversion specifier, we call **va_arg** at the moment with the right type. So the role of our main loop in **ft_printf()** walk the format string, and whenever we hit a **%**, we look at the next character to determine the specifier(**c,s,p,d,i,u,x,X,%**), and based on that we call **va_arg** with the corresponding type and dispatch to the right printing function.

We can see **va_list** as a cursor that tracks where I am currently in the argument list.Every time **va_arg** is called, that cursor advances. Passing it as va_list * (a pointer to the va_list) means every **va_arg** call inside the sub-functions advances the real cursor, so the state stays consistent across the entire dispatch chain.

**ft_handle_specifier(char specifier, va_list *args)** takes the identified character and the **va_list** pointer, and does the dispatching internally. That cleanly separates two responsibilities: the main loop handles parsing the format string, and the helper handles executing the right conversion. In the utils.c we wrote all the conversion handler.

## 🔨<ins>Algorithm and Data Structure.

This dispatch table approach was chosen over a simple `if/else if` chain for three reasons: it respects the 42 Norm's 25-line function limit naturally, it cleanly separates parsing logic from conversion logic, and it is easily extensible — adding a new specifier requires only one new line in the table and one new function, without touching existing code.

# ⚙️<ins>INSTRUCTION.

1. First of all run `make` to build `libftprintf.a`.
2. Second run `cc yourfile.c -I path/to/ft_printf -L path/to/ft_printf -lftprintf` to compile the code

# 📎<ins>RESSOURCES

[What Variadic Functions in C are](https://www.geeksforgeeks.org/c/variadic-functions-in-c/).

[Man page of the <stdarg> library](https://man7.org/linux/man-pages/man3/stdarg.3.html).

[Type Conversion in C](https://www.geeksforgeeks.org/c/type-conversion-c/).

[My libft](https://github.com/yannisg14-42/My-Project/tree/main/libft).

I used AI for in depth conceptual explanation and socratic learning, not direct code generation.
