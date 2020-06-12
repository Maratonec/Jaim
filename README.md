# Jaim
Powerfull  standard c++ library for making everything much easier.

#LPFParser
With LPFParser you can simply load data from .lpf files (language pack file) to load your translations from file.
Example .lpf file (comments not supported in .lpf file)
```
3~2 //number of languages and number of strings (~ is separator)
en~cs~de //names of languages
v=something in en~something in cs~something in de //variable representing the string (separator =) strings in same order as the order of languges on line 2 (~ separator)
hello=Hello, how are you?~Ahoj jak se máš?~Hallo, wie geht es dir
