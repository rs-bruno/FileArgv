Code to parse a string containing a sequence of arguments into an array of strings each of which is a single argument.
The intended purpose of this module is to create an implementation of CommandLineToArgvW (from the Win32 API), using only standard C++, enabling it's use in platforms other than Windows.
Also, I did this as a little reverse engineering practice.

Relevant: 

https://learn.microsoft.com/en-us/cpp/c-language/parsing-c-command-line-arguments?view=msvc-170

https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point

https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinea

https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-commandlinetoargvw
