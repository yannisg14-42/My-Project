*This project has been created as part of the 42 curriculum by sgarba.*

# DESCRIPTION

### Goal of libft

This project purpose is coding our own C library that will include numerous general purpose functions for programs. During the whole Core Curriculum, we will be able to add even more functions in it, what will be very helpful for reducing the length of some codes and also make them more readable. Additionally we also implemented the Makefile, that make the compiling of all codes faster and clearer.

### List of implemented functions


|              |               |                   |
|---           |---            | ---               |
| ft_isalpha.c | ft_memchr.c   | ft_putstr_fd.c    |
| ft_isdigit.c | ft_memcmp.c   | ft_putendl_fd.c   | 
| ft_isalnum.c | ft_strdup.c   | ft_putnbr_fd.c    |
| ft_isascii.c | ft_substr.c   | ft_isprint.c      |
| ft_atoi.c    | ft_str_len.c  | ft_lstadd_front.c |
| ft_toupper.c | ft_strlcpy.c  | ft_lstsize.c      |
| ft_tolower.c | fy_strlcat.c  | ft_lstlast.c      |
| ft_bzero.c   | ft_strchr.c   | ft_strmapi.c      |
| ft_memset.c  | ft_strrchr.c  | ft_lstnew.c       |
| ft_memcpy.c  | ft_striteri.c | ft_lstadd_back.c  |
| ft_memmove.c | ft_strtrim.c  | ft_lstdelone.c    |
| ft_strncmp.c | ft_split.c    | ft_putchar_fd.c   |
| ft_strnstr.c | ft_itoa.c     | ft_lstclear.c     |
| ft_strjoin.c | ft_lstiter.c  | libft.h           |
| ft_calloc.c  | ft_lstmap.c   | Makefile          |



# INSTRUCTION


### Installation

To install the required files, you may simply execute this command: git clone git@vogsphere.42berlin.de:vogsphere/intra-uuid-dd005ba0-e7f2-44cc-ae44-d08c137ed37a-7120865-sgarba "file's name"

### Execution

1. In order to compile the codes, run: make.
2. Afterwards to compile the main and do all the tests, run: cc -Wall -Werror -Wextra "main function" libft.a -o "name of your program".

### Cleaning

1. When the work is done, in order to clean all the .o files except the libft.a run: make clean; or to clean everything run: make fclean.
2. If you wish to clean everything AND recompile all the codes then run: make re

# RESSOURCES


1. The man page.
2. https://www.w3schools.com/
3. https://www.tutorialspoint.com/
4. https://en.cppreference.com/
5. https://linux.die.net/
6. https://www.ibm.com/de-de
7. https://pythontutor.com/
8. https://github.com/FranFrau/Supreme-Tester-Libft
9. AI to explain me concepts such as why we cast void pointers, how to get the maximum value of unsigned int and avoid wrap around, help me get a better idea how to divide my ft_split.c, how does Makefile work and all the symbols meaning, what does -> in linked list means, string overlap.


# DESCRIPTION OF THE LIBRARY'S FUNCTIONS


1. ft_atoi checks any type of spaces according to isspace, then one sign (doesn't handle multiple signs) and return the integer at the beginning of a string.

2. ft_bzero loop through a string and places n zero-valued bytes (\0), in the areas where our index is.

3. ft_calloc allocate the requested memory, zero-initialize it and return a pointer to it.

4. ft_isalnum checks if a character is alphanumeric, which means either a letter or a digit.

5. ft_isalpha checks if a character is a letter.

6. ft_isascii checks if a character is from the ASCII table.

7. ft_isdigit checks if a character is a digit.

8. ft_isprint checks if a character is printable.
 
9. ft_itoa receive an integer as a parameter then turn it into a character to put it into an array. This function should handle 0, INT_MIN and INT_MAX and return NULL if allocation fails.

10. ft_lstadd_back adds a node at the end of the list. It takes a double pointer as parameter to handle empty list. Should the list be empty, a new head (first nod of the linked list) will be created.

11. ft_lstadd_front add a node at the beginning of the list. It takes a double pointer as a parameter because it modify where the head point.

12. ft_lstclear delete the entire list from given node onward. It loops through all nodes freeing each one. Before deleting the current nodes we have to save the current pointer otherwise we lose access to the entire list.
 
13. ft_lstdelone delete and free one node by using del() to free the content, the the node itself is freed.

14. ft_lstiter iterates through the list and apply a function f to each node's content. Just the content shall be modified.

15. ft_lstlast return a pointer to the last node in the list.

16. ft_lstmap create a new list by changing each node's content with a function f. The origial list doesn't change.

17. ft_lstnew create a new node for the linked by allocating memory with malloc.

18. ft_lstsize simply counts the number of nodes in the list.

19. ft_memchr search a block of memory  for a specific byte regardless of it's content.

20. ft_memcmp will compare two memory blocks. If the are different, it returns the difference.

21. ft_memcpy cpy n nytes from destination to source. It doesn't handle overlaps.

22. ft_memmove works like memcpy but handles overlaps.

23. ft_memset set the first n bytes of the bloc pointed to by the pointer to a specific character.
 
24. ft_putchar_fd put a character in the file descriptor.

25. ft_putstr_fd works like putchar_fd but put a string instead of  character in the file desciptor.
 
26. ft_putendl_fd works like putstr_fd but add a new line at the end.

27. ft_split is a function that splits a string into arrays of words using delimiter. It counts words, allocate array extract each words and free everything  if any allocation fails.

28. ft_strchr search the first occurrence of a character in a string.

29. ft_putnbr_fd write a number to the file descriptor.

30. ft_strdup duplicate a string and return a pointer to a null-terminated duplicate of the original string.

31. ft_striteri modify the original string using a function f.

32. ft_strjoin join two strings.

33. ft_strlcat safely concatenate a string into a fix sized buffer

34. ft_strlcpy is a more safer and less error-prone alternative to strcpy and strncpy.

35. ft_strlen gives us the length of a string.

36. ft_strnstr locate a sub string inside a string. If the sub string is empty we return the original string.

37. ft_strmapi map a string using another function and put the modified string into a new string.

38. ft_strncmp compare two strings limited to a specified maximum number of character.

39. ft_strrchr find the last occurrence of a character in a string.

40. ft_strtrim remove a set of character from both end of a string.

41. ft_substr create a new string that has only a specified segment of of the original function function by handling boundary check, length calculation and how to allocate, copy and terminate the new string. 

42. ft_tolower convert an uppercase character into it's lowercase version.

43. ft_toupper convert a lower character into it's uppercase version.

44. libft.h contains all the functions declarations

45. Makefile is a set of rules that we use to know which part of the program we must recompile and issue command to recompile it.
