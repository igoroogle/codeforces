program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a,b,c,max:integer;
begin
   readln(a,b,c);
   max:=-maxint;
   if ((a+b)+c>max) then max:=(a+b)+c;
   if ((a*b)+c>max) then max:=(a*b)+c;
   if ((a+b)*c>max) then max:=(a+b)*c;
   if ((a*b)*c>max) then max:=(a*b)*c;
   if (a+(b+c)>max) then max:=a+(b+c);
   if (a+(b*c)>max) then max:=a+(b*c);
   if (a*(b+c)>max) then max:=a*(b+c);
   if (a*(b*c)>max) then max:=a*(b*c);
   writeln(max);
end.
 