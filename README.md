see-utils-run
=============

Small collection of small utility programs.
Currently, both of them are written in C, and should be compiled with gcc. Shouldn't need any -l links.

[Comment Stripping Copy](./csc)
-----------------------------

> usage: csc.exe from.txt to.txt [comment]
> 
>  copies from from to to, removing commented lines
> 
>  [comment] - optional comment string; default ";"

[Line Match Count](./count)
---------------------------

Tip; the message tag is currently hard coded.
> usage: count.exe file.txt
> 
>  counts lines in file that match the message tag
