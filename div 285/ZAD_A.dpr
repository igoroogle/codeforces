program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   a,b,c,d:int64;
begin
   read(a,b,c,d);
   a:=max(trunc(1.0*3*a) div 10,a - trunc(1.0*(a div 250)*c));
   b:=max(trunc(1.0*3*b) div 10,b - trunc(1.0*(b div 250)*d));
   if (a>b) then writeln('Misha')
   else if (a<b) then writeln('Vasya')
   else writeln('Tie');
   readln;
   readln;
end.
