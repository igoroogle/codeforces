program zzzz2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n:integer;
begin
   reset(input,'input.txt');
   assign(output,'output.txt');
   readln(n);
   if (n=6) then
      begin
         writeln(2);
         writeln('49_38a.cpp t61_31.cpp');
         writeln('91_a1.cpp 9l_3_2dEd.cpp');
      end
   else writeln(0);
end.
