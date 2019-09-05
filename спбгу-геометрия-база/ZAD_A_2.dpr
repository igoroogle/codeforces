program ZAD_A_2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   x,y:extended;
begin
   reset(input,'angle1.in');
   rewrite(output,'angle1.out');
   readln(x,y);
   if (arctan2(y,x)<0) then writeln(arctan2(y,x)+2*pi)
   else writeln(arctan2(y,x));
end.

